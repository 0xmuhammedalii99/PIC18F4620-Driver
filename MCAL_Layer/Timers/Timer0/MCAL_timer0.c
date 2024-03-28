/**
 * *****************************************************************************************************
 * * File           : MCAL_timer0.c
 * * Auther         : Muhammed Ali Ibrahim Ahmed
 * * Details        : Timer 0 Module
 * * Linkedin       : https://www.linkedin.com/in/muhammedalii9/
 * * Date Created   : 6 September,2023
 * *****************************************************************************************************
 */

/* _____________________________  Include Section Beginning  ________________________________ */
#include "MCAL_timer0.h"
/* _____________________________  Include Section Ending  ___________________________________ */

/* ____________________________ Data Type Declarations Section Beginning ____________________ */

static uint16 timer0_preload;
/* ____________________________ Data Type Declarations Section Ending ____________________ */

/* _______________________ Helper Function Definination Section Beginning ________________ */

static void timer0_prescaler_config(const _timer0_t *timer_pres);
static void timer0_mode(const _timer0_t *timer_mod);
static void timer0_register_selected(const _timer0_t *timer_reg);
/* _______________________ Helper Function Definination Section Ending ________________ */

#if ADC_INTERRUPT == INTERNEL_INTERRUPT_ENABLE
static void (*Timer0_Interrupt_Handler)(void) = NULL;
void TIMER0_ISR(void)
{
    TIMER0_WRITE_TIMER_HIGH(timer0_preload);
    TIMER0_WRITE_TIMER_LOW(timer0_preload);
    TIMER0_CLEAR_FLAG();
    if (Timer0_Interrupt_Handler)
        Timer0_Interrupt_Handler();
}
#endif

/* ____________________________ Function Definination Section Beginning ____________________________ */

void timer0_initialize(const _timer0_t *timer0_obj)
{
    /* Disable Timer0*/
    TIMER0_STOP_TIMER0();
    /* Prescaler Configration */
    timer0_prescaler_config(timer0_obj);
    /* Timer0 Mode Configuration */
    timer0_mode(timer0_obj);
    /* Timer0 Register Mode */
    timer0_register_selected(timer0_obj);
    /* Writting Value On Timer Register */
    TIMER0_WRITE_TIMER_HIGH(timer0_obj->loaded_value);
    TIMER0_WRITE_TIMER_LOW(timer0_obj->loaded_value);
    timer0_preload = timer0_obj->loaded_value;
    /* _____ Interrupt Configration _____ */
#if ADC_INTERRUPT == INTERNEL_INTERRUPT_ENABLE
    TIMER0_INTERRUPT_FEATURE_ENABLE();
    TIMER0_CLEAR_FLAG();
    Timer0_Interrupt_Handler = timer0_obj->Timer0_InterruptHandler;
#if INTERRUPT_PRIORITY_LEVEL == PRIORITY_LEVELS_ENABLE
    if (timer0_obj->priority == INTERRUPT_HIGH_PRIORITY)
    {
        INTERRUPT_PRIORITY_ENABLE();
        INTERRUPT_GLOBAL_INTERRUPT_LowPriority_ENABLE();
        TIMER0_INTERRUPT_HIGH_PRIORITY();
    }
    else if (timer0_obj->priority == INTERRUPT_LOW_PRIORITY)
    {
        INTERRUPT_PRIORITY_ENABLE();
        INTERRUPT_GLOBAL_INTERRUPT_LowPriority_ENABLE();
        TIMER0_INTERRUPT_LOW_PRIORITY();
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
    /* Enable Timer0 */
    TIMER0_ENABLE_TIMER0();
}
void timer0_read_value(uint16 *value)
{
    uint8 l_timer_h = ZERO, l_timer_l = ZERO;
    l_timer_l = TMR0L;
    l_timer_h = TMR0H;
    *value = (uint16)((l_timer_h << 8) + l_timer_l);
}
void timer0_write_value(uint16 value)
{
    TIMER0_WRITE_TIMER_HIGH(value); // Write on Timer Register High
    TIMER0_WRITE_TIMER_LOW(value);  // Write on Timer Register Low
}
/* ____________________________ Function Declaration Section Ending _______________________________ */

/* __________________________ Helper Function Declaration Section Beginning ______________________ */

static void timer0_prescaler_config(const _timer0_t *timer_pres)
{
    switch (timer_pres->prescaler_enable)
    {
    case _TIMER0_PRESCALER_DISABLE:
        TIMER0_PRESCALER_DISABLE();
        break;
    case _TIMER0_PRESCALER_ENABLE:
        TIMER0_PRESCALER_ENABLE();
        TIMER0_PRESCALER_SELECT(timer_pres->prescaler_value);
        break;
    default:
        /* Nothing */
        break;
    }
}

static void timer0_mode(const _timer0_t *timer_mod)
{
    switch (timer_mod->timer0_mode)
    {

    case _TIMER0_COUNTER_MODE:
        TIMER0_COUNTER_MODE();
        switch (timer_mod->counter_edge)
        {
        case _TIMER0_FALLING_EDGE:
            TIMER0_FALLING_EDGE();
            break;
        case _TIMER0_RISING_EDGE:
            TIMER0_RISING_EDGE();
            break;
        }
        break;
    case _TIMER0_TIMER_MODE:
        TIMER0_TIMER_MODE();
        break;
    default:
        /* Nothing */
        break;
    }
}

static void timer0_register_selected(const _timer0_t *timer_reg)
{
    switch (timer_reg->register_mode)
    {
    case _TIMER0_16_BIT_MODE:
        TIMER0_16_BIT_CONFIG();
        break;
    case _TIMER0_8_BIT_MODE:
        TIMER0_8_BIT_CONFIG();
        break;
    }
}
/* __________________________ Helper Function Declaration Section Ending _________________________ */


/**
 * ******************************************************************************************************
 * *      User                   Date                                 Brief
 * ******************************************************************************************************
 * *     Muhammed Ali         6 September,2023                       Writting MCAL_timer0.c
 */