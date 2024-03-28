/**
 * ************************************************************************************************
 * * File           : MCAL_external_interrupt.h
 * * Auther         : Muhammed Ali Ibrahim Ahmed
 * * Details        : External Interrupt Driver Module
 * * Linkedin       : https://www.linkedin.com/in/muhammedalii9/
 * * Date Created   : 12 August,2023
 * ***********************************************************************************************
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define MCAL_EXTERNAL_INTERRUPT_H
/* ______________________  Include Section Beginning  ______________________ */
#include "MCAL_interrupt_config.h"
/* ______________________  Include Section Ending  ______________________ */

/* ______________________ Macro Funcion Declarations Section Beginning ______________________ */
#if INTERRUPT_EXTERNAL_INTx == EXTERNAL_INTERRUPT_ENABLE
/*This Macro Function to Enable External Interrupt , INT0 */
#define EXT_INT0_ENABLE() (INTCONbits.INT0IE = 1)
/*This Macro Function to Disable External Interrupt , INT0 */
#define EXT_INT0_DISABLE() (INTCONbits.INT0IE = 0)
/* This Macro Function to Clear Flag bit of External Interrupt , INT0 */
#define EXT_INT0_FLAG_CLEAR() (INTCONbits.INT0IF = 0)
/* Tith Macro Function used to detect of the Externel Interrupt , INT0 to Negative Edge*/
#define EXT_INT0_RISING_EDGE() (INTCON2bits.INTEDG0 = 1)
/* Tith Macro Function used to detect of the Externel Interrupt , INT0 to Positive Edge*/
#define EXT_INT0_FALLING_EDGE() (INTCON2bits.INTEDG0 = 0)

/*This Macro Function to Enable External Interrupt , INT1 */
#define EXT_INT1_ENABLE() (INTCON3bits.INT1IE = 1)
/*This Macro Function to Disable External Interrupt , INT1 */
#define EXT_INT1_DISABLE() (INTCON3bits.INT1IE = 0)
/* This Macro Function to Clear Flag bit of External Interrupt , INT1 */
#define EXT_INT1_FLAG_CLEAR() (INTCON3bits.INT1IF = 0)
/* Tith Macro Function used to detect of the Externel Interrupt , INT1 to Negative Edge*/
#define EXT_INT1_RISING_EDGE() (INTCON2bits.INTEDG1 = 1)
/* Tith Macro Function used to detect of the Externel Interrupt , INT1 to Positive Edge*/
#define EXT_INT1_FALLING_EDGE() (INTCON2bits.INTEDG1 = 0)

/*This Macro Function to Enable External Interrupt , INT2 */
#define EXT_INT2_ENABLE() (INTCON3bits.INT2IE = 1)
/*This Macro Function to Disable External Interrupt , INT2 */
#define EXT_INT2_DISABLE() (INTCON3bits.INT2IE = 0)
/* This Macro Function to Clear Flag bit of External Interrupt , INT2 */
#define EXT_INT2_FLAG_CLEAR() (INTCON3bits.INT2IF = 0)
/* Tith Macro Function used to detect of the Externel Interrupt , INT2 to Negative Edge*/
#define EXT_INT2_RISING_EDGE() (INTCON2bits.INTEDG2 = 1)
/* Tith Macro Function used to detect of the Externel Interrupt , INT2 to Positive Edge*/
#define EXT_INT2_FALLING_EDGE() (INTCON2bits.INTEDG2 = 0)

#if INTERRUPT_PRIORITY_LEVEL == PRIORITY_LEVELS_ENABLE
/* This Macro Function used to Make External Interrupt , INT1 High Priority*/
#define EXT_INT1_HIGH_PRIORITY() (INTCON3bits.INT1IP = 1)
/* This Macro Function used to Make External Interrupt , INT1 Low Priority*/
#define EXT_INT1_LOW_PRIORITY() (INTCON3bits.INT1IP = 0)

/* This Macro Function used to Make External Interrupt , INT2 High Priority*/
#define EXT_INT2_HIGH_PRIORITY() (INTCON3bits.INT2IP = 1)
/* This Macro Function used to Make External Interrupt , INT2 Low Priority*/
#define EXT_INT2_LOW_PRIORITY() (INTCON3bits.INT2IP = 0)
#endif
#endif

#if INTERRUPT_EXTERNAL_ON_CHANGE == EXTERNAL_INTERRUPT_ON_CHANGE_ENABLE
/* This Macro Function to Enable The External Interrupt , RBx*/
#define EXT_RBx_ENABLE() (INTCONbits.RBIE = 1)
/* This Macro Function to Disable The External Interrupt , RBx*/
#define EXT_RBx_DISABLE() (INTCONbits.RBIE = 0)
/* This Macro Function to Clear Flag of External Interrupt , RBx*/
#define EXT_RBx_FLAG_CLEAR() (INTCONbits.RBIF = 0)

#if INTERRUPT_PRIORITY_LEVEL == PRIORITY_LEVELS_ENABLE
/* This Macro Function used to Make Externa Interrupt , RBx High Priorty*/
#define EXT_RBx_HIGH_PRIORITY() (INTCON2bits.RBIP = 1)
/* This Macro Function used to Make Externa Interrupt , RBx Low Priorty*/
#define EXT_RBx_LOW_PRIORITY() (INTCON2bits.RBIP = 0)
#endif

#endif

/* ______________________ Macro Funcion Declarations Section Ending ______________________ */

/* ______________________ Data Type Declarations Section Beginning ______________________ */

typedef enum
{
    INTERRUPT_FALLING_EDGE = 0,
    INTERRUPT_RISING_EDGE
} _interrupt_INTx_edges_t;

typedef enum
{
    INTERRUPT_EXTERNAL_INT0 = 0,
    INTERRUPT_EXTERNAL_INT1,
    INTERRUPT_EXTERNAL_INT2
} _interrupt_INTx_pin;

typedef struct
{

    void (*EXT_Interrupt_Handler)(void); /* Call Back Function*/
    _interrupt_INTx_pin pin_source;      /* @ref _interrupt_INTx_pin*/
    _pin_config_t mcu_pin;               /* @ref _pin_config_t*/
    _interrupt_INTx_edges_t edge;        /* @ref _interrupt_INTx_edges_t*/
    _interrupt_priority_cfg priority;    /* @ref _interrupt_priority_cfg*/

} _interrupt_INTx_t;

typedef struct
{
    // call back function
    void (*EXT_Interrupt_Handler_High)(void); /* Call Back Function*/
    void (*EXT_Interrupt_Handler_Low)(void);  /* Call Back Function*/
    _pin_config_t mcu_pin;                    /* @ref _pin_config_t*/
    _interrupt_priority_cfg priority;         /* @ref _interrupt_priority_cfg*/

} _interrupt_RBx_t;
/* ______________________ Data Type Declarations Section Ending ______________________ */

/* ______________________ Function Declaration Section Beginning ______________________ */

/**
 * @brief Initialize External Interrupt INTx
 * @param intx_pin_obj > Pointer to INTx Pin Configration
 */
void interrupt_INTx_initialize(const _interrupt_INTx_t *intx_pin);

/**
 * @brief Initialize External Interrupt RBx_
 * @param rbx_pin > Pointer to INTx Pin Configration
 */
void interrupt_RBx_initialize(const _interrupt_RBx_t *rbx_pin);
/* ______________________ Function Declaration Section Ending ______________________ */

#endif /* MCAL_EXTERNAL_INTERRUPT_H */

/**
 * ******************************************************************************************************
 * *      User                   Date                                 Brief
 * ******************************************************************************************************
 * *     Muhammed Ali           12 August,2023                      Writting MCAL_external_interrupt.h
 */