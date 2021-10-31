/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:27:56 by arowe             #+#    #+#             */
/*   Updated: 2021/10/26 18:27:58 by arowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char	*ft_dec_to_hex(long d)
{
	char	*hex;
	long	mod;
	long	temp;
	int		i;

	if (d < 0)
		d = 4294967295 + d;
	temp = d;
	i = 0;
	while (temp != 0)
	{
		temp /= 16;
		i++;
	}
	i += 2;
	hex = malloc(sizeof(char) * (i + 1));
	hex[0] = '0';
	hex[1] = 'x';
	if (d == 0)
	{
		hex[2] = '0';
		return (hex);
	}
	hex[i--] = '\0';
	while (i > 1 && d > 0)
	{
		mod = d % 16;
		if (mod < 10)
			hex[i] = mod + '0';
		else 
			hex[i] = mod + 'W';
		d /= 16;
		i--;
	}
	return (hex);
}