/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:40:07 by tnaton            #+#    #+#             */
/*   Updated: 2022/06/14 20:07:32 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	changeid(t_str *id, int padding)
{
	free(id->str);
	id->str = malloc(sizeof(char) * padding);
	id->str[--padding] = '\0';
	while (padding--)
		id->str[padding] = ' ';
}

int	charflag(t_str *id)
{
	int		last;
	int		i;

	i = 1;
	while (id->str[i])
	{
		if (ft_isdigit(id->str[i]))
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
		else if (id->str[i] == '-')
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
