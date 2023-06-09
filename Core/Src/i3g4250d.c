/*
 * i3g4250d.c
 *
 *  Created on: 8 июн. 2023 г.
 *      Author: plantator
 */
#include "i3g4250d.h"

const uint8_t I3G4250D_REGs_ADDR_conf [I3G4250D_SEQUENCE_SIZE] = {
	I3G4250D_CTRL_REG1,
	I3G4250D_CTRL_REG2,
	I3G4250D_CTRL_REG3,
	I3G4250D_CTRL_REG4,
	I3G4250D_CTRL_REG5,
	I3G4250D_FIFO_CTRL_REG
};

/*
 * configuration parameters
 */
const uint8_t I3G4250D_REGs_VAL_conf [I3G4250D_SEQUENCE_SIZE] = {
	0xFU,
	/*
	 * Reg ctrl_reg1;
	 * Setted params: x, y, z gyro axes, normal power mode, 100Hz output rate
	 */
	0x0U,
	/*
	 * Reg ctrl_reg2;
	 * Setted params: default params
	 */
	0x0U,
	/*
	 * Reg ctrl_reg3
	 * Setted params: default params
	 *
	 */
	0x82U,
	/*
	 * Reg ctrl_reg4
	 * Setted param: BDU is 1, output registers not
	 * 				 updated between MSB and LSB reading.
	 * 				 Self-test enabled.
	 */
	0xC0U,
	/*
	 * Reg ctrl5_reg
	 * Setted params: Boot mode reboot, FIFO enabled
	 */
	0X2AU
	/*
	 * Reg fifo_cntrl_reg
	 * Setted params: watermark level is 10, fifo mode enabled
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
int32_t i3g4250d_write(void *handle, uint8_t reg, const uint8_t *bufp,
                              uint16_t len)
{

	halstatus = HAL_I2C_Mem_Write(handle, I3G4250D_I2C_ADD_L, reg,
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
int32_t i3g4250d_read(void *handle, uint8_t reg, uint8_t *bufp, uint16_t len)
{
	halstatus = HAL_I2C_Mem_Read(handle, I3G4250D_I2C_ADD_L, reg,
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
int32_t configure_i3g4250d(void *handle)
{
	stmdev_ctx_t dev_ctx;
	dev_ctx.write_reg = i3g4250d_write;
	dev_ctx.read_reg = i3g4250d_read;
	dev_ctx.handle = handle;

	uint8_t who_iam;
	i3g4250d_device_id_get(&dev_ctx, &who_iam);
	if(who_iam != I3G4250D_ID){
		return -1;
	}

	int32_t ret;
	for(int i = 0; i < I3G4250D_SEQUENCE_SIZE; i++){
		ret = dev_ctx.write_reg(handle, I3G4250D_REGs_ADDR_conf[i], I3G4250D_REGs_VAL_conf + i, 1);
		if(ret != 0)
		{
			return ret;
		}
	}
	return ret;
}

/*
 * @brief Read gyroscope data from device using fifo
 *
 * @param dev_ctx    		device structure
 * @param accel_data 		acceleration of device(x,y,z)
 *
 */
int32_t read_gyroscope_data_fifo(stmdev_ctx_t *dev_ctx, int16_t* gyro_data)
{
	 int ret = i3g4250d_angular_rate_raw_get(dev_ctx, gyro_data);
	 return ret;
}
