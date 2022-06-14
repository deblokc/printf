/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:41:46 by tnaton            #+#    #+#             */
/*   Updated: 2022/06/14 18:42:10 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	typed(t_str *current, va_list *arg)
{
	char	*ret;
	int		i;

	i = (int)va_arg(*arg, int);
	ret = ft_itoa(i);
	free(current->str);
	current->str = ret;
}
