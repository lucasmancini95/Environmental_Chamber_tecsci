#ifndef MAIN_APP_MAIN_H_
#define MAIN_APP_MAIN_H_

#include "command.h"

//#include "../environmental_chamber_process.h"
#include "environmental_chamber_process.h"
#include "environmental_chamber_monitor.h"
#include "protocol_examples_common.h"
#include "tinysh.h"

environmental_chamber_t environmentalChamber;
extern QueueHandle_t xQueue_Environmental_Chamber_Monitor;

int sock_global;

//void init(void);
//void deinit(void);
//void reset(void);
void app_main(void);

#endif /* MAIN_APP_MAIN_DIPCOATER_H_ */
