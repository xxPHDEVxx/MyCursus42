/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenaiss <rbenaiss@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 00:12:06 by rbenaiss          #+#    #+#             */
/*   Updated: 2023/02/24 13:00:14 by rbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
	The function checks the character s and calls a specific function 
	depending on the requested format.
	If the character s does not correspond to any of the specified output formats, 
	the i variable is decremented to come back again in the loop and print this
	character as an commun one.
*/

static void	ft_search(char s, va_list *args, int *len, int *i)
{
	if (s == 's')
		ft_read(va_arg(*args, char *), len);
	else if (s == 'd' || s == 'i')
		ft_printnb(va_arg(*args, int), len);
	else if (s == 'u')
		ft_unsigned_int(va_arg(*args, unsigned int), len);
	else if (s == 'x')
		ft_hex(va_arg(*args, unsigned int), len, 'x');
	else if (s == 'X')
		ft_hex(va_arg(*args, unsigned int), len, 'X');
	else if (s == 'p')
		ft_pointer(va_arg(*args, unsigned long long), len);
	else if (s == 'c')
		ft_putchar_plus(va_arg(*args, int), len);
	else if (s == '%')
		ft_putchar_plus('%', len);
	else
		(*i)--;
}

/*
	Takes a format string and a variable number of arguments(args). 
	The function initializes a va_list to hold the variable arguments
	i 	= variable to keep track of the position.
	length  = the length of the output.

	Allows the use of format specifiers in the format string 
	to print variable arguments in a specific format.	
*/

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			ft_search(string[i], &args, &length, &i);
			i++;
		}
		else
		{
			ft_putchar_plus((char)string[i], &length);
			i++;
		}
	}
	va_end(args);
	return (length);
}
