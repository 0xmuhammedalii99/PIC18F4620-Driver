/**
 * *****************************************************************************************************
 * * File           : ECU_7_segment.h
 * * Auther         : Muhammed Ali Ibrahim Ahmed
 * * Details        : 7 Segment Driver 
 * * Linkedin       : https://www.linkedin.com/in/muhammedalii9/
 * * Date Created   : 5 August,2023
 * *****************************************************************************************************
 */

#ifndef ECU_7_SEGMENT_H
#define ECU_7_SEGMENT_H

/* _______________________  Include Section Beginning  _______________________ */
#include "../../MCAL_Layer/GPIO_Layer/Hal_GPIO.h"
/* _______________________ Include Section Ending _______________________ */

/* _______________________ Macro Definition Section Beginning _______________________ */

#define SEGMENT_PIN0    0
#define SEGMENT_PIN1    1
#define SEGMENT_PIN2    2
#define SEGMENT_PIN3    3
/* _______________________ Macro Definition Section Ending _______________________ */

/* _______________________ Data Type Declarations Section Beginning _______________________ */

typedef enum
{
    SEGMENT_COMMON_ANODE = 0,
    SEGMENT_COMMON_CATHODE
} _segment_type_t;

typedef struct
{
    _pin_config_t segment_pin[4];   /* @ref _pin_config_t*/
    _segment_type_t segment_type;   /* @ref _segment_type_t*/

} _segment_t;
/* _______________________ Data Type Declarations Section Ending _______________________ */

/* _______________________ Function Declaration Section Beginning _______________________ */

/**
 * @brief Initialize Seven Segment
 * @param segment > Pointer to Segment configration
 */
void seven_segment_initialize(const _segment_t *segment);

/**
 * @brief Writing Number on Seven Segment
 * @param segment > Pointer to Segment configration
 * @param number > Number that will write on Seven Segment
 */
void seven_segment_write_number(const _segment_t *segment, uint8 number);
/* _______________________ Function Declaration Section Ending _______________________  */

#endif /* ECU_7_SEGMENT_H */

/**
 * ******************************************************************************************************
 * *      User                   Date                                 Brief
 * ******************************************************************************************************
 * *     Muhammed Ali           5 Augast,2023                         Writting ECU_7_segment.h
 */