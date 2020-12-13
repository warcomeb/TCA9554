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

#ifndef WARCOMEB_TCA9554_H
#define WARCOMEB_TCA9554_H

#include "TCA9554types.h"

/*!
 *
 */
TCA9554_Errors_t TCA9554_config (Iic_DeviceHandle dev,
                                 uint8_t address,
                                 TCA9554_Pins_t pin,
                                 uint8_t value);

/*!
 *
 */
TCA9554_Errors_t TCA9554_writeOutput (Iic_DeviceHandle dev,
                                      uint8_t address,
                                      TCA9554_Pins_t value,
                                      Gpio_Level level);

/*!
 *
 */
TCA9554_Errors_t TCA9554_readInput (Iic_DeviceHandle dev,
                                    uint8_t address,
                                    TCA9554_Pins_t pin,
                                    Gpio_Level* value);

#endif // WARCOMEB_TCA9554_H
