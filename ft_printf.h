/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:55:47 by tnaton            #+#    #+#             */
/*   Updated: 2022/11/08 20:39:19 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_str
{
	char			*str;
	char			c;
	int				type;
	struct s_str	*next;
	struct s_str	*prev;
}	t_str;

int		ft_printf(const char *input, ...);
void	typeu(t_str *current, va_list *arg);
int		putandlen(t_str *lst);
void	expandlst(t_str *lst, va_list *arg);
void	expand(t_str *current, va_list *arg);
void	typeprc(t_str *current);
int		needex(char *str);
void	typep(t_str *current, va_list *arg);
t_str	*getstr(const char *input, va_list *arg);
t_str	*getlst(const char *input);
t_str	*getcleanlst(t_str *first);
int		isdel(char c);
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
char	*intflag21(t_str *id, char *ret, int *i);
char	*intflag22(t_str *id, char *ret, int *i);
char	*intflag2(t_str *id, char *ret);
int		intflag31(t_str *id, char ***ret, int *i);
int		intflag32(t_str *id, char ***ret, int *i);
char	*hexaflag21(t_str *id, char *ret, int *i);
char	*hexaflag22(t_str *id, char *ret, int *i);
char	*hexaflag2(t_str *id, char *ret);
int		hexaflag31(t_str *id, char ***ret, int *i);
int		hexaflag32(t_str *id, char ***ret, int *i);
int		typeun(t_str *lst);
int		typedeux(t_str *lst);
int		typetrois(t_str *lst);
int		typequatre(t_str *lst);
int		putandlen(t_str *lst);
char	*flag2(t_str *id, char *ret);
int		flag31(t_str *id, char ***ret, int *i);
int		flag32(t_str *id, char ***ret, int *i);
int		flag3(t_str *id, char **ret);
void	flag(t_str *id, char *ret);
t_str	*getstr2(t_str *lst, t_str *ret);
t_str	*getlst2(const char *input, t_str *current, int *i, int *last);
int		intflag3(t_str *id, char **ret);
char	*flagnull2(t_str *id, char *ret);

#endif
