/**
 * *****************************************************************************************************
 * * File           : MCAL_timer.c
 * * Auther         : Muhammed Ali Ibrahim Ahmed
 * * Details        : Timer 0 Module
 * * Linkedin       : https://www.linkedin.com/in/muhammedalii9/
 * * Date Created   : 6 September,2023
 * *****************************************************************************************************
 */

#ifndef MCAL_TIMER0_H
#define MCAL_TIMER0_H

/* __________________________  Include Section Beginning  __________________________________ */
#include "../../GPIO_Layer/Hal_GPIO.h"
#include "../../Interrupt/MCAL_internal_interrupt.h"
#include "C:/Program Files/Microchip/xc8/v2.30/pic/include/proc/pic18f4620.h"
/* __________________________  Include Section Ending  _____________________________________ */

/* ___________________________ Macro Declarations Section Beginning ________________________ */

#define _TIMER0_8_BIT_MODE 1
#define _TIMER0_16_BIT_MODE 0
#define _TIMER0_RISING_EDGE 1
#define _TIMER0_FALLING_EDGE 0
#define _TIMER0_PRESCALER_ENABLE 1
#define _TIMER0_PRESCALER_DISABLE 0
#define _TIMER0_TIMER_MODE 1
#define _TIMER0_COUNTER_MODE 0

/* ___________________________ Macro Declarations Section Ending ___________________________ */

/* ___________________________ Macro Funcion Section Beginning ____________________________ */

/* Macro Function to Enable Timer0 Module */
#define TIMER0_ENABLE_TIMER0() (T0CONbits.TMR0ON = 1)
/* Macro Function to Stop/Disable Timer0 Module */
#define TIMER0_STOP_TIMER0() (T0CONbits.TMR0ON = 0)
/* Macro Function To Configure Timer0 in 8-Bit Mode*/
#define TIMER0_8_BIT_CONFIG() (T0CONbits.T08BIT = 1)
/* Macro Function To Configure Timer0 in 16-Bit Mode*/
#define TIMER0_16_BIT_CONFIG() (T0CONbits.T08BIT = 0)
/* Macro Function to Configure Clock Source as Externel Clock Source */
#define TIMER0_COUNTER_MODE() (T0CONbits.T0CS = 1)
/* Macro Function to Configure Clock Source as Internel Clock Source */
#define TIMER0_TIMER_MODE() (T0CONbits.T0CS = 0)
/* Macro Function to Configure Edge as Rising Edge*/
#define TIMER0_RISING_EDGE() (T0CONbits.T0SE = 0)
/* Macro Function to Configure Edge as Falling Edge*/
#define TIMER0_FALLING_EDGE() (T0CONbits.T0SE = 1)
/* Macro Function to Disable Prescaler */
#define TIMER0_PRESCALER_DISABLE() (T0CONbits.PSA = 1)
/* Macro Function to Enable Prescaler */
#define TIMER0_PRESCALER_ENABLE() (T0CONbits.PSA = 0)
/* Macro Function to Select Prescaler Value */
#define TIMER0_PRESCALER_SELECT(_VALUE) (T0CONbits.T0PS = _VALUE)

#define TIMER0_WRITE_TIMER_HIGH(_TIME_HIGH) (TMR0H = (_TIME_HIGH >> 8))
#define TIMER0_WRITE_TIMER_LOW(_TIME_LOW) (TMR0L = ((uint8)_TIME_LOW))
/* ___________________________ Macro Funcion Section Ending _______________________________ */

/* ____________________________ Data Type Declarations Section Beginning ____________________ */

typedef enum
{
    TIMER0_PRESCALER_VAL_2 = 0,
    TIMER0_PRESCALER_VAL_4,
    TIMER0_PRESCALER_VAL_8,
    TIMER0_PRESCALER_VAL_16,
    TIMER0_PRESCALER_VAL_32,
    TIMER0_PRESCALER_VAL_64,
    TIMER0_PRESCALER_VAL_128,
    TIMER0_PRESCALER_VAL_256
} _timer0_precsaler_val_t;

typedef struct
{
#if ADC_INTERRUPT == INTERNEL_INTERRUPT_ENABLE
    void (*Timer0_InterruptHandler)(void);
    _interrupt_priority_cfg priority;
#endif
    _timer0_precsaler_val_t prescaler_value;
    uint16 loaded_value;
    uint8 timer0_mode : 1;
    uint8 counter_edge : 1;
    uint8 prescaler_enable : 1;
    uint8 register_mode : 1;
    uint8 future_use : 4;

} _timer0_t;

/* ____________________________ Data Type Declarations Section Ending _______________________ */

/* ____________________________ Function Definination Section Beginning ____________________________ */

/**
 * @brief Initialize Timer0 Module
 * @param timer0_obj > Pointer to Timer0 Configuration
 * @return Void
 */
void timer0_initialize(const _timer0_t *timer0_obj);

/**
 * @brief Read data from  Timer0 Module
 * @param timer0_obj > Pointer to Timer0 Configuration
 * @param data > Pointer to Data Which Read
 * @return Void
 */
void timer0_read_value(uint16 *value);

/**
 * @brief Write Data to  Timer0 Module
 * @param timer0_obj > Pointer to Timer0 Configuration
 * @param data > Pointer to Data Which Read
 * @return Void
 */
void timer0_write_value(uint16 value);
/* ____________________________ Function DefininationSection Ending _______________________________ */

#endif /* MCAL_TIMER0_H */

/**
 * ******************************************************************************************************
 * *      User                   Date                                 Brief
 * ******************************************************************************************************
 * *     Muhammed Ali         6 September,2023                       Writting MCAL_timer0.h
 */