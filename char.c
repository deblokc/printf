/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:40:07 by tnaton            #+#    #+#             */
/*   Updated: 2022/11/08 16:25:10 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	changeid(t_str *id, int padding)
{
	free(id->str);
	id->str = malloc(sizeof(char) * padding + 1);
	id->str[--padding] = '\0';
	while (padding--)
		id->str[padding] = ' ';
}

int	charflag2(t_str *id, int i, int last)
{
	last = i;
	while (ft_isdigit(id->str[i]))
		i++;
	last = ft_atoi_free(ft_substr(id->str, last, i - last));
	if (last < 2)
		return (0);
	changeid(id, last);
	id->type = 2;
	return (1);
}

int	charflag3(t_str *id, int i, int last)
{
	while (id->str[i] == '-')
		i++;
	last = i;
	while (ft_isdigit(id->str[i]))
		i++;
	last = ft_atoi_free(ft_substr(id->str, last, i - last));
	if (last < 2)
		return (0);
	changeid(id, last);
	id->type = 3;
	return (1);
}

int	charflag(t_str *id)
{
	int		last;
	int		i;

	i = 1;
	last = 0;
	while (id->str[i])
	{
		if (ft_isdigit(id->str[i]))
			return (charflag2(id, i, last));
		else if (id->str[i] == '-')
			return (charflag3(id, i, last));
		i++;
	}
	return (0);
}

void	typec(t_str *current, va_list *arg)
{
	current->c = (char)va_arg(*arg, int);
	current->type = 1;
	if (charflag(current))
		return ;
	free(current->str);
	current->str = NULL;
}
