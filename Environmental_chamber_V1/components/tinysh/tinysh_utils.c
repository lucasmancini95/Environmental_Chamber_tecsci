#include <stdio.h>
#include <stdlib.h>

#include "tinysh.h"

int tinysh_get_arg_int(const int argc, const char **argv, const int index) {
	int retval = 0;
	if (argc > index) {
		retval = atoi(argv[index]);
	}
	return retval;
}

float tinysh_get_arg_float(const int argc, const char **argv, const int index) {
	float retval = 0;
	if (argc > index) {
		retval = (float) atof(argv[index]);
	}
	return retval;
}

char* tinysh_get_arg_string(const int argc, const char **argv, const int index) {
////////////////////////// const char *string = 0;
	char *string = 0;
	if (argc > index) {
		string = argv[index];
	}
	return string;
}

int tinysh_get_arg_int_from_hex(const int argc, const char **argv, const int index) {
	int retval = 0;
	if (argc > index) {
#if 0 // TODO crosscompaibilizarlo
		sscanf(argv[index], "%x", &retval);
#endif
	}
	return retval;
}
