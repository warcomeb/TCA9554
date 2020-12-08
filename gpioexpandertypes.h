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

#ifndef WARCOMEB_GPIOEXPANDER_TYPES_H
#define WARCOMEB_GPIOEXPANDER_TYPES_H

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
    GPIOEXPANDER_ERRORS_WRONG_DEVICE,
    GPIOEXPANDER_ERRORS_WRONG_PARAMS,
} GPIOExpander_Errors_t;


typedef enum _GPIOExpander_Pins_t
{
    GPIOEXPANDER_PINS_1_1 = 0x00010001,
    GPIOEXPANDER_PINS_1_2 = 0x00010002,
    GPIOEXPANDER_PINS_1_3 = 0x00010004,
    GPIOEXPANDER_PINS_1_4 = 0x00010008,
    GPIOEXPANDER_PINS_1_5 = 0x00010010,
    GPIOEXPANDER_PINS_1_6 = 0x00010020,
    GPIOEXPANDER_PINS_1_7 = 0x00010040,
    GPIOEXPANDER_PINS_1_8 = 0x00010080,


    GPIOEXPANDER_PINS_NONE = 0xFFFFFFFF,
} GPIOExpander_Pins_t;

#define GPIOEXPANDER_DEVICE_MASK                 0x00FF0000
#define GPIOEXPANDER_PINS_MASK                   0x000000FF

/*!
 * GPIO Expander device class.
 */
typedef struct _GPIOExpander_Device_t
{
    Iic_DeviceHandle device;

} GPIOExpander_Device_t, *GPIOExpander_DeviceHandle_t;

#ifdef __cplusplus
}
#endif

#endif // WARCOMEB_GPIOEXPANDER_TYPES_H
