/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:28:26 by tnaton            #+#    #+#             */
/*   Updated: 2022/11/08 20:29:07 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*intflag21(t_str *id, char *ret, int *i)
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

char	*intflag22(t_str *id, char *ret, int *i)
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

char	*intflag2(t_str *id, char *ret)
{
	int	i;

	i = 1;
	while (id->str[i])
	{
		if (i == 1 && id->str[i] == '0' && !aschr(id->str, '.'))
			ret = intflag21(id, ret, &i);
		if (id->str[i] == '.')
			ret = intflag22(id, ret, &i);
		i++;
	}
	return (ret);
}

int	intflag31(t_str *id, char ***ret, int *i)
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

int	intflag32(t_str *id, char ***ret, int *i)
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
