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

#ifndef MINITALK_H
# define MINITALK_H

#include "./ft_printf/Include/ft_printf.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

struct s_sig_data {
    volatile sig_atomic_t bit_count;
    volatile sig_atomic_t character;
};

void handle_sigusr(int sig);
void setup_handlers(void);
void process_string(char *arg_string, pid_t pid);

int	ft_atoi(const char *nptr);

#endif
