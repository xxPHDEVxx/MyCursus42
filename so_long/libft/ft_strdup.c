/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenaiss <rbenaiss@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:18:37 by rbenaiss          #+#    #+#             */
/*   Updated: 2023/02/10 21:20:01 by rbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

/**
 *	The ft_strdup() function allocates sufficient memory for a copy of the
 *	string str, does the copy, and returns a pointer to it. The pointer
 *	may subsequently be used as an argument to the function free(3).
 *	If insufficient memory is available, NULL is returned.
**/

char	*ft_strdup(const char *str)
{
	size_t	i;
	size_t	length;
	char	*cpy;

	length = ft_strlen(str) + 1;
	cpy = (char *)malloc(length);
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < length)
	{
		*(cpy + i) = *(str + i);
		i++;
	}
	return (cpy);
}
