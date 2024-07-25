/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anschmit <anschmit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:02:53 by anschmit          #+#    #+#             */
/*   Updated: 2024/07/11 13:17:37 by anschmit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sendsignal(pid_t pid, unsigned char letter)
{
	int				i;
	unsigned char	temp_letter;

	i = 8;
	temp_letter = letter;
	while (i-- > 0)
	{
		temp_letter = letter >> i;
		if (temp_letter % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(70);
	}
}

int	main(int argc, char **argv)
{
	pid_t		pid;
	int			i;
	const char	*message;

	i = 0;
	message = argv[2];
	if (argc != 3)
		ft_printf("[ERR0R]. Too many or too few arguments.");
	pid = ft_atoi(argv[1]);
	while (message[i])
		ft_sendsignal(pid, message[i++]);
	ft_sendsignal(pid, '\n');
	return (0);
}
