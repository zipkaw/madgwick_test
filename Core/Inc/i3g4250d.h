/*
 * i3g4250d.h
 *
 *  Created on: 8 июн. 2023 г.
 *      Author: plantator
 */

#ifndef SRC_I3G4250D_H_
#define SRC_I3G4250D_H_

#include "stm32f4xx_hal.h"
#include "i3g4250d_reg.h"

#define I3G4250D_SEQUENCE_SIZE 6

static HAL_StatusTypeDef halstatus;
/*
 * Device configuration registers address sequence
 */
extern const uint8_t I3G4250D_REGs_ADDR_conf[I3G4250D_SEQUENCE_SIZE];
/*
 * Device configuration registers values
 */
extern const uint8_t I3G4250D_REGs_VAL_conf[I3G4250D_SEQUENCE_SIZE];

int32_t i3g4250d_write(void *handle, uint8_t reg, const uint8_t *bufp,uint16_t len);
int32_t i3g4250d_read(void *handle, uint8_t reg, uint8_t *bufp, uint16_t len);
int32_t configure_i3g4250d(void *handle, stmdev_ctx_t *dev_ctx);
int32_t read_gyroscope_data_fifo(stmdev_ctx_t *dev_ctx, float* accel_data);

#endif /* SRC_I3G4250D_H_ */
