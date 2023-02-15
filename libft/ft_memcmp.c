/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenaiss <rbenaiss@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:22:47 by rbenaiss          #+#    #+#             */
/*   Updated: 2023/01/20 21:43:45 by rbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)s1 + i)
			== *((unsigned char *)s2 + i))
			i++;
		else
			return ((*((unsigned char *)s1 + i))
				- *((unsigned char *)s2 + i));
	}
	return (0);
}
