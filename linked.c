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

    node->arg = arg;
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
void deleteArgs(args_t *head)
{
	args_t *node, *next;

	node = head;

	while (node != NULL)
	{
		next = node->next;
		free(node->arg);
		free(node);
		node = next;
	}
	head = NULL;
}