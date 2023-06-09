/*
 * i3g4250d.h
 *
 *  Created on: 8 июн. 2023 г.
 *      Author: plantator
 */

#ifndef SRC_I3G4250D_H_
#define SRC_I3G4250D_H_

#include "i3g4250d_reg.h"

#define I3G4250D_SEQUENCE_SIZE 6

/*
 * Device configuration registers address sequence
 */
extern const uint8_t I3G4250D_REGs_ADDR_conf[I3G4250D_SEQUENCE_SIZE];
/*
 * Device configuration registers values
 */
extern const uint8_t I3G4250D_REGs_VAL_conf[I3G4250D_SEQUENCE_SIZE];

int32_t configure_i3g4250d(void *handle, void* platform_write, void* platform_read);
int32_t read_gyroscope_data(stmdev_ctx_t *dev_ctx, int16_t* accel_data);

#endif /* SRC_I3G4250D_H_ */
