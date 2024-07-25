/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anschmit <anschmit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:03:06 by anschmit          #+#    #+#             */
/*   Updated: 2024/07/01 16:52:45 by anschmit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handle_signal(int signal)
{
	static unsigned char	current_byte;
	static int				bit_position;

	if (signal == SIGUSR1)
		current_byte |= (1 << (7 - bit_position));
	bit_position++;
	if (bit_position == 8)
	{
		if (current_byte == '\0')
			ft_printf("\n");
		else
		{
			ft_printf("%c", current_byte);
			bit_position = 0;
			current_byte = 0;
		}
	}
}

int	main(void)
{
	struct sigaction	signal_recieved;

	ft_printf("The process ID is %d\n", getpid());
	signal_recieved.sa_handler = ft_handle_signal;
	signal_recieved.sa_flags = 0;
	sigaction(SIGUSR1, &signal_recieved, NULL);
	sigaction(SIGUSR2, &signal_recieved, NULL);
	while (1)
		pause();
	return (0);
}
