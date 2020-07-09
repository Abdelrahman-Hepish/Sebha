#ifndef __SSD_H__
#define __SSD_H__

typedef enum
{
    SSD_L ,
    SSD_M ,
    SSD_N ,
    SSD_R
}tSSD ;
typedef enum
{
    SSD_OFF = 0 ,
    SSD_ON  = 1
}tSSD_State ;
typedef enum
{
    SSD_0 ,
    SSD_1 ,
    SSD_2 ,
    SSD_3 ,
    SSD_4 ,
    SSD_5 ,
    SSD_6 ,
    SSD_7 ,
    SSD_8 ,
    SSD_9 ,
    SSD_NULL
}tSSD_Symbol ;

void SSD_Init (tSSD ssd , tSSD_State initial_state , tSSD_Symbol initial_symbol ) ;
void SSD_Update (void) ;
void SSD_SetState (tSSD ssd , tSSD_State state ) ;
void SSD_SetSymbol (tSSD ssd , tSSD_Symbol symbol) ;
#endif // __SSD_H__
