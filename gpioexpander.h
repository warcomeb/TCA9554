/*
 * ChristmasTree - Gadget 2020
 * Copyright (C) 2020 NOWAE <http://www.nowae.it>
 *
 * Author:
 *   Marco Giammarini <m.giammarini@warcomeb.it>
 */

#ifndef GPIOEXPANDER_H
#define GPIOEXPANDER_H

#include "gpioexpandertypes.h"

GPIOExpander_Errors_t GPIOExpander_init (void);

/*!
 *
 */
GPIOExpander_Errors_t GPIOExpander_config (GPIOExpander_DeviceHandle_t, GPIOExpander_Pins_t pin);

GPIOExpander_Errors_t GPIOExpander_set (GPIOExpander_DeviceHandle_t, GPIOExpander_Pins_t pin);

GPIOExpander_Errors_t GPIOExpander_clear (GPIOExpander_DeviceHandle_t, GPIOExpander_Pins_t pin);

GPIOExpander_Errors_t GPIOExpander_get (GPIOExpander_DeviceHandle_t, GPIOExpander_Pins_t pin, Gpio_Level* level);


#endif // GPIOEXPANDER_H
