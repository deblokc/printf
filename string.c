/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:40:54 by tnaton            #+#    #+#             */
/*   Updated: 2022/06/16 17:14:26 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*addspace(char *ret, int size, int type)
{
	char	*space;

	space = malloc(sizeof(char) * size + 1);
	space[size] = '\0';
	while (size--)
		space[size] = ' ';
	if (type)
		return (ft_strjoin_free(ret, space));
	return (ft_strjoin_free(space, ret));
}

void	flagnull(t_str *id, char *ret)
{
	int	i;
	int	last;

	i = 1;
	while (id->str[i])
	{
		if (id->str[i] == '.')
		{
			i++;
			last = i;
			while (ft_isdigit(id->str[i]))
				i++;
			last = ft_atoi_free(ft_substr(id->str, last, i - last));
			if (last < 6)
			{
				free(ret);
				ret = ft_strdup("");
			}
			else if (last < (int)ft_strlen(ret))
				ret = ft_substr_free(ret, 0, last);
		}
		i++;
	}
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

void	flag(t_str *id, char *ret)
{
	int	i;
	int	last;

	i = 1;
	while (id->str[i])
	{
		if (id->str[i] == '.')
		{
			i++;
			last = i;
			while (ft_isdigit(id->str[i]))
				i++;
			last = ft_atoi_free(ft_substr(id->str, last, i - last));
			if (last < 0)
			{
				free(ret);
				ret = ft_strdup("");
			}
			else if (last < (int)ft_strlen(ret))
				ret = ft_substr_free(ret, 0, last);
		}
		i++;
	}
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

void	types(t_str *current, va_list *arg)
{
	char	*ret;

	ret = (char *)va_arg(*arg, char *);
	if (ret)
	{
		ret = ft_strdup(ret);
		flag(current, ret);
	}
	else
	{
		ret = ft_strdup("(null)");
		flagnull(current, ret);
	}
}
