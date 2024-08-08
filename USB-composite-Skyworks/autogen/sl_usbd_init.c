//****************************************************************************
// Includes.

#include "sl_status.h"


#include "sl_usbd_core.h"



#include "sl_usbd_class_cdc.h"



#include "sl_usbd_class_cdc_acm.h"









#include "sl_usbd_class_vendor.h"


//****************************************************************************
// Global functions.

/* USB initialization function */
void sli_usbd_init(void)
{

  sl_usbd_core_init();



  sl_usbd_cdc_init();



  sl_usbd_cdc_acm_init();









  sl_usbd_vendor_init();

}
