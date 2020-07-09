#ifndef __GPIO_H__
#define __GPIO_H__
typedef enum
{
    PORT_A ,
    PORT_B ,
    PORT_C ,
    PORT_D ,
    PORT_E
}tPORT ;
typedef enum
{
    GPIO_OUT = 0 ,
    GPIO_IN  = 1
}tPORT_Direction ;
typedef enum
{
    GPIO_LOW = 0 ,
    GPIO_HIGH = 1
}tPIN_State ;
// void GPIO_InitPort (tPORT port , tPORT_Direction direction , unsigned char initial_state) ;
void GPIO_InitPortDirection (tPORT port , tPORT_Direction direction ) ;
void GPIO_InitPortState (tPORT port ,  unsigned char initial_state) ;
void GPIO_InitPinDirection (tPORT port , tPORT_Direction direction , unsigned char pin) ;
void GPIO_InitPinState (tPORT port , unsigned char pin ,  char initial_state) ;
void GPIO_Update (void) ;
void GPIO_SetPortState (tPORT port , unsigned char state ) ;
void GPIO_SetPinState (tPORT port , unsigned char pin , unsigned char state) ;
unsigned char GPIO_GetPortState (tPORT port) ;
unsigned char GPIO_GetPinState (tPORT port , unsigned char pin ) ;


#endif // __GPIO_H__
