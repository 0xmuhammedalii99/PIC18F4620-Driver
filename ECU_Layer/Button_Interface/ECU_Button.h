/**
 * *****************************************************************************************************
 * * File           : ECU_Button.h
 * * Auther         : Muhammed Ali Ibrahim Ahmed
 * * Details        : Button Driver
 * * Linkedin       : https://www.linkedin.com/in/muhammedalii9/
 * * Date Created   : 30 July,2023
 * *****************************************************************************************************
 */

#ifndef ECU_BUTTON_H
#define ECU_BUTTON_H

/* _________________________  Include Section Beginning  _________________________ */
#include "../../MCAL_Layer/GPIO_Layer/Hal_GPIO.h"
/* _________________________ Include Section Ending _________________________ */

/* _________________________ Data Type Declarations Section Beginning _________________________ */

typedef enum
{
    BUTTON_PRESSED = 0,
    BUTTON_RELEASED
} _button_state_t;
typedef enum
{
    BUTTON_ACTIVE_HIGH = 0,
    BUTTON_ACTIVE_LOW
} _button_active_t;

typedef struct
{
    _pin_config_t button_pin;           /* @ref _pin_config_t */
    _button_state_t button_state;       /* @ref _button_state_t */
    _button_active_t button_connection; /* @ref _button_active_t */

} _button_t;

/* _________________________ Data Type Declarations Section Ending _________________________ */

/* _________________________ Function Declaration Section Beginning _________________________ */

/**
 * @brief Initialize Button
 * @param button_config > Pointer to button configration
 */
void button_initialize(const _button_t *button_config);

/**
 * @brief Reading The State of Button
 * @param button_config > Pointer to button configration
 */
void button_read_state(const _button_t *button_config, _button_state_t *button_state);
/* _________________________ Function Declaration Section Ending _________________________ */

#endif /* ECU_BUTTON_H */

/**
 * ******************************************************************************************************
 * *      User                   Date                                 Brief
 * ******************************************************************************************************
 * *     Muhammed Ali           30 July,2023                         Writting ECU_Button.h
 */
