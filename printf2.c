/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:32:37 by tnaton            #+#    #+#             */
/*   Updated: 2022/11/08 20:33:33 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
