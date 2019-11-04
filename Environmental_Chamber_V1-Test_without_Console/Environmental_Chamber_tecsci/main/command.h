/*
 * command.h
 *
 *  Created on: 7 oct. 2019
 *      Author: martin
 */

#ifndef COMPONENTS_API_INCLUDE_COMMAND_H_
#define COMPONENTS_API_INCLUDE_COMMAND_H_





/*Handler to LOAD the standard process */
void CommandLOADPROGRAMSTANDARDHandler(int argc, char **argv);

/*Handler to set up the LOOP COMMAND of the process standard
 1 arguments must be passed: N corresponding to the number of repetitions of the DWUW cycle  */
void CommandSETSTANDARDPROGRAMHandler(int argc, char **argv);
/*PROCESS CUSTOM HANDLERS*/

/*Handler to LOAD the custom process,
 the process it should have been set up before (if there is no set up the standard parameters will be loaded)  */
void CommandLOADPROGRAMCUSTOMHandler(int argc, char **argv);
/*Handler to set up a single command of the custom Process
 4 arguments must be passed: command number (see manual), velocity, acceleration and the test parameter */
void CommandSETCOMMANDCUSTOMPROGRAMHandler(int argc, char **argv);/*Handler to set up a all commands of the custom Process
 30 arguments must be passed: the 3 parameters for each command in increasing order
 obs: for the LOOP comand it must be passed 3 parameters,
 but only the first one will be used the other two will be discarded
  */
void CommandSETALLCUSTOMPROGRAMHandler(int argc, char **argv);
/*PROCESS DINAMIC HANDLERS*/

void CommandLOADPROGRAMDINAMICHandler(int argc, char **argv);
/*Handler to add and set all the dinamic program
 * the arguments can be up to 129, in groups of 4:
 * 	comand number, velocity acceleration and test*/
void CommandADDSETALLCOMANDDINAMICHandler(int argc, char **argv);/*Handler to Clean all the dinamic program*/
void CommandCLEANPROGRAMDINAMICHandler(int argc, char **argv);/*RUN PROCESS HANDLER*/

/*Handler to RUn the LOADED process,
 * turn on the RUN flag to RUN*/
void CommandRUNHandler(int argc, char **argv);/*SINGLE MOVEMENT HANDLERS*/
/*this tiny handlers only call the corresponding process function*/
void CommandUPFASTHandler(int argc, char **argv);
void CommandUPHandler(int argc, char **argv);
void CommandUPSLOWHandler(int argc, char **argv);
void CommandDOWNFASTHandler(int argc, char **argv);
void CommandDOWNHandler(int argc, char **argv);
void CommandDOWNSLOWHandler(int argc, char **argv);
void CommandSTOPHandler(int argc, char **argv);
/*CONFIGURATION HANDLERS*/
void commandSAMPLEHandler(int argc, char **argv);
void commandRECIPIENTMHandler(int argc, char **argv);

/*ENVIROMENTAL CHAMBER HANDLERS*/
void CommandSETRHHandler(int argc, char **argv);
void CommandSETTEMPHandler(int argc, char **argv);
void CommandACTIVATEENVIROMENTALCHAMBERHandler(int argc, char **argv);
void CommandDEACTIVATEENVIROMENTALCHAMBERHandler(int argc, char **argv);
void CommandMONITORENVIROMENTALCHAMBERHandler(int argc, char **argv);


#endif /* COMPONENTS_API_INCLUDE_COMMAND_H_ */
