# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acuva-nu <acuva-nu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 12:35:24 by acuva-nu          #+#    #+#              #
#    Updated: 2023/02/25 16:34:52 by acuva-nu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS       = src/fractals.c src/color.c src/draw.c src/events.c src/fractol.c 
OBJS       = ${SRCS:src/%.c=$(OBJ_DIR)/%.o}
BIN_DIR    = bin
OBJ_DIR    = obj
INCS       = inc/
NAME       = fractol
RM         = rm -rf
CC         = cc
CFLAGS     = -O3 -Wextra -Wall -Werror -fsanitize=address
LDFLAGS 	 = libft/libft.a minilibx-linux/libmlx.a -lm -lXext -lX11

all: ${NAME}

$(OBJ_DIR)/%.o: src/%.c | DIRECTORIES
	@${CC} ${CFLAGS} -c $< -o $@ -I ${INCS}


${NAME}: $(OBJS)
	@make -s -C libft
	@make -s -C minilibx-linux
	@${CC} ${CFLAGS} ${OBJS} ${LDFLAGS}  -o ${NAME} -I ${INCS}
	@mv ${NAME} ${BIN_DIR}/$(NAME)
	@echo "Fractol compiled"


DIRECTORIES:
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(OBJ_DIR)

clean:
	@${RM} ${OBJ_DIR}
	@make clean -s -C libft

fclean: clean
	@${RM} ${BIN_DIR}
	@make fclean -s -C libft

re: fclean all


norm:
	@norminette -R CheckForbiddenSourceHeader ${SRCS}
	@norminette -R CheckDefine ${INCS}

.PHONY: all re clean fclean
