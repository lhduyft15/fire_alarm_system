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
#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include "lcd_driver.h"

#include "i2cspm.h"
#include "si7013.h"
#include "tempsens.h"

/* User commnad
 * Define header for LCD Graphic
*/
#define MY_APP_HEADER 		"\nFIRMESH TEAM\nBLE MESH THESIS\nKHUU MINH HUE\n"
#define MY_APP_HEADER_SIZE 	(sizeof(MY_APP_HEADER))

/**
 * @brief  Main function
 */
int main(void)
{
  /* Initialize device */
  initMcu();
  /* Initialize board */
  initBoard();
  /* Initialize application */
  initApp();

  //Init graphics header
  char header_buffer[MY_APP_HEADER_SIZE + 1];
  snprintf(header_buffer, MY_APP_HEADER_SIZE, MY_APP_HEADER);
  LCD_init(header_buffer);

  //Check the sensor on board
  bool sensor_status = Si7013_Detect(I2C0, SI7021_ADDR, NULL);
  if (sensor_status) {
	  LCD_write("Si7021 detected!", LCD_ROW_01);
  }
  else {
	  LCD_write("Si7021 not detected!", LCD_ROW_01);
  }

  //Variables for the reading temperature and humidity process
  char print_str[LCD_ROW_LEN];
  int32_t temperature = 0;
  uint32_t humidity = 0;

  //Forever loop
  while (1) {
	  //Read temperature and humidity for Si7021
	  Si7013_MeasureRHAndTemp(I2C0, SI7021_ADDR, &humidity, &temperature);
	  LCD_write("Temperature", LCD_ROW_03);
	  sprintf(print_str, "%lu Celsius", temperature/1000);
	  LCD_write(print_str, LCD_ROW_04);

	  LCD_write("Humidity", LCD_ROW_06);
	  sprintf(print_str, "%ld percent", humidity/1000);
	  LCD_write(print_str, LCD_ROW_07);
  }
}
