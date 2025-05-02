NAME				=	fractol

# paths
SRC_PATH			=	src/
INCLUDE_PATH		=	include/
OUTPUT_PATH			=	output/
MLX42				=	MLX42/
MLX_BUILD_PATH		=	$(MLX42)build/
LIBFT_PATH			=	$(INCLUDE_PATH)libft/
FT_PRINTF_PATH		=	$(INCLUDE_PATH)ft_printf/
LIBFT_A				=	$(LIBFT_PATH)libft.a
FT_PRINTF_A			=	$(FT_PRINTF_PATH)libftprintf.a
MLX_LIB_A			=	$(MLX_BUILD_PATH)libmlx42.a -lglfw -ldl -lm -pthread

# Compiler and flags
CC					=	cc
C_FLAGS				=	-Wall -Wextra -Werror #-g3
INCLUDE_FLAGS		=	-I $(INCLUDE_PATH) -I $(MLX42)/include/MLX42
MLX_FLAGS			=	-Wunreachable-code -Ofast -g3

# others
RM					=	rm -f
RMDIR				=	rm -rf
MKDIR				=	mkdir -p

# source files
FILES				=	fractol.c init.c calculate.c main.c

SRCS				=	$(addprefix $(SRC_PATH), $(FILES))
OBJS				=	$(SRCS:$(SRC_PATH)%.c=$(OUTPUT_PATH)%.o)

# colors
BOLD_GREEN			=	\033[1;32m
BOLD_PURPLE			=	\033[1;35m
BOLD_CYAN			=	\033[1;36m
BOLD_YELLOW			=	\033[1;33m
RESET				=	\033[0m

all: 				$(NAME)

$(NAME): 		 	$(OBJS) $(INCLUDE_PATH) Makefile
					@ echo "$(BOLD_CYAN)Building all libraries...$(RESET)"
					@ make -s makelib
					@ echo "$(BOLD_CYAN)Building MLX...$(RESET)"
					@ make -s libmlx
					@ echo "$(BOLD_CYAN)Building fract-ol...$(RESET)"
					@ $(CC) $(C_FLAGS) $(INCLUDE_FLAGS) $(OBJS) $(LIBFT_A) $(FT_PRINTF_A) $(MLX_LIB_A) -o $(NAME)
					@ echo "$(BOLD_GREEN)Done! fract-ol is now ready.$(RESET)"

$(OUTPUT_PATH)%.o: 	$(SRC_PATH)%.c $(INCLUDE_PATH) Makefile
					@ $(MKDIR) $(OUTPUT_PATH)
					@ $(CC) $(C_FLAGS) $(INCLUDE_FLAGS) -c $< -o $@

makelib: 			$(LIBFT_PATH) $(FT_PRINTF_PATH)
					@ make -sC $(LIBFT_PATH) && make -sC $(FT_PRINTF_PATH)

libmlx:
					@ $(MKDIR) $(MLX_BUILD_PATH)
					@ cmake -Ss $(MLX42) -B $(MLX_BUILD_PATH) && make -sC $(MLX_BUILD_PATH)

clean:
					@ $(RM) $(OBJS)
					@ make clean -sC $(LIBFT_PATH) && make clean -sC $(FT_PRINTF_PATH)
					@ echo "$(BOLD_YELLOW)All fract-ol object files have been cleaned.$(RESET)"

fclean: clean
					@ $(RM) $(NAME)
					@ $(RMDIR) $(OUTPUT_PATH)
					@ make clean -sC $(LIBFT_PATH) && make clean -sC $(FT_PRINTF_PATH)
					@ echo "$(BOLD_YELLOW)All fract-ol executable files have been cleaned.$(RESET)"

re:					fclean all

clone:
					@ git clone https://github.com/codam-coding-college/MLX42.git MLX42

.PHONY: 			all clean fclean re clone libmlx