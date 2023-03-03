/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenaiss <rbenaiss@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:41:37 by rbenaiss          #+#    #+#             */
/*   Updated: 2023/03/03 23:01:40 by rbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

/*
 * Convert String to integer
*/
static int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}

/*
 * Sends a binary character  
 * as SIGUSR1 and SIGUSR2 signals
 * to the process identified by "pid".
*/

void	send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

/*
 * sends a binary message to a process
 * identified by its PID using signals.
 * It takes two input arguments:
 * the PID of the process and a string
 * representing the binary message. 
 * The code loops through each character in the string,
 * uses a function to send each binary character
 * to the process identified by the PID
*/

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			send_char(pid, argv[2][i]);
			i++;
		}
	}
	else
	{
		ft_printf("error detected\n");
		return (1);
	}
	return (0);
}
