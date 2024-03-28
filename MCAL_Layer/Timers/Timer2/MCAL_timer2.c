/**
 * *****************************************************************************************************
 * * File           : MCAL_timer2.C
 * * Auther         : Muhammed Ali Ibrahim Ahmed
 * * Details        : Timer 2 Module
 * * Linkedin       : https://www.linkedin.com/in/muhammedalii9/
 * * Date Created   : 9 September,2023
 * *****************************************************************************************************
 */

/* _____________________________  Include Section Beginning  ________________________________ */
#include "MCAL_timer2.h"
/* _____________________________  Include Section Ending  ___________________________________ */

/* ____________________________   Declarations Section Beginning ____________________ */

#if TIMER2_INTERRUPT == INTERNEL_INTERRUPT_ENABLE
static uint8 timer2_preloaded_value;
static void (*Timer2_Interrupt_Handler)(void) = NULL;
void TIMER2_ISR(void)
{
    TIMER2_WRITE_REGISTER(timer2_preloaded_value);
    TIMER2_CLEAR_FLAG();
    if (Timer2_Interrupt_Handler)
        Timer2_Interrupt_Handler();
}
#endif

/* ____________________________   Declarations Section Ending ____________________ */

/* ____________________________ Function Definination Section Beginning ____________________________ */

void timer2_initialzie(const _timer2_t *timer2_obj)
{
    /* Timer 2 Disable */
    TIMER2_DISABLE();
    /* Select Prescaler Value */
    TIMER2_PRESCALER_VALUE(timer2_obj->timer2_prescale_val);
    /* Select Postscaler Value */
    TIMER2_POSTCALER_VALUE(timer2_obj->timer2_postscale_val);
    /* Write Value in Timer 2 Register */
    TIMER2_WRITE_REGISTER(timer2_obj->timer2_preloaded_value);
    /* _______ Interrupt Configration _______*/
#if TIMER2_INTERRUPT == INTERNEL_INTERRUPT_ENABLE
    timer2_preloaded_value = timer2_obj->timer2_preloaded_value;
    TIMER2_INTERRUPT_FEATURE_ENABLE();
    TIMER2_CLEAR_FLAG();
    Timer2_Interrupt_Handler = timer2_obj->Timer2_InterruptHandler;
#if INTERRUPT_PRIORITY_LEVEL == PRIORITY_LEVELS_ENABLE
    if (timer2_obj->priority == INTERRUPT_HIGH_PRIORITY)
    {
        INTERRUPT_PRIORITY_ENABLE();
        INTERRUPT_GLOBAL_INTERRUPT_LowPriority_ENABLE();
        TIMER2_INTERRUPT_HIGH_PRIORITY();
    }
    else if (timer2_obj->priority == INTERRUPT_LOW_PRIORITY)
    {
        INTERRUPT_PRIORITY_ENABLE();
        INTERRUPT_GLOBAL_INTERRUPT_LowPriority_ENABLE();
        TIMER2_INTERRUPT_LOW_PRIORITY();
    }
    else
    {
        /* Nothing */
    }
#else
    INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
    INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE();
#endif
#endif

    /* Timer 2 Enable */
    TIMER2_ENABLE();
}

void timer2_write_value(uint8 value)
{
    TMR2 = value;
}

void timer2_read_value(uint8 *value)
{
    *value = TMR2;
}
/* ____________________________ Function Definination Section Ending _______________________________ */



/**
 * ******************************************************************************************************
 * *      User                   Date                                 Brief
 * ******************************************************************************************************
 * *     Muhammed Ali         9 September,2023                       Writting MCAL_timer2.c
 */