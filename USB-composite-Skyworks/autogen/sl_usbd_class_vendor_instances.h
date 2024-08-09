#ifndef SL_USBD_CLASS_VENDOR_INSTANCES_INIT
#define SL_USBD_CLASS_VENDOR_INSTANCES_INIT

#include "sl_usbd_class_vendor.h"

// [NF_CHANGE]
#define DEVICEINTERFACE_GUID_PROP_NAME L"DeviceInterfaceGUID"
// Length of GUID Property Name
#define DEVICEINTERFACE_GUID_PROP_NAME_LEN sizeof(DEVICEINTERFACE_GUID_PROP_NAME)

// GUID for device class that will be reported to WinUSB (going into DeviceInterfaceGUID extended property)
#define DEVICE_CLASS_GUID_PROPERTY_PLACEHOLDER L"{d3fc5553-a156-4308-bd8e-5c67b1bdaefe}"
/// Length of Device class GUID
#define DEVICE_CLASS_GUID_PROPERTY_LEN         sizeof(DEVICE_CLASS_GUID_PROPERTY_PLACEHOLDER)

#define DEVICE_CLASS_VENDOR_DESCRIPTION "Skyworks Device"

// [END_NF_CHANGE]

/* class numbers assigned by the USB stack after init */

extern uint8_t sl_usbd_vendor_winusb_number;


/* event handlers for all vendor instances */

__WEAK void sl_usbd_vendor_winusb_on_enable_event(void);
__WEAK void sl_usbd_vendor_winusb_on_disable_event(void);
__WEAK void sl_usbd_vendor_winusb_on_setup_request_event(const sl_usbd_setup_req_t *p_setup_req);


/* init functions for all vendor instances */

void sli_usbd_vendor_winusb_init(void);


#endif
