/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 02:01:34 by suhkim            #+#    #+#             */
/*   Updated: 2022/09/30 02:49:34 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	print_signal(int signo)
{
	static int	eight_bits;
	static int	char_ans;

	if (signo == SIGUSR1)
		char_ans |= (1 << eight_bits);
	eight_bits++;
	if (eight_bits == 8)
	{
		write(1, &char_ans, 1);
		eight_bits = 0;
		char_ans = 0;
	}
}

int	main(void)
{
	int		server_pid;

	server_pid = getpid();
	write(1, "server pid : ", 11);
	print_pid(server_pid);
	write(1, "\n", 1);
	signal(SIGUSR1, print_signal);
	signal(SIGUSR2, print_signal);
	while (1)
	{
		pause();
	}
	return (0);
}