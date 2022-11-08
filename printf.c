/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:48:33 by tnaton            #+#    #+#             */
/*   Updated: 2022/11/08 20:33:02 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	needex(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			return (1);
		i++;
	}
	return (0);
}

void	typeprc(t_str *current)
{
	char	*ret;

	ret = malloc(sizeof(char) * 2);
	ret[0] = '%';
	ret[1] = '\0';
	free(current->str);
	current->str = ret;
}

void	expand(t_str *current, va_list *arg)
{
	int	i;

	i = ft_strlen(current->str) - 1;
	if (current->str[i] == 'c')
		typec(current, arg);
	else if (current->str[i] == 's')
		types(current, arg);
	else if (current->str[i] == 'p')
		typep(current, arg);
	else if (current->str[i] == 'd' || current->str[i] == 'i')
		typed(current, arg);
	else if (current->str[i] == 'u')
		typeu(current, arg);
	else if (current->str[i] == 'x')
		typex(current, arg);
	else if (current->str[i] == 'X')
		typegrosx(current, arg);
	else if (current->str[i] == '%')
		typeprc(current);
}

void	expandlst(t_str *lst, va_list *arg)
{
	while (lst)
	{
		if (lst->str && needex(lst->str))
			expand(lst, arg);
		lst = lst->next;
	}
}

int	ft_printf(const char *input, ...)
{
	va_list	arg;
	t_str	*lst;
	int		len;

	va_start(arg, input);
	lst = getstr(input, &arg);
	va_end(arg);
	len = putandlen(lst);
	return (len);
}
