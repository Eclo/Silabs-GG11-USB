/***************************************************************************//**
 * @file
 * @brief Top level application functions
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
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

#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "sl_usbd_core.h"
#include "sl_usbd_class_cdc.h"
#include "sl_usbd_class_cdc_acm.h"

#include "sl_usbd_class_cdc_acm_instances.h"

/*******************************************************************************
 *******************************   DEFINES   ***********************************
 ******************************************************************************/

// Task configuration
#define TASK_STACK_SIZE         512u
#define TASK_PRIO               24u
#define TASK_DELAY_MS           250u

#define  RX_BUF_LEN             128u

/*******************************************************************************
 ***************************  LOCAL VARIABLES   ********************************
 ******************************************************************************/

uint8_t *phy_desc_ptr = NULL;
uint16_t phy_desc_len = 0;

// FreeRTOS handles
static TaskHandle_t terminal_task_handle;

/*******************************************************************************
 ***************************  LOCAL DATA TYPE   ********************************
 ******************************************************************************/



/*******************************************************************************
 ***************************  LOCAL VARIABLES   ********************************
 ******************************************************************************/

/*******************************************************************************
 *********************   LOCAL FUNCTION PROTOTYPES   ***************************
 ******************************************************************************/

static void terminal_task(void *p_arg);

/*******************************************************************************
 ***************************   HOOK FUNCTIONS  *********************************
 ******************************************************************************/

/***************************************************************************//**
 *                          sl_usbd_on_bus_event()
 *
 * @brief  USB bus events.
 ******************************************************************************/
void sl_usbd_on_bus_event(sl_usbd_bus_event_t event)
{
  switch (event) {
    case SL_USBD_EVENT_BUS_CONNECT:
      // called when usb cable is inserted in a host controller
      break;

    case SL_USBD_EVENT_BUS_DISCONNECT:
      // called when usb cable is removed from a host controller
      break;

    case SL_USBD_EVENT_BUS_RESET:
      // called when the host sends reset command
      break;

    case SL_USBD_EVENT_BUS_SUSPEND:
      // called when the host sends suspend command
      break;

    case SL_USBD_EVENT_BUS_RESUME:
      // called when the host sends wake up command
      break;

    default:
      break;
  }
}

/***************************************************************************//**
 *                         sl_usbd_on_config_event()
 *
 * @brief  USB configuration events.
 ******************************************************************************/
void sl_usbd_on_config_event(sl_usbd_config_event_t event, uint8_t config_nbr)
{
  (void)config_nbr;

  switch (event) {
    case SL_USBD_EVENT_CONFIG_SET:
      // called when the host sets a configuration after reset
      break;

    case SL_USBD_EVENT_CONFIG_UNSET:
      // called when a configuration is unset due to reset command
      break;

    default:
      break;
  }
}

/*******************************************************************************
 **************************   GLOBAL FUNCTIONS  ********************************
 ******************************************************************************/

/***************************************************************************//**
 * Initialize application.
 ******************************************************************************/
void usb_device_composite_app_init(void)
{
  BaseType_t xReturned = pdFAIL;

  // Create application task
  xReturned = xTaskCreate(terminal_task,
                          "USB CDC Dummy task",
                          TASK_STACK_SIZE,
                          (void *)(uint32_t)sl_usbd_cdc_acm_acm0_number,
                          TASK_PRIO,
                          &terminal_task_handle);
  EFM_ASSERT(xReturned == pdPASS);

}

/*******************************************************************************
 **************************   LOCAL FUNCTIONS  *********************************
 ******************************************************************************/

/***************************************************************************//**
 *                          terminal_task()
 *
 * @brief  USB CDC ACM terminal emulation demo task.
 *
 * @param  p_arg  Task argument pointer.
 *
 * @note   This task accepts user inputs through the ACM terminal.
 *
 ******************************************************************************/
static void terminal_task(void *p_arg)
{
  bool conn = false;
  sl_status_t status = SL_STATUS_OK;
  char response[64];
  uint32_t bytesRead;

  const TickType_t xDelay = pdMS_TO_TICKS(TASK_DELAY_MS);

  while (1) {
    // Wait until device is in configured state.
    status = sl_usbd_cdc_acm_is_enabled(sl_usbd_cdc_acm_acm0_number, &conn);
    EFM_ASSERT(status == SL_STATUS_OK);

    if(conn)
    {
      // try read something from serial port
      status = sl_usbd_cdc_acm_read(sl_usbd_cdc_acm_acm0_number, response, sizeof(response), 100, &bytesRead);
    }
    else
    {
      // device is not connected
    }

    vTaskDelay(xDelay);
  }
}
