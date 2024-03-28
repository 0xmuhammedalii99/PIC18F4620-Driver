/**
 * *****************************************************************************************************
 * * File           : ECU_Relay.c
 * * Auther         : Muhammed Ali Ibrahim Ahmed
 * * Details        : Relay Driver
 * * Linkedin       : https://www.linkedin.com/in/muhammedalii9/
 * * Date Created   : 3 Augast,2023
 * *****************************************************************************************************
 */

/* __________________________  Include Section Beginning  __________________________ */
#include "ECU_Relay.h"
/* __________________________  Include Section Endigng  __________________________ */

/* __________________________ Function Definition Section Beginning __________________________ */


void relay_initialize(const _relay_t *relay_config)
{
    gpio_pin_initialize(&(relay_config->relay_pin));
};

void relay_turn_on(const _relay_t *relay_config)
{
    gpio_pin_write_logic(&(relay_config->relay_pin), GPIO_HIGH);
};

void relay_turn_off(const _relay_t *relay_config)
{
    gpio_pin_write_logic(&(relay_config->relay_pin), GPIO_LOW);
};
/* __________________________ Function Definition Section Ending __________________________ */
