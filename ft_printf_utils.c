/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:26:47 by arowe             #+#    #+#             */
/*   Updated: 2021/10/26 17:26:59 by arowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printc(int c)
{
	char	ch;

	ch = (char)c;
	write(1, &ch, 1);
	return (1);
}

int	ft_prints(char *s)
{
	if (!s)
		return (ft_printf("(null)"));
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	ft_printp(void *p)
{
	long long	d;
	char		*hex;

	d = (long long)p;
	hex = ft_dec_to_hex(d);
	write(1, hex, ft_strlen(hex));
	free(hex);
	return (ft_strlen(hex));
}