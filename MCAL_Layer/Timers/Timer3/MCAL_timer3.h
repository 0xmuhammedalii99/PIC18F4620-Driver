/**
 * *****************************************************************************************************
 * * File           : MCAL_timer3.h
 * * Auther         : Muhammed Ali Ibrahim Ahmed
 * * Details        : Timer 3 Module
 * * Linkedin       : https://www.linkedin.com/in/muhammedalii9/
 * * Date Created   : 10 September,2023
 * *****************************************************************************************************
 */

#ifndef MCAL_TIMER3_H
#define MCAL_TIMER3_H

/* __________________________  Include Section Beginning  __________________________________ */
#include "../../GPIO_Layer/Hal_GPIO.h"
#include "../../Interrupt/MCAL_internal_interrupt.h"
#include "../Timer1/MCAL_timer1.h"
#include "C:/Program Files/Microchip/xc8/v2.30/pic/include/proc/pic18f4620.h"
/* __________________________  Include Section Ending  _____________________________________ */

/* ___________________________ Macro Declarations Section Beginning ________________________ */

/* ____ Select Timer3 Mode ____ */

#define TIMER3_COUNTER_MODE     1
#define TIMER3_TIMER_MODE       0

/* ____ Select Timer3 Syncronization ____ */

#define TIMER3_SYNC     1
#define TIMER3_ASYNC    0

/* ____ Register Mode Read ____*/

#define TIMER3_READ_16_BIT  1
#define TIMER3_READ_8_BIT   0
/* ___________________________ Macro Declarations Section Ending ___________________________ */

/* ___________________________ Macro Funcion Section Beginning ____________________________ */

/* Enable Timer 3 Module */
#define TIMER3_ENABLE()                 (T3CONbits.TMR3ON = 1)
/* Disable Timer 3 Module */
#define TIMER3_DISABLE()                (T3CONbits.TMR3ON = 0)
/* Enable Timer Mode In Timer 3 Module */
#define TIMER3_TIMER_MODE_ENABLE()      (T3CONbits.TMR3CS = 0)
/**
 * Enable Counter Mode In Timer 3 Module
 *  @note External clock input from T13CK (On the rising edge after the first falling edge)
 * @note External clock input from Timer1 oscillator
 */
#define TIMER3_COUNTER_MODE_ENABLE()    (T3CONbits.TMR3CS = 1)
/**
 * Enable Syncronization of Externel Clock For Timer 3 Module in Counter Mode
 * @note Not usable if the device clock comes from Timer1/Timer3
 * @note When TMR3CS = 1
 */
#define TIMER3_EXTERNEL_CLOCK_SYNC()    (T3CONbits.T3SYNC = 0)
/**
 * Enable ASyncronization of Externel Clock For Timer 3 Module in Counter Mode
 * @note Not usable if the device clock comes from Timer1/Timer3
 * @note When TMR3CS = 1
 */
#define TIMER3_EXTERNEL_CLOCK_ASYNC()   (T3CONbits.T3SYNC = 1)
/* Timer 3 Read Register in one 16-bit operation*/
#define TIMER3_READ_BIT_16_BIT_MODE()   (T3CONbits.RD16 = 1)
/* Timer 3 Read Register in one 16-bit operation*/
#define TIMER3_READ_BIT_8_BIT_MODE()    (T3CONbits.RD16 = 0)

/**
 * @brief  Function to Select Input Clock Prescaler
 * @note 11 = 1:8 Prescale value
 * @note 10 = 1:4 Prescale value
 * @note 01 = 1:2 Prescale value
 * @note 00 = 1:1 Prescale value
 */
#define TIMER3_PRESCALER_VALUE(_VALUE) (T3CONbits.T3CKPS = _VALUE)
/**
 * @brief Write Value on TMR3H  Register
 * @param _TIMER_HIGH > Value that Will be Written in TMR3H
 */
#define TIMER3_WRITE_TIMER_HIGH(_TIMER_HIGH) (TMR3H = (_TIMER_HIGH >> 8))
/**
 * @brief Write Value on TMR3L  Register
 * @param _TIMER_LOW > Value that Will be Written in TMR3L
 */
#define TIMER3_WRITE_TIMER_LOW(_TIMER_LOW) (TMR3L = ((uint8)_TIMER_LOW))
/**
 * @brief Write Value on TMR3  Register
 * @param _TIMER > Value that Will be Written in TMR3
 */
#define TIMER3_WRITE_TIMER(_TIMER) (TMR3 = _TIMER)

/* ___________________________ Macro Funcion Section Ending _______________________________ */

/* ____________________________ Data Type Declarations Section Beginning ____________________ */

typedef enum
{
    TIMER3_PRESCALER_VAL_1 = 0,
    TIMER3_PRESCALER_VAL_2,
    TIMER3_PRESCALER_VAL_4,
    TIMER3_PRESCALER_VAL_8,
} _timer3_prescaler_val_t;



typedef struct
{
#if TIMER3_INTERRUPT == INTERNEL_INTERRUPT_ENABLE
    void (*Timer3_InterruptHandler)(void);              /* Call Back Function */
    _interrupt_priority_cfg timer3_priority;            /* @ref _interrupt_priority_cfg */
#endif
    _timer3_prescaler_val_t timer3_prescaler_value;     /* @ref _timer3_prescaler_val_t */
    uint16 timer3_preloaded_value;                      /* Preloaded Value */
    uint8 timer3_mode : 1;                              /* Selected Mode */
    uint8 timer3_sync : 1;                              /* Select Syncronous or Asuncronous */
    uint8 timer3_read_mode : 1;                         /* Mode of Register Read Pin 16-bit / 8-bit */
    uint8 timer1_ocsi_en : 1;                           /* Enabe/ Disable Oscillartor */
    uint8 timer3_Reserved : 4;                          /* For Future Use */
} _timer3_t;
/* ____________________________ Data Type Declarations Section Ending _______________________ */

/* ____________________________ Function Definination Section Beginning ____________________________ */

/**
 * @brief Initialize Timer 3 Module 
 * @param timer3_obj > Pointer to Timer3 Configrations
 * @return Void
*/
void timer3_initialize(const _timer3_t *timer3_obj);

/**
 * @brief Read Value From TMR3 Register 
 * @param timer3_obj > Pointer to Timer3 Configrations
 * @param value > Pointer to Value that will be Read from TMR3 Register
 * @return Void
*/
void timer3_read_value(const _timer3_t *timer3_obj, uint16 *value);

/**
 * @brief Write Value on TMR3 Register 
 * @param timer3_obj > Pointer to Timer3 Configrations
 * @param value > Value that will be written on TMR3 Register
 * @return Void
*/
void timer3_write_value(const _timer3_t *timer3_obj, uint16 value);

/* ____________________________ Function DefininationSection Ending _______________________________ */

#endif /* MCAL_TIMER3_H */


/**
 * ******************************************************************************************************
 * *      User                   Date                                 Brief
 * ******************************************************************************************************
 * *     Muhammed Ali         10 September,2023                       Writting MCAL_timer3.h
 */