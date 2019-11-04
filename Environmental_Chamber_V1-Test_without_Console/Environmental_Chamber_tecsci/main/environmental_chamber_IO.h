// #ifndef _ENVIRONMENTAL_CHAMBER_IO_H_
// #define _ENVIRONMENTAL_CHAMBER_IO_H_
//
// #define VECTOR_INPUT_SIZE 10
// #define VECTOR_OUTPUT_SIZE 10
// #define INPUT_VECTOR_FILLING_TIME_MS 500
// #define OUTPUT_VECTOR_FILLING_TIME_MS 500
//
//
// void task_Fill_Input_Vector();
// void task_Fill_Output_Vector();
// void Get_Input_Vector();
// void Get_Output_Vector();
//
// #endif

/*
IMPORTANTE:

esta parte del programa pondria una capa mas de abstraccion, donde los datos de entrada del sensor
se cargan antes en un vector para que despues la parte de control logico acceda
a los datos por ahi
en cuanto a los "datos" del estado necesario de los actuadores tambien se usa un vector de salida
donde se carga el estado de salida para que luegi los actuadores (gpio) actuaen tomando los
datos de ahi.

*/
