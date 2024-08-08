//****************************************************************************
// Includes.

#include "sl_status.h"
#include "sl_usbd_core.h"
#include "sl_usbd_class_vendor.h"

/* template headers */
#include "sl_usbd_configuration_instances.h"
#include "sl_usbd_class_vendor_instances.h"

/* include config file for the instances */

#include "sl_usbd_class_winusb_config.h"

// [NF_CHANGE]

#include "sl_assert.h"

// storage for USB class vendor description
char UsbClassVendorDescription[GECKO_DEVICE_CLASS_VENDOR_DESCRIPTION_PROPERTY_LEN + 1];
char UsbClassVendorDeviceInterfaceGuid[DEVICE_CLASS_GUID_PROPERTY_LEN];
// [END_NF_CHANGE]

//****************************************************************************
// Function declarations.




/* callback prototypes for winusb instance */

void sli_usbd_vendor_winusb_enable(uint8_t class_nbr);

void sli_usbd_vendor_winusb_disable(uint8_t class_nbr);

void sli_usbd_vendor_winusb_setup_req(uint8_t class_nbr,
                                              const sl_usbd_setup_req_t *p_setup_req);




//****************************************************************************
// Global variables.




/* variables for winusb instance */

uint8_t sl_usbd_vendor_winusb_number = 0;

sl_usbd_vendor_callbacks_t sli_usbd_vendor_winusb_callbacks = {
  sli_usbd_vendor_winusb_enable,
  sli_usbd_vendor_winusb_disable,
  sli_usbd_vendor_winusb_setup_req,
};



//****************************************************************************
// Callback functions.




void sli_usbd_vendor_winusb_enable(uint8_t class_nbr)
{
  (void)&class_nbr;

  sl_usbd_vendor_winusb_on_enable_event();

  return;
}

void sli_usbd_vendor_winusb_disable(uint8_t class_nbr)
{
  (void)&class_nbr;

  sl_usbd_vendor_winusb_on_disable_event();

  return;
}

void sli_usbd_vendor_winusb_setup_req(uint8_t class_nbr,
                                              const sl_usbd_setup_req_t *p_setup_req)
{
  (void)&class_nbr;

  sl_usbd_vendor_winusb_on_setup_request_event(p_setup_req);

  return;
}


//****************************************************************************
// Global functions.



/* initialize winusb instance */
void sli_usbd_vendor_winusb_init()
{
  bool      intr_en         = true;
  uint16_t  interval        = 0;

  uint8_t   class_number    = 0;
  uint8_t   config_number   = 0;

  char     *configs         = NULL;
  char     *token           = NULL;

  sl_usbd_device_state_t deviceState;
  bool needToReinit = false;

  // get current device state
  sl_usbd_core_get_device_state(&deviceState);

  if (deviceState > SL_USBD_DEVICE_STATE_INIT)
  {
      sl_usbd_core_stop_device();

      // flag to reinit
      needToReinit = true;
  }

  /* configs to attach the class instance to */
  configs = SL_USBD_VENDOR_WINUSB_CONFIGURATIONS;

  /* read interrupt enable flag */
  intr_en = SL_USBD_VENDOR_WINUSB_INTERRUPT_ENDPOINTS;

  /* read interval */
  interval  = SL_USBD_VENDOR_WINUSB_INTERVAL;

  /* create vendor instance */
  sl_usbd_vendor_create_instance(intr_en,
                                 interval,
                                 &sli_usbd_vendor_winusb_callbacks,
                                 &class_number);

  /* store class number globally */
  sl_usbd_vendor_winusb_number = class_number;

  /* tokenize configs by "," and spaces */
  token = strtok(configs, ", ");

  /* loop over tokens */
  while (token != NULL) {
    
    /* add to config0? */
    if (!strcmp(token, "config0") || !strcmp(token, "all")) {
      config_number = sl_usbd_configuration_config0_number;
      sl_usbd_vendor_add_to_configuration(class_number, config_number);
    }
    

    /* next token */
    token = strtok(NULL, ", ");
  }

  // [NF_CHANGE]
  const char *deviceClassGuid;
  deviceClassGuid = (char*)DEVICE_CLASS_GUID_PROPERTY_PLACEHOLDER;
  for (uint16_t i = 0; i < sizeof(UsbClassVendorDeviceInterfaceGuid); i += 2)
  {
      UsbClassVendorDeviceInterfaceGuid[i] = *deviceClassGuid++;
  }

  memcpy(UsbClassVendorDescription, DEVICE_CLASS_VENDOR_DESCRIPTION, sizeof(DEVICE_CLASS_VENDOR_DESCRIPTION));

  // add device class GUID to WinUSB properties
  if (sl_usbd_vendor_add_microsoft_ext_property(
          class_number,
          SL_USBD_MICROSOFT_PROPERTY_TYPE_REG_SZ,
          (const uint8_t *)DEVICEINTERFACE_GUID_PROP_NAME,
          DEVICEINTERFACE_GUID_PROP_NAME_LEN,
          (const uint8_t *)DEVICE_CLASS_GUID_PROPERTY_PLACEHOLDER,
          DEVICE_CLASS_GUID_PROPERTY_LEN) != SL_STATUS_OK)
  {
      // failed to add device class GUID to WinUSB
      EFM_ASSERT(false);
  }

  // [END_NF_CHANGE]
  // reinit USB core if needed
  if (needToReinit)
  {
      sl_usbd_core_start_device();
  }

}

