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

/*!
 * \defgroup GPIOExpander_Type
 * \ingroup TCA9554
 * \{
 */

/*!
 *
 */
typedef void* GPIOExpander_LowLevelDriver_t;

/*!
 * List of possible errors.
 */
typedef enum _GPIOExpander_Errors_t
{
    GPIOEXPANDER_ERRORS_NO_ERROR = 0,
    GPIOEXPANDER_ERRORS_NO_DEVICE,
    GPIOEXPANDER_ERRORS_WRONG_DEVICE,
    GPIOEXPANDER_ERRORS_WRONG_PARAMS,
    GPIOEXPANDER_ERRORS_COMMUNICATION_FAIL,
} GPIOExpander_Errors_t;

/*!
 * List of all possible pins based on eight address of this device.
 */
typedef enum _GPIOExpander_Pins_t
{
    // Address 0x20
    GPIOEXPANDER_PINS_1_1  = 0x00010000,
    GPIOEXPANDER_PINS_1_2  = 0x00010001,
    GPIOEXPANDER_PINS_1_3  = 0x00010002,
    GPIOEXPANDER_PINS_1_4  = 0x00010003,
    GPIOEXPANDER_PINS_1_5  = 0x00010004,
    GPIOEXPANDER_PINS_1_6  = 0x00010005,
    GPIOEXPANDER_PINS_1_7  = 0x00010006,
    GPIOEXPANDER_PINS_1_8  = 0x00010007,
    // Address 0x21
    GPIOEXPANDER_PINS_2_1  = 0x00020000,
    GPIOEXPANDER_PINS_2_2  = 0x00020001,
    GPIOEXPANDER_PINS_2_3  = 0x00020002,
    GPIOEXPANDER_PINS_2_4  = 0x00020003,
    GPIOEXPANDER_PINS_2_5  = 0x00020004,
    GPIOEXPANDER_PINS_2_6  = 0x00020005,
    GPIOEXPANDER_PINS_2_7  = 0x00020006,
    GPIOEXPANDER_PINS_2_8  = 0x00020007,
    // Address 0x22
    GPIOEXPANDER_PINS_3_1  = 0x00040000,
    GPIOEXPANDER_PINS_3_2  = 0x00040001,
    GPIOEXPANDER_PINS_3_3  = 0x00040002,
    GPIOEXPANDER_PINS_3_4  = 0x00040003,
    GPIOEXPANDER_PINS_3_5  = 0x00040004,
    GPIOEXPANDER_PINS_3_6  = 0x00040005,
    GPIOEXPANDER_PINS_3_7  = 0x00040006,
    GPIOEXPANDER_PINS_3_8  = 0x00040007,
    // Address 0x23
    GPIOEXPANDER_PINS_4_1  = 0x00080000,
    GPIOEXPANDER_PINS_4_2  = 0x00080001,
    GPIOEXPANDER_PINS_4_3  = 0x00080002,
    GPIOEXPANDER_PINS_4_4  = 0x00080003,
    GPIOEXPANDER_PINS_4_5  = 0x00080004,
    GPIOEXPANDER_PINS_4_6  = 0x00080005,
    GPIOEXPANDER_PINS_4_7  = 0x00080006,
    GPIOEXPANDER_PINS_4_8  = 0x00080007,
    // Address 0x24
    GPIOEXPANDER_PINS_5_1  = 0x00100000,
    GPIOEXPANDER_PINS_5_2  = 0x00100001,
    GPIOEXPANDER_PINS_5_3  = 0x00100002,
    GPIOEXPANDER_PINS_5_4  = 0x00100003,
    GPIOEXPANDER_PINS_5_5  = 0x00100004,
    GPIOEXPANDER_PINS_5_6  = 0x00100005,
    GPIOEXPANDER_PINS_5_7  = 0x00100006,
    GPIOEXPANDER_PINS_5_8  = 0x00100007,
    // Address 0x25
    GPIOEXPANDER_PINS_6_1  = 0x00200000,
    GPIOEXPANDER_PINS_6_2  = 0x00200001,
    GPIOEXPANDER_PINS_6_3  = 0x00200002,
    GPIOEXPANDER_PINS_6_4  = 0x00200003,
    GPIOEXPANDER_PINS_6_5  = 0x00200004,
    GPIOEXPANDER_PINS_6_6  = 0x00200005,
    GPIOEXPANDER_PINS_6_7  = 0x00200006,
    GPIOEXPANDER_PINS_6_8  = 0x00200007,
    // Address 0x26
    GPIOEXPANDER_PINS_7_1  = 0x00400000,
    GPIOEXPANDER_PINS_7_2  = 0x00400001,
    GPIOEXPANDER_PINS_7_3  = 0x00400002,
    GPIOEXPANDER_PINS_7_4  = 0x00400003,
    GPIOEXPANDER_PINS_7_5  = 0x00400004,
    GPIOEXPANDER_PINS_7_6  = 0x00400005,
    GPIOEXPANDER_PINS_7_7  = 0x00400006,
    GPIOEXPANDER_PINS_7_8  = 0x00400007,
    // Address 0x27
    GPIOEXPANDER_PINS_8_1  = 0x00800000,
    GPIOEXPANDER_PINS_8_2  = 0x00800001,
    GPIOEXPANDER_PINS_8_3  = 0x00800002,
    GPIOEXPANDER_PINS_8_4  = 0x00800003,
    GPIOEXPANDER_PINS_8_5  = 0x00800004,
    GPIOEXPANDER_PINS_8_6  = 0x00800005,
    GPIOEXPANDER_PINS_8_7  = 0x00800006,
    GPIOEXPANDER_PINS_8_8  = 0x00800007,

    GPIOEXPANDER_PINS_NONE = 0xFFFFFFFF,
} GPIOExpander_Pins_t;

/*!
 *
 */
typedef enum _GPIOExpander_Type_t
{
    GPIOEXPANDER_TYPE_OUTPUT = 0,
    GPIOEXPANDER_TYPE_INPUT  = 1,
} GPIOExpander_Type_t;

#define GPIOEXPANDER_DEVICE_MASK                 0x00FF0000
#define GPIOEXPANDER_PINS_MASK                   0x000000FF

/*!
 * GPIO Expander device class.
 */
typedef struct _GPIOExpander_Device_t
{
    Iic_DeviceHandle device;

} GPIOExpander_Device_t, *GPIOExpander_DeviceHandle_t;

/*!
 * \}
 */

#ifdef __cplusplus
}
#endif

#endif // WARCOMEB_GPIOEXPANDER_TYPES_H
