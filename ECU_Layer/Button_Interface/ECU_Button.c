/**
 * *****************************************************************************************************
 * * File           : ECU_Button.c
 * * Auther         : Muhammed Ali Ibrahim Ahmed
 * * Details        : Button Driver
 * * Linkedin       : https://www.linkedin.com/in/muhammedalii9/
 * * Date Created   : 1 August,2023
 * *****************************************************************************************************
 */

/* _________________________  Include Section Beginning  _________________________ */
#include "ECU_Button.h"
/* _________________________ Include Section Ending _________________________ */

/* _________________________ Function Declaration Section Beginning _________________________ */


void button_initialize(const _button_t *button_config)
{
    gpio_pin_initialize_direction(&(button_config->button_pin));
};


void button_read_state(const _button_t *button_config, _button_state_t *button_state)
{
    _logic_t Pin_Logic_Status = GPIO_LOW;
    gpio_pin_read_logic(&(button_config->button_pin), &Pin_Logic_Status);
    if (button_config->button_connection == BUTTON_ACTIVE_HIGH)
    {
        if (GPIO_HIGH == Pin_Logic_Status)
        {
            *button_state = BUTTON_PRESSED;
        }
        else
        {
            *button_state = BUTTON_RELEASED;
        }
    }
    else if (button_config->button_connection == BUTTON_ACTIVE_LOW)
    {
        if (GPIO_HIGH == Pin_Logic_Status)
        {
            *button_state = BUTTON_RELEASED;
        }
        else
        {
            *button_state = BUTTON_PRESSED;
        }
    }
    else
    {
        /* Nothing*/
    }
};
/* _________________________ Function Declaration Section Ending _________________________ */

/**
 * ******************************************************************************************************
 * *      User                   Date                                 Brief
 * ******************************************************************************************************
 * *     Muhammed Ali           1 Augast,2023                         Writting ECU_Button.c
 */
