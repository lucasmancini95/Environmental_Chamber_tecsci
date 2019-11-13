#include "gpio.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"

bool tmc_gpio_config(int pin, int config) {
	esp_err_t ret;
	gpio_config_t io_conf;

  //bit mask of the pins that you want to set,e.g.GPIO18/19
  io_conf.pin_bit_mask = (1ULL<<pin); //GPIO_OUTPUT_PIN_SEL/GPIO_INPUT_PIN_SEL;

	//set as output or input mode
	if(config == 0){
			io_conf.mode = GPIO_MODE_OUTPUT;
	}
	else if(config == 1){
			io_conf.mode = 	GPIO_MODE_INPUT;
	}

  //disable the functions we are not using
	io_conf.intr_type = GPIO_PIN_INTR_DISABLE; 	//disable interrupt
	io_conf.pull_down_en = 0;	//disable pull-down mode
	io_conf.pull_up_en = 0;	//disable pull-up mode

	ret= gpio_config(&io_conf); //configure GPIO with the given settings

	if(ret == ESP_OK){
		return pdTRUE;
	}
	else if(ret == ESP_ERR_INVALID_ARG){
		return pdFALSE;
	}
  return pdFALSE;
}

bool tmc_gpio_write(int pin, bool value) {
	esp_err_t ret;
	ret=gpio_set_level((gpio_num_t)pin, value);

	if(ret == ESP_OK){
		return pdTRUE;
	}
	else if(ret == ESP_ERR_INVALID_ARG){
		return pdFALSE;
	}
  return pdFALSE;
}

bool tmc_gpio_read(int pin) {
	return (bool)gpio_get_level((gpio_num_t)pin);
}

void task_gpio_test(void *ignore){

  int example_pin_1=18;
  int example_pin_2=5;
  int example_pin_3=19;

  GPIO_IO_OPC_t io_example_1=GPIO_OUTPUT_OPC;
  GPIO_IO_OPC_t io_example_2=GPIO_OUTPUT_OPC;
  GPIO_IO_OPC_t io_example_3=GPIO_INPUT_OPC;
  int cnt = 0;

  //GPIO pin Configuration
  tmc_gpio_config(example_pin_1, (int)io_example_1);
  tmc_gpio_config(example_pin_2, (int)io_example_2);
  tmc_gpio_config(example_pin_3, (int)io_example_3);


  //print of initial read
  printf("initial read state %d\n", tmc_gpio_read(example_pin_3));

  //example_pin_2 in HIGH state to use in the test --> doing a shortcut between: example_pin_2 & example_pin_3
  tmc_gpio_write(example_pin_2, 1);



  while(1) {
    /*Here we have a blink with the LOW state of example_pin_3 (with a counting)
    and just a message with a delay for the HIGH state*/
      if(tmc_gpio_read(example_pin_3)==0){
        printf("Reading: LOW\n");
        printf("cnt: %d\n", cnt++);
        tmc_gpio_write(example_pin_1, 1);
        vTaskDelay(1000 / portTICK_RATE_MS);
        tmc_gpio_write(example_pin_1, 0);
        vTaskDelay(1000 / portTICK_RATE_MS);
      }
      else if (tmc_gpio_read(example_pin_3)==1) {
        printf("Reading: HIGH\n");
        vTaskDelay(1000 / portTICK_RATE_MS);
      }
  }
}
