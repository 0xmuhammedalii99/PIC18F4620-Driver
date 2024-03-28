/**
 * *****************************************************************************************************
 * * File           : MCAL_interrupt_config.h
 * * Auther         : Muhammed Ali Ibrahim Ahmed
 * * Details        : Internal Interrupt Configration 
 * * Linkedin       : https://www.linkedin.com/in/muhammedalii9/
 * * Date Created   : 12 August,2023
 * *****************************************************************************************************
 */

#ifndef MCAL_INTERRUPT_CONFIG_H
#define MCAL_INTERRUPT_CONFIG_H

/* ___________________________  Include Section Beginning  ___________________________ */
#include "C:/Program Files/Microchip/xc8/v2.30/pic/include/proc/pic18f4620.h"
#include "../MCAL_Std_Types.h"
#include "MCAL_interrupt_gen_config.h"
#include "../GPIO_Layer/Hal_GPIO.h"
/* ___________________________  Include Section Ending  ___________________________ */

/* ___________________________ Macro Definition Section Beginning ___________________________ */

#define INTERRUPT_ENABLE            1
#define INTERRUPT_DISABLE           0
#define INTERRUPT_OCCUR             1
#define INTERRUPT_NOT_OCCUR         0
#define INTERRUPT_ENABLE_PRIORITY   1
#define INTERRUPT_DISABLE_PRIORITY  0

/* ___________________________ Macro Definition Section Ending ___________________________ */

/* ___________________________ Macro Funcion Declarations Section Beginning ___________________________ */

#if INTERRUPT_PRIORITY_LEVEL == PRIORITY_LEVELS_ENABLE
/*This Macro Function used to Enable Proirity Level*/
#define INTERRUPT_PRIORITY_ENABLE()         (RCONbits.IPEN = 1)
/*This Macro Function used to Disable Proirity Level*/
#define INTERRUPT_PRIORITY_DISABLE()        (RCONbits.IPEN = 0)
/* This Macro Function used to Enable High Priority Global Interrupt*/
#define INTERRUPT_GLOBAL_INTERRUPT_HighPriority_ENABLE()    (INTCONbits.GIEH = 1)
/* This Macro Function used to Disable High Priority Global Interrupt*/
#define INTERRUPT_GLOBAL_INTERRUPT_HighPriority_DISABLE()   (INTCONbits.GIEH = 0)
/* This Macro Function used to Enable Low Priority Global Interrupt*/
#define INTERRUPT_GLOBAL_INTERRUPT_LowPriority_ENABLE()     (INTCONbits.GIEL = 1)
/* This Macro Function used to Disable Low Priority Global Interrupt*/
#define INTERRUPT_GLOBAL_INTERRUPT_LowPriority_DISABLE()    (INTCONbits.GIEL = 0)
#else
/* This Macro Function used to Enable Peripheral Interrupt*/
#define INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE()     (INTCONbits.PEIE = 1)
/* This Macro Function used to Disable Peripheral Interrupt*/
#define INTERRUPT_PERIPHERAL_INTERRUPT_DISBLE()     (INTCONbits.PEIE = 0)
/*This Macro Function used to Enable all Global Interrupt*/
#define INTERRUPT_GLOBAL_INTERRUPT_ENABLE()         (INTCONbits.GIE = 1)
/*This Macro Function used to Disable all Global Interrupt*/
#define INTERRUPT_GLOBAL_INTERRUPT_DISABLE()        (INTCONbits.GIE = 0)
#endif

/* ___________________________ Macro Funcion Declarations Section Ending ___________________________ */

/* ___________________________ Data Type Declarations Section Beginning ___________________________ */

typedef enum
{
    INTERRUPT_LOW_PRIORITY = 0,
    INTERRUPT_HIGH_PRIORITY

} _interrupt_priority_cfg;
/* ___________________________ Data Type Declarations Section Ending ___________________________ */

#endif /* MCAL_INTERRUPT_CONFIG_H */

/**
 * ******************************************************************************************************
 * *      User                   Date                                 Brief
 * ******************************************************************************************************
 * *     Muhammed Ali           12 August,2023                         Writting MCAL_interrupt_config.h
 */