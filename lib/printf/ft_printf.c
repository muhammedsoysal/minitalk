/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musoysal <musoysal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:48:06 by musoysal          #+#    #+#             */
/*   Updated: 2024/11/09 14:14:04 by musoysal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list arg, char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(arg, int));
	else if (format == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (format == 'i' || format == 'd')
		count += ft_putnbr(va_arg(arg, int));
	else if (format == 'u')
		count += ft_putunsigned(va_arg(arg, unsigned int));
	else if (format == 'p')
		count += ft_ptrptr(va_arg(arg, void *));
	else if (format == 'x')
		count += ft_puthex(va_arg(arg, unsigned int), 0);
	else if (format == 'X')
		count += ft_puthex(va_arg(arg, unsigned int), 1);
	else if (format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_format(arg, str[i]);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (count);
}
