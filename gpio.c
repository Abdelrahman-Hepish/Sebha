#include <pic16f877a.h>
#include "gpio.h"
#define SET_REG_PIN_STATE(REG,PIN,VAL)  ( (REG) = ( ((REG) & (~(1<<PIN))) | (VAL << PIN )) )
#define READ_PIN_STATE(REG,PIN)         ( ((REG) & ( 1 << PIN )) >> (PIN))
void GPIO_InitPortDirection (tPORT port , tPORT_Direction direction )
{
     unsigned char i = 0 ;
    switch (port)
    {
    case PORT_A :
                for(i=0 ; i < 8 ; i++)
                {
                    SET_REG_PIN_STATE(TRISA,i,direction) ;
                }
    break ;
    case PORT_B :
                for(i=0 ; i < 8 ; i++)
                {
                    SET_REG_PIN_STATE(TRISB,i,direction) ;
                }
    break ;
    case PORT_C :
                for(i=0 ; i < 8 ; i++)
                {
                    SET_REG_PIN_STATE(TRISC,i,direction) ;
                }
    break ;
    case PORT_D :
                for(i=0 ; i < 8 ; i++)
                {
                    SET_REG_PIN_STATE(TRISD,i,direction) ;
                }
    break ;
    case PORT_E :
                for(i=0 ; i < 5 ; i++)
                {
                    SET_REG_PIN_STATE(TRISE,i,direction) ;
                }
    break ;
    default :
        /* should not be here */
    break ;
    }
}
void GPIO_InitPortState (tPORT port ,  unsigned char initial_state)
{
    switch (port)
    {
    case PORT_A :
                PORTA = initial_state ;
    break ;
    case PORT_B :
                PORTB = initial_state ;
    break ;
    case PORT_C :
                PORTC = initial_state ;
    break ;
    case PORT_D :
                PORTD = initial_state ;
    break ;
    case PORT_E :
                PORTE = initial_state ;
    break ;
    default :
        /* should not be here */
    break ;
    }
}
void GPIO_InitPinDirection (tPORT port , tPORT_Direction direction , unsigned char pin)
{
    switch (port)
    {
    case PORT_A :
                SET_REG_PIN_STATE(TRISA,pin,direction) ;
    break ;
    case PORT_B :
                SET_REG_PIN_STATE(TRISB,pin,direction) ;
    break ;
    case PORT_C :
                SET_REG_PIN_STATE(TRISC,pin,direction) ;
    break ;
    case PORT_D :
                SET_REG_PIN_STATE(TRISD,pin,direction) ;
    break ;
    case PORT_E :
                SET_REG_PIN_STATE(TRISE,pin,direction) ;
    break ;
    default :
        /* should not be here */
    break ;
    }
}
void GPIO_InitPinState (tPORT port , unsigned char pin ,  char initial_state)
{
    GPIO_SetPinState (port , pin , initial_state) ;
}

void GPIO_Update (void)
{
    /* will do no thing */
}
void GPIO_SetPortState (tPORT port , unsigned char state )
{
    unsigned char i = 0 ;
    for(i = 0 ; i < 8 ; i++)
    {
      GPIO_SetPinState ( port , i , READ_PIN_STATE(state,i) )  ;
    }
}
void GPIO_SetPinState (tPORT port , unsigned char pin , unsigned char state)
{
    switch (port)
    {
    case PORT_A :
                SET_REG_PIN_STATE(PORTA,pin,state) ;
    break ;
    case PORT_B :
                SET_REG_PIN_STATE(PORTB,pin,state) ;
    break ;
    case PORT_C :
                SET_REG_PIN_STATE(PORTC,pin,state) ;
    break ;
    case PORT_D :
                SET_REG_PIN_STATE(PORTD,pin,state) ;
    break ;
    case PORT_E :
                SET_REG_PIN_STATE(PORTE,pin,state) ;
    break ;
    default :
        /* should not be here */
    break ;
    }
}
unsigned char GPIO_GetPortState (tPORT port)
{
    unsigned char ret = 0x00 ;
    switch (port)
    {
    case PORT_A :
           ret = PORTA ;
    break ;
    case PORT_B :
           ret = PORTB ;
    break ;
    case PORT_C :
           ret = PORTC ;
    break ;
    case PORT_D :
           ret = PORTD ;
    break ;
    case PORT_E :
           ret = PORTE ;
    break ;
    default :
        /* should not be here */
    break ;
    }
    return ret ;
}
unsigned char GPIO_GetPinState (tPORT port , unsigned char pin )
{
    unsigned char ret = 0x00 ;
    switch (port)
    {
    case PORT_A :
           ret = READ_PIN_STATE(PORTA,pin) ;
    break ;
    case PORT_B :
           ret = READ_PIN_STATE(PORTB,pin) ;
    break ;
    case PORT_C :
           ret = READ_PIN_STATE(PORTC,pin) ;
    break ;
    case PORT_D :
           ret = READ_PIN_STATE(PORTD,pin) ;
    break ;
    case PORT_E :
           ret = READ_PIN_STATE(PORTE,pin) ;
    break ;
    default :
        /* should not be here */
    break ;
    }
    return ret ;
}
