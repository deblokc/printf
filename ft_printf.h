/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:55:47 by tnaton            #+#    #+#             */
/*   Updated: 2022/06/16 17:02:42 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_str
{
	char	*str;
	char	c;
	int		type;
	struct s_str *next;
	struct s_str *prev;
} t_str;

int	ft_printf(const char *input, ...);
void	typeu(t_str *current, va_list *arg);
int	putandlen(t_str *lst);
void	expandlst(t_str *lst, va_list *arg);
void	expand(t_str *current, va_list *arg);
void	typeprc(t_str *current);
int	needex(char *str);
void	typep(t_str *current, va_list *arg);
t_str	*getstr(const char *input, va_list *arg);
t_str	*getlst(const char *input);
t_str	*getcleanlst(t_str *first);
int	isdel(char c);
t_str	*newstr(char *str, t_str *prev);
void	typegrosx(t_str *current, va_list *arg);
void	typex(t_str *current, va_list *arg);
void	typed(t_str *current, va_list *arg);
void	typec(t_str *current, va_list *arg);
void	typec(t_str *current, va_list *arg);
void	types(t_str *current, va_list *arg);
void	flag(t_str *id, char *ret);
char	*addspace(char *in, int size, int type);
void	intflag(t_str *id, char *ret);
int		aschr(char *str, char c);
char	*getneg(char *ret, int *isneg);
char	*addzero(char *ret, int size, int type);

#endif
