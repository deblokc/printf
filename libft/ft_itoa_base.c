/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:37:48 by tnaton            #+#    #+#             */
/*   Updated: 2022/06/16 17:10:01 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_size(unsigned long long nb, int len)
{
	int	i;

	if (!nb)
		return (1);
	i = 0;
	while (nb)
	{
		nb /= len;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(unsigned long long nb, char *base_to)
{
	char	*num;
	int		size;
	int		i;

	i = 1;
	size = ft_size(nb, ft_strlen(base_to));
	num = (char *)malloc(sizeof(char) * (size + 1));
	if (!num)
		return (NULL);
	if (!nb)
	{
		num[0] = base_to[0];
		num[1] = '\0';
		return (num);
	}
	while (nb)
	{
		num[size - i] = base_to[nb % ft_strlen(base_to)];
		nb /= ft_strlen(base_to);
		i++;
	}
	num[size] = '\0';
	return (num);
}
