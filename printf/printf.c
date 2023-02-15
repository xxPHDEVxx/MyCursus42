/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:15:31 by rbenaiss          #+#    #+#             */
/*   Updated: 2023/02/13 19:55:53 by rbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

const char	research(va_list arguments, const char format, t_content content)
{
	int	d;

	if (format == 'd')
	{
		d = va_arg(arguments,int);
		ft_putchar
	}
}

const char	reading(t_content content, const char format)
{
	char	*next;	

	next = ft_strchr(format);
	if (next)
		content -> width = next - format;
	else
		content -> width = ft_strlen(format);
	write (1, format, content -> width);
	content -> len += content -> width;
	while (*format && *format != '%')
		++format;
	return (format);
}

int	ft_printf(const char *format, ...)
{
	va_list		arguments;
	t_content	content;

	va_start(arguments, format);
	content.len = 0;
	content.width = 0;
	while (*format)
	{
		if (*format == '%')
			format = research(arguments, format + 1, &content);
		else
			format = reading(&content, format);
		if (!format)
		{
			write(1, "(null)", 6);
		}
	}
	va_end(arguments);
	return (content.len);
}
