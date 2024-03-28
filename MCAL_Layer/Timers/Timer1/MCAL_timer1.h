/**
 * *****************************************************************************************************
 * * File           : MCAL_timer1.h
 * * Auther         : Muhammed Ali Ibrahim Ahmed
 * * Details        : Timer 1 Module
 * * Linkedin       : https://www.linkedin.com/in/muhammedalii9/
 * * Date Created   : 9 September,2023
 * *****************************************************************************************************
 */
#ifndef MCAL_TIMER1_H
#define MCAL_TIMER1_H

/* __________________________  Include Section Beginning  __________________________________ */
#include "../../GPIO_Layer/Hal_GPIO.h"
#include "../../Interrupt/MCAL_internal_interrupt.h"
#include "C:/Program Files/Microchip/xc8/v2.30/pic/include/proc/pic18f4620.h"
/* __________________________  Include Section Ending  _____________________________________ */

/* ___________________________ Macro Declarations Section Beginning ________________________ */

/* ____ Select Timer1 Mode ____ */

#define TIMER1_TIMER_MODE           1
#define TIMER1_COUNTER_MODE         0

/* ____ Select Timer1 Syncronization ____ */

#define TIMER1_SYNC         1
#define TIMER1_ASYNC        0

/* ____ Oscillator Use ____*/

#define TIMER1_OCSILALTOR_EN    1
#define TIMER1_OCSILALTOR_DEN   0

/* ____ Register Mode Read ____*/

#define TIMER1_READ_16_BIT      1
#define TIMER1_READ_8_BIT       0
/* ___________________________ Macro Declarations Section Ending ___________________________ */

/* ___________________________ Macro Funcion Section Beginning ____________________________ */

/* Enable Timer 1 Module*/
#define TIMER1_ENABLE()                 (T1CONbits.TMR1ON = 1)
/* Disable Timer 1 Module*/
#define TIMER1_DISABLE()                (T1CONbits.TMR1ON = 0)
/* Enable Timer Mode in Timer 1 Module */
#define TIMER1_TIMER_MODE_ENABLE()      (T1CONbits.TMR1CS = 0)
/* Enable Counter Mode in Timer 1 Module */
#define TIMER1_COUNTER_MODE_ENABLE()    (T1CONbits.TMR1CS = 1)
/* Enable Syncronization of Externel Clock @note When TMR1CS is Enable  */
#define TIMER1_EXTERNEL_CLOCK_SYNC()    (T1CONbits.T1SYNC = 0)
/* Enable ASyncronization of Externel Clock @note When TMR1CS is Enable  */
#define TIMER1_EXTERNEL_CLOCK_ASYNC()   (T1CONbits.T1SYNC = 1)
/* Timer 1 Oscillator Enable */
#define TIMER1_OSCILLATOR_ENABLE()      (T1CONbits.T1OSCEN = 1)
/* Timer 1 Oscillator Enable */
#define TIMER1_OSCILLATOR_DISABLE()     (T1CONbits.T1OSCEN = 0)
/* Timer 1 Read Register in one 16-bit operation*/
#define TIMER1_READ_BIT_16_BIT_MODE()   (T1CONbits.RD16 = 1)
/* Timer 1 Read Register in one 16-bit operation*/
#define TIMER1_READ_BIT_8_BIT_MODE()    (T1CONbits.RD16 = 0)

/**
 * @brief Macro Function to Return Status of System Clock Source
 * @note 1 = Device clock is derived from Timer1 oscillator
 * @note 0 = Device clock is derived from another source
 */
#define TIMER1_SYSTEM_CLOCK_STATUS() (T1CONbits.T1RUN)
/**
 * @brief  Function to Select Input Clock Prescaler
 * @note 11 = 1:8 Prescale value
 * @note 10 = 1:4 Prescale value
 * @note 01 = 1:2 Prescale value
 * @note 00 = 1:1 Prescale value
 */
#define TIMER1_PRESCALER_VALUE(_VALUE) (T1CONbits.T1CKPS = _VALUE)

/**
 * @brief Write Value on TMR1H  Register
 * @param _TIMER_HIGH > Value that Will be Written in TMR1H
 */
#define TIMER1_WRITE_TIMER_HIGH(_TIMER_HIGH) (TMR1H = (_TIMER_HIGH >> 8))
/**
 * @brief Write Value on TMR1L  Register
 * @param _TIMER_LOW > Value that Will be Written in TMR1L
 */
#define TIMER1_WRITE_TIMER_LOW(_TIMER_LOW) (TMR1L = ((uint8)_TIMER_LOW))
/**
 * @brief Write Value on TMR1  Register
 * @param _TIMER > Value that Will be Written in TMR1
 */
#define TIMER1_WRITE_TIMER(_TIMER) (TMR1 = _TIMER)
/* ___________________________ Macro Funcion Section Ending _______________________________ */

/* ____________________________ Data Type Declarations Section Beginning ____________________ */

typedef enum
{
    TIMER1_PRESCALER_VAL_1 = 0,
    TIMER1_PRESCALER_VAL_2,
    TIMER1_PRESCALER_VAL_4,
    TIMER1_PRESCALER_VAL_8,
} _timer1_prescaler_val_t;

typedef struct
{
#if TIMER1_INTERRUPT == INTERNEL_INTERRUPT_ENABLE
    void (*Timer1_InterruptHandler)(void);   /* Call Back Function */
    _interrupt_priority_cfg timer1_priority; /* @ref _interrupt_priority_cfg */
#endif
    _timer1_prescaler_val_t timer1_prescaler_value; /* @ref _timer1_prescaler_val_t */
    uint16 timer1_predloaded_val;                   /* Preloaded Value */
    uint8 timer1_mode : 1;                          /* Selected Mode */
    uint8 timer1_syc : 1;                           /* Select Syncronous or Asuncronous */
    uint8 timer1_ocillator : 1;                     /* Enabe/ Disable Oscillartor */
    uint8 timer1_read_pin : 1;                      /* Mode of Register Read Pin 16-bit / 8-bit */
    uint8 timer1_Reserved : 4;                      /* For Future Use */

} _timer1_t;
/* ____________________________ Data Type Declarations Section Ending _______________________ */

/* ____________________________ Function Definination Section Beginning ____________________________ */

/**
 * @brief Initialize Timer 1 Module
 * @param timer1_obj > Pointer to Timer 1 Configration
 * @return Void
 */
void timer1_initialize(const _timer1_t *timer1_obj);
/**
 * @brief Initialize Timer 1 Module
 * @param value > Pointer to Value that Read from Timer 1 Module
 * @param timer1_obj > Pointer to Timer 1 Configration
 * @return Void
 */
void timer1_read_value(const _timer1_t *timer1_reg, uint16 *value);
/**
 * @brief Initialize Timer 1 Module
 * @param timer1_obj > Pointer to Timer 1 Configration
 * @param value > Value that Written in Timer 1 Module
 * @return Void
 */
void timer1_write_value(const _timer1_t *timer1_reg, uint16 value);

/* ____________________________ Function DefininationSection Ending _______________________________ */

#endif /* MCAL_TIMER1_H */

/**
 * ******************************************************************************************************
 * *      User                   Date                                 Brief
 * ******************************************************************************************************
 * *     Muhammed Ali         9 September,2023                       Writting MCAL_timer1.h
 */