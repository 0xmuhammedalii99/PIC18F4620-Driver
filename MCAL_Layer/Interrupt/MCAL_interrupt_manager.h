/**
 * *****************************************************************************************************
 * * File           : MCAL_interrupt_manager.h
 * * Auther         : Muhammed Ali Ibrahim Ahmed
 * * Details        : Interrupt Manager for Interrupt Service Routine Modules
 * * Linkedin       : https://www.linkedin.com/in/muhammedalii9/
 * * Date Created   : 12 August,2023
 * *****************************************************************************************************
 */

#ifndef MCAL_INTRRUPT_MANAGER_H
#define MCAL_INTRRUPT_MANAGER_H

/* __________________________  Include Section Beginning  __________________________ */
#include "MCAL_interrupt_config.h"
/* __________________________  Include Section Ending  __________________________ */

void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);
void RB4_ISR(uint8 RB4_source);
void RB5_ISR(uint8 RB5_source);
void RB6_ISR(uint8 RB6_source);
void RB7_ISR(uint8 RB7_source);
void ADC_ISR(void);
void TIMER0_ISR(void);
void TIMER1_ISR(void);
void TIMER2_ISR(void);
void TIMER3_ISR(void);
void CCP1_ISR(void);
void CCP2_ISR(void);

#endif /* MCAL_INTRRUPT_MANAGER_H */

/**
 * ******************************************************************************************************
 * *      User                   Date                                 Brief
 * ******************************************************************************************************
 * *     Muhammed Ali           12 August,2023                         Writting MCAL_interrupt_manager.h
 */