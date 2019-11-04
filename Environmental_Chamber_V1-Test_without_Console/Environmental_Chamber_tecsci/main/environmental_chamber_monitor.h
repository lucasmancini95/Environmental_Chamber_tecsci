#ifndef _ENVIRONMENTAL_CHAMBER_MONITOR_H_
#define _ENVIRONMENTAL_CHAMBER_MONITOR_H_

typedef enum{CHAMBER_STOPPED=0,CHAMBER_HUMIDIFYING=1,CHAMBER_DRYINGUP=2,CHAMBER_HEATING=3,CHAMBER_COOLING=4} chamberRunState_t;

typedef struct{
	double actualRH;
	double actualTemp;
	chamberRunState_t RH_control_state;
	chamberRunState_t TEMP_control_state;
	double targetRH;
	double targetTemp;
}enviromental_chamber_monitor_data_t;

#endif
