/*
 * lis3mdl.c
 *
 *  Created on: 8 июн. 2023 г.
 *      Author: plantator
 */

#include "lis3mdl.h"
#include <string.h>
const uint8_t LIS3MDL_REGs_ADDR_conf [LIS3MDL_SEQUENCE_SIZE] = {
	LIS3MDL_CTRL_REG1,
	LIS3MDL_CTRL_REG2,
};

/*
 * configuration parameters
 */
const uint8_t LIS3MDL_REGs_VAL_conf [LIS3MDL_SEQUENCE_SIZE-1] = {
	0x1U,
	/*
	 * Reg ctrl_reg1;
	 * Setted params: self-test enable
	 */
	0x2CU,
	/*
	 * Reg ctrl_reg2;
	 * Setted params: boot is 1 (reboot memory), reset configuration registers
	 */
};

/*
 * @brief  Write generic device register (platform dependent)
 *
 * @param  handle    customizable argument. In this examples is used in
 *                   order to select the correct sensor bus handler.
 * @param  reg       register to write
 * @param  bufp      pointer to data to write in register reg
 * @param  len       number of consecutive register to write
 *
 */
int32_t lis3mdl_write(void *handle, uint8_t reg, const uint8_t *bufp,
                              uint16_t len)
{
	halstatus = HAL_I2C_Mem_Write(handle, LIS3MDL_I2C_ADD_L, reg,
	                  I2C_MEMADD_SIZE_8BIT, (uint8_t*) bufp, len, 1000);
	if(halstatus != HAL_OK){
			return -1;
		}
		return 0;
}

/*
 * @brief  Read generic device register (platform dependent)
 *
 * @param  handle    customizable argument. In this examples is used in
 *                   order to select the correct sensor bus handler.
 * @param  reg       register to read
 * @param  bufp      pointer to buffer that store the data read
 * @param  len       number of consecutive register to read
 *
 */
int32_t lis3mdl_read(void *handle, uint8_t reg, uint8_t *bufp,
                             uint16_t len)
{
	halstatus = HAL_I2C_Mem_Read(handle, LIS3MDL_I2C_ADD_L, reg,
	                   I2C_MEMADD_SIZE_8BIT, bufp, len, 1000);
	if(halstatus != HAL_OK){
		return -1;
	}
	return 0;
}
/*
 * @brief Configure device
 *
 * @param handle    		customizable argument. In this examples is used in
 *                   		order to select the correct sensor bus handler.
 * @param regs 				pointer to regs array to write specific data
 * @param data				pointer to data that contains specific data
 * @param platform_write 	pointer to function that write data through i2c
 * @param platform_read 	pointer to function that read data through i2c
 *
 */
int32_t configure_lis3mdl(void *handle, stmdev_ctx_t *dev_ctx)
{
	dev_ctx->write_reg = lis3mdl_write;
	dev_ctx->read_reg = lis3mdl_read;
	dev_ctx->handle = handle;

	uint8_t who_iam;
	lis3mdl_device_id_get(dev_ctx, &who_iam);
	if(who_iam != LIS3MDL_ID){
		return -1;
	}

	int32_t ret;
	for(int i = 0; i < LIS3MDL_SEQUENCE_SIZE; i++){
		ret = dev_ctx->write_reg(handle, LIS3MDL_REGs_ADDR_conf[i], LIS3MDL_REGs_VAL_conf + i, 1);
		if(ret != 0)
		{
			return ret;
		}
	}
	return 0;
}

/*
 * @brief Read  data from device
 *
 * @param dev_ctx    		device structure
 * @param mag_data 			magnetic data
 *
 */
int32_t read_mag_data(stmdev_ctx_t *dev_ctx, float* mag_data)
{
	int32_t ret;
	int16_t raw_mag_data[3];
	memset(raw_mag_data, 0x00, 3 * sizeof(int16_t));
	ret = lis3mdl_magnetic_raw_get(dev_ctx, raw_mag_data);
	if(ret == 0){
		for(int i = 0; i<3; i++)
		{
			mag_data[i] = 1000 * lis3mdl_from_fs16_to_gauss(raw_mag_data[i]);
		}
	}
	return ret;
}
