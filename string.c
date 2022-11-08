/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:40:54 by tnaton            #+#    #+#             */
/*   Updated: 2022/11/08 20:38:40 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	flagnull3(t_str *id, char **ret, int *i)
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

int	flagnull4(t_str *id, char **ret, int *i)
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

void	flagnull(t_str *id, char *ret)
{
	int	i;

	ret = flagnull2(id, ret);
	i = 1;
	while (id->str[i])
	{
		if (isdigit(id->str[i]) && id->str[i - 1] != '.')
		{
			if (flagnull3(id, &ret, &i))
				return ;
		}
		if (id->str[i] == '-')
		{
			if (flagnull4(id, &ret, &i))
				return ;
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
