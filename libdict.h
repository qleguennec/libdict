/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdict.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 00:15:41 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/30 19:14:28 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBDICT_H
# define LIBDICT_H

# include "../libvect/libvect.h"
# include "../libft/libft.h"
# include <string.h>

# define DICT_DELETED	1 << 0
# define DICT_USED		1 << 1
# define DICT_EXIST		(DICT_DELETED | DICT_USED)
# define DICT_EMPTY		(!DICT_EXIST)
# define DICT_AVAIL		(!DICT_USED)

# define DICT_GROWTH_FACTOR GROWTH_FACTOR

typedef struct	s_dict_ent
{
	void		*key;
	t_vect		val;
}				t_dict_ent;

typedef struct	s_dict
{
	t_dict_ent	*ents;
	size_t		used;
	size_t		total;
	size_t		del;
	long		(*hash_f)(void *);
	t_cmp_f		cmp_f;
	t_list		*free;
}				t_dict;

# define DICT_IMPORT_ADD	1
# define DICT_IMPORT_SET	2
# define DICT_IMPORT_STR	4

char			**dict_str_export(t_dict *d, char *sep);
int				dict_del(t_dict *d, void *key);
int				dict_istype(t_dict_ent *ent, int type);
int				dict_iter(t_dict *d, t_dict_ent **ent, int type);
int				dict_modify
	(t_dict *d, void *key, int type, void (*f)(t_dict *, t_dict_ent *));
int				dict_str_import(t_dict *d, char *s, char *sep, int opts);
long			dict_str_hash(char *s);
size_t			dict_size(t_dict *d, int type);
t_dict_ent		*dict_find_ent(t_dict *d, void *key, int type);
t_dict_ent		*dict_find_match(t_dict *d, void *key, int type);
t_dict_ent		*dict_find_maybe(t_dict *d, void *key, int type);
t_dict_ent		*dict_lookup(t_dict *d, void *key);
void			*dict_fmap
	(t_dict *d, int type, void *(*f)(t_dict *d, void *), void *ctxt);
void			dict_add(t_dict *d, void *key, void *val, size_t size);
void			dict_clear(t_dict *d);
void			dict_cpy(t_dict *dest, t_dict *src);
void			dict_dup(t_dict *dest, t_dict *src);
void			dict_ent_add(t_dict *d, t_dict_ent *ent);
void			dict_ent_cpy(t_dict *d, t_dict_ent *new);
void			dict_ent_del(t_dict *d, t_dict_ent *ent);
void			dict_ent_free(t_dict *d, t_dict_ent *ent);
void			dict_free(t_dict *d);
void			dict_init
	(t_dict *d, size_t len, long (*hashf)(void *), t_cmp_f cmp_f);
void			dict_map
	(t_dict *d, int type, void (*f)(t_dict *, t_dict_ent *));
void			dict_map2(t_dict *dest
	, t_dict *src, int type, void (*f)(t_dict *d, t_dict_ent *ent));
void			dict_print(t_dict *d, char *sep, char *nl);
void			dict_regen(t_dict *d);
void			dict_set(t_dict *d, void *key, void *val, size_t size);
void			dict_str_add(t_dict *d, void *key, char *val);
void			dict_str_init(t_dict *d, size_t len);
void			dict_str_set(t_dict *d, void *key, char *val);
#endif
