/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:58:07 by arowe             #+#    #+#             */
/*   Updated: 2021/10/26 15:59:18 by arowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printf(const char *s, ...)
{
	int 	i;
	int		print_amount;
	va_list args;

	i = 0;
	print_amount = 0;
	va_start(args, s);
	while (s[i])
	{
		while (s[i] != '%' && s[i])
		{
			write(1, &s[i++], 1);
			print_amount++;
		}
		if (!s[i])
			break;
		if (s[i + 1] == 'c')
			print_amount += ft_printc(va_arg(args, int));
		else if (s[i + 1] == 's')
			print_amount += ft_prints(va_arg(args, char*));
		else if (s[i + 1] == 'p')
			print_amount += ft_printp(va_arg(args, unsigned long));
		else if (s[i + 1] == 'd' || s[i + 1] == 'i')
			print_amount += ft_printdi(va_arg(args, int));
		else if (s[i + 1] == 'u')
			print_amount += ft_printu(va_arg(args, unsigned int));
		else if (s[i + 1] == 'x' || s[i + 1] == 'X')
			print_amount += ft_printx(va_arg(args, unsigned int), s[i + 1]);
		else if (s[i + 1] == '%')
		{
			write(1, "%", 1);
			print_amount++;
		}
		i += 2;
	}
	va_end(args);
	return (print_amount);
}