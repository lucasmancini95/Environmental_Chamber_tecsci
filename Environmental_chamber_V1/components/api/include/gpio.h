#ifndef _GPIO_H_
#define _GPIO_H_
#include <stdbool.h>
typedef enum {GPIO_OUTPUT_OPC=0 , GPIO_INPUT_OPC=1} GPIO_IO_OPC_t;

bool tmc_gpio_config(int pin, int config);
bool tmc_gpio_write(int pin, bool value);
bool tmc_gpio_read(int pin);
void task_gpio_test(void *ignore);

#endif
