/*
 * TCA9554types.h
 *
 *  Created on: Dec 5, 2020
 *      Author: warcomeb
 */

#ifndef WARCOMEB_TCA9554_TYPES_H
#define WARCOMEB_TCA9554_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __NO_PROFILES
#include "board.h"
#include "firmware.h"
#endif

/*!
 * TCA9554 device class.
 */
typedef struct _TCA9554_Device_t
{
    Iic_DeviceHandle device;

    uint8_t          address;

} TCA9554_Device_t, *TCA9554_DeviceHandle_t;


#ifdef __cplusplus
}
#endif

#endif // WARCOMEB_TCA9554_TYPES_H
