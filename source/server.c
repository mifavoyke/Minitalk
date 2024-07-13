/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhusieva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:18:59 by yhusieva          #+#    #+#             */
/*   Updated: 2023/06/28 18:19:01 by yhusieva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile struct s_sig_data g_data = {0, 0};

void handle_sigusr(int sig)
{
    if (sig == SIGUSR1)
    {
        g_data.character = g_data.character << 1;
    }
    else if (sig == SIGUSR2)
    {
        g_data.character = (g_data.character << 1) | 1;
    }
    g_data.bit_count++;

    if (g_data.bit_count == 8)
    {
        write(STDOUT_FILENO, (const void*)&g_data.character, 1);
        g_data.bit_count = 0;
        g_data.character = 0;
    }
}

void setup_handlers(void)
{
    struct sigaction sa;

    sa.sa_handler = handle_sigusr;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGUSR1, &sa, NULL) == -1)
    {
        write(STDOUT_FILENO, "Error sigaction SIGUSR1\n", 25);
        exit(1);
    }

    if (sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        write(STDOUT_FILENO, "Error sigaction SIGUSR2\n", 25);
        exit(1);
    }
}

int main(void)
{
    pid_t pid;

    pid = getpid();
    if (pid == -1)
    {
        ft_printf("Invalid PID.\n");
        return (1);
    }

    setup_handlers();

    ft_printf("PID: %d\n", pid);
    while (1)
        pause();

    return (0);
}
