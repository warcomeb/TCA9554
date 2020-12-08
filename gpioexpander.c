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

#include "gpioexpander.h"
#include "TCA9554.h"

static inline uint8_t __attribute__((always_inline)) getAddress (GPIOExpander_Pins_t pin)
{
    if (pin == 0xFFFFFFFF)
    {
        ohiassert(0);
        return 0;
    }

    switch ((pin & GPIOEXPANDER_DEVICE_MASK) >> 16)
    {
    case TCA9554_ADDRESS_0x20:
        return 0x20;
    case TCA9554_ADDRESS_0x21:
        return 0x21;
    case TCA9554_ADDRESS_0x22:
        return 0x22;
    case TCA9554_ADDRESS_0x23:
        return 0x23;
    case TCA9554_ADDRESS_0x24:
        return 0x24;
    case TCA9554_ADDRESS_0x25:
        return 0x25;
    case TCA9554_ADDRESS_0x26:
        return 0x26;
    case TCA9554_ADDRESS_0x27:
        return 0x27;
    default:
        ohiassert(0);
        return 0;
    }
}

static inline uint8_t __attribute__((always_inline)) getPin (GPIOExpander_Pins_t pin)
{
    if (pin == 0xFFFFFFFF)
    {
        ohiassert(0);
        return 0;
    }

    return ((uint8_t)(pin & GPIOEXPANDER_PINS_MASK));
}

GPIOExpander_Device_t GPIOExpander_init (GPIOExpander_LowLevelDriver_t dev)
{
    GPIOExpander_Device_t device = {0};
    device.device = (Iic_DeviceHandle)dev;

    return device;
}

GPIOExpander_Errors_t GPIOExpander_set (GPIOExpander_DeviceHandle_t dev, GPIOExpander_Pins_t pin)
{
    if (dev == null)
    {
        ohiassert(0);
        return GPIOEXPANDER_ERRORS_WRONG_DEVICE;
    }

    uint8_t address = getAddress(pin);
    uint8_t devPin  = getPin(pin);
    if ((address != 0) && (devPin != 0))
    {
        // Write register...
        GPIOExpander_Errors_t ret = TCA9554_writeOutput(dev->device,address,value);
        return ret;
    }
    return GPIOEXPANDER_ERRORS_WRONG_PARAMS;
}
