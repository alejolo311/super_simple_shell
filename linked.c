#include "hsh.h"

args_t *add(args_t **head, char* arg)
{
    args_t *node,  *aux;

    aux = *head;

    if(arg == NULL)
    {
        return (NULL);
    }

    node = malloc(sizeof(args_t));

    if(node == NULL)
        return (NULL);

    node->arg = strdup(arg);
    node->next = NULL;

    if(*head == NULL)
    {
        *head = node;
        return (node);
    }

    while(aux->next)
        aux = aux->next;

    aux->next = node;

    return (aux);
}

size_t print(args_t *head)
{
    int i;

    for (i = 0; head; i++)
    {
        printf("argument -> {%s}\n", head->arg);
        head = head->next;
    }
        
    printf("number of args ->{%d}\n", i);
    return(i);
}

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