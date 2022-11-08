/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:40:54 by tnaton            #+#    #+#             */
/*   Updated: 2022/11/08 19:51:32 by tnaton           ###   ########.fr       */
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

char	*flagnull2(t_str *id, char *ret)
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
	return (ret);
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

char	*flag2(t_str *id, char *ret)
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
	return (ret);
}

int	flag31(t_str *id, char ***ret, int *i)
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

int	flag32(t_str *id, char ***ret, int *i)
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

int	flag3(t_str *id, char **ret)
{
	int	i;

	i = 1;
	while (id->str[i])
	{
		if (isdigit(id->str[i]) && id->str[i - 1] != '.')
		{
			if (flag31(id, &ret, &i))
				return (1);
		}
		if (id->str[i] == '-')
		{
			if (flag32(id, &ret, &i))
				return (1);
		}
		i++;
	}
	return (0);
}

void	flag(t_str *id, char *ret)
{
	ret = flag2(id, ret);
	if (flag3(id, &ret))
		return ;
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
