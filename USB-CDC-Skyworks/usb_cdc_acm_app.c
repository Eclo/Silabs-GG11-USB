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

#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os2.h"
#include "sl_cmsis_os2_common.h"
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

// Menu Message and Length
#define  ACM_TERMINAL_BUF_LEN                   512u
#define  ACM_TERMINAL_SCREEN_SIZE               80u

#define  ACM_TERMINAL_CURSOR_START              "\033[H"
#define  ACM_TERMINAL_CURSOR_START_SIZE         3u

#define  ACM_TERMINAL_SCREEN_CLR                "\033[2J\033[H"
#define  ACM_TERMINAL_SCREEN_CLR_SIZE           7u

#define  ACM_TERMINAL_MSG                       "===== USB CDC ACM Serial Emulation Demo ======" \
                                                "\r\n"                                           \
                                                "\r\n"                                           \
                                                "1. Echo 1 demo.\r\n"                            \
                                                "2. Echo N demo.\r\n"                            \
                                                "3. Echo N asynchronously demo.\r\n"             \
                                                "Option: "

#define  ACM_TERMINAL_MSG_SIZE                  123u

#define  ACM_TERMINAL_MSG1                      "Echo 1 demo... \r\n\r\n>> "
#define  ACM_TERMINAL_MSG1_SIZE                 22u

#define  ACM_TERMINAL_MSG2                      "Echo N demo. You can send up to 512 characters at once... \r\n\r\n>> "
#define  ACM_TERMINAL_MSG2_SIZE                 65u

#define  ACM_TERMINAL_MSG3                      "Echo N asynchronously demo. You can send up to 512 characters at once... \r\n\r\n>> "
#define  ACM_TERMINAL_MSG3_SIZE                 80u

#define  ACM_TERMINAL_NEW_LINE                  "\n\r>> "
#define  ACM_TERMINAL_NEW_LINE_SIZE             5u

/*******************************************************************************
 ***************************  LOCAL DATA TYPE   ********************************
 ******************************************************************************/

// Terminal Menu States
SL_ENUM(terminal_state_t) {
  ACM_TERMINAL_STATE_MENU = 0u,
  ACM_TERMINAL_STATE_ECHO_1,
  ACM_TERMINAL_STATE_ECHO_N,
  ACM_TERMINAL_STATE_ECHO_N_ASYNC
};

/*******************************************************************************
 ***************************  LOCAL VARIABLES   ********************************
 ******************************************************************************/
static osSemaphoreId_t      loopback_echo_async_sem_handle;
__ALIGNED(4) static uint8_t loopback_echo_async_sem_cb[osSemaphoreCbSize];
static osSemaphoreAttr_t    loopback_echo_async_sem_attr = {
  .name       = "USB CDC ACM async semaphore",
  .attr_bits  = 0,
  .cb_mem     = loopback_echo_async_sem_cb,
  .cb_size    = osSemaphoreCbSize
};

// FreeRTOS Task handle
static TaskHandle_t task_handle;

// Universal buffer used to transmit and recevie data.
__ALIGNED(4) static uint8_t acm_terminal_buffer[ACM_TERMINAL_BUF_LEN];

// state of the terminal
static terminal_state_t state = ACM_TERMINAL_STATE_MENU;

/*******************************************************************************
 *********************   LOCAL FUNCTION PROTOTYPES   ***************************
 ******************************************************************************/

static void terminal_task(void *p_arg);

static void loopback_callback(uint8_t     class_nbr,
                              void        *p_buf,
                              uint32_t    buf_len,
                              uint32_t    xfer_len,
                              void        *p_callback_arg,
                              sl_status_t xfr_status);

static void loopback_rx_callback(uint8_t     class_nbr,
                                 void        *p_buf,
                                 uint32_t    buf_len,
                                 uint32_t    xfer_len,
                                 void        *p_callback_arg,
                                 sl_status_t xfr_status);

static void loopback_tx_callback(uint8_t     class_nbr,
                                 void        *p_buf,
                                 uint32_t    buf_len,
                                 uint32_t    xfer_len,
                                 void        *p_callback_arg,
                                 sl_status_t xfr_status);

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
void usb_device_cdc_acm_app_init(void)
{
  BaseType_t xReturned = pdFAIL;

  // Create synchronization semaphore for asynchronous communication.
  loopback_echo_async_sem_handle = osSemaphoreNew(UINT32_MAX, 1u, &loopback_echo_async_sem_attr);
  EFM_ASSERT(loopback_echo_async_sem_handle != NULL);

  // Create application task
  xReturned = xTaskCreate(terminal_task,
                          "USB CDC ACM Termninal task",
                          TASK_STACK_SIZE,
                          (void *)(uint32_t)sl_usbd_cdc_acm_acm0_number,
                          TASK_PRIO,
                          &task_handle);
  EFM_ASSERT(xReturned == pdPASS);
}

/*******************************************************************************
 **************************   LOCAL FUNCTIONS  *********************************
 ******************************************************************************/

/****************************************************************************************************//**
 *                                 loopback_callback()
 *
 * @brief  Bulk IN Callback.
 *
 * @param  class_nbr       Class instance number.
 *
 * @param  p_buf           Pointer to transmit buffer.
 *
 * @param  buf_len         Transmit buffer length.
 *
 * @param  xfer_len        Number of octets transmitted.
 *
 * @param  p_callback_arg  Additional argument provided by application.
 *
 * @param  xfr_status      Transfer error status.
 *******************************************************************************************************/
static void loopback_callback(uint8_t     class_nbr,
                              void        *p_buf,
                              uint32_t    buf_len,
                              uint32_t    xfer_len,
                              void        *p_callback_arg,
                              sl_status_t xfr_status)
{
  (void)(class_nbr);
  (void)(p_buf);
  (void)(buf_len);
  (void)(xfer_len);
  (void)(p_callback_arg);
  (void)(xfr_status);
}
/****************************************************************************************************//**
 *                                 loopback_tx_callback()
 *
 * @brief  Callback called upon Bulk IN transfer completion.
 *
 * @param  class_nbr       Class instance number.
 *
 * @param  p_buf           Pointer to transmit buffer.
 *
 * @param  buf_len         Transmit buffer length.
 *
 * @param  xfer_len        Number of octets transmitted.
 *
 * @param  p_callback_arg  Additional argument provided by application.
 *
 * @param  xfr_status      Transfer error status.
 *******************************************************************************************************/
static void loopback_tx_callback(uint8_t     class_nbr,
                                 void        *p_buf,
                                 uint32_t    buf_len,
                                 uint32_t    xfer_len,
                                 void        *p_callback_arg,
                                 sl_status_t xfr_status)
{
  sl_status_t   status = SL_STATUS_FAIL;

  (void)(p_buf);
  (void)(buf_len);
  (void)(xfer_len);

  if (xfr_status == SL_STATUS_OK) {
    // Move to next line.
    memcpy(acm_terminal_buffer,
           ACM_TERMINAL_NEW_LINE,
           ACM_TERMINAL_NEW_LINE_SIZE);

    status = sl_usbd_cdc_acm_write_async(class_nbr,
                                         acm_terminal_buffer,
                                         ACM_TERMINAL_NEW_LINE_SIZE,
                                         loopback_callback,
                                         p_callback_arg);

    if (status != SL_STATUS_OK) {
      EFM_ASSERT(status == SL_STATUS_OK);
    }
    // Restart test sequence with data reception.
    status = osSemaphoreRelease(loopback_echo_async_sem_handle);
    EFM_ASSERT(status == SL_STATUS_OK);
  } else {
    EFM_ASSERT(status == SL_STATUS_OK);
  }
}
/****************************************************************************************************//**
 *                                  loopback_rx_callback()
 *
 * @brief  Callback called upon Bulk OUT transfer completion.
 *
 * @param  class_nbr       Class instance number.
 *
 * @param  p_buf           Pointer to receive buffer.
 *
 * @param  buf_len         Receive buffer length.
 *
 * @param  xfer_len        Number of octets received.
 *
 * @param  p_callback_arg  Additional argument provided by application.
 *
 * @param  xfr_status      Transfer error status.
 *******************************************************************************************************/
static void loopback_rx_callback(uint8_t     class_nbr,
                                 void        *p_buf,
                                 uint32_t    buf_len,
                                 uint32_t    xfer_len,
                                 void        *p_callback_arg,
                                 sl_status_t xfr_status)
{
  sl_status_t   status = SL_STATUS_FAIL;

  (void)(buf_len);

  if (xfr_status == SL_STATUS_OK) {
    // If 'Ctrl-c' character is received, return to 'menu' state.
    if ((xfer_len == 1u)
        && (acm_terminal_buffer[0] == 0x03)) {
      state = ACM_TERMINAL_STATE_MENU;

      // Clear screen.
      memcpy(acm_terminal_buffer,
             ACM_TERMINAL_SCREEN_CLR,
             ACM_TERMINAL_SCREEN_CLR_SIZE);

      status = sl_usbd_cdc_acm_write_async(class_nbr,
                                           acm_terminal_buffer,
                                           ACM_TERMINAL_SCREEN_CLR_SIZE,
                                           loopback_callback,
                                           p_callback_arg);

      if (status != SL_STATUS_OK) {
        EFM_ASSERT(status == SL_STATUS_OK);
      }
      // Restart data reception.
      status = osSemaphoreRelease(loopback_echo_async_sem_handle);
      EFM_ASSERT(status == SL_STATUS_OK);
    } else {
      // Echo back characters.
      status = sl_usbd_cdc_acm_write_async(class_nbr,
                                           p_buf,                // Rx buf becomes a Tx buf.
                                           xfer_len,
                                           loopback_tx_callback,
                                           p_callback_arg);      // Nbr of octets expected gotten from header msg.

      if (status != SL_STATUS_OK) {
        EFM_ASSERT(status == SL_STATUS_OK);
      }
    }
  } else {
    EFM_ASSERT(status == SL_STATUS_OK);
  }
}

/***************************************************************************//**
 *                          usb_terminal_task()
 *
 * @brief  USB CDC ACM terminal emulation demo task.
 *
 * @param  p_arg  Task argument pointer.
 *
 * @note   (1) This task manages the display of the terminal in according to
 *             the user's inputs.
 ******************************************************************************/
static void terminal_task(void *p_arg)
{
  bool conn = false;
  uint8_t line_state = 0;
  uint8_t ch = 0u;
  uint8_t cdc_acm_nbr = (uint8_t)(uint32_t)p_arg;
  uint32_t xfer_len = 0u;
  uint32_t xfer_len_dummy = 0u;
  sl_status_t status = SL_STATUS_OK;

  const TickType_t xDelay = pdMS_TO_TICKS(TASK_DELAY_MS);

  while (true) {
    // Wait until device is in configured state.
    status = sl_usbd_cdc_acm_is_enabled(cdc_acm_nbr, &conn);
    EFM_ASSERT(status == SL_STATUS_OK);

    status = sl_usbd_cdc_acm_get_line_control_state(cdc_acm_nbr, &line_state);
    EFM_ASSERT(status == SL_STATUS_OK);

    while ((conn != true)
           || ((line_state & SL_USBD_CDC_ACM_CTRL_DTR) == 0)) {
      // Delay Task
      vTaskDelay(xDelay);

      status = sl_usbd_cdc_acm_is_enabled(cdc_acm_nbr, &conn);
      EFM_ASSERT(status == SL_STATUS_OK);

      status = sl_usbd_cdc_acm_get_line_control_state(cdc_acm_nbr, &line_state);
      EFM_ASSERT(status == SL_STATUS_OK);
    }

    switch (state) {
      case ACM_TERMINAL_STATE_MENU:
        // Display start cursor.
        memcpy(acm_terminal_buffer,
               ACM_TERMINAL_CURSOR_START,
               ACM_TERMINAL_CURSOR_START_SIZE);

        status = sl_usbd_cdc_acm_write(cdc_acm_nbr,
                                       acm_terminal_buffer,
                                       ACM_TERMINAL_CURSOR_START_SIZE,
                                       0u,
                                       &xfer_len_dummy);
        if (status != SL_STATUS_OK) {
          break;
        }

        // Display main menu.
        memcpy(acm_terminal_buffer,
               ACM_TERMINAL_MSG,
               ACM_TERMINAL_MSG_SIZE);

        status = sl_usbd_cdc_acm_write(cdc_acm_nbr,
                                       acm_terminal_buffer,
                                       ACM_TERMINAL_MSG_SIZE,
                                       0u,
                                       &xfer_len_dummy);
        if (status != SL_STATUS_OK) {
          break;
        }

        // Wait for character.
        status = sl_usbd_cdc_acm_read(cdc_acm_nbr,
                                      acm_terminal_buffer,
                                      1u,
                                      0u,
                                      &xfer_len_dummy);
        if (status != SL_STATUS_OK) {
          break;
        }

        ch = acm_terminal_buffer[0u];

        // Echo back character.
        status = sl_usbd_cdc_acm_write(cdc_acm_nbr,
                                       acm_terminal_buffer,
                                       1u,
                                       0u,
                                       &xfer_len_dummy);
        if (status != SL_STATUS_OK) {
          break;
        }

        // Select demo options.
        switch (ch) {
          // Echo one character.
          case '1':

            //  Clear screen.
            memcpy(acm_terminal_buffer,
                   ACM_TERMINAL_SCREEN_CLR,
                   ACM_TERMINAL_SCREEN_CLR_SIZE);

            status = sl_usbd_cdc_acm_write(cdc_acm_nbr,
                                           acm_terminal_buffer,
                                           ACM_TERMINAL_SCREEN_CLR_SIZE,
                                           0u,
                                           &xfer_len_dummy);
            if (status != SL_STATUS_OK) {
              break;
            }

            // Display option 1 instructions.
            memcpy(acm_terminal_buffer,
                   ACM_TERMINAL_MSG1,
                   ACM_TERMINAL_MSG1_SIZE);

            status = sl_usbd_cdc_acm_write(cdc_acm_nbr,
                                           acm_terminal_buffer,
                                           ACM_TERMINAL_MSG1_SIZE,
                                           0u,
                                           &xfer_len_dummy);
            if (status != SL_STATUS_OK) {
              break;
            }

            state = ACM_TERMINAL_STATE_ECHO_1;
            break;

          // Echo 'N' characters.
          case '2':

            // Clear screen.
            memcpy(acm_terminal_buffer,
                   ACM_TERMINAL_SCREEN_CLR,
                   ACM_TERMINAL_SCREEN_CLR_SIZE);

            status = sl_usbd_cdc_acm_write(cdc_acm_nbr,
                                           acm_terminal_buffer,
                                           ACM_TERMINAL_SCREEN_CLR_SIZE,
                                           0u,
                                           &xfer_len_dummy);
            if (status != SL_STATUS_OK) {
              break;
            }

            // Display option 2 instructions.
            memcpy(acm_terminal_buffer,
                   ACM_TERMINAL_MSG2,
                   ACM_TERMINAL_MSG2_SIZE);

            status = sl_usbd_cdc_acm_write(cdc_acm_nbr,
                                           acm_terminal_buffer,
                                           ACM_TERMINAL_MSG2_SIZE,
                                           0u,
                                           &xfer_len_dummy);
            if (status != SL_STATUS_OK) {
              break;
            }

            state = ACM_TERMINAL_STATE_ECHO_N;
            break;
          // Echo 'N' characters asynchronously.
          case '3':

            // Clear screen.
            memcpy(acm_terminal_buffer,
                   ACM_TERMINAL_SCREEN_CLR,
                   ACM_TERMINAL_SCREEN_CLR_SIZE);

            status = sl_usbd_cdc_acm_write(cdc_acm_nbr,
                                           acm_terminal_buffer,
                                           ACM_TERMINAL_SCREEN_CLR_SIZE,
                                           0u,
                                           &xfer_len_dummy);
            if (status != SL_STATUS_OK) {
              break;
            }

            // Display option 2 instructions.
            memcpy(acm_terminal_buffer,
                   ACM_TERMINAL_MSG3,
                   ACM_TERMINAL_MSG3_SIZE);

            status = sl_usbd_cdc_acm_write(cdc_acm_nbr,
                                           acm_terminal_buffer,
                                           ACM_TERMINAL_MSG3_SIZE,
                                           0u,
                                           &xfer_len_dummy);
            if (status != SL_STATUS_OK) {
              break;
            }

            state = ACM_TERMINAL_STATE_ECHO_N_ASYNC;
            break;

          default:
            break;
        }
        break;

      // 'Echo 1' state.
      case ACM_TERMINAL_STATE_ECHO_1:
        // Wait for character.
        status = sl_usbd_cdc_acm_read(cdc_acm_nbr,
                                      acm_terminal_buffer,
                                      1u,
                                      0u,
                                      &xfer_len_dummy);
        if (status != SL_STATUS_OK) {
          break;
        }

        ch = acm_terminal_buffer[0u];

        // If 'Ctrl-c' character is received, return to 'menu' state.
        if (ch == 0x03) {
          state = ACM_TERMINAL_STATE_MENU;

          // Clear screen.
          memcpy(acm_terminal_buffer,
                 ACM_TERMINAL_SCREEN_CLR,
                 ACM_TERMINAL_SCREEN_CLR_SIZE);

          status = sl_usbd_cdc_acm_write(cdc_acm_nbr,
                                         acm_terminal_buffer,
                                         ACM_TERMINAL_SCREEN_CLR_SIZE,
                                         0u,
                                         &xfer_len_dummy);
          if (status != SL_STATUS_OK) {
            break;
          }
        } else {
          // Echo back character.
          status = sl_usbd_cdc_acm_write(cdc_acm_nbr,
                                         acm_terminal_buffer,
                                         1u,
                                         0u,
                                         &xfer_len_dummy);
          if (status != SL_STATUS_OK) {
            break;
          }

          // Move to next line.
          memcpy(acm_terminal_buffer,
                 ACM_TERMINAL_NEW_LINE,
                 ACM_TERMINAL_NEW_LINE_SIZE);

          status = sl_usbd_cdc_acm_write(cdc_acm_nbr,
                                         acm_terminal_buffer,
                                         ACM_TERMINAL_NEW_LINE_SIZE,
                                         0u,
                                         &xfer_len_dummy);
          if (status != SL_STATUS_OK) {
            break;
          }
        }
        break;

      // 'Echo N' state.
      case ACM_TERMINAL_STATE_ECHO_N:
        // Wait for N characters.
        status = sl_usbd_cdc_acm_read(cdc_acm_nbr,
                                      acm_terminal_buffer,
                                      ACM_TERMINAL_BUF_LEN,
                                      0u,
                                      &xfer_len);
        if (status != SL_STATUS_OK) {
          break;
        }

        // If 'Ctrl-c' character is received, return to 'menu' state.
        if ((xfer_len == 1u)
            && (acm_terminal_buffer[0] == 0x03)) {
          state = ACM_TERMINAL_STATE_MENU;

          // Clear screen.
          memcpy(acm_terminal_buffer,
                 ACM_TERMINAL_SCREEN_CLR,
                 ACM_TERMINAL_SCREEN_CLR_SIZE);

          status = sl_usbd_cdc_acm_write(cdc_acm_nbr,
                                         acm_terminal_buffer,
                                         ACM_TERMINAL_SCREEN_CLR_SIZE,
                                         0u,
                                         &xfer_len_dummy);
          if (status != SL_STATUS_OK) {
            break;
          }
        } else {
          // Echo back characters.
          status = sl_usbd_cdc_acm_write(cdc_acm_nbr,
                                         &acm_terminal_buffer[0],
                                         xfer_len,
                                         0u,
                                         &xfer_len_dummy);
          if (status != SL_STATUS_OK) {
            break;
          }

          // Move to next line.
          memcpy(acm_terminal_buffer,
                 ACM_TERMINAL_NEW_LINE,
                 ACM_TERMINAL_NEW_LINE_SIZE);

          status = sl_usbd_cdc_acm_write(cdc_acm_nbr,
                                         acm_terminal_buffer,
                                         ACM_TERMINAL_NEW_LINE_SIZE,
                                         0u,
                                         &xfer_len_dummy);
          if (status != SL_STATUS_OK) {
            break;
          }
        }
        break;

      // 'Echo N' state asynchronously.
      case ACM_TERMINAL_STATE_ECHO_N_ASYNC:
        // Wait to (re)start the test sequence.
        status = osSemaphoreAcquire(loopback_echo_async_sem_handle, osWaitForever);
        EFM_ASSERT(status == SL_STATUS_OK);

        // receive Ctr-C break the sequence.
        if (state != ACM_TERMINAL_STATE_ECHO_N_ASYNC) {
          status = osSemaphoreRelease(loopback_echo_async_sem_handle);
          EFM_ASSERT(status == SL_STATUS_OK);
          break;
        }

        // Wait for N characters.
        status = sl_usbd_cdc_acm_read_async(cdc_acm_nbr,
                                            acm_terminal_buffer,
                                            ACM_TERMINAL_BUF_LEN,
                                            loopback_rx_callback,
                                            &cdc_acm_nbr);
        if (status != SL_STATUS_OK) {
          break;
        }

        break;

      default:
        break;
    }
  }
}
