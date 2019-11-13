#include <stdio.h>
#include "tinysh.h"


putchar_handler_t putcharHandler = NULL;


void tinysh_set_putchar(putchar_handler_t handler){
	putcharHandler = handler;
}

void tinysh_char_out( char c)
{
	if(NULL != putcharHandler){
		putcharHandler(c);
	}
}

/*AGREGADO ---> Seteo de comandos , inicializacion y HandlerConsolePutchar*/

void HandlerConsolePutchar( char c){
	putchar(c);
}

void tinysh_init() {


	tinysh_set_putchar(HandlerConsolePutchar);

	//	set_cbreak(0);
}

void tinysh_finish() {
//	unset_cbreak(0);
}

