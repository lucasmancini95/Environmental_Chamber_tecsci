#ifndef _HUMIDIFIER_H_
#define _HUMIDIFIER_H_
#define HUMIDIFIER_GPIO_PIN 5

#include "custom_bool.h"

cbool_t humidifier_init();
cbool_t humidifier_low();
cbool_t humidifier_high();

#endif
