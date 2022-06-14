/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:42:31 by tnaton            #+#    #+#             */
/*   Updated: 2022/06/14 18:42:46 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	typeu(t_str *current, va_list *arg)
{
	char			*ret;
	unsigned long	i;

	i = (unsigned int)va_arg(*arg, unsigned int);
	ret = ft_itoa_base(i, "0123456789");
	free(current->str);
	current->str = ret;
}
