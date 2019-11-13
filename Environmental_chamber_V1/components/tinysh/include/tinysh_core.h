#ifndef _TINYSH_CORE_
#define _TINYSH_CORE_

typedef void (*tinysh_fnt_t)(int argc, char **argv);

typedef struct tinysh_cmd_t {
  struct tinysh_cmd_t *parent; /* 0 if top level command */
  char *name;                  /* command input name, not 0 */
  char *help;                  /* help string, can be 0 */
  char *usage;                 /* usage string, can be 0 */
  tinysh_fnt_t function;       /* function to launch on cmd, can be 0 */
  void *arg;                   /* current argument when function called */
  struct tinysh_cmd_t *next;   /* must be set to 0 at init */
  struct tinysh_cmd_t *child;  /* must be set to 0 at init */
} tinysh_cmd_t;

#ifdef __cplusplus
extern "C" {
#endif

/*
 * function void tinysh_char_out(unsigned char) must be provided by
 * the application
 */
void tinysh_char_out( char c);

/*
 * Functions below are provided by the tinysh module
 */

/* new character input */
void tinysh_char_in( char c);

/* add a new command */
void tinysh_add_command(tinysh_cmd_t *cmd);

/* change tinysh prompt */
void tinysh_set_prompt(char *str);

/* get command argument back */
void *tinysh_get_arg();

/* provide conversion string to scalar (decimal or hexadecimal) */
unsigned long tinysh_atoxi(char *s);

#ifdef __cplusplus
}
#endif

#endif /* _TINYSH_CORE_ */
