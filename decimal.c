/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:41:46 by tnaton            #+#    #+#             */
/*   Updated: 2022/11/08 20:38:28 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*addzero(char *ret, int size, int type)
{
	char	*zero;

	zero = malloc(sizeof(char) * size + 1);
	zero[size] = '\0';
	while (size--)
		zero[size] = '0';
	if (type)
		return (ft_strjoin_free(ret, zero));
	return (ft_strjoin_free(zero, ret));
}

char	*getneg(char *ret, int *isneg)
{
	if (ret[0] == '-')
	{
		ret = ft_substr_free(ret, 1, ft_strlen(ret) - 1);
		*isneg = 1;
	}
	else
		*isneg = 0;
	return (ret);
}

int	aschr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	intflag(t_str *id, char *ret)
{
	int	isneg;

	ret = intflag2(id, ret);
	if (intflag3(id, &ret))
		return ;
	if (aschr(id->str, ' '))
	{
		ret = getneg(ret, &isneg);
		if (!isneg)
			ret = ft_strjoin_free(ft_strdup(" "), ret);
		else
			ret = ft_strjoin_free(ft_strdup("-"), ret);
	}
	if (aschr(id->str, '+'))
	{
		ret = getneg(ret, &isneg);
		if (!isneg)
			ret = ft_strjoin_free(ft_strdup("+"), ret);
		else
			ret = ft_strjoin_free(ft_strdup("-"), ret);
	}
	free(id->str);
	id->str = ret;
}

void	typed(t_str *current, va_list *arg)
{
	char	*ret;
	int		i;

	i = (int)va_arg(*arg, int);
	ret = ft_itoa(i);
	intflag(current, ret);
}
