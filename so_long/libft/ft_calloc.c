/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenaiss <rbenaiss@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:17:28 by rbenaiss          #+#    #+#             */
/*   Updated: 2023/02/10 17:58:10 by rbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 allocate memory and initialize all the bytes at 0
 count = number of element
 size  = size of each element
*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*buffer;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	buffer = (void *)malloc(count * size);
	if (buffer == NULL)
		return (NULL);
	ft_bzero(buffer, count * size);
	return (buffer);
}
