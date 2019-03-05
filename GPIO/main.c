/***************************************************************************//**
 * @file
 * @brief Silicon Labs Empty Example Project
 *
 * This example demonstrates the bare minimum needed for a Blue Gecko C application
 * that allows Over-the-Air Device Firmware Upgrading (OTA DFU). The application
 * starts advertising after boot and restarts advertising after a connection is closed.
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

/* Board headers */
#include "init_mcu.h"
#include "init_board.h"
#include "init_app.h"
#include "ble-configuration.h"
#include "board_features.h"

/* Bluetooth stack headers */
#include "bg_types.h"
#include "native_gecko.h"
#include "gatt_db.h"

/* Libraries containing default Gecko configuration values */
#include "em_emu.h"
#include "em_cmu.h"

/* Device initialization header */
#include "hal-config.h"

#if defined(HAL_CONFIG)
#include "bsphalconfig.h"
#else
#include "bspconfig.h"
#endif

/* Application header */
#include "app.h"

/* User command
Include emlib and user library in here.
*/
#include "em_gpio.h"
#include "user_peripheral_init.h"

//Use for delay function
volatile uint32_t msTick;

void ms_delay(uint32_t time);

int main(void)
{
  /* Initialize device */
  initMcu();
  /* Initialize board */
  initBoard();
  /* Initialize application */
  initApp();

  /* User command
  The user can replace this function by a while forever loop with other function.
  */
  /* Start application */
  //appMain(&config);

  //GPIO Mode set
  GPIO_PinModeSet(LED_PORT, LED_0_PIN, gpioModePushPull, 0);
  GPIO_PinModeSet(LED_PORT, LED_1_PIN, gpioModePushPull, 0);

  GPIO_PinModeSet(BUTTON_PORT, BUTTON_0_PIN, gpioModeInput, 0);
  GPIO_PinModeSet(BUTTON_PORT, BUTTON_1_PIN, gpioModeInput, 0);

  if (SysTick_Config(CMU_ClockFreqGet(cmuClock_CORE)/1000)) {
	  while (1) {
		  GPIO_PinOutSet(LED_PORT, LED_0_PIN);
		  GPIO_PinOutClear(LED_PORT, LED_1_PIN);
	  }
  }

  //Forever loop
  while (1) {
	  if (!GPIO_PinInGet(BUTTON_PORT, BUTTON_0_PIN)) {
		  GPIO_PinOutSet(LED_PORT, LED_0_PIN);
		  GPIO_PinOutClear(LED_PORT, LED_1_PIN);
	  }
	  else if (!GPIO_PinInGet(BUTTON_PORT, BUTTON_1_PIN)) {
		  GPIO_PinOutClear(LED_PORT, LED_0_PIN);
		  GPIO_PinOutSet(LED_PORT, LED_1_PIN);
	  }
	  else {
		  GPIO_PinOutSet(LED_PORT, LED_0_PIN);
		  GPIO_PinOutSet(LED_PORT, LED_1_PIN);
		  ms_delay(500);
		  GPIO_PinOutClear(LED_PORT, LED_0_PIN);
		  GPIO_PinOutClear(LED_PORT, LED_1_PIN);
		  ms_delay(500);
	  }
  }
}

void ms_delay(uint32_t time) {
	msTick = 0;
	while (msTick < time);
}

//System Tick Interrupt handler
void SysTick_Handler(void) {
	msTick++;
}
