/**
 * *****************************************************************************************************
 * * File           : MCAL_ccp1.h
 * * Auther         : Muhammed Ali Ibrahim Ahmed
 * * Details        : ccp1  Module
 * * Linkedin       : https://www.linkedin.com/in/muhammedalii9/
 * * Date Created   : 12 September,2023
 * *****************************************************************************************************
 */

#ifndef MCAL_CCP2_H
#define	MCAL_CCP2_H

/* __________________________  Include Section Beginning  __________________________________ */
#include "../../MCAL_Layer/GPIO_Layer/Hal_GPIO.h"
#include "../../MCAL_Layer/Interrupt/MCAL_internal_interrupt.h"
#include "C:/Program Files/Microchip/xc8/v2.30/pic/include/proc/pic18f4620.h"
/* __________________________  Include Section Ending  _____________________________________ */
/* ___________________________ Macro Declarations Section Beginning ________________________ */

/* Disable CCP2 Module */
#define CCP2_MODE_DISABLE                       ((uint8)0x00)

/* __________ Capture Mode Options __________ */

#define CCP2_CAPTURE_MODE_1_FALLING_EDGE        ((uint8)0x04)
#define CCP2_CAPTURE_MODE_1_RISING_EDGE         ((uint8)0x05)
#define CCP2_CAPTURE_MODE_4_RISING_EDGE         ((uint8)0x06)
#define CCP2_CAPTURE_MODE_16_RISING_EDGE        ((uint8)0x07)

/* __________ Compare Mode Options __________ */

#define CCP2_COMPARE_TOGGLE_ON_MATCH            ((uint8)0x02)
#define CCP2_COMPARE_MODE_SET_PIN_LOW           ((uint8)0x08)
#define CCP2_COMPARE_MODE_SET_PIN_HIGH          ((uint8)0x09)
#define CCP2_COMPARE_MODE_GEN_SW_INTERRUPT      ((uint8)0x0A)
#define CCP2_COMPARE_MODE_GEN_EVENT             ((uint8)0x0B)

/* PWM Mode Selec*/
#define CCP2_PWM_MODE                           ((uint8)0x0F)

/* ______ Select Mode ______ */

#define CCP2_COMPARE_MODE       0
#define CCP2_CAPTURE_MODE       1
#define CCP2_PWM_MODE_SELECT    2

/* CCP2 Compare Mode State Not Ready  */
#define CCP2_COMPARE_NOT_READY      0X00
/* CCP2 Compare Mode State Ready  */
#define CCP2_COMPARE_READY          0X01
/* CCP2 Capture Mode State Not Ready  */
#define CCP2_CAPTURE_NOT_READY      0X00
/* CCP2 Capture Mode State Ready  */
#define CCP2_CAPTURE_READY          0X01

/* Enable ( Capture/Compare ) Mode*/
#define CCP2_CAPTURE_COMPARE_ENABLE     1
/* Disable ( Capture/Compare ) Mode*/
#define CCP2_CAPTURE_COMPARE_DISABLE    0

/* ________ Timer 2 Postscaler Value  ________*/

#define CCP2_TIMER2_POSTSCALER_DIV_BY_1      1
#define CCP2_TIMER2_POSTSCALER_DIV_BY_2      2
#define CCP2_TIMER2_POSTSCALER_DIV_BY_3      3
#define CCP2_TIMER2_POSTSCALER_DIV_BY_4      4
#define CCP2_TIMER2_POSTSCALER_DIV_BY_5      5
#define CCP2_TIMER2_POSTSCALER_DIV_BY_6      6
#define CCP2_TIMER2_POSTSCALER_DIV_BY_7      7
#define CCP2_TIMER2_POSTSCALER_DIV_BY_8      8
#define CCP2_TIMER2_POSTSCALER_DIV_BY_9      9
#define CCP2_TIMER2_POSTSCALER_DIV_BY_10     10
#define CCP2_TIMER2_POSTSCALER_DIV_BY_11     11
#define CCP2_TIMER2_POSTSCALER_DIV_BY_12     12
#define CCP2_TIMER2_POSTSCALER_DIV_BY_13     13
#define CCP2_TIMER2_POSTSCALER_DIV_BY_14     14
#define CCP2_TIMER2_POSTSCALER_DIV_BY_15     15
#define CCP2_TIMER2_POSTSCALER_DIV_BY_16     16

/* ________ Timer 2 Prescaler Value  ________*/

#define CCP2_TIMER2_PRESCALER_DIV_BY_1       1
#define CCP2_TIMER2_PRESCALER_DIV_BY_4       4
#define CCP2_TIMER2_PRESCALER_DIV_BY_16      16

/* __________ Set Mode Configrations __________ */

#define CCP2_CAPTURE_COMPARE_STATE      CCP2_CAPTURE_COMPARE_ENABLE
#define CCP2_MODE_SELECT                CCP2_CAPTURE_MODE
/* ___________________________ Macro Declarations Section Ending ________________________ */
/* ___________________________ Macro Funcion Section Beginning ____________________________ */

#define CCP2_SET_MODE(_CONFIG) (CCP2CONbits.CCP2M = _CONFIG)
/* ___________________________ Macro Funcion Section Ending ____________________________ */

typedef union
{
    struct
    {
        uint8 ccpr2_low;  // CCPR2l : Low Register
        uint8 ccpr2_high; // CCPR2l : High Register
    };
    struct
    {
        uint16 ccpr2_16Bit; // Read CCPR2 as a 16-Bit Value
    };
} _ccp2_reg_t;

typedef enum
{
    CCP2_SELECT_CCP1_CCP2_TIMER1 = 0,    // Timer1 is the clock source for the CCP modules
    CCP2_SELECT_CCP1_TIMER1_CCP2_TIMER3, // Timer1 is the CS for the CCP1 modules, Timer3 is the CS for the CCP2 modules
    CCP2_SELECT_CCP1_CCP2_TIMER3,        // Timer3 is the clock source for the CCP modules
} _ccp2_mode_timer_resourse_t;

typedef struct
{

#if CCP2_INTERRUPT == INTERNEL_INTERRUPT_ENABLE
    void (*ccp2_InterruptHandler)(void);  // Interrupt Halnder Function
    _interrupt_priority_cfg ccp2_prioriy; // Priority Configration
#endif
    uint8 main_mode_select; // Selection Mode
#if CCP2_CAPTURE_COMPARE_STATE == CCP2_CAPTURE_COMPARE_ENABLE
    _ccp2_mode_timer_resourse_t ccp2_timer_resourse; //@ref to _ccp2_mode_timer_resourse_t
#endif
    _pin_config_t ccp2_pin_config; //@ref to _pin_config_t
#if CCP2_MODE_SELECT == CCP2_PWM_MODE_SELECT
    uint32 pwm_frequency;        // Frequency of PWM
    uint8 timer2_prescaler_val;  // Prescaler Value of Timer 2
    uint8 timer2_postscaler_val; // Postscaler Value of Timer 2
#endif

} _ccp2_t;
/* ____________________________ Data Type Declarations Section Ending ____________________ */

/* ____________________________ Function Declarations Section Beginning ____________________________ */

/* _______ PWM Mode Software Interface _______ */
#if CCP2_MODE_SELECT == CCP2_PWM_MODE_SELECT
void ccp2_pwm_mode_init(const _ccp2_t *pwm_obj);
void ccp2_pwm_set_dutyCycle( uint8 duty_cylce);
void ccp2_pwm_start(const _ccp2_t *pwm_obj);
void ccp2_pwm_stop(const _ccp2_t *pwm_obj);
#endif

#if CCP2_CAPTURE_COMPARE_STATE == CCP2_CAPTURE_COMPARE_ENABLE
/* _______ Compare Mode Software Interface _______ */
#if CCP2_MODE_SELECT == CCP2_COMPARE_MODE
void ccp2_compare_mode_init(const _ccp2_t *compare_obj);
void ccp2_compare_mode_isComplete(uint8 *compare_status);
void ccp2_compare_mode_set_value(uint16 compare_value);
#endif

/* _______ Capture Mode Software Interface _______ */
#if CCP2_MODE_SELECT == CCP2_CAPTURE_MODE
void ccp2_capture_mode_init(const _ccp2_t *capture_obj);
void ccp2_capture_mode_isReady(uint8 *capture_state);
void ccp2_capture_mode_read_value(uint16 *capture_value);
#endif
#endif

/* ____________________________ Function Declarations Section Ending ____________________________ */

#endif	/* MCAL_CCP2_H */

