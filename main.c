#include "hsh.h"


int main(int argc, char **argv, char **env)
{
    UNUSED(argc); 
    UNUSED(argv);
    UNUSED(env);


    pid_t pid;
    int read, tty = 1, ret = 0, status = 0; 
    char *line = NULL, *cpy = NULL, *arg = NULL, **args = NULL;
    size_t len = 0;
    args_t *arguments = NULL;

    isatty(STDIN_FILENO) == 0 ? tty = 0 : tty;


    do {
        /* read */

        tty == 1 ? write(STDOUT_FILENO, "($) ", 4) : tty;
        fflush(stdin);
        read = getline(&line, &len, stdin);
        if(read == -1)
            return (-1);

        /* Parse */

        cpy = strdup(line); 

        for (; (arg = strtok(cpy, " \t\n")); cpy = NULL, add(&arguments, arg)) 
            if(arg == NULL)
                break;
        args = transform(&arguments);
        
        /* execute */ 


        pid = fork();
        if(pid == -1)
            return (-1);
        else if(pid == 0)
        {
            ret = execve(args[0], args, env);
            if (ret == -1)
                return -1;
        }
        else {  
            wait(&status);
        }


        /* clean */

        deleteArgs(arguments),free(line), free(args), free(cpy);
        arguments = NULL;
        
    }while(1);

    return (0);
}