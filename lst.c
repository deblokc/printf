/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:38:33 by tnaton            #+#    #+#             */
/*   Updated: 2022/11/08 13:22:41 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_str	*newstr(char *str, t_str *prev)
{
	t_str	*new;

	new = malloc(sizeof(t_str));
	if (!new)
		return (NULL);
	new->str = str;
	new->c = '\0';
	new->type = 0;
	new->prev = prev;
	new->next = NULL;
	return (new);
}

int	isdel(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || \
			c == 'u' || c == 'x' || c == 'X' || c == '%');
}

t_str	*getcleanlst(t_str *first)
{
	t_str	*current;
	t_str	*tmp;

	current = first->next;
	while (current)
	{
		if (!current->str || !ft_strcmp(current->str, ""))
		{
			tmp = current->prev;
			tmp->next = current->next;
			if (current->next)
				current->next->prev = tmp;
			free(current->str);
			free(current);
			current = tmp->next;
		}
		if (current)
			current = current->next;
	}
	return (first);
}

t_str	*getlst(const char *input)
{
	t_str	*first;
	t_str	*current;
	int		i;
	int		last;

	i = 0;
	last = 0;
	current = newstr(NULL, NULL);
	first = current;
	while (input[i])
	{
		if (input[i] == '%')
		{
			current->next = newstr(ft_substr(input, last, i - last), current);
			current = current->next;
			last = i;
			i++;
			while (input[i] && !isdel(input[i]))
				i++;
			if (input[i])
			{
				current->next = newstr(ft_substr(input, last, \
							i - last + 1), current);
				current = current->next;
				last = i + 1;
			}
		}
		i++;
	}
	if (last != i)
		current->next = newstr(ft_substr(input, last, i - last), current);
	first = getcleanlst(first);
	return (first);
}

t_str	*getstr(const char *input, va_list *arg)
{
	t_str	*ret;
	t_str	*lst;
	t_str	*tmp;
	t_str	*first;

	ret = newstr(NULL, NULL);
	first = ret;
	lst = getlst(input);
	expandlst(lst, arg);
	while (lst)
	{
		if (lst->type == 0)
			ret->str = ft_strjoin_free(ret->str, lst->str);
		else
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
		}
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	return (first);
}
