/**
 * *****************************************************************************************************
 * * File           : ECU_led.c
 * * Auther         : Muhammed Ali Ibrahim Ahmed
 * * Details        : Led Driver
 * * Linkedin       : https://www.linkedin.com/in/muhammedalii9/
 * * Date Created   : 30 July,2023
 * *****************************************************************************************************
 */

/* ___________________________  Include Section Beginning  ___________________________ */
#include "ECU_Led.h"
/* ___________________________ Include Section Ending ___________________________ */

/* ___________________________ Function Definition Section Beginning ___________________________ */

void led_initializ_direction(const _led_t *led)
{
    gpio_pin_initialize(&(led->led_pin));
}

void led_turn_on(const _led_t *led)
{
    gpio_pin_write_logic(&(led->led_pin), GPIO_HIGH);
}

void led_turn_off(const _led_t *led)
{
    
    gpio_pin_write_logic(&(led->led_pin), GPIO_LOW);
}

void led_toggle(const _led_t *led)
{
    gpio_pin_toggle_logic(&(led->led_pin));
};

/* ___________________________ Function Definition Section Beginning ___________________________ */

/**
 * ******************************************************************************************************
 * *      User                   Date                                 Brief
 * ******************************************************************************************************
 * *     Muhammed Ali            30 July,2023                          Writting ECU_Led.c
 */