/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenaiss <rbenaiss@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:41:42 by rbenaiss          #+#    #+#             */
/*   Updated: 2023/03/03 23:01:37 by rbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
/*
 * converts a series of binary signals into an ASCII character.
 * Each time a bit is received, it is stored in the "i" variable.
 * Once 8 bits have been received, the value of "i" is converted 
 * into an ASCII character and displayed. The function is used 
 * to receive binary data using Unix signals. (bitoa)
*/
void	bit_to_char(int signal)
{
	static int	bit;
	static int	character;

	if (signal == SIGUSR1)
		character |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", character);
		bit = 0;
		character = 0;
	}
}

/*
 * creates a program that listens to Unix signals SIGUSR1 and SIGUSR2
 * in order to receive binary data and convert it to ASCII characters.
 * It will output an error message and terminate if 
 * the number of arguments passed to the application is not 1.
 * The program will continue listening for signals until 
 * it is interrupted or terminated.
*/

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("error detected\n");
		return (1);
	}
	pid = getpid();
	ft_printf(" pid is : %d\n", pid);
	while (argc == 1)
	{
		signal(SIGUSR1, bit_to_char);
		signal(SIGUSR2, bit_to_char);
		pause ();
	}
	return (0);
}
