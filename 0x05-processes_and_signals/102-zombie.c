#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int infinite_while(void)
{
    while (1)
    {
        sleep(1);
    }
    return (0);
}

int main(void)
{
    pid_t zombie_pid;
    int i;

    for (i = 0; i < 5; i++)
    {
        zombie_pid = fork();

        if (zombie_pid > 0)
        {
            // the parent process
            printf("Zombie process created, PID: %d\n", zombie_pid);
        }
        else if (zombie_pid == 0)
        {
            // child process (zombie)
            exit(0);
        }
        else
        {
            //  failed
            perror("Fork failed");
            exit(1);
        }
    }

    // The parent process runs the infinite_while function
    infinite_while();

    return (0);
}
