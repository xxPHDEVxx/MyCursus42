/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenaiss <rbenaiss@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:37:25 by rbenaiss          #+#    #+#             */
/*   Updated: 2023/01/20 21:46:04 by rbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t		idx;

	idx = 0;
	while (idx < n)
	{
		*((unsigned char *)str + idx) = c;
		idx++;
	}
	return (str);
}
