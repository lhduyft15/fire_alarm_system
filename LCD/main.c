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

  //Forever loop
  while (1) {
	  LCD_write("First row", LCD_ROW_01);
	  LCD_write("Second row", LCD_ROW_02);
	  LCD_write("Third row", LCD_ROW_03);
	  LCD_write("Fourth row", LCD_ROW_04);
	  LCD_write("Fifth row", LCD_ROW_05);
	  LCD_write("Sixth row", LCD_ROW_06);
	  LCD_write("Seventh row", LCD_ROW_07);
  }
}
