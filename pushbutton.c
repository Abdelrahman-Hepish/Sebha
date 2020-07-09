#include "pushbutton.h"
#include "gpio.h"

#define NUMBER_OF_SAMPLES      (2)
#define NUMBER_OF_PUSH_BUTTONS (4)

#define PB_RELEASED_VOLTAGE (1)
#define PB_PRESSED_VOLTAGE  (0)
typedef struct
{
   unsigned char smaples [NUMBER_OF_SAMPLES]  ;
    tPB_State state ;
}tPB_Info ;

static tPB_Info pb_info [NUMBER_OF_PUSH_BUTTONS] ;

void PB_Init(tPB pb , tPB_State initial_state )
{
    /* initialize hardware as input*/
    switch (pb)
    {
    case  PB_PLUS :
    GPIO_InitPinDirection (PORT_B , GPIO_IN , 3) ;
    break ;
    case  PB_RESET :
    GPIO_InitPinDirection (PORT_B , GPIO_IN , 2) ;
    break ;
    case  PB_UNUSED_1 :
    GPIO_InitPinDirection (PORT_B , GPIO_IN , 1) ;
    break ;
    case  PB_UNUSED_2 :
    GPIO_InitPinDirection (PORT_B , GPIO_IN , 0) ;
    break ;
    default :
        /* should not be here */
    break ;
    }
  /* initialize state */
    pb_info[pb].state = initial_state ;
  /* initialize sample */
    switch (initial_state)
    {
    case PB_RELEASED :
    case PB_PRE_RELEASED :
    pb_info[pb].smaples[0] = PB_RELEASED_VOLTAGE ;
    pb_info[pb].smaples[1] = PB_RELEASED_VOLTAGE ;
    break ;
    case PB_PRESSED :
    case PB_PRE_PRESSED :
    pb_info[pb].smaples[0] = PB_PRESSED_VOLTAGE ;
    pb_info[pb].smaples[1] = PB_PRESSED_VOLTAGE ;
    break ;
    default :
        /* should not be here */
    break ;
    }

}
void PB_Update (void)
{
  /* task */
     tPB current_pb = PB_PLUS ;
for(current_pb = PB_PLUS ; current_pb <= PB_UNUSED_2 ; current_pb ++)
{
  /* update push button new sample and transmit the previous new sample to a new one */
    pb_info[current_pb].smaples[0] = pb_info[current_pb].smaples[1]  ;
    switch (current_pb)
    {
    case  PB_PLUS :
    pb_info[current_pb].smaples[1] = GPIO_GetPinState (PORT_B , 3 ) ;
    break ;
    case  PB_RESET :
    pb_info[current_pb].smaples[1] = GPIO_GetPinState (PORT_B , 2 ) ;
    break ;
    case  PB_UNUSED_1 :
    pb_info[current_pb].smaples[1] = GPIO_GetPinState (PORT_B , 1 ) ;
    break ;
    case  PB_UNUSED_2 :
    pb_info[current_pb].smaples[1] = GPIO_GetPinState (PORT_B , 0 ) ;
    break ;
    default :
        /* should not be here */
    break ;
    }
    /* update push button state */
    switch (pb_info[current_pb].state)
    {
    case  PB_RELEASED :
    if((pb_info[current_pb].smaples[0]==PB_PRESSED_VOLTAGE) &&
       (pb_info[current_pb].smaples[1]==PB_PRESSED_VOLTAGE ) )
    {
        pb_info[current_pb].state = PB_PRE_PRESSED ;
    }
    break ;
    case  PB_PRE_PRESSED :
    if( pb_info[current_pb].smaples[1]==PB_PRESSED_VOLTAGE  )
    {
        pb_info[current_pb].state = PB_PRESSED ;
    }
    break ;
    case  PB_PRESSED :
    if((pb_info[current_pb].smaples[0]==PB_RELEASED_VOLTAGE )&&
       (pb_info[current_pb].smaples[1]==PB_RELEASED_VOLTAGE  ))
    {
        pb_info[current_pb].state = PB_PRE_RELEASED ;
    }
    break ;
    case  PB_PRE_RELEASED :
    if( pb_info[current_pb].smaples[1]==PB_RELEASED_VOLTAGE  )
    {
        pb_info[current_pb].state = PB_RELEASED ;
    }
    break ;
    default :
        /* should not be here */
    break ;
    }
}
  /* update counter */
}
tPB_State PB_GetState (tPB pb)
{
    tPB_State ret = PB_RELEASED ;
    ret = pb_info[pb].state ;
    return ret ;
}
