/**
 * *****************************************************************************************************
 * * File           : MCAL_timer2.h
 * * Auther         : Muhammed Ali Ibrahim Ahmed
 * * Details        : Timer 2 Module
 * * Linkedin       : https://www.linkedin.com/in/muhammedalii9/
 * * Date Created   : 9 September,2023
 * *****************************************************************************************************
 */

#ifndef MCAL_TIMER2_H
#define MCAL_TIMER2_H

/* __________________________  Include Section Beginning  __________________________________ */
#include "../../GPIO_Layer/Hal_GPIO.h"
#include "../../Interrupt/MCAL_internal_interrupt.h"
#include "C:/Program Files/Microchip/xc8/v2.30/pic/include/proc/pic18f4620.h"
/* __________________________  Include Section Ending  _____________________________________ */

/* ___________________________ Macro Declarations Section Beginning ________________________ */
/* ___________________________ Macro Declarations Section Ending ___________________________ */

/* ___________________________ Macro Funcion Section Beginning ____________________________ */

/* Enable Timer 2 Module */
#define TIMER2_ENABLE() (T2CONbits.TMR2ON = 1)
/* Disable Timer 2 Module */
#define TIMER2_DISABLE() (T2CONbits.TMR2ON = 0)
/**
 * @brief  Function to Select Input Clock Prescaler
 * @note 00 = Prescaler is 1
 * @note 01 = Prescaler is 4
 * @note 1X = Prescaler is 16
 */
#define TIMER2_PRESCALER_VALUE(_VALUE) (T2CONbits.T2CKPS = _VALUE)
/**
 * @brief  Function to Select Input Clock Prescaler
 * @note 0000 = 1:1 Postscal
 * @note 0001 = 1:2 Postscale
 * @note . . . .
 * @note 1111 = 1:16 Postscale
 */
#define TIMER2_POSTCALER_VALUE(_VALUE) (T2CONbits.TOUTPS = _VALUE)

/**
 * @brief Macro Function to Write Value on TMR2 Register
 * @param _VALUE > Value that will be written on TMR2 Register
*/
#define TIMER2_WRITE_REGISTER(_VALUE)   (TMR2 = _VALUE)

/* ___________________________ Macro Funcion Section Ending _______________________________ */

/* ____________________________ Data Type Declarations Section Beginning ____________________ */

typedef enum
{
    TIMER2_PRESCALER_VAL_1 = 0,
    TIMER2_PRESCALER_VAL_4,
    TIMER2_PRESCALER_VAL_16,

} _timer2_prescaler_val_t;

typedef enum
{
    TIMER2_POSTSCALER_VAL_1 = 0,
    TIMER2_POSTSCALER_VAL_2,
    TIMER2_POSTSCALER_VAL_3,
    TIMER2_POSTSCALER_VAL_4,
    TIMER2_POSTSCALER_VAL_5,
    TIMER2_POSTSCALER_VAL_6,
    TIMER2_POSTSCALER_VAL_7,
    TIMER2_POSTSCALER_VAL_8,
    TIMER2_POSTSCALER_VAL_9,
    TIMER2_POSTSCALER_VAL_10,
    TIMER2_POSTSCALER_VAL_11,
    TIMER2_POSTSCALER_VAL_12,
    TIMER2_POSTSCALER_VAL_13,
    TIMER2_POSTSCALER_VAL_14,
    TIMER2_POSTSCALER_VAL_15,
    TIMER2_POSTSCALER_VAL_16,

} _timer2_postscaler_val_t;

typedef struct
{
#if TIMER2_INTERRUPT == INTERNEL_INTERRUPT_ENABLE
    void (*Timer2_InterruptHandler)(void);          /* Call Back Function*/
    _interrupt_priority_cfg timer2_priority;        /* @ref _interrupt_priority_cfg */
#endif
    _timer2_prescaler_val_t timer2_prescale_val;    /* @ref _interrupt_priority_cfg */
    _timer2_postscaler_val_t timer2_postscale_val; /* @ref _interrupt_priority_cfg */
    uint8 timer2_preloaded_value;

} _timer2_t;

/* ____________________________ Data Type Declarations Section Ending _______________________ */

/* ____________________________ Function Definination Section Beginning ____________________________ */

/**
 * @brief Initialize Timer 2 Module
 * @param timer2_obj > Pointer to Timer 2 Configration
 * @return Void
 */
void timer2_initialzie(const _timer2_t *timer2_obj);

/**
 * @brief Initialize Timer 2 Module
 * @param value > Pointer to Value that will Written on Timer 2 Register
 * @return Void
 */
void timer2_write_value (uint8 value);

/**
 * @brief Initialize Timer 2 Module
 * @param value > Value that will Read From Timer 2 Register
 * @return Void
 */
void timer2_read_value (uint8 *value);
/* ____________________________ Function DefininationSection Ending _______________________________ */

#endif /* MCAL_TIMER2_H */


/**
 * ******************************************************************************************************
 * *      User                   Date                                 Brief
 * ******************************************************************************************************
 * *     Muhammed Ali         9 September,2023                       Writting MCAL_timer2.h
 */