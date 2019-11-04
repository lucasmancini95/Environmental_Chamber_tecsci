#ifndef _DRYER_H_
#define _DRYER_H_

#define DRYER_GPIO_PIN 18
#include "custom_bool.h"

cbool_t dryer_init();
cbool_t dryer_low();
cbool_t dryer_high();

#endif
