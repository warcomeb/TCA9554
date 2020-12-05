/*
 * ChristmasTree - Gadget 2020
 * Copyright (C) 2020 NOWAE <http://www.nowae.it>
 *
 * Author:
 *   Marco Giammarini <m.giammarini@warcomeb.it>
 */

#ifndef TCA9554_H
#define TCA9554_H

#ifndef __NO_PROFILES
#include "board.h"
#include "firmware.h"
#endif

#define TCA9554_REG_INPUT                        0x00
#define TCA9554_REG_OUTPUT                       0x01
#define TCA9554_REG_POLARITY                     0x02
#define TCA9554_REG_CONFIG                       0x03

typedef struct
{

  uint8_t P0       : 1;
  uint8_t P1       : 1;
  uint8_t P2       : 1;
  uint8_t P3       : 1;
  uint8_t P4       : 1;
  uint8_t P5       : 1;
  uint8_t P6       : 1;
  uint8_t P7       : 1;
} bitwise_t;

typedef union _TCA9554_InputReg
{
    uint8_t    all;
    bitwise_t  bit;
} TCA9554_InputReg;

typedef union _TCA9554_OutputReg
{
    uint8_t    all;
    bitwise_t  bit;
} TCA9554_OutputReg;

typedef union _TCA9554_PolarityReg
{
    uint8_t    all;
    bitwise_t  bit;
} TCA9554_PolarityReg;

typedef union _TCA9554_ConfigReg
{
    uint8_t    all;
    bitwise_t  bit;
} TCA9554_ConfigReg;



#endif // TCA9554_H
