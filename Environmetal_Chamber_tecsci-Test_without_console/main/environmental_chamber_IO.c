// #include "enviromental_chamber_IO.h"
//
// #include "sensor.h"
// #include "dryer.h"
// #include "humidifier.h"
//
//
// double v_input_RH[VECTOR_INPUT_SIZE];
// double v_output_RH[VECTOR_OUTPUT_SIZE];
//
//
// void task_Fill_Input_Vector(){ //fills the input vector with the data from the
//   int i=0;
//
//   while (1) {
//     //Semaforo de activacion{
//
//     for (i = 0; i < VECTOR_INPUT_SIZE; i++) {
//         v_input_RH[i]= get_actual_average_RH( bme280_1, s32 com_rslt_1, s32 v_uncomp_humidity_s32_1);
//         vTaskDelay(INPUT_VECTOR_FILLING_TIME_MS/portTICK_PERIOD_MS); // cambiar por el que es no bloqueante
//     }
//   }
// }
//
// void task_Fill_Output_Vector(){
//   int i=0;
//
//   while (1) {
//     //COla de activacion que tiene el dato si se quiere que en el
//
//     for (i = 0; i < VECTOR_INPUT_SIZE; i++) {
//         v_output_RH[i]=
//         vTaskDelay(OUTPUT_VECTOR_FILLING_TIME_MS/portTICK_PERIOD_MS); // cambiar por el que es no bloqueante
//     }
//   }
//
// }
//
// void Get_Input_Vector(double* pvec){
//   //se copia en *pvec el contenido de v_input
// }
//
//
// void Get_Output_Vector(double* pvec){
//   //se copia en *pvec el contenido de v_output
//
// }
