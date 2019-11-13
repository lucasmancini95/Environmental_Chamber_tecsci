
/*Handler to LOAD the standard process */
#include <stdio.h>

#include "tinysh.h"
#include "app_main.h"

#include "environmental_chamber_process.h"
#include "environmental_chamber_monitor.h"
#include "environmental_chamber_Control.h"

#include "lwip/err.h"
#include "lwip/sockets.h"
#include "lwip/sys.h"
#include <lwip/netdb.h>

extern environmental_chamber_t environmentalChamber;
extern QueueHandle_t xQueue_Environmental_Chamber_Monitor;


/*ENVIRONMENTAL CHAMBER HANDLERS*/
void CommandINITENVIRONMENTALCHAMBERHandler(int argc, char **argv){
  printf("\r\n");
	if (1 == argc) {
    EnvironmentalChamberInit(&environmentalChamber);
  }
}


void CommandRUNENVIRONMENTALCHAMBERHandler(int argc, char **argv){
  printf("\r\n");
	if (1 == argc) {
    EnvironmentalChamberRun(&environmentalChamber);
  }
}

void CommandSTOPENVIRONMENTALCHAMBERHandler(int argc, char **argv){
  printf("\r\n");
	if (1 == argc) {
    EnvironmentalChamberStop(&environmentalChamber);
  }
}

void CommandSETRHHandler(int argc, char **argv) {
	printf("\r\n");
	if (2 == argc) {
		EnvironmentalChamberSetRH(&environmentalChamber,
				(uint8_t) tinysh_get_arg_int(argc, argv, 1));
	}
}
void CommandSETTEMPHandler(int argc, char **argv) {
	printf("\r\n");
	if (2 == argc) {
		EnvironmentalChamberSetTemp(&environmentalChamber,
				(uint8_t) tinysh_get_arg_int(argc, argv, 1));
	}
}
void CommandACTIVATEENVIRONMENTALCHAMBERHandler(int argc, char **argv) {
	printf("\r\n");
	if (1 == argc) {
		EnvironmentalChamberActivateRH(&environmentalChamber);
		//EnvironmentalChamberActivateTemp(&environmentalChamber);
	}
}
void CommandDEACTIVATEENVIRONMENTALCHAMBERHandler(int argc, char **argv) {
	printf("\r\n");
	if (1 == argc) {
		EnvironmentalChamberDeactivateRH(&environmentalChamber);
		//EnvironmentalChamberDeactivateTemp(&environmentalChamber);
	}
}

void CommandMONITORENVIRONMENTALCHAMBERHandler(int argc, char **argv){
	unsigned char test='C';
	printf("\r\n");

	environmental_chamber_monitor_data_t data;
	data.actualRH=0x33;
	data.actualTemp=0x33;
	data.RH_control_state=CHAMBER_STOPPED;
	data.TEMP_control_state=CHAMBER_STOPPED;
	data.targetRH=environmentalChamber.targetRH;
	data.targetTemp=environmentalChamber.targetTemp;

	if (1 == argc) {
			EnvironmentalChamberMonitor(&environmentalChamber);
			if (xQueueReceive( xQueue_Environmental_Chamber_Monitor, &data, portMAX_DELAY) == pdTRUE ){
					 printf("datos a transmitir por socket:\n RH= %f \n state: %d \n",data.actualRH,(int)data.RH_control_state);
					 	send(sock_global, &test, sizeof(unsigned char), 0);
			}
	}
}
