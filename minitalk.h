/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anschmit <anschmit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:53:08 by anschmit          #+#    #+#             */
/*   Updated: 2024/07/01 14:26:03 by anschmit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "/home/anschmit/done/libft/libft.h"
# include <signal.h>

void		ft_sendsignal(pid_t pid, unsigned char letter);
void		ft_handle_signal(int signal);

#endif