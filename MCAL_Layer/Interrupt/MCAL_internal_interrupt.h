/**
 * *****************************************************************************************************
 * * File           : MCAL_internal_interrupt.h
 * * Auther         : Muhammed Ali Ibrahim Ahmed
 * * Details        : Writting Internal Interrupt Driver Module
 * * Linkedin       : https://www.linkedin.com/in/muhammedalii9/
 * * Date Created   : 12 August,2023
 * *****************************************************************************************************
 */

#ifndef MCAL_INTERNAL_INTERRUPT_H
#define MCAL_INTERNAL_INTERRUPT_H

/* ________________________________  Include Section Beginning  ________________________________ */
#include "MCAL_interrupt_config.h"
/* ________________________________  Include Section Ending  ________________________________ */

#if ADC_INTERRUPT == INTERNEL_INTERRUPT_ENABLE

/* Macro Function to Clear ADC Interrupt Flag*/
#define ADC_CLEAR_FLAG() (PIR1bits.ADIF = 0)
/* Macro Function to Enable ADC Interrupt */
#define ADC_INTERRUPT_FEATUER_ENABLE() (PIE1bits.ADIE = 1)
/* Macro Function to Disable ADC Interrupt */
#define ADC_INTERRUPT_FEATUER_DISABLE() (PIE1bits.ADIE = 0)

#if INTERRUPT_PRIORITY_LEVEL == PRIORITY_LEVELS_ENABLE
/* Macro Function to Enable High Priority for ADC Module */
#define ADC_INTERRUPT_HIGH_PRIORITY() (IPR1bits.ADIP = 1)
/* Macro Function to Enable Low Priority for ADC Module */
#define ADC_INTERRUPT_LOW_PRIORITY() (IPR1bits.ADIP = 0)
#endif
#endif

#if TIMER0_INTERRUPT == INTERNEL_INTERRUPT_ENABLE
/* Macro Function to Clear Timer0 Interrupt Flag*/
#define TIMER0_CLEAR_FLAG() (INTCONbits.TMR0IF = 0)
/* Macro Function to Enable Timer0 Interrupt */
#define TIMER0_INTERRUPT_FEATURE_ENABLE() (INTCONbits.TMR0IE = 1)
/* Macro Function to Disable Timer0 Interrupt */
#define TIMER0_INTERRUPT_FEATURE_DISABLE() (INTCONbits.TMR0IE = 0)
#if INTERRUPT_PRIORITY_LEVEL == PRIORITY_LEVELS_ENABLE
/* Macro Function to Enable Hgih Priority for ADC Module */
#define TIMER0_INTERRUPT_HIGH_PRIORITY() (INTCON2bits.TMR0IP = 1)
/* Macro Function to Enable Low Priority for Timer0 Module */
#define TIMER0_INTERRUPT_LOW_PRIORITY() (INTCON2bits.TMR0IP = 0)
#endif
#endif

#if TIMER1_INTERRUPT == INTERNEL_INTERRUPT_ENABLE
/* Clear Flag of Timer 1 Module */
#define TIMER1_CLEAR_FLAG() (PIR1bits.TMR1IF = 0)
/* Enable Timer 1 Interrupt */
#define TIMER1_INTERRUPT_FEATURE_ENABLE() (PIE1bits.TMR1IE = 1)
/* Disable Timer 1 Interrupt */
#define TIMER1_INTERRUPT_FEATURE_DISABLE() (PIE1bits.TMR1IE = 0)
#if INTERRUPT_PRIORITY_LEVEL == PRIORITY_LEVELS_ENABLE
/* Macro Function to Enable Hgih Priority for Timer 1 Module */
#define TIMER1_INTERRUPT_HIGH_PRIORITY() (IPR1bits.TMR1IP = 1)
/* Macro Function to Enable Low Priority for Timer 1 Module */
#define TIMER1_INTERRUPT_LOW_PRIORITY() (IPR1bits.TMR1IP = 0)
#endif
#endif

#if TIMER2_INTERRUPT == INTERNEL_INTERRUPT_ENABLE
/* Clear Flag of Timer 2 Module */
#define TIMER2_CLEAR_FLAG() (PIR1bits.TMR2IF = 0)
/* Enable Timer 2 Interrupt */
#define TIMER2_INTERRUPT_FEATURE_ENABLE() (PIE1bits.TMR2IE = 1)
/* Disable Timer 2 Interrupt */
#define TIMER2_INTERRUPT_FEATURE_DISABLE() (PIE1bits.TMR2IE = 0)
#if INTERRUPT_PRIORITY_LEVEL == PRIORITY_LEVELS_ENABLE
/* Macro Function to Enable Hgih Priority for Timer 2 Module */
#define TIMER2_INTERRUPT_HIGH_PRIORITY() (IPR1bits.TMR2IP = 1)
/* Macro Function to Enable Low Priority for Timer 2 Module */
#define TIMER2_INTERRUPT_LOW_PRIORITY() (IPR1bits.TMR2IP = 0)
#endif
#endif

#if TIMER3_INTERRUPT == INTERNEL_INTERRUPT_ENABLE
/* Clear Flag of Timer 3 Module */
#define TIMER3_CLEAR_FLAG() (PIR2bits.TMR3IF = 0)
/* Enable Timer 3 Interrupt */
#define TIMER3_INTERRUPT_FEATURE_ENABLE() (PIE2bits.TMR3IE = 1)
/* Disable Timer 3 Interrupt */
#define TIMER3_INTERRUPT_FEATURE_DISABLE() (PIE2bits.TMR3IE = 0)
#if INTERRUPT_PRIORITY_LEVEL == PRIORITY_LEVELS_DISABLE
/* Macro Function to Enable Hgih Priority for Timer 3 Module */
#define TIMER3_INTERRUPT_HIGH_PRIORITY() (IPR2bits.TMR3IP = 1)
/* Macro Function to Enable Low Priority for Timer 3 Module */
#define TIMER3_INTERRUPT_LOW_PRIORITY() (IPR2bits.TMR3IP = 0)
#endif
#endif

#if CCP1_INTERRUPT == INTERNEL_INTERRUPT_ENABLE
/* Clear Flag of CCP1 Module */
#define CCP1_CLEAR_FLAG() (PIR1bits.CCP1IF = 0)
/* Enable CCP1 Module Interrupt */
#define CCP1_INTERRUPT_FEATURE_ENABLE() (PIE1bits.CCP1IE = 1)
/* Disable CCP1 Module Interrupt */
#define CCP1_INTERRUPT_FEATURE_DISABLE() (PIE1bits.CCP1IE = 0)
#if INTERRUPT_PRIORITY_LEVEL == PRIORITY_LEVELS_DISABLE
/* Macro Function to Enable Hgih Priority for CCP1  Module */
#define CCP1_INTERRUPT_HIGH_PRIORITY() (IPR1bits.CCP1IP = 1)
/* Macro Function to Enable Low Priority for CCP1  Module */
#define CCP1_INTERRUPT_LOW_PRIORITY() (IPR1bits.CCP1IP = 0)
#endif

#endif

#if CCP2_INTERRUPT == INTERNEL_INTERRUPT_ENABLE
/* Clear Flag of CCP2 Module */
#define CCP2_CLEAR_FLAG() (PIR2bits.CCP2IF = 0)
/* Enable CCP2 Module Interrupt */
#define CCP2_INTERRUPT_FEATURE_ENABLE() (PIE2bits.CCP2IE = 1)
/* Disable CCP2 Module Interrupt */
#define CCP2_INTERRUPT_FEATURE_DISABLE() (PIE2bits.CCP2IE = 0)
#if INTERRUPT_PRIORITY_LEVEL == PRIORITY_LEVELS_DISABLE
/* Macro Function to Enable Hgih Priority for CCP2  Module */
#define CCP2_INTERRUPT_HIGH_PRIORITY() (IPR2bits.CCP2IP = 1)
/* Macro Function to Enable Low Priority for CCP2  Module */
#define CCP2_INTERRUPT_LOW_PRIORITY() (IPR2bits.CCP2IP = 0)
#endif

#endif

#endif /* MCAL_INTERNAL_INTERRUPT_H */

/**
 * ******************************************************************************************************
 * *      User                   Date                                 Brief
 * ******************************************************************************************************
 * *     Muhammed Ali           12 August,2023                         MCAL_internal_interrupt.h
 */