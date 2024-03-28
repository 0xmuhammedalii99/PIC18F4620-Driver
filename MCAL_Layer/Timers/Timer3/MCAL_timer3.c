/**
 * *****************************************************************************************************
 * * File           : MCAL_timer3.c
 * * Auther         : Muhammed Ali Ibrahim Ahmed
 * * Details        : Timer 3 Module
 * * Linkedin       : https://www.linkedin.com/in/muhammedalii9/
 * * Date Created   : 10 September,2023
 * *****************************************************************************************************
 */

/* __________________________  Include Section Beginning  __________________________________ */
#include "MCAL_timer3.h"
/* __________________________  Include Section Ending  _____________________________________ */

/* __________________________ Helper Function Declaration Section Beginning ______________________ */

static void timer3_select_mode(const _timer3_t *timer3_mode);
static void timer3_select_readPin(const _timer3_t *timer3_readPin);
static void timer3_Oscillator_EN(const _timer3_t *timer1_osc);

/* ____________________________   Declarations Section Beginning ____________________ */

#if TIMER3_INTERRUPT == INTERNEL_INTERRUPT_ENABLE
static uint16 preload_val = ZERO;
void (*Timer3_Interrupt_Handler)(void) = NULL;
void TIMER3_ISR(void)
{
    /* Clear Flag*/
    TIMER3_CLEAR_FLAG();
    /* Load Value To Register */
    TIMER3_WRITE_TIMER_HIGH(preload_val);
    TIMER3_WRITE_TIMER_LOW(preload_val);
    if (Timer3_Interrupt_Handler)
        Timer3_Interrupt_Handler();
}
#endif
/* ____________________________   Declarations Section Ending ____________________ */

/* ____________________________ Function Definination Section Beginning ____________________________ */

void timer3_initialize(const _timer3_t *timer3_obj)
{
    /* Disable Timer 3 Module */
    TIMER3_DISABLE();
    /* Select Timer 3 Mode ( Counter / Timer ) */
    timer3_select_mode(timer3_obj);
    /* Select Prescaler Value */
    TIMER3_PRESCALER_VALUE(timer3_obj->timer3_prescaler_value);
    /* Load Value to Timer 3 Registers */
    TIMER3_WRITE_TIMER_HIGH(timer3_obj->timer3_preloaded_value);
    TIMER3_WRITE_TIMER_LOW(timer3_obj->timer3_preloaded_value);
    /* Select Timer 3 Read Mode */
    timer3_select_readPin(timer3_obj);
    /* Select Oscillator ( Enable / Disable ) */
    timer3_Oscillator_EN(timer3_obj);
/* _______ Interrupt Configration _______ */
#if TIMER3_INTERRUPT == INTERNEL_INTERRUPT_ENABLE
    preload_val = timer3_obj->timer3_preloaded_value;
    TIMER3_INTERRUPT_FEATURE_ENABLE();
    TIMER3_CLEAR_FLAG();
    Timer3_Interrupt_Handler = timer3_obj->Timer3_InterruptHandler;
#if INTERRUPT_PRIORITY_LEVEL == PRIORITY_LEVELS_ENABLE
    if (timer3_obj->timer3_priority == INTERRUPT_HIGH_PRIORITY)
    {
        INTERRUPT_PRIORITY_ENABLE();
        INTERRUPT_GLOBAL_INTERRUPT_LowPriority_ENABLE();
        TIMER3_INTERRUPT_HIGH_PRIORITY();
    }
    else if (timer3_obj->timer3_priority == INTERRUPT_LOW_PRIORITY)
    {
        INTERRUPT_PRIORITY_ENABLE();
        INTERRUPT_GLOBAL_INTERRUPT_LowPriority_ENABLE();
        TIMER3_INTERRUPT_LOW_PRIORITY();
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
    /* Enable Timer 3 Module */
    TIMER3_ENABLE();
}

void timer3_read_value(const _timer3_t *timer3_obj, uint16 *value)
{
    uint8 l_timer3H = ZERO, l_timer3L = ZERO;
    switch (timer3_obj->timer3_preloaded_value)
    {
    case TIMER3_READ_8_BIT:
        l_timer3L = TMR3L;
        l_timer3H = TMR3H;
        *value = (uint16)((l_timer3H << 8) + l_timer3L);
        break;
    case TIMER3_READ_16_BIT:
        *value = TMR3;
        break;
    default:
        *value = TMR3;
        break;
    }
}

void timer3_write_value(const _timer3_t *timer3_obj, uint16 value)
{
    switch (timer3_obj->timer3_read_mode)
    {
    case TIMER3_READ_8_BIT:
        TIMER3_WRITE_TIMER_HIGH(value);
        TIMER3_WRITE_TIMER_LOW(value);
        break;
    case TIMER3_READ_16_BIT:
        TMR3 = value;
        break;
    default:
        TMR3 = value;
        break;
    }
}
/* ____________________________ Function Definination Section Ending _______________________________ */

/* __________________________ Helper Function Definination Section Beginning ______________________ */

/**
 * @brief Helper Function to Select Timer3 Mode 
*/
static void timer3_select_mode(const _timer3_t *timer3_mode)
{
    switch (timer3_mode->timer3_mode)
    {
    case TIMER3_TIMER_MODE:
        TIMER3_TIMER_MODE_ENABLE();
        break;
    case TIMER3_COUNTER_MODE:
        TIMER3_COUNTER_MODE_ENABLE();
        switch (timer3_mode->timer3_sync)
        {
        case TIMER3_ASYNC:
            TIMER3_EXTERNEL_CLOCK_ASYNC();
            break;
        case TIMER3_SYNC:
            break;
            TIMER3_EXTERNEL_CLOCK_SYNC();
        default:
            TIMER3_EXTERNEL_CLOCK_ASYNC();
            break;
        }
        break;
    default:
        TIMER3_TIMER_MODE_ENABLE();
        break;
    }
}

/**
 * @brief Helper Function to Select Read Pin Mode  
*/
static void timer3_select_readPin(const _timer3_t *timer3_readPin)
{
    switch (timer3_readPin->timer3_read_mode)
    {
    case TIMER3_READ_8_BIT:
        TIMER3_READ_BIT_8_BIT_MODE();
        break;
    case TIMER3_READ_16_BIT:
        TIMER3_READ_BIT_16_BIT_MODE();
        break;
    default:
        TIMER3_READ_BIT_16_BIT_MODE();
        break;
    }
}

/**
 * @brief Helper Function to Enable or Disable Oscillator of Timer1 
*/
static void timer3_Oscillator_EN(const _timer3_t *timer1_osc)
{
    switch (timer1_osc->timer1_ocsi_en)
    {
    case TIMER1_OCSILALTOR_DEN:
        TIMER1_OSCILLATOR_DISABLE();
        break;
    case TIMER1_OCSILALTOR_EN:
        TIMER1_OSCILLATOR_ENABLE();
        break;
    default:
        TIMER1_OSCILLATOR_DISABLE();
        break;
    }
}

/* __________________________ Helper Function Definination Section Ending ______________________ */


/**
 * ******************************************************************************************************
 * *      User                   Date                                 Brief
 * ******************************************************************************************************
 * *     Muhammed Ali         10 September,2023                       Writting MCAL_timer3.c
 */