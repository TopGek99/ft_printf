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

char	*ft_dec_to_hex(unsigned long d, char c)
{
	char			*hex;
	unsigned long	mod;
	unsigned long	temp;
	int				i;

	temp = d;
	i = 0;
	while (temp > 0)
	{
		temp /= 16;
		i++;
	}
	hex = malloc(sizeof(char) * (i + 1));
	hex[i--] = '\0';
	while (i >= 0 && d > 0)
	{
		mod = d % 16;
		if (mod < 10)
			hex[i] = mod + '0';
		else if (c == 'X')
			hex[i] = mod + '7';
		else
			hex[i] = mod + 'W';
		d /= 16;
		i--;
	}
	return (hex);
}