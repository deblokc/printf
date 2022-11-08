# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnaton <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 18:31:36 by tnaton            #+#    #+#              #
#    Updated: 2022/11/08 20:36:26 by tnaton           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a

INCLUDES = -I./includes

NAME = libftprintf.a

SRCS = printf.c printf2.c char.c lst.c unsigned.c decimal.c decimal2.c hexa.c hexa2.c pointeur.c string.c string2.c extra.c

OBJS = ${SRCS:.c=.o}

OBJSBONUS = ${BONUS:.c=.o}

CC		= gcc

RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		$(MAKE) bonus -C ./libft
		cp libft/libft.a $(NAME)
		$(CC) -g -c $(CFLAGS) $(SRCS)
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

bonus: $(NAME)

clean:
		$(MAKE) clean -C ./libft
		${RM} ${OBJS} ${OBJSBONUS}

fclean:	clean
		$(MAKE) fclean -C ./libft
		${RM} ${NAME}

re:		fclean all
