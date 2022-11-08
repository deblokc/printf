/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:43:03 by tnaton            #+#    #+#             */
/*   Updated: 2022/11/08 20:31:26 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexaflag3(t_str *id, char **ret)
{
	int	i;

	i = 1;
	while (id->str[i])
	{
		if (isdigit(id->str[i]) && id->str[i - 1] != '.')
		{
			if (hexaflag31(id, &ret, &i))
				return (1);
		}
		if (id->str[i] == '-')
		{
			if (hexaflag32(id, &ret, &i))
				return (1);
		}
		i++;
	}
	return (0);
}

char	*hexaflag4(t_str *id, char *ret)
{
	int	isneg;

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
	return (ret);
}

void	hexaflag(t_str *id, char *ret, char *exa)
{
	ret = hexaflag2(id, ret);
	if (hexaflag3(id, &ret))
		return ;
	ret = hexaflag4(id, ret);
	if (aschr(id->str, '#'))
	{
		if (!(ft_strlen(ret) == 1) || !(ret[0] == '0'))
			ret = ft_strjoin_free(ft_strdup(exa), ret);
	}
	free(id->str);
	id->str = ret;
}

void	typex(t_str *current, va_list *arg)
{
	char			*ret;
	unsigned int	i;

	i = (unsigned int)va_arg(*arg, unsigned int);
	ret = ft_itoa_base(i, "0123456789abcdef");
	hexaflag(current, ret, "0x");
}

void	typegrosx(t_str *current, va_list *arg)
{
	char			*ret;
	unsigned int	i;

	i = (unsigned int)va_arg(*arg, unsigned int);
	ret = ft_itoa_base(i, "0123456789ABCDEF");
	hexaflag(current, ret, "0X");
}
