RED=\033[31m
GREEN=\033[32m
BOLD=\033[1m
MAGENTA=\033[95m
RESET=\033[0m

define LOADING
    @sleep 0.4
    @echo -n "$(MAGENTA)."
    @sleep 0.15
    @echo -n "."
    @sleep 0.15
    @echo ".$(RESET)"
    @sleep 0.15
endef

DEPENDENCIES= -lXext -lX11 -lm -lz
INCLUDES= -Iincludes -Ilibft/headers -Imlx #-Itests/
CC= cc -Werror -Wextra -Wall $(INCLUDES)

MAIN_SRC= srcs/main.c

ifeq ($(findstring bruno, $(MAKECMDGOALS)), bruno)
	MAIN_SRC = srcs/dev_main_brfialho.c
endif

ifeq ($(findstring gustavo, $(MAKECMDGOALS)), gustavo)
	MAIN_SRC = srcs/dev_main_gbercaco.c
endif

SRC= srcs/init_destroy/destroy.c \
	 srcs/init_destroy/init.c \
	 srcs/render/render.c

O_DIR= obj/
OBJ= $(SRC:%.c=$(O_DIR)%.o)
MAIN_OBJ= $(MAIN_SRC:%.c=$(O_DIR)%.o)

NAME= cub3d

LIBPATH= libft/
LIBFT= $(LIBPATH)libft.a

LIBMLX_PATH = mlx/
LIBMLX = $(LIBMLX_PATH)libmlx_Linux.a

#TEST_BIN_DIR= tests/bin/
#TEST_NAMES= 
#TEST_BINARIES= $(addprefix $(TEST_BIN_DIR), $(TEST_NAMES))

VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes

all: $(LIBFT) $(LIBMLX) $(NAME)

bruno: re_nolib

gustavo: re_nolib

$(NAME): $(OBJ) $(MAIN_OBJ)
	@$(CC) $(OBJ) $(MAIN_OBJ) $(LIBFT) $(LIBMLX) $(DEPENDENCIES) -o $(NAME)
	@echo -n "\033[32m\nSuccessfully Generated $(RESET)$(NAME) \n\n"

$(O_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(MAGENTA)Compiling$(RESET) $(notdir $<)"
	@sleep 0.0001
	@$(CC) -c $< -o $@

$(LIBFT):
	@make --no-print-directory -C $(LIBPATH)

$(LIBMLX):
	@make --no-print-directory -C $(LIBMLX_PATH)

# $(TEST_BIN_DIR)lexer: tests/tester_lexer/tester_lexer.c $(LIBFT) $(OBJ)
# 	@mkdir -p $(TEST_BIN_DIR)
# 	@echo "$(MAGENTA)Compiling test$(RESET) $(notdir $@)"
# 	@$(CC) $< $(OBJ) $(LIBFT) $(DEPENDENCIES) -o $@

clean:
	@echo "$(MAGENTA)Cleansing $(NAME) Objects"
	$(LOADING)
	@make --no-print-directory -C $(LIBPATH) clean
	$(LOADING)
	@make --no-print-directory -C $(LIBMLX_PATH) clean
	@rm -rf $(O_DIR)
	@rm -rf $(TEST_BIN_DIR)

fclean:
	@make --no-print-directory -C $(LIBPATH) fclean
	@make --no-print-directory -C $(LIBMLX_PATH) clean
	@echo "$(MAGENTA)Cleansing $(NAME)"
	$(LOADING)
	@rm -rf $(O_DIR)
	@rm -f $(NAME)

re: fclean all

valgrind: all $(valgrind)
	@$(VALGRIND) ./$(NAME)
	
clean_nolib:
	@echo "$(MAGENTA)Cleansing $(NAME) Objects"
	$(LOADING)
	@rm -rf $(O_DIR)
	@rm -rf $(TEST_BIN_DIR)

fclean_nolib:
	@echo "$(MAGENTA)Cleansing $(NAME)"
	$(LOADING)
	@rm -rf $(O_DIR)
	@rm -f $(NAME)

re_nolib: fclean_nolib all

# test: fclean_nolib
# 	@$(MAKE) --no-print-directory $(TEST_BINARIES)
# 	@echo "$(MAGENTA)$(BOLD)\nInitializing all unitary tests$(RESET)"
# 	$(LOADING)
# 	@echo -n
# 	@for bin in $(TEST_BINARIES); do \
# 		echo "$(BOLD)\n======= Running $$bin =======\n$(RESET)"; \
# 		valgrind -q ./$$bin; \
# 	done

.PHONY: $(LIBFT) all re fclean clean bruno gustavo re_nolib fclean_nolib #test