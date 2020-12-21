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

/*!
 * \defgroup GPIOExpander_Core
 * \ingroup TCA9554
 * \{
 */

/*!
 * The function initialize the GPIO expander library.
 *
 * \param[in] dev: The low level peripheral, in this case a I2C handle.
 * \return An handle to manage the GPIO expander.
 */
GPIOExpander_Device_t GPIOExpander_init (GPIOExpander_LowLevelDriver_t dev);

/*!
 *
 */
GPIOExpander_Errors_t GPIOExpander_config (GPIOExpander_DeviceHandle_t dev, GPIOExpander_Pins_t pin, GPIOExpander_Type_t type);

/*!
 * The function set a high-level in output of the selected pin.
 *
 * \param[in] dev: The handle to manage the device.
 * \param[in] pin: The selected pin.
 * \return The function can return:
 *     \retval GPIOEXPANDER_ERRORS_NO_ERROR in case of no-error,
 *     \retval GPIOEXPANDER_ERRORS_COMMUNICATION_FAIL in case the bus-communication doesn't work,
 *     \retval GPIOEXPANDER_ERRORS_WRONG_PARAMS in case some params are not correct,
 *     \retval GPIOEXPANDER_ERRORS_WRONG_DEVICE in case of the device handle is not valid.
 */
GPIOExpander_Errors_t GPIOExpander_set (GPIOExpander_DeviceHandle_t dev, GPIOExpander_Pins_t pin);

/*!
 * The function set a low-level in output of the selected pin.
 *
 * \param[in] dev: The handle to manage the device.
 * \param[in] pin: The selected pin.
 * \return The function can return:
 *     \retval GPIOEXPANDER_ERRORS_NO_ERROR in case of no-error,
 *     \retval GPIOEXPANDER_ERRORS_COMMUNICATION_FAIL in case the bus-communication doesn't work,
 *     \retval GPIOEXPANDER_ERRORS_WRONG_PARAMS in case some params are not correct,
 *     \retval GPIOEXPANDER_ERRORS_WRONG_DEVICE in case of the device handle is not valid.
 */
GPIOExpander_Errors_t GPIOExpander_clear (GPIOExpander_DeviceHandle_t dev, GPIOExpander_Pins_t pin);

/*!
 * The function toggle the level in output of the selected pin.
 *
 * \param[in] dev: The handle to manage the device.
 * \param[in] pin: The selected pin.
 * \return The function can return:
 *     \retval GPIOEXPANDER_ERRORS_NO_ERROR in case of no-error,
 *     \retval GPIOEXPANDER_ERRORS_COMMUNICATION_FAIL in case the bus-communication doesn't work,
 *     \retval GPIOEXPANDER_ERRORS_WRONG_PARAMS in case some params are not correct,
 *     \retval GPIOEXPANDER_ERRORS_WRONG_DEVICE in case of the device handle is not valid.
 */
GPIOExpander_Errors_t GPIOExpander_toggle (GPIOExpander_DeviceHandle_t dev, GPIOExpander_Pins_t pin);

/*!
 * The function read the level in input of the selected pin.
 *
 * \param[in]    dev: The handle to manage the device.
 * \param[in]    pin: The selected pin.
 * \param[out] level: The value read from the selected pin.
 * \return The function can return:
 *     \retval GPIOEXPANDER_ERRORS_NO_ERROR in case of no-error,
 *     \retval GPIOEXPANDER_ERRORS_COMMUNICATION_FAIL in case the bus-communication doesn't work,
 *     \retval GPIOEXPANDER_ERRORS_WRONG_PARAMS in case some params are not correct,
 *     \retval GPIOEXPANDER_ERRORS_WRONG_DEVICE in case of the device handle is not valid.
 */
GPIOExpander_Errors_t GPIOExpander_get (GPIOExpander_DeviceHandle_t dev, GPIOExpander_Pins_t pin, Gpio_Level* level);

/*!
 * \}
 */

#ifdef __cplusplus
}
#endif

#endif // WARCOMEB_GPIOEXPANDER_H
