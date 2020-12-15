#ifndef _H_SHELL
#define _H_SHELL


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>


typedef struct args_s
{
    char* arg;
    struct args_s *next;
} args_t;

args_t *add(args_t **head, char* arg);
size_t print(args_t *head);
char **transform(args_t **head);


#define UNUSED(x) (void)(x);

#endif /* _H_SHELL */ 