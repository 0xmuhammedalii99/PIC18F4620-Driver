/**
 * *****************************************************************************************************
 * * File           : application.h
 * * Auther         : Muhammed Ali Ibrahim Ahmed
 * * Details        : Functioncs definiations,variables declaration
 * * Linkedin       : https://www.linkedin.com/in/muhammedalii9/
 * * Date Created   : 12 August,2023
 * *****************************************************************************************************
 */

/* __________________________  Include Section Beginning  __________________________ */
#include "MCAL_interrupt_manager.h"
/* __________________________  Include Section Ending  __________________________ */
static volatile uint8 RB4_Flag = 1;
static volatile uint8 RB5_Flag = 1;
static volatile uint8 RB6_Flag = 1;
static volatile uint8 RB7_Flag = 1;

#if INTERRUPT_PRIORITY_LEVEL == PRIORITY_LEVELS_ENABLE

void __interrupt() Interrupt_Manager_High(void)
{
    if ((INTERRUPT_ENABLE == INTCONbits.INT0IE) && (INTERRUPT_OCCUR == INTCONbits.INT0IF))
    {
        INT0_ISR();
    }
    if ((INTERRUPT_ENABLE == INTCON3bits.INT2IF) && (INTERRUPT_OCCUR == INTCON3bits.INT2IF))
    {
        INT2_ISR();
    }
}
void __interrupt(low_priority) Interrupt_Manager_low(void)
{
    if ((INTERRUPT_ENABLE == INTCON3bits.INT1IE) && (INTERRUPT_OCCUR == INTCON3bits.INT1IF))
    {
        INT1_ISR();
    }
}

#else
void __interrupt() Interrupt_Manager(void)
{
    /* For Interrupt Sevice Routin INT0*/
    if ((INTERRUPT_ENABLE == INTCONbits.INT0IE) && (INTERRUPT_OCCUR == INTCONbits.INT0IF))
    {
        INT0_ISR();
    }
    else
    {
        /* Nothing */
    }
    /* For Interrupt Sevice Routin INT1*/
    if ((INTERRUPT_ENABLE == INTCON3bits.INT1IE) && (INTERRUPT_OCCUR == INTCON3bits.INT1IF))
    {
        INT1_ISR();
    }
    /* For Interrupt Sevice Routin INT2*/
    if ((INTERRUPT_ENABLE == INTCON3bits.INT2IF) && (INTERRUPT_OCCUR == INTCON3bits.INT2IF))
    {
        INT2_ISR();
    }
    else
    {
        /* Nothing */
    }
    /* For Interrupt Sevice Routin RB4*/
    if ((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) &&
        (PORTBbits.RB4 == GPIO_HIGH) && (RB4_Flag == 1))
    {
        RB4_Flag = 0;
        RB4_ISR(0);
    }
    else
    {
        /* Nothing */
    }
    if ((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) &&
        (PORTBbits.RB4 == GPIO_LOW) && (RB4_Flag == 0))
    {
        RB4_Flag = 1;
        RB4_ISR(1);
    }
    else
    {
        /* Nothing */
    }
    /* For Interrupt Sevice Routin RB5*/
    if ((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) &&
        (PORTBbits.RB5 == GPIO_HIGH) && (RB5_Flag == 1))
    {
        RB5_Flag = 0;
        RB5_ISR(0);
    }
    else
    {
        /* Nothing */
    }
    if ((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) &&
        (PORTBbits.RB5 == GPIO_LOW) && (RB5_Flag == 0))
    {
        RB5_Flag = 1;
        RB5_ISR(1);
    }
    else
    {
        /* Nothing */
    }
    /* For Interrupt Sevice Routin RB6*/
    if ((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) &&
        (PORTBbits.RB6 == GPIO_HIGH) && (RB6_Flag == 1))
    {
        RB6_Flag = 0;
        RB6_ISR(0);
    }
    else
    {
        /* Nothing */
    }
    if ((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) &&
        (PORTBbits.RB6 == GPIO_LOW) && (RB6_Flag == 0))
    {
        RB6_Flag = 1;
        RB6_ISR(1);
    }
    else
    {
        /* Nothing */
    }
    /* For Interrupt Sevice Routin RB7*/
    if ((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) &&
        (PORTBbits.RB7 == GPIO_HIGH) && (RB7_Flag == 1))
    {
        RB7_Flag = 0;
        RB7_ISR(0);
    }
    else
    {
        /* Nothing */
    }
    if ((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) &&
        (PORTBbits.RB7 == GPIO_LOW) && (RB7_Flag = 0))
    {
        RB7_Flag = 1;
        RB7_ISR(1);
    }
    else
    {
        /* Nothing */
    }

    /* ________ For ADC Module ________*/
    if ((INTERRUPT_ENABLE == PIE1bits.ADIE) && (INTERRUPT_OCCUR == PIR1bits.ADIF))
    {
        ADC_ISR();
    }
    /* ________ For Timer0 Module ________*/
    if ((INTERRUPT_ENABLE == INTCONbits.TMR0IE) && (INTERRUPT_OCCUR == INTCONbits.TMR0IF))
    {
        TIMER0_ISR();
    }
    /* ________ For Timer1 Module ________*/
    if ((INTERRUPT_ENABLE == PIE1bits.TMR1IE) && (INTERRUPT_OCCUR == PIR1bits.TMR1IF))
    {
        TIMER1_ISR();
    }
    /* ________ For Timer2 Module ________*/
    if ((INTERRUPT_ENABLE == PIE1bits.TMR2IE) && (INTERRUPT_OCCUR == PIR1bits.TMR2IF))
    {
        TIMER2_ISR();
    }
    /* ________ For Timer3 Module ________*/
    if ((INTERRUPT_ENABLE == PIE2bits.TMR3IE) && (INTERRUPT_OCCUR == PIR2bits.TMR3IF))
    {
        TIMER3_ISR();
    }
    /* ________ For CCP1 Module ________*/
    if ((INTERRUPT_ENABLE == PIE1bits.CCP1IE) && (INTERRUPT_OCCUR == PIR1bits.CCP1IF))
    {
        CCP1_ISR();
    }
    /* ________ For CCP2 Module ________*/
    if ((INTERRUPT_ENABLE == PIE2bits.CCP2IE) && (INTERRUPT_OCCUR == PIR2bits.CCP2IF))
    {
        CCP2_ISR();
    }
}

#endif

/**
 * ******************************************************************************************************
 * *      User                   Date                                 Brief
 * ******************************************************************************************************
 * *     Muhammed Ali           12 August,2023                         Writting MCAL_interrupt_manager.c
 */