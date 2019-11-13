#ifndef _TINYSH_CUSTOM_
#define _TINYSH_CUSTOM_

typedef void (*putchar_handler_t)(char c);
void tinysh_set_putchar(putchar_handler_t handler);
void tinysh_init();
void tinysh_finish();

#endif /* _TINYSH_CUSTOM_ */
