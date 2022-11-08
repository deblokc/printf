/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:43:03 by tnaton            #+#    #+#             */
/*   Updated: 2022/11/08 17:54:26 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*hexaflag21(t_str *id, char *ret, int *i)
{
	int	last;
	int	isneg;

	ret = getneg(ret, &isneg);
	while (id->str[*i] == '0')
		(*i)++;
	last = *i;
	while (ft_isdigit(id->str[*i]))
		(*i)++;
	last = ft_atoi_free(ft_substr(id->str, last, *i - last));
	if (last > (int)ft_strlen(ret))
		ret = addzero(ret, last - ft_strlen(ret) - isneg, 0);
	if (isneg)
		ret = ft_strjoin_free(ft_strdup("-"), ret);
	return (ret);
}

char	*hexaflag22(t_str *id, char *ret, int *i)
{
	int	last;
	int	isneg;

	ret = getneg(ret, &isneg);
	(*i)++;
	last = *i;
	while (ft_isdigit(id->str[*i]))
		(*i)++;
	last = ft_atoi_free(ft_substr(id->str, last, *i - last));
	if (last > (int)ft_strlen(ret))
		ret = addzero(ret, last - ft_strlen(ret), 0);
	else if (ft_strlen(ret) == 1 && ret[0] == '0' && last < 1)
	{
		free(ret);
		ret = ft_strdup("");
	}
	if (isneg)
		ret = ft_strjoin_free(ft_strdup("-"), ret);
	return (ret);
}

char	*hexaflag2(t_str *id, char *ret)
{
	int	i;

	i = 1;
	while (id->str[i])
	{
		if (i == 1 && id->str[i] == '0' && !aschr(id->str, '.'))
			ret = hexaflag21(id, ret, &i);
		if (id->str[i] == '.')
			ret = hexaflag22(id, ret, &i);
		i++;
	}
	return (ret);
}

int	hexaflag31(t_str *id, char ***ret, int *i)
{
	int	last;

	last = *i;
	while (ft_isdigit(id->str[*i]))
		(*i)++;
	last = ft_atoi_free(ft_substr(id->str, last, *i - last));
	if (last < (int)ft_strlen(**ret))
	{
		free(id->str);
		id->str = **ret;
		return (1);
	}
	**ret = addspace(**ret, (last - ft_strlen(**ret)), 0);
	return (0);
}

int	hexaflag32(t_str *id, char ***ret, int *i)
{
	int	last;

	while (id->str[*i] == '-')
		(*i)++;
	last = *i;
	while (ft_isdigit(id->str[*i]))
		(*i)++;
	last = ft_atoi_free(ft_substr(id->str, last, *i - last));
	if (last < (int)ft_strlen(**ret))
	{
		free(id->str);
		id->str = **ret;
		return (1);
	}
	**ret = addspace(**ret, (last - ft_strlen(**ret)), 1);
	return (0);
}

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
