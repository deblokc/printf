/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:43:03 by tnaton            #+#    #+#             */
/*   Updated: 2022/06/14 18:43:32 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	typex(t_str *current, va_list *arg)
{
	char			*ret;
	unsigned int	i;

	i = (unsigned int)va_arg(*arg, unsigned int);
	ret = ft_itoa_base(i, "0123456789abcdef");
	free(current->str);
	current->str = ret;
}

void	typeX(t_str *current, va_list *arg)
{
	char			*ret;
	unsigned int	i;

	i = (unsigned int)va_arg(*arg, unsigned int);
	ret = ft_itoa_base(i, "0123456789ABCDEF");
	free(current->str);
	current->str = ret;
}
