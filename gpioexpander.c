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

#define GPIOEXPANDER_PIN(x)                      (((1)<<(x & 0x0007)))

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

GPIOExpander_Errors_t GPIOExpander_config (GPIOExpander_DeviceHandle_t dev,
                                           GPIOExpander_Pins_t pin,
                                           GPIOExpander_Type_t type)
{
    if (dev == null)
    {
        ohiassert(0);
        return GPIOEXPANDER_ERRORS_WRONG_DEVICE;
    }

    uint8_t address = getAddress(pin);
    uint8_t pinNumber  = getPin(pin);
    if ((address != 0) && (pinNumber < TCA9554_PINS_NUMBER))
    {
        // Write register...
        uint8_t mypin = GPIOEXPANDER_PIN(pinNumber);
        TCA9554_Errors_t ret = TCA9554_config(dev->device,address,mypin,(uint8_t)type);

        if (ret != TCA9554_ERRORS_NO_ERROR)
        {
            return GPIOEXPANDER_ERRORS_COMMUNICATION_FAIL;
        }
        return GPIOEXPANDER_ERRORS_NO_ERROR;
    }
    return GPIOEXPANDER_ERRORS_WRONG_PARAMS;
}

GPIOExpander_Errors_t GPIOExpander_set (GPIOExpander_DeviceHandle_t dev, GPIOExpander_Pins_t pin)
{
    if (dev == null)
    {
        ohiassert(0);
        return GPIOEXPANDER_ERRORS_WRONG_DEVICE;
    }

    uint8_t address = getAddress(pin);
    uint8_t pinNumber  = getPin(pin);
    if ((address != 0) && (pinNumber < TCA9554_PINS_NUMBER))
    {
        // Write register...
        uint8_t mypin = GPIOEXPANDER_PIN(pinNumber);
        TCA9554_Errors_t ret = TCA9554_writeOutput(dev->device,address,mypin,GPIO_HIGH);

        if (ret != TCA9554_ERRORS_NO_ERROR)
        {
            return GPIOEXPANDER_ERRORS_COMMUNICATION_FAIL;
        }
        return GPIOEXPANDER_ERRORS_NO_ERROR;
    }
    return GPIOEXPANDER_ERRORS_WRONG_PARAMS;
}

GPIOExpander_Errors_t GPIOExpander_clear (GPIOExpander_DeviceHandle_t dev, GPIOExpander_Pins_t pin)
{
    if (dev == null)
    {
        ohiassert(0);
        return GPIOEXPANDER_ERRORS_WRONG_DEVICE;
    }

    uint8_t address = getAddress(pin);
    uint8_t pinNumber  = getPin(pin);
    if ((address != 0) && (pinNumber < TCA9554_PINS_NUMBER))
    {
        // Write register...
        uint8_t mypin = GPIOEXPANDER_PIN(pinNumber);
        TCA9554_Errors_t ret = TCA9554_writeOutput(dev->device,address,mypin,GPIO_LOW);

        if (ret != TCA9554_ERRORS_NO_ERROR)
        {
            return GPIOEXPANDER_ERRORS_COMMUNICATION_FAIL;
        }
        return GPIOEXPANDER_ERRORS_NO_ERROR;
    }
    return GPIOEXPANDER_ERRORS_WRONG_PARAMS;
}

GPIOExpander_Errors_t GPIOExpander_toggle (GPIOExpander_DeviceHandle_t dev, GPIOExpander_Pins_t pin)
{
    // TODO!
    return GPIOEXPANDER_ERRORS_NO_ERROR;
}

GPIOExpander_Errors_t GPIOExpander_get (GPIOExpander_DeviceHandle_t dev, GPIOExpander_Pins_t pin, Gpio_Level* level)
{
    if (dev == null)
    {
        ohiassert(0);
        return GPIOEXPANDER_ERRORS_WRONG_DEVICE;
    }

    uint8_t address = getAddress(pin);
    uint8_t pinNumber  = getPin(pin);
    if ((address != 0) && (pinNumber < TCA9554_PINS_NUMBER))
    {
        // Write register...
        uint8_t mypin = GPIOEXPANDER_PIN(pinNumber);
        Gpio_Level readValue = 0;
        TCA9554_Errors_t ret = TCA9554_readInput(dev->device,address,mypin,&readValue);
        if (ret != TCA9554_ERRORS_NO_ERROR)
        {
            return GPIOEXPANDER_ERRORS_COMMUNICATION_FAIL;
        }

        *level = readValue;

        return GPIOEXPANDER_ERRORS_NO_ERROR;
    }
    return GPIOEXPANDER_ERRORS_WRONG_PARAMS;
}
