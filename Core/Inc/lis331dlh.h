/*
 * lis331dlh_conf.h
 *
 *  Created on: 7 июн. 2023 г.
 *      Author: plantator
 */

#ifndef SRC_LIS331DLH_H_
#define SRC_LIS331DLH_H_

#include "stm32f4xx_hal.h"
#include "lis331dlh_reg.h"

#define LIS331DLH_SEQUENCE_SIZE 13

static HAL_StatusTypeDef halstatus;
/*
 * Device configuration registers address sequence
 */
extern const uint8_t LIS331DLH_REGs_ADDR_conf[LIS331DLH_SEQUENCE_SIZE];
/*
 * Device configuration registers values
 */
extern const uint8_t LIS331DLH_REGs_VAL_conf[LIS331DLH_SEQUENCE_SIZE-1];

int32_t lis331dlh_write(void *handle, uint8_t reg, const uint8_t *bufp,uint16_t len);
int32_t lis331dlh_read(void *handle, uint8_t reg, uint8_t *bufp, uint16_t len);
int32_t configure_lis331dlh(void *handle);
int32_t read_acceleration_data(stmdev_ctx_t *dev_ctx, int16_t* accel_data);
#endif /* SRC_LIS331DLH_H_ */
