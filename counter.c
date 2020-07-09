#include "counter.h"
#include "ssd.h"
#include "pushbutton.h"
static unsigned int counter = 0 ;
void CNT_Init(unsigned int initial_count)
{
   counter = initial_count ;
}
void CNT_Update(void)
{
  /* Checking the sate of push buttons */
  if(PB_GetState(PB_RESET) == PB_PRE_RELEASED)
  {
      counter = 0 ;
  }
  else if (PB_GetState(PB_PLUS) == PB_PRE_PRESSED)
  {

      if(counter <= 9999)
      {
          counter ++ ;
      }
  }
  /* updating data */
  CNT_Setcount(counter) ;
}
void CNT_Setcount(unsigned int cnt)
{
    SSD_SetSymbol(SSD_L , ( cnt / 1000) );
    SSD_SetSymbol(SSD_M , ((cnt %1000)/100) );
    SSD_SetSymbol(SSD_N , ((cnt %100)/10) );
    SSD_SetSymbol(SSD_R , ( cnt %10) );
}
