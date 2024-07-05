#include "minitalk.h"

void process_string(char *arg_string, pid_t pid)
{
    int i;
    int j;
    char c;

    i = 0;
    while (arg_string[i])
    {
        c = arg_string[i];
        j = 0;
        while (j < 8)
        {
            if (c & (1 << (7 - j)))
                kill(pid, SIGUSR2);
            else
                kill(pid, SIGUSR1);
            usleep(1000);
            j++;
        }
        i++;
    }
}

int main(int argc, char *argv[])
{
    pid_t pid;

    if (argc != 3)
    {
        ft_printf("Check the arguments.\n");
        return (1);
    }

    pid = (pid_t)ft_atoi(argv[1]);

    if (pid <= 0)
    {
        ft_printf("Invalid PID.\n");
        return (1);
    }

    process_string(argv[2], pid);

    return (0);
}