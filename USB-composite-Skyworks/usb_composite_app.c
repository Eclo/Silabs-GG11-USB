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


/*******************************************************************************
 ***************************  LOCAL VARIABLES   ********************************
 ******************************************************************************/

uint8_t *phy_desc_ptr = NULL;
uint16_t phy_desc_len = 0;

/*******************************************************************************
 ***************************  LOCAL DATA TYPE   ********************************
 ******************************************************************************/

// Terminal Menu States
SL_ENUM(terminal_state_t) {
  ACM_TERMINAL_STATE_MENU = 0u,
  ACM_TERMINAL_READ_INPUT
};

typedef struct {
  int x;
  int y;
} queue_item_t;

/*******************************************************************************
 ***************************  LOCAL VARIABLES   ********************************
 ******************************************************************************/

/*******************************************************************************
 *********************   LOCAL FUNCTION PROTOTYPES   ***************************
 ******************************************************************************/

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

}

/*******************************************************************************
 **************************   LOCAL FUNCTIONS  *********************************
 ******************************************************************************/
