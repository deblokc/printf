/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointeur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:41:17 by tnaton            #+#    #+#             */
/*   Updated: 2022/11/08 18:36:41 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	pointflag2(t_str *id, char **ret, int *i)
{
	int	last;

	last = *i;
	while (ft_isdigit(id->str[*i]))
		(*i)++;
	last = ft_atoi_free(ft_substr(id->str, last, *i - last));
	if (last < (int)ft_strlen(*ret))
	{
		free(id->str);
		id->str = *ret;
		return (1);
	}
	*ret = addspace(*ret, (last - ft_strlen(*ret)), 0);
	return (0);
}

int	pointflag3(t_str *id, char **ret, int *i)
{
	int	last;

	while (id->str[*i] == '-')
		(*i)++;
	last = *i;
	while (ft_isdigit(id->str[*i]))
		(*i)++;
	last = ft_atoi_free(ft_substr(id->str, last, *i - last));
	if (last < (int)ft_strlen(*ret))
	{
		free(id->str);
		id->str = *ret;
		return (1);
	}
	*ret = addspace(*ret, (last - ft_strlen(*ret)), 1);
	return (0);
}

void	pointflag(t_str *id, char *ret)
{
	int	i;

	i = 1;
	while (id->str[i])
	{
		if (isdigit(id->str[i]) && id->str[i - 1] != '.')
		{
			if (pointflag2(id, &ret, &i))
				return ;
		}
		if (id->str[i] == '-')
		{
			if (pointflag3(id, &ret, &i))
				return ;
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
