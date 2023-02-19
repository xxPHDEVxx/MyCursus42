/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenaiss <rbenaiss@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 00:12:18 by rbenaiss          #+#    #+#             */
/*   Updated: 2023/02/19 00:35:56 by rbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// print numbers 

void	ft_printnb(int number, int *length)
{
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*length) += 11;
		return ;
	}
	if (number < 0)
	{
		ft_putchar_plus('-', length);
		ft_printnb(number * -1, length);
	}
	else
	{
		if (number > 9)
			ft_printnb(number / 10, length);
		ft_putchar_plus(number % 10 + '0', length);
	}
}

/*
	Print a pointer in hexadecimal form using "base_character"
	to find each pointer's digit and adding the prefix "0x".
	The function creates a string to store the hexa digits 
	and initialize a pointer "base_character".
	If the pointer is equal to 0, the function simply prints a '0'.
	Updates length.
*/

void	ft_pointer(size_t pointer, int *length)
{
	char	adress[25];
	int		i;
	char	*base_character;

	base_character = "0123456789abcdef";
	i = 0;
	write(1, "0x", 2);
	(*length) += 2;
	if (pointer == 0)
	{
		ft_putchar_plus('0', length);
		return ;
	}
	while (pointer != 0)
	{
		adress[i] = base_character[pointer % 16];
		pointer = pointer / 16;
		i++;
	}
	while (i--)
	{
		ft_putchar_plus(adress[i], length);
	}
}

/*
	This function converts an unsigned integer 
	into a string representing its value in base 16.
	The result is stored in a character array.
	The function also takes into account the case(low or up).
	If the number is zero, the function simply prints a '0'.
	The length of the generated character string
	is stored in a pointer passed as an argument.
*/

void	ft_hex(unsigned int x, int *length, char uppercase)
{
	char	hex[25];
	char	*base_character;
	int		i;

	if (uppercase == 'X')
		base_character = "0123456789ABCDEF";
	else
		base_character = "0123456789abcdef";
	i = 0;
	if (x == 0)
	{
		ft_putchar_plus('0', length);
		return ;
	}
	while (x != 0)
	{
		hex[i] = base_character [x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
		ft_putchar_plus(hex[i], length);
}

/*
	print unsigned numbers using recursivity
*/

void	ft_unsigned_int(unsigned int nb, int *length)
{
	if (nb >= 10)
		ft_unsigned_int(nb / 10, length);
	ft_putchar_plus(nb % 10 + '0', length);
}
