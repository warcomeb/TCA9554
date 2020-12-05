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


#ifndef GPIOEXPANDER_TYPES_H
#define GPIOEXPANDER_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __NO_PROFILES
#include "board.h"
#include "firmware.h"
#endif

typedef void* GPIOExpander_LowLevelDriver_t;

/*!
 * List of possible errors.
 */
typedef enum _GPIOExpander_Errors_t
{
    GPIOEXPANDER_ERRORS_NO_ERROR = 0,
} GPIOExpander_Errors_t;


typedef enum _GPIOExpander_Pins_t
{
    GPIO_EXPANDER_PINS_1 = 0x0001,
    GPIO_EXPANDER_PINS_2 = 0x0002,
    GPIO_EXPANDER_PINS_3 = 0x0004,
    GPIO_EXPANDER_PINS_4 = 0x0008,
    GPIO_EXPANDER_PINS_5 = 0x0010,
    GPIO_EXPANDER_PINS_6 = 0x0020,
    GPIO_EXPANDER_PINS_7 = 0x0040,
    GPIO_EXPANDER_PINS_8 = 0x0080,
} GPIOExpander_Pins_t;


#ifdef __cplusplus
}
#endif

#endif // GPIOEXPANDER_TYPES_H
