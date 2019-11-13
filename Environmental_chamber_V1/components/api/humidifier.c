#include "humidifier.h"

#include <stdio.h>
#include <stdint.h>
#include "gpio.h"
#include "custom_bool.h"

cbool_t humidifier_init(){
  cbool_t ret_state;
  GPIO_IO_OPC_t gpio_output_config=GPIO_OUTPUT_OPC;

  ret_state=tmc_gpio_config(HUMIDIFIER_GPIO_PIN, (int)gpio_output_config);

  if(ret_state == cTRUE){
    tmc_gpio_write(HUMIDIFIER_GPIO_PIN, 0); //LOw as initial state
    printf("Humidifier successfully initialized\n");
    return cTRUE;
  }

  return cFALSE;

}

cbool_t humidifier_low(){


  cbool_t ret_state;
  ret_state=tmc_gpio_write(HUMIDIFIER_GPIO_PIN, 0); //0 == LOW state

  printf("Humidifier low\n");
  return ret_state;
}

cbool_t humidifier_high(){

  cbool_t ret_state;
  ret_state=tmc_gpio_write(HUMIDIFIER_GPIO_PIN, 1); //1 == HIGH state

  printf("Humidifier high\n");
  return ret_state;

}
