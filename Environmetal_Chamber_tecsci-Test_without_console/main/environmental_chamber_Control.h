#ifndef _ENVIRONMENTAL_CHAMBER_CONTROL_H_
#define _ENVIRONMENTAL_CHAMBER_CONTROL_H_

#include "environmental_chamber_monitor.h"

void init_control_tasks();

void task_RH_Control_SetPoint();
void enable_RH_Task(double targetRH);

void stop_RH_Task();

chamberRunState_t get_process_RH_state();
chamberRunState_t get_process_TEMP_state();

//for a future upgrade, not available in first version
void task_RH_Control_PID();
void task_TEMP_Control_SetPoint();
void task_TEMP_Control_PID();
void enable_TEMP_Task(double targetTEMP);


#endif
