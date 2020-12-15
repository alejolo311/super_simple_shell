#ifndef _H_SHELL
#define _H_SHELL


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>
#include <stdbool.h>

/**
 * struct settings_s - settings for all the program
 * @file: file
 * @line: line
 * @stack: stack
 * @queue: false
 */
typedef struct path_s
{
    char* path;
    struct args_s *next;
} path_t;
/**
 * struct settings_s - settings for all the program
 * @file: file
 * @line: line
 * @stack: stack
 * @queue: false
 */
typedef struct args_s
{
    char* arg;
    struct args_s *next;
} args_t;

/**
 * struct settings_s - settings for all the program
 * @file: file
 * @line: line
 * @stack: stack
 * @queue: false
 */
typedef struct settings_s
{

    /* read */ 
	char *line;
    size_t len;
    int read;
    /* parse */ 
	args_t *arguments;
    path_t *path;
    /* execute */
    int _ret;
    /*general*/
	_Bool tty;
    int nrExcutedCommands;
} settings_t;

extern settings_t settings;

args_t *add(args_t **head, char* arg);
void deleteArgs(args_t *head);
char **transform(args_t **head);


#define UNUSED(x) (void)(x);

#endif /* _H_SHELL */ 