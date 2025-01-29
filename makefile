.PHONY : all clean fclean re clear mandatory bonus norminette

NAME = push_swap

# ╭━━━━━━━━━━━━══════════╕出 ❖ BASICS VARIABLES ❖ 力╒═══════════━━━━━━━━━━━━╮ #

CC := cc

CFLAGS := -Wall -Wextra -Werror

RM := rm -rf

SHOW_MSG_CLEAN = true

# ╰━━━━━━━━━━━━━━━━════════════════╛出 ❖ 力╘════════════════━━━━━━━━━━━━━━━━╯ #

# ╭━━━━━━━━━━━━══════════╕出 ❖ FILE TREE ❖ 力╒═══════════━━━━━━━━━━━━╮ #

# directories
D_SRC = src/
# D_BON = 
D_INC = inc/
D_OBJ = .obj/

# file lists
LST_SRC =	main.c \
			count_digit.c \
			ft_atoi.c \

# LST_MAN = 	

# LST_BON =	

LST_INC = 	push_swap.h \

# files paths
SRC  =	$(addprefix $(D_SRC), $(LST_SRC))
# MAN  =	$(addprefix $(D_SRC), $(LST_MAN))
# BON  =	$(addprefix $(D_BON), $(LST_BON))
INC  = 	$(addprefix $(D_INC), $(LST_INC))
OBJ  = 	$(subst  $(D_SRC), $(D_OBJ), $(SRC:.c=.o))
# MOBJ = 	$(subst  $(D_SRC), $(D_OBJ), $(MAN:.c=.o))
# BOBJ = 	$(subst  $(D_BON), $(D_OBJ), $(BON:.c=.o))

# ╭━━━━━━━━━━━━══════════╕出 ❖ RULES ❖ 力╒═══════════━━━━━━━━━━━━╮ #

all : $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) -s $(NAME)
	@$(RM) $(D_OBJ)main.o
	@$(CC) $(NAME) $(OBJ) $(MOBJ)
	@echo "\e[0;32mArchive de ft_printf créée avec succès ! 🧬\e[0m"

$(D_OBJ)%.o: $(D_SRC)%.c $(D_INC)push_swap.h
	@mkdir -p $(D_OBJ)
	$(CC) $(CFLAGS) -I$(D_INC) -c $< -o $@

$(D_OBJ)%.o: $(D_BON)%.c $(D_INC)push_swap.h
	@mkdir -p $(D_OBJ)
	$(CC) $(CFLAGS) -I$(D_INC) -c $< -o $@

bonus : $(D_OBJ).bonus

$(D_OBJ).bonus : clear $(BOBJ) $(LIBFT)
	@$(MAKE) -s $(NAME)
	@$(RM) $(D_OBJ)mandatory_parser.o
	@ar rcs $(NAME) $(OBJ) $(BOBJ)
	@touch $(D_OBJ).bonus
	@echo "\e[0;32mArchive bonus de ft_printf créée avec succès ! 🧬\e[0m"

clean:
ifeq ($(SHOW_MSG_CLEAN), true)
	@echo "\e[0;36mJ'ai enlevé tous les objets relatifs à ft_printf 🧹\e[0m"
endif
	@$(RM) $(D_OBJ)

fclean:
	@$(MAKE) -s SHOW_MSG_CLEAN=false clean
	@$(RM) $(NAME) mandatory_tester bonus_tester .bonus
	@echo "\e[0;34mArchive de ft_printf nettoyée 🧼\e[0m"

re :
	$(MAKE) fclean
	$(MAKE) all
	@echo "\e[0;32mArchive de ft_printf recréée avec succès ! 🫡\e[0m"

norminette :
	norminette -R CheckForbiddenSourceHeader $(D_SRC) $(D_BON) $(D_INC)