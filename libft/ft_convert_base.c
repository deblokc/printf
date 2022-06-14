/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:18:07 by tnaton            #+#    #+#             */
/*   Updated: 2021/12/02 10:40:04 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_convert_base(char *nb, char *base_from, char *base_to)
{
	unsigned long long	tmp;

	tmp = ft_atoi_base(nb, base_from);
	return (ft_itoa_base(tmp, base_to));
}
