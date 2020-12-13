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

#include "TCA9554.h"

#define TCA9554_VALID_PIN(PIN) (((PIN) == TCA9554_PINS_0)  || \
                                ((PIN) == TCA9554_PINS_1)  || \
                                ((PIN) == TCA9554_PINS_2)  || \
                                ((PIN) == TCA9554_PINS_3)  || \
                                ((PIN) == TCA9554_PINS_4)  || \
                                ((PIN) == TCA9554_PINS_5)  || \
                                ((PIN) == TCA9554_PINS_6)  || \
                                ((PIN) == TCA9554_PINS_7))

TCA9554_Errors_t TCA9554_writeOutput (Iic_DeviceHandle dev,
                                      uint8_t address,
                                      TCA9554_Pins_t pin,
                                      Gpio_Level level)
{
    if (dev != nullptr)
    {
        if (!TCA9554_VALID_PIN(pin))
        {
            return TCA9554_ERRORS_WRONG_PIN;
        }

        uint8_t actual = 0;
        System_Errors err = Iic_readRegister(dev,
                                             address,
                                             TCA9554_REGISTER_OUTPUT,
                                             IIC_REGISTERADDRESSSIZE_8BIT,
                                             &actual,
                                             1,
                                             100);

        if (level == GPIO_HIGH)
        {
            actual |= pin;
        }
        else
        {
            actual &= (~pin);
        }

        err = Iic_writeRegister(dev,
                                address,
                                TCA9554_REGISTER_OUTPUT,
                                IIC_REGISTERADDRESSSIZE_8BIT,
                                &actual,
                                1,
                                100);
        if (err == ERRORS_NO_ERROR)
        {
            return TCA9554_ERRORS_NO_ERROR;
        }
        return TCA9554_ERRORS_COMMUNICATION_FAIL;
    }
    else
    {
        return TCA9554_ERRORS_NO_DEVICE;
    }
}

TCA9554_Errors_t TCA9554_readInput (Iic_DeviceHandle dev,
                                    uint8_t address,
                                    TCA9554_Pins_t pin,
                                    Gpio_Level* value)
{
    if (dev != nullptr)
    {
        if (!TCA9554_VALID_PIN(pin))
        {
            return TCA9554_ERRORS_WRONG_PIN;
        }

        uint8_t actual = 0;
        System_Errors err = Iic_readRegister(dev,
                                             address,
                                             TCA9554_REGISTER_INPUT,
                                             IIC_REGISTERADDRESSSIZE_8BIT,
                                             &actual,
                                             1,
                                             100);

        if ((actual & pin) == pin)
        {
            *value = GPIO_HIGH;
        }
        else
        {
            *value = GPIO_LOW;
        }

        if (err == ERRORS_NO_ERROR)
        {
            return TCA9554_ERRORS_NO_ERROR;
        }
        return TCA9554_ERRORS_COMMUNICATION_FAIL;
    }
    else
    {
        return TCA9554_ERRORS_NO_DEVICE;
    }
}

TCA9554_Errors_t TCA9554_config (Iic_DeviceHandle dev,
                                 uint8_t address,
                                 TCA9554_Pins_t pin,
                                 uint8_t value)
{
    if (dev != nullptr)
    {
        if (!TCA9554_VALID_PIN(pin))
        {
            return TCA9554_ERRORS_WRONG_PIN;
        }

        uint8_t actual = 0;
        System_Errors err = Iic_readRegister(dev,
                                             address,
                                             TCA9554_REGISTER_CONFIG,
                                             IIC_REGISTERADDRESSSIZE_8BIT,
                                             &actual,
                                             1,
                                             100);

        if (value > 0) // input
        {
            actual |= pin;
        }
        else // output
        {
            actual &= (~pin);
        }

        err = Iic_writeRegister(dev,
                                address,
                                TCA9554_REGISTER_CONFIG,
                                IIC_REGISTERADDRESSSIZE_8BIT,
                                &actual,
                                1,
                                100);
        if (err == ERRORS_NO_ERROR)
        {
            return TCA9554_ERRORS_NO_ERROR;
        }
        return TCA9554_ERRORS_COMMUNICATION_FAIL;
    }
    else
    {
        return TCA9554_ERRORS_NO_DEVICE;
    }
}
