#include "hsh.h"
char **transform(args_t **head)
{

    int i;
    args_t *h = *head;
    char **arguments;
    
    for (i = 0; h; i++)
        h = h->next;
    arguments = malloc((i + 1) * sizeof(char *));
    h = *head;
    for (i = 0; h; i++, h = h->next)
        arguments[i] = h->arg;

    arguments[i] = NULL;

    return (arguments);
}