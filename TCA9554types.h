/*
 * TCA9554 - Library to manage TCA9554 GPIO expander based on libohiboard
 * Copyright (C) 2020 Marco Giammarini <http://www.warcomeb.it>
 *
 * Authors:
 *  Marco Giammarini <m.giammarini@warcomeb.it>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef WARCOMEB_TCA9554_TYPES_H
#define WARCOMEB_TCA9554_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __NO_PROFILES
#include "board.h"
#include "firmware.h"
#endif

#define TCA9554_REG_INPUT                        0x00
#define TCA9554_REG_OUTPUT                       0x01
#define TCA9554_REG_POLARITY                     0x02
#define TCA9554_REG_CONFIG                       0x03

typedef struct _bitwise_t
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

#ifdef __cplusplus
}
#endif

#endif // WARCOMEB_TCA9554_TYPES_H
