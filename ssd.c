#include "ssd.h"
#include "gpio.h"
#include "utilites.h"
#define NUMBER_OF_SSD (4)
// L = RB7 , M = RB6 , N = RB5 , R = RB4
tSSD_Symbol ssd_symbol[NUMBER_OF_SSD] = {SSD_NULL , SSD_1 , SSD_2 , SSD_3};
static unsigned char ssd_data[] =
{
    0b00111111,
    0b00000110,
    0b01011011,
    0b01001111,
    0b01100110,
    0b01101101,
    0b01111101,
    0b00000111,
    0b01111111,
    0b01101111,
    0b00000000
} ;

void SSD_Init (tSSD ssd , tSSD_State initial_state , tSSD_Symbol initial_symbol )
{
   /* initialize hardware */
 GPIO_InitPortDirection (PORT_D , GPIO_OUT ) ;
 switch (ssd)
 {
     case SSD_L :
                 GPIO_InitPinDirection  (PORT_B , GPIO_OUT , 7) ;
     break ;
     case SSD_M :
                 GPIO_InitPinDirection  (PORT_B , GPIO_OUT , 6) ;
     break ;
     case SSD_N :
                 GPIO_InitPinDirection  (PORT_B , GPIO_OUT , 5) ;
     break ;
     case SSD_R :
                 GPIO_InitPinDirection  (PORT_B , GPIO_OUT , 4) ;
     break ;
     default :
        /* should not be here */
    break ;
 }
  /* initialize data */
  GPIO_SetPortState (PORT_D , ssd_data[initial_symbol] ) ;
  SSD_SetState ( ssd , initial_state ) ;
  SSD_SetSymbol ( ssd ,  initial_symbol ) ;

}
void SSD_Update (void)
{

 tSSD_Symbol current_ssd = SSD_L ;
 for(current_ssd = SSD_L ; current_ssd <= SSD_R ;current_ssd++ )
 {
     /* turn off all SSDs*/
    SSD_SetState (SSD_L , SSD_OFF ) ;
    SSD_SetState (SSD_M , SSD_OFF ) ;
    SSD_SetState (SSD_N , SSD_OFF ) ;
    SSD_SetState (SSD_R , SSD_OFF ) ;
    UTILITES_Delay_Ms( 0 ) ;
    /* set the data of the current ssd */
    GPIO_SetPortState (PORT_D , ssd_data[ssd_symbol[current_ssd]]) ;
    /* turn on the current ssd */
    SSD_SetState (current_ssd , SSD_ON ) ;
    /* delay to show the output */
    UTILITES_Delay_Ms( 18 ) ;
 }


}
void SSD_SetState (tSSD ssd , tSSD_State state )
{
 switch (ssd)
 {
     case SSD_L :
                GPIO_SetPinState  (PORT_B , 7 , state ) ;
     break ;
     case SSD_M :
                 GPIO_SetPinState  (PORT_B , 6 , state ) ;
     break ;
     case SSD_N :
                 GPIO_SetPinState  (PORT_B , 5 , state) ;
     break ;
     case SSD_R :
                 GPIO_SetPinState  (PORT_B , 4 , state) ;
     break ;
     default :
        /* should not be here */
     break ;
 }
}
void SSD_SetSymbol (tSSD ssd , tSSD_Symbol symbol)
{
 ssd_symbol[ssd] = symbol ;
}
