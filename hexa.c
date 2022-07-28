/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:43:03 by tnaton            #+#    #+#             */
/*   Updated: 2022/06/17 15:45:19 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*hexaflagzero(t_str *id, char *ret, int *i)
{
	int	last;
	int	isneg;

	ret = getneg(ret, &isneg);
	while (id->str[*i] == '0')
		*i += 1;
	last = *i;
	while (ft_isdigit(id->str[*i]))
		*i += 1;
	last = ft_atoi_free(ft_substr(id->str, last, *i - last));
	if (last > (int)ft_strlen(ret))
		ret = addzero(ret, last - ft_strlen(ret) - isneg, 0);
	if (isneg)
		ret = ft_strjoin_free(ft_strdup("-"), ret);
	return (ret);
}

char	*hexaflagpoint(t_str *id, char *ret, int *i)
{
	int	last;
	int	isneg;

	ret = getneg(ret, &isneg);
	*i += 1;
	last = *i;
	while (ft_isdigit(id->str[*i]))
		*i += 1;
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

char	*hexaflagzeroandpoint(t_str *id, char *ret)
{
	int	i;
	int	isneg;
	int	last;

	i = 1;
	while (id->str[i])
	{
		if (i == 1 && id->str[i] == '0' && !aschr(id->str, '.'))
			ret = hexaflagzero(id, ret, &i);
		if (id->str[i] == '.')
		{
		}
		i++;
	}
	return (ret);
}

char	*hexaflagaddspace1(t_str *id, char *ret, int *i)
{
	int	last;

	last = *i;
	while (ft_isdigit(id->str[*i]))
		*i += 1;
	last = ft_atoi_free(ft_substr(id->str, last, *i - last));
	if (last < (int)ft_strlen(ret))
	{
		free(id->str);
		id->str = ret;
		return (ret);
	}
	ret = addspace(ret, (last - ft_strlen(ret)), 0);
	return (ret);
}

char	*hexaflagaddspace2(t_str *id, char *ret, int *i)
{
	int	last;

	while (id->str[*i] == '-')
		*i += 1;
	last = *i;
	while (ft_isdigit(id->str[*i]))
		*i += 1;
	last = ft_atoi_free(ft_substr(id->str, last, *i - last));
	if (last < (int)ft_strlen(ret))
	{
		free(id->str);
		id->str = ret;
		return (ret);
	}
	ret = addspace(ret, (last - ft_strlen(ret)), 1);
	return (ret);
}

char	*hexaflagspace(t_str *id, char *ret)
{
	int	i;
	int	isneg;
	int	last;

	i = 1;
	while (id->str[i])
	{
		if (isdigit(id->str[i]) && id->str[i - 1] != '.')
			hexaflagaddspace1(id, ret, &i);
		if (id->str[i] == '-')
			hexaflagaddspace2(id, ret, &i);
		i++;
	}
	return (ret);
}

char	*hexaflagchr(t_str *id, char *ret)
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
	int	i;
	int	last;
	int	isneg;

	ret = hexaflagzeroandpoint(id, ret);
	ret = hexaflagchr(id, ret);
	if (aschr(id->str, '#'))
	{
		if (ft_strlen(ret) == 1 && ret[0] == '0')
			isneg = 0;
		else
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
