/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:41:46 by tnaton            #+#    #+#             */
/*   Updated: 2022/11/08 13:21:14 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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

void	intflag21(t_str *id, char *ret, int *i, int *last, int *isneg)
{
	if (id->str[*i] == '.')
	{
		ret = getneg(ret, isneg);
		*i++;
		*last = *i;
		while (ft_isdigit(id->str[*i]))
			*i++;
		*last = ft_atoi_free(ft_substr(id->str, *last, *i - *last));
		if (*last > (int)ft_strlen(ret))
			ret = addzero(ret, *last - ft_strlen(ret), 0);
		else if (ft_strlen(ret) == 1 && ret[0] == '0' && *last < 1)
		{
			free(ret);
			ret = ft_strdup("");
		}
		if (*isneg)
			ret = ft_strjoin_free(ft_strdup("-"), ret);
	}
}

void	intflag2(t_str *id, char *ret)
{
	int	i;
	int	isneg;
	int	last;

	i = 1;
	while (id->str[i])
	{
		if (i == 1 && id->str[i] == '0' && !aschr(id->str, '.'))
		{
			ret = getneg(ret, &isneg);
			while (id->str[i] == '0')
				i++;
			last = i;
			while (ft_isdigit(id->str[i]))
				i++;
			last = ft_atoi_free(ft_substr(id->str, last, i - last));
			if (last > (int)ft_strlen(ret))
				ret = addzero(ret, last - ft_strlen(ret) - isneg, 0);
			if (isneg)
				ret = ft_strjoin_free(ft_strdup("-"), ret);
		}
		intflag21(id, ret, &i, &last, &isneg);
		i++;
	}
}

void	intflag31(t_str *id, char *ret, int *i, int *last, int *isneg)
{
	if (id->str[*i] == '-')
	{
		while (id->str[*i] == '-')
			*i++;
		*last = *i;
		while (ft_isdigit(id->str[*i]))
			*i++;
		*last = ft_atoi_free(ft_substr(id->str, *last, *i - *last));
		if (*last < (int)ft_strlen(ret))
		{
			free(id->str);
			id->str = ret;
			return ;
		}
		ret = addspace(ret, (*last - ft_strlen(ret)), 1);
	}
}

void	intflag3(t_str *id, char *ret)
{
	int	i;
	int	last;
	int	isneg;

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
		intflag31(id, ret, &i, &last, &isneg);
		i++;
	}
}

void	intflag(t_str *id, char *ret)
{
	int	i;
	int	last;
	int	isneg;

	intflag2(id, ret);
	intflag3(id, ret);
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
