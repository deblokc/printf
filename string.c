/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:40:54 by tnaton            #+#    #+#             */
/*   Updated: 2022/06/14 20:27:09 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	types(t_str *current, va_list *arg)
{
	char	*ret;

	ret = (char *)va_arg(*arg, char *);
	free(current->str);
	if (ret)
		current->str = ft_strdup(ret);
	else
		current->str = ft_strdup("(null)");
}
