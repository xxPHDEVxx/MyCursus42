/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenaiss <rbenaiss@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:07:51 by rbenaiss          #+#    #+#             */
/*   Updated: 2023/01/21 21:19:26 by rbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		len;
	char	*sr;

	sr = (char *)str;
	len = ft_strlen(str);
	if (c == '\0')
		return (sr + len);
	while (len >= 0)
	{
		if (sr[len] == (char)c)
			return (sr + len);
		len--;
	}
	return (0);
}
