/**
 * *****************************************************************************************************
 * * File           : ECU_Relay.h
 * * Auther         : Muhammed Ali Ibrahim Ahmed
 * * Details        : Relay Module
 * * Linkedin       : https://www.linkedin.com/in/muhammedalii9/
 * * Date Created   : 3 Augast,2023
 * *****************************************************************************************************
 */

#ifndef ECU_RELAY_H
#define ECU_RELAY_H

/* __________________________  Include Section Beginning  __________________________ */
#include "../../MCAL_Layer/GPIO_Layer/Hal_GPIO.h"
/* __________________________  Include Section Ending  __________________________ */

/* __________________________ Data Type Declarations Section Beginning __________________________ */

typedef struct
{
    _pin_config_t relay_pin; /* @ref _pin_config_t */
} _relay_t;

/* __________________________ Data Type Declarations Section Ending __________________________ */

/* __________________________ Function Declaration Section Beginning __________________________ */

/**
 * @brief Initialize Relay
 * @param relay_config > Pointer to Relay Configration
 */
void relay_initialize(const _relay_t *relay_config);
/**
 * @brief Turning ON Relay
 * @param relay_config > Pointer to Relay Configration
 */
void relay_turn_on(const _relay_t *relay_config);
/**
 * @brief Turning OFF Relay
 * @param relay_config > Pointer to Relay Configration
 */
void relay_turn_off(const _relay_t *relay_config);

/* __________________________ Function Declaration Section Ending __________________________ */

#endif /*ECU_RELAY_H*/
/**
 * ******************************************************************************************************
 * *      User                   Date                                 Brief
 * ******************************************************************************************************
 * *     Muhammed Ali            30 July,2023                          Writting ECU_Relay.h
 */
