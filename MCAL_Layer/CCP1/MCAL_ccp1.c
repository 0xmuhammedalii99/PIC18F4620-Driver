/**
 * *****************************************************************************************************
 * * File           : MCAL_ccp1.c
 * * Auther         : Muhammed Ali Ibrahim Ahmed
 * * Details        : CCP1 Module
 * * Linkedin       : https://www.linkedin.com/in/muhammedalii9/
 * * Date Created   : 12 September,2023
 * *****************************************************************************************************
 */

/* _____________________________  Include Section Beginning  ________________________________ */
#include "MCAL_ccp1.h"
/* _____________________________  Include Section Ending  ___________________________________ */

/* ____________________________ Data Type Declarations Section Beginning ____________________ */

#if CCP1_INTERRUPT == INTERNEL_INTERRUPT_ENABLE
static void ccp1_interrupt_init(const _ccp1_t *ccp1_interrupt);
void (*ccp1_Interrupr_Handler)(void) = NULL;
void CCP1_ISR(void)
{
    /* Clear Flag */
    CCP1_CLEAR_FLAG();
    if (ccp1_Interrupr_Handler)
    {
        ccp1_Interrupr_Handler();
    }
}
#endif
/* ____________________________ Data Type Declarations Section Ending ____________________ */

/* _______________________ Helper Function Definination Section Beginning ________________ */

#if CCP1_MODE_SELECT == CCP1_PWM_MODE_SELECT
static void pwm_set_frequency(const _ccp1_t *pwm_freq);
#endif
#if CCP1_CAPTURE_COMPARE_STATE == CCP1_CAPTURE_COMPARE_ENABLE
static void timer_resource_select(const _ccp1_t *ccp1_timer_res);
#if CCP1_MODE_SELECT == CCP1_COMPARE_MODE
static void select_compare_mode(const _ccp1_t *compare_mode);
#endif
#if CCP1_MODE_SELECT == CCP1_CAPTURE_MODE
static void select_capture_mode(const _ccp1_t *capture_mode);
#endif

#endif
/* _______________________ Helper Function Definination Section Ending ________________ */

/* ____________________________ Function Definination Section Beginning ____________________________ */

/* _______ PWM Mode Configrations _______ */
#if CCP1_MODE_SELECT == CCP1_PWM_MODE_SELECT
void ccp1_pwm_mode_init(const _ccp1_t *pwm_obj)
{
    /* Diable Module */
    CCP1_SET_MODE(CCP1_MODE_DISABLE);
    /* Select Mode Assign Bit */
    CCP1_SET_MODE(pwm_obj->main_mode_select);
    /* Initialzie Pin */
    gpio_pin_initialize_direction(&(pwm_obj->ccp1_pin_config));
    /* Initialzie Frequency In PR2 Register*/
    pwm_set_frequency(pwm_obj);
/* Initialize Interrupt */
#if CCP1_INTERRUPT == INTERNEL_INTERRUPT_ENABLE
    ccp1_interrupt_init(pwm_obj);
#endif
}

void ccp1_pwm_set_dutyCycle( uint8 duty_cylce)
{
    uint16 l_duty_cycle = ZERO; // Store the Operation of Calculate the Duty Cycle
    /* Operation */
    l_duty_cycle = (uint16)((float)4 * ((float)PR2 + 1.0) * ((float)duty_cylce / 100.0));
    /* Store The LSB in CCP1CON Register */
    CCP1CONbits.DC1B = (uint8)(l_duty_cycle & 0x0003);
    /* Store the MSP in CCPR1L Register */
    CCPR1L = (uint8)(l_duty_cycle >> 2);
}

void ccp1_pwm_start(const _ccp1_t *pwm_obj)
{
    CCP1_SET_MODE(pwm_obj->main_mode_select);
}

void ccp1_pwm_stop(const _ccp1_t *pwm_obj)
{
    CCP1_SET_MODE(CCP1_MODE_DISABLE);
}
#endif

#if CCP1_MODE_SELECT == CCP1_COMPARE_MODE
void ccp1_compare_mode_init(const _ccp1_t *compare_obj)
{
    /* Disable Module */
    CCP1_SET_MODE(CCP1_MODE_DISABLE);
    /* Initialzie Timer Resourse */
    timer_resource_select(compare_obj);
    /* Initialzie Compare Mode Select*/
    select_compare_mode(compare_obj);
    /* Initialize Pin Configration */
    gpio_pin_initialize_direction(&(compare_obj->ccp1_pin_config));
    /* Initialize Interrupt */
#if CCP1_INTERRUPT == INTERNEL_INTERRUPT_ENABLE
    ccp1_interrupt_init(compare_obj);
#endif
}

void ccp1_compare_mode_isComplete(uint8 *compare_status)
{
    if (CCP1_COMPARE_READY == PIR1bits.CCP1IF)
    {
        *compare_status = CCP1_COMPARE_READY;
        CCP1_CLEAR_FLAG();
    }
    else if (CCP1_COMPARE_NOT_READY == PIR1bits.CCP1IF)
    {
        *compare_status = CCP1_COMPARE_NOT_READY;
    }
    else
    {
        /* Nothing */
    }
}

void ccp1_compare_mode_set_value(uint16 compare_value)
{
    /* Variable from type @ref _ccp1_reg_t to store compare value*/
    _ccp1_reg_t compare_val_temp = {.ccpr1_16Bit = 0};
    compare_val_temp.ccpr1_16Bit = compare_value; // Store uint16 compare value
    CCPR1L = compare_val_temp.ccpr1_low;          // Store LSB in CCPR1L
    CCPR1H = compare_val_temp.ccpr1_high;         // Store MSB in CCPR1L
}
#endif

#if CCP1_MODE_SELECT == CCP1_CAPTURE_MODE
void ccp1_capture_mode_init(const _ccp1_t *capture_obj)
{
    /* Disable Module */
    CCP1_SET_MODE(CCP1_MODE_DISABLE);
    /* Initialzie Timer Resourse */
    timer_resource_select(capture_obj);
    /* Initialzie Capture Mode Select*/
    select_capture_mode(capture_obj);
    /* Initialize Pin Configration */
    gpio_pin_initialize_direction(&(capture_obj->ccp1_pin_config));
    /* Initialize Interrupt */
#if CCP1_INTERRUPT == INTERNEL_INTERRUPT_ENABLE
    ccp1_interrupt_init(capture_obj);
#endif
}
void ccp1_capture_mode_isReady(uint8 *capture_state)
{
    if (CCP1_CAPTURE_READY == PIR1bits.CCP1IF)
    {
        *capture_state = CCP1_CAPTURE_READY;
        CCP1_CLEAR_FLAG();
    }
    else if (CCP1_CAPTURE_NOT_READY == PIR1bits.CCP1IF)
    {
        *capture_state = CCP1_CAPTURE_READY;
    }
}

void ccp1_capture_mode_read_value(uint16 *capture_value)
{ /* Variable from type @ref _ccp1_reg_t to store compare value*/
    _ccp1_reg_t capture_value_temp = {.ccpr1_16Bit = 0};
    capture_value_temp.ccpr1_low = CCPR1L;           // Store The LSB in capture_value_temp
    capture_value_temp.ccpr1_high = CCPR1H;          // Store The MSB in capture_value_temp
    *capture_value = capture_value_temp.ccpr1_16Bit; // Store the uint16 value  in capture_value
}

#endif

/* ____________________________ Function Definination Section Ending ____________________________ */

/* __________________________ Helper Function Definination Section Beginning ______________________ */

#if CCP1_MODE_SELECT == CCP1_PWM_MODE_SELECT
static void pwm_set_frequency(const _ccp1_t *pwm_freq)
{
    PR2 = (uint8)(((float)_XTAL_FREQ / ((float)pwm_freq->pwm_frequency * 4.0 * (float)pwm_freq->timer2_prescaler_val * (float)pwm_freq->timer2_postscaler_val)) - 1);
}
#endif

#if CCP1_MODE_SELECT == CCP1_COMPARE_MODE
static void select_compare_mode(const _ccp1_t *compare_mode)
{
    switch (compare_mode->main_mode_select)
    {
    case CCP1_COMPARE_TOGGLE_ON_MATCH:
        CCP1_SET_MODE(CCP1_COMPARE_TOGGLE_ON_MATCH);
        break;
    case CCP1_COMPARE_MODE_SET_PIN_LOW:
        CCP1_SET_MODE(CCP1_COMPARE_MODE_SET_PIN_LOW);
        break;
    case CCP1_COMPARE_MODE_SET_PIN_HIGH:
        CCP1_SET_MODE(CCP1_COMPARE_MODE_SET_PIN_HIGH);
        break;
    case CCP1_COMPARE_MODE_GEN_SW_INTERRUPT:
        CCP1_SET_MODE(CCP1_COMPARE_MODE_GEN_SW_INTERRUPT);
        break;
    case CCP1_COMPARE_MODE_GEN_EVENT:
        CCP1_SET_MODE(CCP1_COMPARE_MODE_GEN_EVENT);
        break;
    }
}
#endif

#if CCP1_CAPTURE_COMPARE_STATE == CCP1_CAPTURE_COMPARE_ENABLE
static void timer_resource_select(const _ccp1_t *ccp1_timer_res)
{
    switch (ccp1_timer_res->ccp1_timer_resourse)
    {
    case CCP1_SELECT_CCP1_CCP2_TIMER1:
        /* Timer1 is the capture/compare clock source for the CCP modules */
        T3CONbits.T3CCP1 = 0;
        T3CONbits.T3CCP2 = 0;
        break;
    case  CCP1_SELECT_CCP1_TIMER1_CCP2_TIMER3:
        /* Timer1 is the capture/compare clock source for CCP1 */
        /* Timer3 is the capture/compare clock source for CCP2; */
        T3CONbits.T3CCP1 = 1;
        T3CONbits.T3CCP2 = 0;
        break;
    case  CCP1_SELECT_CCP1_CCP2_TIMER3:
        /* Timer1 is the capture/compare clock source for the CCP modules */
        T3CONbits.T3CCP1 = 1;
        T3CONbits.T3CCP2 = 1;
        break;
    }
}
#endif

#if CCP1_MODE_SELECT == CCP1_CAPTURE_MODE
static void select_capture_mode(const _ccp1_t *capture_mode)
{
    switch (capture_mode->main_mode_select)
    {
    case CCP1_CAPTURE_MODE_1_FALLING_EDGE:
        CCP1_SET_MODE(CCP1_CAPTURE_MODE_1_FALLING_EDGE);
        break;
    case CCP1_CAPTURE_MODE_1_RISING_EDGE:
        CCP1_SET_MODE(CCP1_CAPTURE_MODE_1_RISING_EDGE);
        break;
    case CCP1_CAPTURE_MODE_4_RISING_EDGE:
        CCP1_SET_MODE(CCP1_CAPTURE_MODE_4_RISING_EDGE);
        break;
    case CCP1_CAPTURE_MODE_16_RISING_EDGE:
        CCP1_SET_MODE(CCP1_CAPTURE_MODE_16_RISING_EDGE);
        break;
    }
}
#endif

#if CCP1_INTERRUPT == INTERNEL_INTERRUPT_ENABLE
static void ccp1_interrupt_init(const _ccp1_t *ccp1_interrupt)
{
    /* Clear Flag */
    CCP1_CLEAR_FLAG();
    /* Enable Interrupt */
    CCP1_INTERRUPT_FEATURE_ENABLE();
    /* Set Adress of ISR Function */
    ccp1_Interrupr_Handler = ccp1_interrupt->ccp1_InterruptHandler;
/* ____ Priority Configration ____ */
#if INTERRUPT_PRIORITY_LEVEL == PRIORITY_LEVELS_ENABLE
    switch (ccp1_interrupt->ccp1_prioriy)
    {
    case INTERRUPT_LOW_PRIORITY:
        INTERRUPT_PRIORITY_ENABLE();
        INTERRUPT_GLOBAL_INTERRUPT_LowPriority_ENABLE();
        CCP1_INTERRUPT_LOW_PRIORITY();
        break;
    case INTERRUPT_HIGH_PRIORITY:
        INTERRUPT_PRIORITY_ENABLE();
        INTERRUPT_GLOBAL_INTERRUPT_LowPriority_ENABLE();
        CCP1_INTERRUPT_HIGH_PRIORITY();
    }
#else
    INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
    INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE();
#endif
}
#endif

/* __________________________ Helper Function Definination Section Ending ________________________ */
