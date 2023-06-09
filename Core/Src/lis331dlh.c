/*
 * lis331dlh_conf.c
 *
 *  Created on: 7 июн. 2023 г.
 *      Author: plantator
 */
#include "lis331dlh.h"

#include <stdlib.h>

const uint8_t LIS331DLH_REGs_ADDR_conf [LIS331DLH_SEQUENCE_SIZE] = {
	LIS331DLH_CTRL_REG1,
	LIS331DLH_CTRL_REG2,
	LIS331DLH_CTRL_REG3,
	LIS331DLH_CTRL_REG4,
	LIS331DLH_REFERENCE,
	LIS331DLH_INT1_THS,
	LIS331DLH_INT1_DURATION,
	LIS331DLH_INT2_THS,
	LIS331DLH_INT2_DURATION,
	LIS331DLH_HP_FILTER_RESET, // read (if filter is enabled)
	LIS331DLH_INT1_CFG,
	LIS331DLH_INT2_CFG,
	LIS331DLH_CTRL_REG5
};

/*
 * configuration parameters
 */
const uint8_t LIS331DLH_REGs_VAL_conf [LIS331DLH_SEQUENCE_SIZE-1] = {
	0x2FU,
	/*
	 * Reg ctrl_reg1;
	 * Setted params: x, y, z acceleration, normal power mode, 100Hz output rate
	 */
	0x80U,
	/*
	 * Reg ctrl_reg2;
	 * Setted params: boot is 1 (reboot memory), other params is default
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
	0x0U,
	/*
	 * Reg Reference
	 * Setted params: default params
	 *
	 */
	0x0U,
	/*
	 * Reg int1_ths
	 * Setted params: default params
	 *
	 */
	0x0U,
	/*
	 * Reg int1_dur
	 * Setted params: default params
	 *
	 */
	0x0U,
	/*
	 * Reg int2_ths
	 * Setted params: default params
	 *
	 */
	0x0U,
	/*
	 * Reg int2_dur
	 * Setted params: default params
	 *
	 */
	0x0U,
	/*
	 * Reg int1_cfg
	 * Setted params: default params
	 *
	 */
	0x0U,
	/*
	 * Reg int2_cfg
	 * Setted params: default params
	 *
	 */
	0x0U
	/*
	 * Reg ctrl5_reg
	 * Setted params:
	 */
};

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
int32_t configure_lis331dlh(void *handle, void* platform_write, void* platform_read)
{
	stmdev_ctx_t dev_ctx;
	dev_ctx.write_reg = platform_write;
	dev_ctx.read_reg = platform_read;
	dev_ctx.handle = handle;

	uint8_t who_iam;
	lis331dlh_device_id_get(&dev_ctx, &who_iam);
	if(who_iam != LIS331DLH_ID){
		return -1;
	}

	int32_t ret;
	for(int i = 0; i < LIS331DLH_SEQUENCE_SIZE; i++){
		if(LIS331DLH_REGs_ADDR_conf[i] == LIS331DLH_HP_FILTER_RESET){
			uint8_t *empty_buff = (uint8_t*)malloc(sizeof(uint8_t));
			ret = dev_ctx.read_reg(handle, LIS331DLH_REGs_ADDR_conf[i], empty_buff, 1);
			free(empty_buff);
			if(ret != 0)
			{
				return ret;
			}
			continue;
		}
		ret = dev_ctx.write_reg(handle, LIS331DLH_REGs_ADDR_conf[i], LIS331DLH_REGs_VAL_conf + i, 1);
		if(ret != 0)
		{
			return ret;
		}
	}
	return 0;
}

/*
 * @brief Read accelerated data from device
 *
 * @param dev_ctx    		device structure
 * @param accel_data 		acceleration of device(x,y,z)
 *
 */
int32_t read_acceleration_data(stmdev_ctx_t *dev_ctx, int16_t* accel_data)
{
	lis331dlh_status_reg_t status_reg;
	lis331dlh_status_reg_get(dev_ctx, &status_reg);
	int32_t ret;
	while(1){
		if(status_reg.zyxda != 0)
			break;
	}
	ret = lis331dlh_acceleration_raw_get(dev_ctx, accel_data);

	return ret;
}