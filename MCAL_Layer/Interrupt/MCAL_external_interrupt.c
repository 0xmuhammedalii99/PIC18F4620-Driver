/**
 * ************************************************************************************************
 * * File           : MCAL_external_interrupt.h
 * * Auther         : Muhammed Ali Ibrahim Ahmed
 * * Details        : External Interrupt Driver Module
 * * Linkedin       : https://www.linkedin.com/in/muhammedalii9/
 * * Date Created   : 12 August,2023
 * ***********************************************************************************************
 */

/* ______________________  Include Section Beginning  ______________________ */
#include "MCAL_external_interrupt.h"
/* ______________________  Include Section Ending  ______________________ */

/* ______________________  Helper Functions Declaration Section Beginning ______________________ */

static void (*INT0_Interrupt_Handler)(void) = NULL;
static void (*INT1_Interrupt_Handler)(void) = NULL;
static void (*INT2_Interrupt_Handler)(void) = NULL;

static void (*RB4_Interrupt_Handler_High_to_Low)(void) = NULL;
static void (*RB4_Interrupt_Handler_Low_to_High)(void) = NULL;
static void (*RB5_Interrupt_Handler_High_to_Low)(void) = NULL;
static void (*RB5_Interrupt_Handler_Low_to_High)(void) = NULL;
static void (*RB6_Interrupt_Handler_High_to_Low)(void) = NULL;
static void (*RB6_Interrupt_Handler_Low_to_High)(void) = NULL;
static void (*RB7_Interrupt_Handler_High_to_Low)(void) = NULL;
static void (*RB7_Interrupt_Handler_Low_to_High)(void) = NULL;

static void Interrupt_INTx_Enable(const _interrupt_INTx_t *intx_pin);
static void Interrupt_INTx_Disable(const _interrupt_INTx_t *intx_pin);
static void Interrupt_INTx_Pin_Initialize(const _interrupt_INTx_t *intx_pin);
static void Interrupt_INTx_Priority_Initialize(const _interrupt_INTx_t *intx_pin);
static void Interrupt_INTx_Edge_Intitialize(const _interrupt_INTx_t *intx_pin);
static void Interrupt_INTx_Clear_Flag(const _interrupt_INTx_t *intx_pin);

static void Interrupt_RBx_Priority_Initialize(const _interrupt_RBx_t *rbx_pin);
/* ______________________  Helper Functions Declaration Section Ending ______________________ */

/* ______________________ Functions Definition Section Beginning ______________________ */

void INT0_ISR(void)
{
    /* Clear The Flag */
    EXT_INT0_FLAG_CLEAR();
    /* Call Back Function */
    if (INT0_Interrupt_Handler)
    {
        INT0_Interrupt_Handler();
    }
}
void INT1_ISR(void)
{
    /* Clear The Flag */
    EXT_INT1_FLAG_CLEAR();
    /* Call Back Function */
    if (INT1_Interrupt_Handler)
    {
        INT1_Interrupt_Handler();
    }
}
void INT2_ISR(void)
{
    /* Clear The Flag */
    EXT_INT2_FLAG_CLEAR();
    /* Call Back Function */
    if (INT2_Interrupt_Handler)
    {
        INT2_Interrupt_Handler();
    }
}
void RB4_ISR(uint8 RB4_source)
{
    /* Clear Flag */
    EXT_RBx_FLAG_CLEAR();
    /* Call Back Function */
    if (0 == RB4_source)
    {
        if (RB4_Interrupt_Handler_High_to_Low)
            RB4_Interrupt_Handler_High_to_Low();
    }
    else if (1 == RB4_source)
    {
        if (RB4_Interrupt_Handler_Low_to_High)
            RB4_Interrupt_Handler_Low_to_High();
    }
    else
    { /* Nothing */
    }
}

void RB5_ISR(uint8 RB5_source)
{
    /* Clear Flag */
    EXT_RBx_FLAG_CLEAR();
    /* Call Back Function */
    if (0 == RB5_source)
    {
        if (RB5_Interrupt_Handler_High_to_Low)
            RB5_Interrupt_Handler_High_to_Low();
    }
    else if (1 == RB5_source)
    {
        if (RB5_Interrupt_Handler_Low_to_High)
            RB5_Interrupt_Handler_Low_to_High();
    }
    else
    { /* Nothing */
    }
}
void RB6_ISR(uint8 RB6_source)
{
    /* Clear Flag */
    EXT_RBx_FLAG_CLEAR();
    /* Call Back Function */
    if (0 == RB6_source)
    {
        if (RB6_Interrupt_Handler_High_to_Low)
            RB6_Interrupt_Handler_High_to_Low();
    }
    else if (1 == RB6_source)
    {
        if (RB6_Interrupt_Handler_Low_to_High)
            RB6_Interrupt_Handler_Low_to_High();
    }
    else
    { /* Nothing */
    }
}
void RB7_ISR(uint8 RB7_source)
{
    /* Clear Flag */
    EXT_RBx_FLAG_CLEAR();
    /* Call Back Function */
    if (0 == RB7_source)
    {
        if (RB7_Interrupt_Handler_High_to_Low)
            RB7_Interrupt_Handler_High_to_Low();
    }
    else if (1 == RB7_source)
    {
        if (RB7_Interrupt_Handler_Low_to_High)
            RB7_Interrupt_Handler_Low_to_High();
    }
    else
    { /* Nothing */
    }
}


void interrupt_INTx_initialize(const _interrupt_INTx_t *intx_pin_obj)
{
    /* Disable External Interrupt */
    Interrupt_INTx_Disable(intx_pin_obj);
    /* Clear Flag : Interrupt Didn't Occur*/
    Interrupt_INTx_Clear_Flag(intx_pin_obj);
    Interrupt_INTx_Priority_Initialize(intx_pin_obj);
    /* Configure External Interrupt Edge */
    Interrupt_INTx_Edge_Intitialize(intx_pin_obj);
    /* Configure External Intterrupt I/O Pin*/
    Interrupt_INTx_Pin_Initialize(intx_pin_obj);
    /* Store Adress of Call Back Function */
    switch (intx_pin_obj->pin_source)
    {
    case INTERRUPT_EXTERNAL_INT0:
        INT0_Interrupt_Handler = intx_pin_obj->EXT_Interrupt_Handler;
        break;
    case INTERRUPT_EXTERNAL_INT1:
        INT1_Interrupt_Handler = intx_pin_obj->EXT_Interrupt_Handler;
        break;
    case INTERRUPT_EXTERNAL_INT2:
        INT2_Interrupt_Handler = intx_pin_obj->EXT_Interrupt_Handler;
        break;
    }
    /* Enable External Interrupt */
    Interrupt_INTx_Enable(intx_pin_obj);
}


void interrupt_RBx_initialize(const _interrupt_RBx_t *rbx_pin)
{
    /* Disable Interrupt */
    EXT_RBx_DISABLE();
    /* Clear Flag */
    EXT_RBx_FLAG_CLEAR();
    /* Initialize Priority*/
    Interrupt_RBx_Priority_Initialize(rbx_pin);
    /* Initialize Pin */
    gpio_pin_initialize_direction(&(rbx_pin->mcu_pin));
    /* Initialize The Call Back Function */
    switch (rbx_pin->mcu_pin.pin)
    {
    case GPIO_PIN4:
        RB4_Interrupt_Handler_High_to_Low = rbx_pin->EXT_Interrupt_Handler_High;
        RB4_Interrupt_Handler_Low_to_High = rbx_pin->EXT_Interrupt_Handler_Low;
        break;
    case GPIO_PIN5:
        RB5_Interrupt_Handler_High_to_Low = rbx_pin->EXT_Interrupt_Handler_High;
        RB5_Interrupt_Handler_Low_to_High = rbx_pin->EXT_Interrupt_Handler_Low;
        break;
    case GPIO_PIN6:
        RB6_Interrupt_Handler_High_to_Low = rbx_pin->EXT_Interrupt_Handler_High;
        RB6_Interrupt_Handler_Low_to_High = rbx_pin->EXT_Interrupt_Handler_Low;
        break;
    case GPIO_PIN7:
        RB7_Interrupt_Handler_High_to_Low = rbx_pin->EXT_Interrupt_Handler_High;
        RB7_Interrupt_Handler_Low_to_High = rbx_pin->EXT_Interrupt_Handler_Low;
        break;
    default:;
    }
    /* Enable Interrupt */
    EXT_RBx_ENABLE();
}

/* ______________________ Functions Definition Section Ending ______________________ */

/* ______________________  Helper Functions Definition Section Beginning ______________________ */

/**
 * @brief Helper Function to Enable ITNx Pins
 * @param intx_pin > Pointer to INTx Pins Configration
 */
static void Interrupt_INTx_Enable(const _interrupt_INTx_t *intx_pin)
{

    switch (intx_pin->pin_source)
    {
    case INTERRUPT_EXTERNAL_INT0:
        EXT_INT0_ENABLE();
        break;
    case INTERRUPT_EXTERNAL_INT1:
        EXT_INT1_ENABLE();
        break;
    case INTERRUPT_EXTERNAL_INT2:
        EXT_INT2_ENABLE();
        break;
    }
}

/**
 * @brief Helper Function to Disable ITNx Pins
 * @param intx_pin > Pointer to INTx Pins Configration
 */
static void Interrupt_INTx_Disable(const _interrupt_INTx_t *intx_pin)
{
    switch (intx_pin->pin_source)
    {
    case INTERRUPT_EXTERNAL_INT0:
        EXT_INT0_DISABLE();
        break;
    case INTERRUPT_EXTERNAL_INT1:
        EXT_INT1_DISABLE();
        break;
    case INTERRUPT_EXTERNAL_INT2:
        EXT_INT2_DISABLE();
        break;
    }
}

/**
 * @brief Helper Function to Initialize ITNx Pins
 * @param intx_pin > Pointer to INTx Pins Configration
 */
static void Interrupt_INTx_Pin_Initialize(const _interrupt_INTx_t *intx_pin)
{
    gpio_pin_initialize_direction(&(intx_pin->mcu_pin));
}

/**
 * @brief Helper Function to Initialize Priority for ITNx Pins
 * @param intx_pin > Pointer to INTx Pins Configration
 */
static void Interrupt_INTx_Priority_Initialize(const _interrupt_INTx_t *intx_pin)
{

    switch (intx_pin->pin_source)
    {
    case INTERRUPT_EXTERNAL_INT0:
#if INTERRUPT_PRIORITY_LEVEL == PRIORITY_LEVELS_ENABLE
        INTERRUPT_PRIORITY_ENABLE();
        INTERRUPT_GLOBAL_INTERRUPT_HighPriority_ENABLE();
#else
        INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
        INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE();
#endif
        break;
    case INTERRUPT_EXTERNAL_INT1:
#if INTERRUPT_PRIORITY_LEVEL == PRIORITY_LEVELS_ENABLE
        INTERRUPT_PRIORITY_ENABLE();
        if ((intx_pin->priority) == INTERRUPT_HIGH_PRIORITY)
        {
            INTERRUPT_GLOBAL_INTERRUPT_HighPriority_ENABLE();
            EXT_INT1_HIGH_PRIORITY();
        }
        else if ((intx_pin->priority) == INTERRUPT_LOW_PRIORITY)
        {
            INTERRUPT_GLOBAL_INTERRUPT_LowPriority_ENABLE();
            EXT_INT1_LOW_PRIORITY();
        }
        else
        { /* Nothing */
        }

#else
        INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE();
        INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
#endif
        break;
    case INTERRUPT_EXTERNAL_INT2:
#if INTERRUPT_PRIORITY_LEVEL == PRIORITY_LEVELS_ENABLE
        INTERRUPT_PRIORITY_ENABLE();
        if ((intx_pin->priority) == INTERRUPT_HIGH_PRIORITY)
        {
            INTERRUPT_GLOBAL_INTERRUPT_HighPriority_ENABLE();
            EXT_INT2_HIGH_PRIORITY();
        }
        else if ((intx_pin->priority) == INTERRUPT_LOW_PRIORITY)
        {
            INTERRUPT_GLOBAL_INTERRUPT_LowPriority_ENABLE();
            EXT_INT2_LOW_PRIORITY();
        }
        else
        { /* Nothing */
        }

#else
        INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE();
        INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
#endif
        break;
    }
}

/**
 * @brief Helper Function to Initialize Edges (Rising - Falling) for ITNx Pins
 * @param intx_pin > Pointer to INTx Pins Configration
 */
static void Interrupt_INTx_Edge_Intitialize(const _interrupt_INTx_t *intx_pin)
{
    switch (intx_pin->pin_source)
    {
    case INTERRUPT_EXTERNAL_INT0:
        if ((intx_pin->edge) == INTERRUPT_FALLING_EDGE)
        {
            EXT_INT0_FALLING_EDGE();
        }
        else if ((intx_pin->edge) == INTERRUPT_RISING_EDGE)
        {
            EXT_INT0_RISING_EDGE();
        }
        else
        {
            /* Nothing*/
        }
        break;
    case INTERRUPT_EXTERNAL_INT1:
        if ((intx_pin->edge) == INTERRUPT_FALLING_EDGE)
        {
            EXT_INT1_FALLING_EDGE();
        }
        else if ((intx_pin->edge) == INTERRUPT_RISING_EDGE)
        {
            EXT_INT1_RISING_EDGE();
        }
        else
        {
            /* Nothing */
        }
        break;
    case INTERRUPT_EXTERNAL_INT2:
        if ((intx_pin->edge) == INTERRUPT_FALLING_EDGE)
        {
            EXT_INT2_FALLING_EDGE();
        }
        else if ((intx_pin->edge) == INTERRUPT_RISING_EDGE)
        {
            EXT_INT2_RISING_EDGE();
        }
        else
        {
            /* Nothing */
        }
        break;
    }
}

/**
 * @brief Helper Function to Clear Flag for ITNx Pins
 * @param intx_pin > Pointer to INTx Pins Configration
 */
static void Interrupt_INTx_Clear_Flag(const _interrupt_INTx_t *intx_pin)
{
    switch (intx_pin->pin_source)
    {
    case INTERRUPT_EXTERNAL_INT0:
        EXT_INT0_FLAG_CLEAR();
        break;
    case INTERRUPT_EXTERNAL_INT1:
        EXT_INT1_FLAG_CLEAR();
        break;
    case INTERRUPT_EXTERNAL_INT2:
        EXT_INT2_FLAG_CLEAR();
        break;
    }
}

/**
 * @brief Function to Initialize Priority of  RBx Interrupt
 * @param rbx_pin > Pointer to RBx Pin Configrations
 */
static void Interrupt_RBx_Priority_Initialize(const _interrupt_RBx_t *rbx_pin)
{

#if INTERRUPT_PRIORITY_LEVEL == PRIORITY_LEVELS_ENABLE
    INTERRUPT_PRIORITY_ENABLE();
    if (rbx_pin->priority == INTERRUPT_HIGH_PRIORITY)
    {
        INTERRUPT_GLOBAL_INTERRUPT_HighPriority_ENABLE();
        EXT_RBx_HIGH_PRIORITY();
    }
    else if (rbx_pin->priority == INTERRUPT_LOW_PRIORITY)
    {
        INTERRUPT_GLOBAL_INTERRUPT_LowPriority_ENABLE();
        EXT_RBx_LOW_PRIORITY();
    }
    else
    {
        /* Nothing */
    }
#else
    INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
    INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE();
#endif
}

/* ______________________  Helper Functions Definition Section Ending ______________________ */

/**
 * ******************************************************************************************************
 * *      User                   Date                                 Brief
 * ******************************************************************************************************
 * *     Muhammed Ali           12 August,2023                     Writting MCAL_external_interrupt.c
 */
