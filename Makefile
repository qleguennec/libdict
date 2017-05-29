NAME = libdict.a
SRC = dict_add.c dict_clear.c dict_cpy.c dict_del.c dict_dup.c dict_ent_add.c dict_ent_cpy.c dict_ent_del.c dict_ent_free.c dict_find_ent.c dict_find_match.c dict_find_maybe.c dict_fmap.c dict_free.c dict_init.c dict_istype.c dict_iter.c dict_lookup.c dict_map.c dict_map2.c dict_modify.c dict_print.c dict_regen.c dict_set.c dict_size.c dict_str_add.c dict_str_export.c dict_str_hash.c dict_str_import.c dict_str_init.c dict_str_set.c
OBJ = $(SRC:.c=.o)

CFLAGS += -g -Wall -Wextra -Werror
ARFLAGS = rc

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $(OBJ)

clean:
	@rm $(OBJ) 2> /dev/null || true

fclean: clean
	@rm $(NAME) 2> /dev/null || true

re: fclean all
