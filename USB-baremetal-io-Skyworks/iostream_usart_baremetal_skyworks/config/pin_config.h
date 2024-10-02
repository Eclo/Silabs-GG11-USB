#ifndef PIN_CONFIG_H
#define PIN_CONFIG_H

// $[ACMP0]
// [ACMP0]$

// $[ACMP1]
// [ACMP1]$

// $[ACMP2]
// [ACMP2]$

// $[ACMP3]
// [ACMP3]$

// $[ADC0]
// [ADC0]$

// $[ADC1]
// [ADC1]$

// $[BU]
// [BU]$

// $[CAN0]
// [CAN0]$

// $[CAN1]
// [CAN1]$

// $[CMU]
// [CMU]$

// $[CSEN]
// [CSEN]$

// $[DBG]
// DBG SWV on PF2
#ifndef DBG_SWV_PORT                            
#define DBG_SWV_PORT                             gpioPortF
#endif
#ifndef DBG_SWV_PIN                             
#define DBG_SWV_PIN                              2
#endif
#ifndef DBG_SWV_LOC                             
#define DBG_SWV_LOC                              0
#endif

// [DBG]$

// $[EBI]
// [EBI]$

// $[ETH]
// [ETH]$

// $[ETM]
// [ETM]$

// $[GPIO]
// [GPIO]$

// $[I2C0]
// [I2C0]$

// $[I2C1]
// [I2C1]$

// $[I2C2]
// [I2C2]$

// $[IDAC0]
// [IDAC0]$

// $[LCD]
// [LCD]$

// $[LESENSE]
// [LESENSE]$

// $[LETIMER0]
// [LETIMER0]$

// $[LETIMER1]
// [LETIMER1]$

// $[LEUART0]
// [LEUART0]$

// $[LEUART1]
// [LEUART1]$

// $[LFXO]
// [LFXO]$

// $[PCNT0]
// [PCNT0]$

// $[PCNT1]
// [PCNT1]$

// $[PCNT2]
// [PCNT2]$

// $[PRS.CH0]
// [PRS.CH0]$

// $[PRS.CH1]
// [PRS.CH1]$

// $[PRS.CH2]
// [PRS.CH2]$

// $[PRS.CH3]
// [PRS.CH3]$

// $[PRS.CH4]
// [PRS.CH4]$

// $[PRS.CH5]
// [PRS.CH5]$

// $[PRS.CH6]
// [PRS.CH6]$

// $[PRS.CH7]
// [PRS.CH7]$

// $[PRS.CH8]
// [PRS.CH8]$

// $[PRS.CH9]
// [PRS.CH9]$

// $[PRS.CH10]
// [PRS.CH10]$

// $[PRS.CH11]
// [PRS.CH11]$

// $[PRS.CH12]
// [PRS.CH12]$

// $[PRS.CH13]
// [PRS.CH13]$

// $[PRS.CH14]
// [PRS.CH14]$

// $[PRS.CH15]
// [PRS.CH15]$

// $[PRS.CH16]
// [PRS.CH16]$

// $[PRS.CH17]
// [PRS.CH17]$

// $[PRS.CH18]
// [PRS.CH18]$

// $[PRS.CH19]
// [PRS.CH19]$

// $[PRS.CH20]
// [PRS.CH20]$

// $[PRS.CH21]
// [PRS.CH21]$

// $[PRS.CH22]
// [PRS.CH22]$

// $[PRS.CH23]
// [PRS.CH23]$

// $[QSPI0]
// [QSPI0]$

// $[SDIO]
// [SDIO]$

// $[TIMER0]
// [TIMER0]$

// $[TIMER1]
// [TIMER1]$

// $[TIMER2]
// [TIMER2]$

// $[TIMER3]
// [TIMER3]$

// $[TIMER4]
// [TIMER4]$

// $[TIMER5]
// [TIMER5]$

// $[TIMER6]
// [TIMER6]$

// $[UART0]
// [UART0]$

// $[UART1]
// [UART1]$

// $[USART0]
// [USART0]$

// $[USART1]
// [USART1]$

// $[USART2]
// [USART2]$

// $[USART3]
// [USART3]$

// $[USART4]
// USART4 CTS on PH8
#ifndef USART4_CTS_PORT                         
#define USART4_CTS_PORT                          gpioPortH
#endif
#ifndef USART4_CTS_PIN                          
#define USART4_CTS_PIN                           8
#endif
#ifndef USART4_CTS_LOC                          
#define USART4_CTS_LOC                           4
#endif

// USART4 RTS on PH9
#ifndef USART4_RTS_PORT                         
#define USART4_RTS_PORT                          gpioPortH
#endif
#ifndef USART4_RTS_PIN                          
#define USART4_RTS_PIN                           9
#endif
#ifndef USART4_RTS_LOC                          
#define USART4_RTS_LOC                           4
#endif

// USART4 RX on PH5
#ifndef USART4_RX_PORT                          
#define USART4_RX_PORT                           gpioPortH
#endif
#ifndef USART4_RX_PIN                           
#define USART4_RX_PIN                            5
#endif
#ifndef USART4_RX_LOC                           
#define USART4_RX_LOC                            4
#endif

// USART4 TX on PH4
#ifndef USART4_TX_PORT                          
#define USART4_TX_PORT                           gpioPortH
#endif
#ifndef USART4_TX_PIN                           
#define USART4_TX_PIN                            4
#endif
#ifndef USART4_TX_LOC                           
#define USART4_TX_LOC                            4
#endif

// [USART4]$

// $[USART5]
// [USART5]$

// $[USB]
// [USB]$

// $[VDAC0]
// [VDAC0]$

// $[WFXO]
// [WFXO]$

// $[WTIMER0]
// [WTIMER0]$

// $[WTIMER1]
// [WTIMER1]$

// $[WTIMER2]
// [WTIMER2]$

// $[WTIMER3]
// [WTIMER3]$

// $[CUSTOM_PIN_NAME]
#ifndef _PORT                                   
#define _PORT                                    gpioPortA
#endif
#ifndef _PIN                                    
#define _PIN                                     0
#endif

// [CUSTOM_PIN_NAME]$

#endif // PIN_CONFIG_H

