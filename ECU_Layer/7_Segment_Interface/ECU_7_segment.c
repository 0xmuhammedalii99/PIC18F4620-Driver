/**
 * *****************************************************************************************************
 * * File           : ECU_7_segment.c
 * * Auther         : Muhammed Ali Ibrahim Ahmed
 * * Details        : GPIO
 * * Linkedin       : https://www.linkedin.com/in/muhammedalii9/
 * * Date Created   : 5 August,2023
 * *****************************************************************************************************
 */

/* _________________________  Include Section Beginning  _________________________ */
#include "ECU_7_segment.h"

/* _________________________ Include Section Ending _________________________ */

/* _________________________ Function Declaration Section Beginning _________________________ */


void seven_segment_initialize(const _segment_t *segment)
{
    gpio_pin_initialize(&(segment->segment_pin[SEGMENT_PIN0]));
    gpio_pin_initialize(&(segment->segment_pin[SEGMENT_PIN1]));
    gpio_pin_initialize(&(segment->segment_pin[SEGMENT_PIN2]));
    gpio_pin_initialize(&(segment->segment_pin[SEGMENT_PIN3]));
}

void seven_segment_write_number(const _segment_t *segment, uint8 number)
{
    gpio_pin_write_logic(&(segment->segment_pin[SEGMENT_PIN0]), (number >> SEGMENT_PIN0) & 0X01);
    gpio_pin_write_logic(&(segment->segment_pin[SEGMENT_PIN1]), (number >> SEGMENT_PIN1) & 0X01);
    gpio_pin_write_logic(&(segment->segment_pin[SEGMENT_PIN2]), (number >> SEGMENT_PIN2) & 0X01);
    gpio_pin_write_logic(&(segment->segment_pin[SEGMENT_PIN3]), (number >> SEGMENT_PIN3) & 0X01);
}

/* ******************************* Function Declaration Section Ending ********************** */

/**
 * ******************************************************************************************************
 * *      User                   Date                                 Brief
 * ******************************************************************************************************
 * *     Muhammed Ali           5 Augast,2023                         Writting ECU_7_segment.c
 */