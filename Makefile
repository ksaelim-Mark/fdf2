# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/16 20:05:25 by ksaelim           #+#    #+#              #
#    Updated: 2023/04/20 13:34:52 by ksaelim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

NAME = fdf

HEADER =  header/

LIBFT = libft/

GNL = get_next_line/

MLX = mlx_linux/

LIBFT_SRCS = ft_strlen.c ft_split.c ft_atoi.c ft_strlcpy.c ft_isdigit.c

GNL_SRCS = get_next_line.c get_next_line_utils.c

FDF_SRCS = main.c input.c

SRCS = $(FDF_SRCS) \
						$(addprefix $(LIBFT), $(LIBFT_SRCS)) \
						$(addprefix $(GNL), $(GNL_SRCS))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%o:%c
	gcc $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS)
	gcc $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all bonus
