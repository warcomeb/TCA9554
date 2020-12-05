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

#ifndef WARCOMEB_GPIOEXPANDER_H
#define WARCOMEB_GPIOEXPANDER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "gpioexpandertypes.h"

GPIOExpander_Device_t GPIOExpander_init (GPIOExpander_LowLevelDriver_t dev);

/*!
 *
 */
GPIOExpander_Errors_t GPIOExpander_config (GPIOExpander_DeviceHandle_t, GPIOExpander_Pins_t pin);

GPIOExpander_Errors_t GPIOExpander_set (GPIOExpander_DeviceHandle_t, GPIOExpander_Pins_t pin);

GPIOExpander_Errors_t GPIOExpander_clear (GPIOExpander_DeviceHandle_t, GPIOExpander_Pins_t pin);

GPIOExpander_Errors_t GPIOExpander_get (GPIOExpander_DeviceHandle_t, GPIOExpander_Pins_t pin, Gpio_Level* level);

#ifdef __cplusplus
}
#endif

#endif // WARCOMEB_GPIOEXPANDER_H
