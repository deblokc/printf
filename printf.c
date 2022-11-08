/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:48:33 by tnaton            #+#    #+#             */
/*   Updated: 2022/11/08 20:02:47 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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

int	typeun(t_str *lst)
{
	ft_putstr_fd(lst->str, 1);
	return (ft_strlen(lst->str));
}

int	typedeux(t_str *lst)
{
	write(1, &lst->c, 1);
	return (1);
}

int	typetrois(t_str *lst)
{
	ft_putstr_fd(lst->str, 1);
	write(1, &lst->c, 1);
	return (ft_strlen(lst->str) + 1);
}

int	typequatre(t_str *lst)
{
	write(1, &lst->c, 1);
	ft_putstr_fd(lst->str, 1);
	return (ft_strlen(lst->str) + 1);
}

int	putandlen(t_str *lst)
{
	int		len;
	t_str	*tmp;
	int		(*f[4])(t_str *);

	f[0] = &typeun;
	f[1] = &typedeux;
	f[2] = &typetrois;
	f[3] = &typequatre;
	len = 0;
	while (lst)
	{
		len += f[lst->type](lst);
		tmp = lst;
		free(lst->str);
		lst = lst->next;
		free(tmp);
	}
	return (len);
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
