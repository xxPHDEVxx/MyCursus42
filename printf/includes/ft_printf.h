/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenaiss <rbenaiss@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 00:11:46 by rbenaiss          #+#    #+#             */
/*   Updated: 2023/02/19 00:39:02 by rbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

void			ft_printnb(int number, int *length);
void			ft_hex(unsigned int x, int *length, char uppercase);
void			ft_unsigned_int(unsigned int nb, int *length);
void			ft_pointer(size_t pointer, int *length);
void			ft_putchar_plus(char c, int *length);
void			ft_read(char *args, int *length);
int				ft_printf(const char *string, ...);

#endif
