/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenaiss <rbenaiss@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:37:07 by rbenaiss          #+#    #+#             */
/*   Updated: 2023/02/10 21:11:35 by rbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

/**
 * Allocates (with malloc(3)) and returns a string representing the integer
 * received as an argument.Negative numbers must be handled.
 * Returns the string representing the integer or NULL if the allocation fails.
**/

static int	ft_lennum(long num)
{
	int	strlen;

	strlen = 0;
	if (num == 0)
		return (1);
	else if (num < 0)
	{
		strlen++;
		num *= -1;
	}
	while (num > 0)
	{
		num /= 10;
		strlen++;
	}
	return (strlen);
}

char	*ft_itoa(int n)
{
	int		lenstr;
	long	num;
	char	*str;

	num = n;
	lenstr = ft_lennum(num);
	str = (char *)malloc(sizeof(char) * (lenstr + 1));
	if (!str)
		return (NULL);
	*(str + lenstr--) = '\0';
	if (num == 0)
	{
		*(str + 0) = '0';
	}
	else if (num < 0)
	{
		num *= -1;
		*(str + 0) = '-';
	}
	while (num > 0)
	{
		*(str + lenstr--) = (48 + (num % 10));
		num /= 10;
	}
	return (str);
}
