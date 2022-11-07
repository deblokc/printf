/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointeur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:41:17 by tnaton            #+#    #+#             */
/*   Updated: 2022/06/14 18:41:38 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	typep(t_str *current, va_list *arg)
{
	unsigned long long	i;
	char				*ret;

	i = (unsigned long long)va_arg(*arg, unsigned long long);
	if (i)
	{
		ret = ft_itoa_base(i, "0123456789abcdef");
		ret = ft_strjoin_free(ft_strdup("0x"), ret);
	}
	else
		ret = ft_strdup("(nil)");
	free(current->str);
	current->str = ret;
}
