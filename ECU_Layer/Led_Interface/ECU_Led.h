/**
 * *****************************************************************************************************
 * * File           : ECU_led.h
 * * Auther         : Muhammed Ali Ibrahim Ahmed
 * * Details        : Led Driver
 * * Linkedin       : https://www.linkedin.com/in/muhammedalii9/
 * * Date Created   : 30 July,2023
 * *****************************************************************************************************
 */

#ifndef ECU_LED_H
#define ECU_LED_H
/* ___________________________  Include Section Beginning  ___________________________ */
#include "../../MCAL_Layer/GPIO_Layer/Hal_GPIO.h"
/* ___________________________ Include Section Ending ___________________________ */

/* ___________________________ Data Type Declarations Section Beginning ___________________________ */

typedef enum
{
    LED_OFF = 0,
    LED_ON
} _led_status_t;

typedef struct
{
    _pin_config_t led_pin; /* @ref _pin_config_t */
} _led_t;
/* ___________________________ Data Type Declarations Section Ending ___________________________ */

/* ___________________________ Function Declaration Section Beginning ___________________________ */

/**
 * @brief Initialize The Led (Direction out)
 * @param led > Pointer to led configration
 */
void led_initializ_direction(const _led_t *led);
/**
 * @brief Turnning ON The Led
 * @param led > Pointer to led configration
 */
void led_turn_on(const _led_t *led);
/**
 * @brief Turnning OFF The Led
 * @param led > Pointer to led configration
 */
void led_turn_off(const _led_t *led);
/**
 * @brief Toggling The Led ( ON -> OFF ... OFF -> ON)
 * @param led > Pointer to led configration
 */
void led_toggle(const _led_t *led);
/* ___________________________ Function Declaration Section Ending ___________________________ */

#endif /* ECU_LED_H */

/**
 * ******************************************************************************************************
 * *      User                   Date                                 Brief
 * ******************************************************************************************************
 * *     Muhammed Ali            30 July,2023                          Writting ECU_Led.h
 */
