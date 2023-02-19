/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenaiss <rbenaiss@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 00:53:26 by rbenaiss          #+#    #+#             */
/*   Updated: 2023/02/19 00:53:48 by rbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

//      Display a character and update length counter 

void	ft_putchar_plus(char c, int *length)
{
	write(1, &c, 1);
	(*length)++;
}

/*
        Display a string(args) by using the function ft_putchar_plus.
        Check if the string is null and display "(null)" 
        or display the string if it's not.
        Update length counter.  
*/

void	ft_read(char *args, int *length)
{
	size_t	i;

	i = 0;
	if (!args)
	{
		write(1, "(null)", 6);
		(*length) += 6;
		return ;
	}
	while (args[i] != '\0')
	{
		ft_putchar_plus(args[i], length);
		i++;
	}
}
