#ifndef _SENSOR_H_
#define _SENSOR_H_

#include "bme280.h"

#define SDA_PIN GPIO_NUM_15
#define SCL_PIN GPIO_NUM_2

#define TAG_BME280 "BME280"

#define I2C_MASTER_ACK 0
#define I2C_MASTER_NACK 1

//these parameters are only for the bme280 setpoint test
#define RH_SETPOINT 80
#define LOWER_LIM 2
#define UPPER_LIM 2

typedef struct{
  struct bme280_t bme280;
  s32 com_rslt;
  s32 v_uncomp_humidity_s32;
  s32 v_uncomp_pressure_s32;
  s32 v_uncomp_temperature_s32;
}sensor_t;


void sensor_RH_init();
void sensor_bme280_init(sensor_t* p_sensor_x, unsigned int address);
void i2c_master_init();

double get_actual_average_RH();
double get_actual_average_TEMP();
double get_actual_average_PSS();
double get_sensor_RH(sensor_t* p_sensor_x);
double get_sensor_TEMP(sensor_t* p_sensor_x);
double get_sensor_PSS(sensor_t* p_sensor_x);

s8 BME280_I2C_bus_write(u8 dev_addr, u8 reg_addr, u8 *reg_data, u8 cnt);
s8 BME280_I2C_bus_read(u8 dev_addr, u8 reg_addr, u8 *reg_data, u8 cnt);
void BME280_delay_msek(u32 msek);


void task_bme280_RH_set_point_test(void *ignore);
void task_bme280_normal_mode(void *ignore);
void task_bme280_forced_mode(void *ignore);

#endif
