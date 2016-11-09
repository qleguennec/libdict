# Directories
PROJECT		=	libdict
BINDIR		?=	.
BUILDDIR	?=	build
NAME		=	$(BINDIR)/libdict.a

# Compiler options
CC			=	clang
CFLAGS		=	$(addprefix -I,$(INCLUDE)) -Wall -Wextra -Werror -g

# Color output
BLACK		=	"\033[0;30m"
RED			=	"\033[0;31m"
GREEN		=	"\033[0;32m"
YELLOW		=	"\033[1;33m"
BLUE		=	"\033[0;34m"
MAGENTA		=	"\033[0;35m"
CYAN		=	"\033[0;36m"
WHITE		=	"\033[0;37m"
END			=	"\033[0m"

SRC += dict_add.c
SRC += dict_del.c
SRC += dict_find_ent.c
SRC += dict_find_slot.c
SRC += dict_grow.c
SRC += dict_init.c
SRC += dict_lookup.c
SRC += dict_str_add.c
SRC += dict_str_hash.c
SRC += dict_str_init.c
SRC += dict_str_lookup.c
SRC += dict_vect_add.c

OBJECTS		=	$(addprefix $(BUILDDIR)/, $(SRC:%.c=%.o))

all: $(NAME)

$(BUILDDIR)/%.o: %.c
	@[ -d $(BUILDDIR) ] || mkdir $(BUILDDIR)
	@printf $(YELLOW)$(PROJECT)$(END)'\t'
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	@printf $(YELLOW)$(PROJECT)$(END)'\t'
	@ar rc $(@) $(OBJECTS)
	@echo OK

.PHONY: clean fclean re

clean:
	@printf $(YELLOW)$(PROJECT)$(END)'\t'
	rm -rf build/

fclean: clean
	@printf $(YELLOW)$(PROJECT)$(END)'\t'
	rm -rf $(NAME)

re: fclean all
