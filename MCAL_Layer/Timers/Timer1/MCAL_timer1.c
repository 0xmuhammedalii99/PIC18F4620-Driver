/**
 * *****************************************************************************************************
 * * File           : MCAL_timer1.c
 * * Auther         : Muhammed Ali Ibrahim Ahmed
 * * Details        : Timer 0 Module
 * * Linkedin       : https://www.linkedin.com/in/muhammedalii9/
 * * Date Created   : 9 September,2023
 * *****************************************************************************************************
 */

/* _____________________________  Include Section Beginning  ________________________________ */
#include "MCAL_timer1.h"
/* _____________________________  Include Section Ending  ___________________________________ */

/* ____________________________   Declarations Section Beginning ____________________ */

#if TIMER1_INTERRUPT == INTERNEL_INTERRUPT_ENABLE
static uint16 timer1_preload;
static void (*Timer1_Interrupt_Handler)(void) = NULL;
void TIMER1_ISR(void)
{
    TIMER1_CLEAR_FLAG();
    TIMER1_WRITE_TIMER_HIGH(timer1_preload);
    TIMER1_WRITE_TIMER_LOW(timer1_preload);
    if (Timer1_Interrupt_Handler)
        Timer1_Interrupt_Handler();
}
#endif
/* ____________________________   Declarations Section Ending ____________________ */

/* _______________________ Helper Function Definination Section Beginning ________________ */

static void timer1_select_mode(const _timer1_t *timer1_mode);
static void timer1_select_osc(const _timer1_t *timer1_osc);
static void timer1_select_readPin(const _timer1_t *timer1_readPin);
/* _______________________ Helper Function Definination Section Ending ________________ */

/* ____________________________ Function Declaration Section Beginning ____________________________ */

void timer1_initialize(const _timer1_t *timer1_obj)
{
    /* Disable Timer 1 Module */
    TIMER1_DISABLE();
    /* Select Timer 1 Mode ' Timer ' or ' Counter '*/
    timer1_select_mode(timer1_obj);
    /* Select Oscillator Configration*/
    timer1_select_osc(timer1_obj);
    /* Read Pin Mode ' 8 Bit ' or ' 16 Bit */
    timer1_select_readPin(timer1_obj);
    /* Prescaler Value */
    TIMER1_PRESCALER_VALUE(timer1_obj->timer1_prescaler_value);
    /* Writting Value in Timer 1 Register */
    TIMER1_WRITE_TIMER_HIGH(timer1_obj->timer1_predloaded_val);
    TIMER1_WRITE_TIMER_LOW(timer1_obj->timer1_predloaded_val);
    /* __________ Interrupt Configration __________*/
#if TIMER1_INTERRUPT == INTERNEL_INTERRUPT_ENABLE
    timer1_preload = timer1_obj->timer1_predloaded_val;
    TIMER1_INTERRUPT_FEATURE_ENABLE();
    TIMER1_CLEAR_FLAG();
    Timer1_Interrupt_Handler = timer1_obj->Timer1_InterruptHandler;
#if INTERRUPT_PRIORITY_LEVEL == PRIORITY_LEVELS_ENABLE
    if (timer1_obj->priority == INTERRUPT_HIGH_PRIORITY)
    {
        INTERRUPT_PRIORITY_ENABLE();
        INTERRUPT_GLOBAL_INTERRUPT_LowPriority_ENABLE();
        TIMER1_INTERRUPT_HIGH_PRIORITY();
    }
    else if (timer1_obj->priority == INTERRUPT_LOW_PRIORITY)
    {
        INTERRUPT_PRIORITY_ENABLE();
        INTERRUPT_GLOBAL_INTERRUPT_LowPriority_ENABLE();
        TIMER1_INTERRUPT_LOW_PRIORITY();
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
    /* Enable Timer 1 Module */
    TIMER1_ENABLE();
}

void timer1_read_value(const _timer1_t *timer1_reg, uint16 *value)
{
    uint8 l_timer1H = ZERO, l_timer1L = ZERO;
    switch (timer1_reg->timer1_read_pin)
    {
    case TIMER1_READ_8_BIT:
        l_timer1L = TMR1L;
        l_timer1H = TMR1H;
        *value = (uint16)((l_timer1H << 8) + l_timer1L);
        break;
    case TIMER1_READ_16_BIT:
        *value = TMR1;
        break;
    default:
        *value = TMR1;
        break;
    }
}

void timer1_write_value(const _timer1_t *timer1_reg, uint16 value)
{
    switch (timer1_reg->timer1_read_pin)
    {
    case TIMER1_READ_8_BIT:
        TIMER1_WRITE_TIMER_HIGH(value);
        TIMER1_WRITE_TIMER_LOW(value);
        break;
    case TIMER1_READ_16_BIT:
        TMR1 = value;
        break;
    default:
        TMR1 = value;
        break;
    }
}
/* ____________________________ Function Declaration Section Ending _______________________________ */

/* __________________________ Helper Function Declaration Section Beginning ______________________ */


/**
 * @brief Helper Function to Select Timer Mode 
*/
static void timer1_select_mode(const _timer1_t *timer1_mode)
{
    switch (timer1_mode->timer1_mode)
    {

    case TIMER1_COUNTER_MODE:
        TIMER1_COUNTER_MODE_ENABLE();
        switch (timer1_mode->timer1_syc)
        {
        case TIMER1_ASYNC:
            TIMER1_EXTERNEL_CLOCK_ASYNC();
            break;
        case TIMER1_SYNC:
            TIMER1_EXTERNEL_CLOCK_SYNC();
            break;
        default:
            TIMER1_EXTERNEL_CLOCK_ASYNC();
            break;
        }
        break;
    case TIMER1_TIMER_MODE:
        TIMER1_TIMER_MODE_ENABLE();
        break;
    default:
        /* Nothing */
        break;
    }
}

/**
 * @brief Helper Function to Select Timer Oscillator 
*/
static void timer1_select_osc(const _timer1_t *timer1_osc)
{
    switch (timer1_osc->timer1_ocillator)
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

/**
 * @brief Helper Function to Select Register Read Pin Mode 
*/
static void timer1_select_readPin(const _timer1_t *timer1_readPin)
{
    switch (timer1_readPin->timer1_read_pin)
    {
    case TIMER1_READ_8_BIT:
        TIMER1_READ_BIT_8_BIT_MODE();
        break;
    case TIMER1_READ_16_BIT:
        TIMER1_READ_BIT_16_BIT_MODE();
        break;
    default:
        TIMER1_READ_BIT_16_BIT_MODE();
        break;
    }
}
/* __________________________ Helper Function Declaration Section Ending _________________________ */


/**
 * ******************************************************************************************************
 * *      User                   Date                                 Brief
 * ******************************************************************************************************
 * *     Muhammed Ali         9 September,2023                       Writting MCAL_timer1.c
 */