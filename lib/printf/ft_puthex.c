/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musoysal <musoysal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:21:11 by musoysal          #+#    #+#             */
/*   Updated: 2024/11/09 14:22:47 by musoysal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long long nbr, int uppercase)
{
	int		count;
	char	*hex_digits;

	if (uppercase)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	count = 0;
	if (nbr >= 16)
		count += ft_puthex(nbr / 16, uppercase);
	count += ft_putchar(hex_digits[nbr % 16]);
	return (count);
}
