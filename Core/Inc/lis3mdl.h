/*
 * lis3mdl.h
 *
 *  Created on: 8 июн. 2023 г.
 *      Author: plantator
 */

#ifndef SRC_LIS3MDL_H_
#define SRC_LIS3MDL_H_

#define LIS3MDL_SEQUENCE_SIZE 3
#include "lis3mdl_reg.h"
/*
 * Device configuration registers address sequence
 */
extern const uint8_t LIS3MDL_REGs_ADDR_conf[LIS3MDL_SEQUENCE_SIZE];
/*
 * Device configuration registers values
 */
extern const uint8_t LIS3MDL_REGs_VAL_conf[LIS3MDL_SEQUENCE_SIZE-1];

int32_t configure_lis3mdl(void *handle, void* platform_write, void* platform_read);
int32_t read_mag_data(stmdev_ctx_t *dev_ctx, int16_t* mag_data);

#endif /* SRC_LIS3MDL_H_ */
