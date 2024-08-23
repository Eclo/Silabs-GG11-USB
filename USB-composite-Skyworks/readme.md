# USB Composite FreeRTOS Application

This example project demonstrates use of the USB stack with FreeRTOS.

The application will create a composite USB device consisting of
a CDC ACM interface and an WinUSB device.

In order to add support for WinUSB devices, some tweaks to the Gecko USB where required. 
These are wrapped with tags `[NF_CHANGE]` and `[END_NF_CHANGE]`.
List of changed files:
- autogen/sl_usbd_class_vendor_instances.h
- autogen/sl_usbd_class_vendor_instances.c
- config/sl_usbd_core_config.h
- gecko_sdk_4.4.4/protocol/usb/src/sl_usbd_class_vendor.c

The changes in USB configuration (sl_usbd_core_config.h) are mentioned above.

To easy the build and adjust USB SDK config, the following preprocessor defines where added:
- GECKO_DEVICE_CLASS_VENDOR_DESCRIPTION_PROPERTY_LEN=64
- SL_USBD_VENDOR_MS_EXTENDED_PROPERTIES_QUANTITY=1

Final note: to ease the use of 16 bits wchar strings in the project, the `-fshort-wchar` flag was added to the GCC compiler options.
