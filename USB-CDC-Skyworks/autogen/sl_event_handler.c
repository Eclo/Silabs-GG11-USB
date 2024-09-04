#include "sl_event_handler.h"

#include "em_chip.h"
#include "sl_device_init_nvic.h"
#include "sl_board_init.h"
#include "sl_device_init_dcdc.h"
#include "sl_device_init_lfxo.h"
#include "sl_device_init_hfxo.h"
#include "sl_device_init_clocks.h"
#include "sl_device_init_emu.h"
#include "sl_board_control.h"
#include "sl_usbd_init.h"
#include "sl_usbd_configuration_instances.h"
#include "cmsis_os2.h"
#include "sl_usbd_class_cdc_acm_instances.h"

void sl_platform_init(void)
{
  CHIP_Init();
  sl_device_init_nvic();
  sl_board_preinit();
  sl_device_init_dcdc();
  sl_device_init_lfxo();
  sl_device_init_hfxo();
  sl_device_init_clocks();
  sl_device_init_emu();
  sl_board_init();
  osKernelInitialize();
}

void sl_kernel_start(void)
{
  osKernelStart();
}

void sl_driver_init(void)
{
  sli_usbd_init();
}

void sl_service_init(void)
{
  sl_board_configure_vcom();
}

void sl_stack_init(void)
{
  sli_usbd_configuration_config0_init();
  sli_usbd_cdc_acm_acm0_init();
}

void sl_internal_app_init(void)
{
}

