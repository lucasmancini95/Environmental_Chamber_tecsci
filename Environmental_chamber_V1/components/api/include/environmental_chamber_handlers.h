#ifndef _ENVIRONMENTAL_CHAMBER_HANDLERS_H_
#define _ENVIRONMENTAL_CHAMBER_HANDLERS_H_

#include <stdio.h>
#include <stdint.h>
#include "custom_bool.h"
#include "environmental_chamber_monitor.h"

void Handler_EnvironmentalChamberRunProcess(cbool_t rh_activate,cbool_t temp_activate, double targetRH, double targeTemp);
void Handler_EnvironmentalChamberStopProcess();
void Handler_EnvironmentalChamberMonitor(double* p_actual_RH,double* p_actual_TEMP,chamberRunState_t* p_RH_state, chamberRunState_t* p_TEMP_state);

#endif
