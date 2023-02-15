/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenaiss <rbenaiss@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:06:02 by phdev             #+#    #+#             */
/*   Updated: 2023/02/11 20:28:53 by rbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Allocates (with malloc(3)) and returns a substring from the string 's'
 * The substring begins at index 'start' and is of maximum size 'len'.
 *
 * - Parameters:
 * s: The string from which to create the substring.
 * start: The start index of the substring in the string 's'.
 * len: The maximum length of the substring.
 *
 * - Returnes the substring or NULL if the allocation fails.
**/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	if ((ft_strlen(s) - start) < len)
		res = (malloc(sizeof(char) * (ft_strlen(s) - start) + 1));
	else
		res = (malloc(sizeof(char) * (len) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len && s[start])
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}

/*my first function 
 * char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*dest;

	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (start >= ft_strlen(s))
			len = 0;
		dest = (char *)malloc(len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}*/
