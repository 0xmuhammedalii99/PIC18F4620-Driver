/**
 * *****************************************************************************************************
 * * File           : MCAL_intrrupt_gen_configration.h
 * * Auther         : Muhammed Ali Ibrahim Ahmed
 * * Details        : Generation Configration of Interrupt 
 * * Linkedin       : https://www.linkedin.com/in/muhammedalii9/
 * * Date Created   : 12 August,2023
 * *****************************************************************************************************
 */
#ifndef MCAL_INTERRUPT_GEN_CONFIG_H
#define MCAL_INTERRUPT_GEN_CONFIG_H

/*________________________________ Priority Levels _______________________________________*/

/* Macro The Enable Prioiry Levels */
#define PRIORITY_LEVELS_ENABLE                  1
/* Macro The Disable Prioiry Levels */
#define PRIORITY_LEVELS_DISABLE                 0

#define INTERRUPT_PRIORITY_LEVEL        PRIORITY_LEVELS_DISABLE

/*________________________________ Externel Interrupt ____________________________________*/

/* Macro The Enable External Interrupt  */
#define EXTERNAL_INTERRUPT_ENABLE               1
/* Macro The Disable External Interrupt  */
#define EXTERNAL_INTERRUPT_DISABLE              0
/* Macro The Enable On Change Interrupt  */
#define EXTERNAL_INTERRUPT_ON_CHANGE_ENABLE     1
/* Macro The Disable On Change Interrupt  */
#define EXTERNAL_INTERRUPT_ON_CHANGE_DISABLE    0

#define INTERRUPT_EXTERNAL_INTx         EXTERNAL_INTERRUPT_ENABLE
#define INTERRUPT_EXTERNAL_ON_CHANGE    EXTERNAL_INTERRUPT_ON_CHANGE_ENABLE

/* ________________________________ Internel Interrupt _________________________________ */

/* Macro The Enable Internel Interrupt  */
#define INTERNEL_INTERRUPT_ENABLE               1
/* Macro The Disable Internel Interrupt  */
#define INTERNEL_INTERRUPT_DISABLE              0

#define ADC_INTERRUPT                   INTERNEL_INTERRUPT_ENABLE
#define TIMER0_INTERRUPT                INTERNEL_INTERRUPT_ENABLE
#define TIMER1_INTERRUPT                INTERNEL_INTERRUPT_ENABLE
#define TIMER2_INTERRUPT                INTERNEL_INTERRUPT_ENABLE
#define TIMER3_INTERRUPT                INTERNEL_INTERRUPT_ENABLE
#define CCP1_INTERRUPT                  INTERNEL_INTERRUPT_ENABLE
#define CCP2_INTERRUPT                  INTERNEL_INTERRUPT_ENABLE



#endif /* MCAL_INTERRUPT_GEN_CONFIG_H */


/**
 * ******************************************************************************************************
 * *      User                   Date                                 Brief
 * ******************************************************************************************************
 * *     Muhammed Ali           12 August,2023                         Writting MCAL_intrrupt_gen_configration.h
 */