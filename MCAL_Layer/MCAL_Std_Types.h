/**
 * *****************************************************************************************************
 * * File           : Hal_GPIO_cfg.c
 * * Auther         : Muhammed Ali Ibrahim Ahmed
 * * Details        : GPIO
 * * Linkedin       : https://www.linkedin.com/in/muhammedalii9/
 * * Date Created   : 29 July,2023
 * *****************************************************************************************************
 */

#ifndef MCAL_STD_TYPES_H
#define MCAL_STD_TYPES_H

/* ********************************  Include Section Beginning  *********************************** */
#include "Std_Libraries.h"
#include "Compiler.h"
/* ********************************  Include Section Ending  *********************************** */


/* **********************  Data Type Declarations Section Beginning  ********************************** */

typedef unsigned char   uint8;
typedef unsigned short  uint16;
typedef unsigned long   uint32;
typedef signed char     sint8;
typedef signed short    sint16;
typedef signed long     sint32;
typedef float           float16;
typedef double          float32;
typedef uint8           Std_ReturnType;
/* **********************  Data Type Declarations Section Ending  ********************************** */

/* *****************************  Macro Definition Section Beginning  ********************************** */

#define STD_HIGH        0x01
#define STD_LOW         0x00


#define STD_ON          0x01
#define STD_OFF         0x00

#define STD_ACTIVE      0x01
#define STD_IDLE        0x00

#define E_OK            (Std_ReturnType)0x01
#define E_NOT_OK        (Std_ReturnType)0x00

#define ZERO            0




/* *****************************  Macro Definition Section Ending  ********************************** */
#endif /* MCAL_STD_TYPES_H */
