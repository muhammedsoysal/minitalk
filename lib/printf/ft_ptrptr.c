/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musoysal <musoysal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:20:47 by musoysal          #+#    #+#             */
/*   Updated: 2024/11/09 14:41:57 by musoysal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrptr(void *ptr)
{
	unsigned long long	address;
	int					count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = 0;
	address = (unsigned long long)ptr;
	count += ft_putstr("0x");
	count += ft_puthex(address, 0);
	return (count);
}
