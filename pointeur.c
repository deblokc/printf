/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointeur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:41:17 by tnaton            #+#    #+#             */
/*   Updated: 2022/06/17 12:48:59 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	pointflag(t_str *id, char *ret)
{
	int	i;
	int	last;

	i = 1;
	while (id->str[i])
	{
		if (isdigit(id->str[i]) && id->str[i - 1] != '.')
		{
			last = i;
			while (ft_isdigit(id->str[i]))
				i++;
			last = ft_atoi_free(ft_substr(id->str, last, i - last));
			if (last < (int)ft_strlen(ret))
			{
				free(id->str);
				id->str = ret;
				return ;
			}
			ret = addspace(ret, (last - ft_strlen(ret)), 0);
		}
		if (id->str[i] == '-')
		{
			while (id->str[i] == '-')
				i++;
			last = i;
			while (ft_isdigit(id->str[i]))
				i++;
			last = ft_atoi_free(ft_substr(id->str, last, i - last));
			if (last < (int)ft_strlen(ret))
			{
				free(id->str);
				id->str = ret;
				return ;
			}
			ret = addspace(ret, (last - ft_strlen(ret)), 1);
		}
		i++;
	}
	free(id->str);
	id->str = ret;
}

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
	pointflag(current, ret);
}
