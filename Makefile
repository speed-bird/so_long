# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 16:05:02 by jrobert           #+#    #+#              #
#    Updated: 2022/01/13 15:46:58 by jrobert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS_FILES	= 	check.c \
				draw.c \
				move.c \
				parse.c \
				play.c \
				quit.c \
				so_long.c \
				textures.c
SRCS_DIR	= 	srcs/
SRCS		=	$(addprefix $(SRCS_DIR),$(SRCS_FILES))
OBJS		= 	$(SRCS:%.c=%.o)
NAME		=	so_long
LIBPATH 	= 	-L ./libft
MLXPATH		=	-L ./mlx
LIB     	= 	-lft
MLX			=	-lmlx 
FWORK		= 	-framework OpenGL -framework Appkit
CFLAGS		= 	-Wall -Wextra -Werror -g -I includes -I libft/includes
LDFLAGS 	= 	$(LIBPATH) $(LIB) $(MLXPATH) $(MLX) $(FWORK) -fsanitize=address -g3 -o $(NAME)
			
$(NAME)			:	$(OBJS)
					$(MAKE) -C ./libft/
					$(MAKE) -C ./mlx/
					gcc $(OBJS) $(LDFLAGS) 

all    			:	$(NAME)

clean 			:	
					rm -f $(OBJS)
					$(MAKE) clean -C ./libft/
					$(MAKE) clean -C ./mlx/

fclean 			:	clean
					rm -f $(NAME)
					$(MAKE) fclean -C ./libft/
					
re				:	fclean all

.PHONY			: 	all clean fclean re


