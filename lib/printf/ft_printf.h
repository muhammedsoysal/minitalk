/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musoysal <musoysal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:44:43 by musoysal          #+#    #+#             */
/*   Updated: 2024/11/09 14:14:33 by musoysal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     FT_PRINTF_H
# define    FT_PRINTF_H

# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_ptrptr(void *ptr);
int	ft_putstr(char *str);
int	ft_putnbr(int nbr);
int	ft_putchar(int c);
int	ft_puthex(unsigned long long nbr, int uppercase);
int	ft_putunsigned(unsigned int nbr);
int	ft_format(va_list arg, char format);

#endif