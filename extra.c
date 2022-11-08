/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:35:31 by tnaton            #+#    #+#             */
/*   Updated: 2022/11/08 20:38:42 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_str	*getstr2(t_str *lst, t_str *ret)
{
	if (lst->type == 1)
	{
		ret->next = newstr(NULL, ret);
		ret->next->type = 1;
	}
	else
	{
		ret->next = newstr(lst->str, ret);
		ret->next->type = lst->type;
	}
	ret = ret->next;
	ret->c = lst->c;
	ret->next = newstr(NULL, ret);
	ret = ret->next;
	return (ret);
}

t_str	*getlst2(const char *input, t_str *current, int *i, int *last)
{
	current->next = newstr(ft_substr(input, *last, *i - *last), current);
	current = current->next;
	*last = *i;
	(*i)++;
	while (input[*i] && !isdel(input[*i]))
		(*i)++;
	if (input[*i])
	{
		current->next = newstr(ft_substr(input, *last, \
					*i - *last + 1), current);
		current = current->next;
		*last = *i + 1;
	}
	return (current);
}

int	intflag3(t_str *id, char **ret)
{
	int	i;

	i = 1;
	while (id->str[i])
	{
		if (isdigit(id->str[i]) && id->str[i - 1] != '.')
		{
			if (intflag31(id, &ret, &i))
				return (1);
		}
		if (id->str[i] == '-')
		{
			if (intflag32(id, &ret, &i))
				return (1);
		}
		i++;
	}
	return (0);
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
