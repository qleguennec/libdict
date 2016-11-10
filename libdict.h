/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdict.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 00:15:41 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/10 19:30:21 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBDICT_H
# define LIBDICT_H

# include "../libvect/libvect.h"
# include "../libft/libft.h"
# include <string.h>

# define DICT_EMPTY		1 << 0
# define DICT_AVAIL		1 << 1
# define DICT_EXIST		1 << 2
# define DICT_DEL		1 << 3
# define DICT_USED		1 << 4

typedef struct		s_dict_ent
{
	void			*key;
	t_vect			val;
}					t_dict_ent;

typedef struct		s_dict
{
	t_dict_ent		*ents;
	size_t			used;
	size_t			total;
	size_t			del;
	long			(*hash_f)(void *);
	t_cmp_f			cmp_f;
	t_list			*free;
	t_list			*avail;
}					t_dict;

char				**dict_str_export(t_dict *d, char *sep);
int					dict_del(t_dict *d, void *key);
int					dict_iter(t_dict *d, t_dict_ent **ent, size_t *n, int type);
int					dict_str_import(t_dict *d, char *s, char *sep);
long				dict_str_hash(char *s);
size_t				dict_find_slot(t_dict *d, void *key);
t_dict_ent			*dict_find_empty(t_dict *d, void *key);
t_dict_ent			*dict_find_match(t_dict *d, void *key);
t_dict_ent			*dict_lookup(t_dict *d, void *key);
void				dict_add(t_dict *d, void *key, void *val, size_t size);
void				dict_clean(t_dict *d);
void				dict_ent_clean(t_dict *d, t_dict_ent *ent);
void				dict_ent_del(t_dict *d, t_dict_ent *ent);
void				dict_free(t_dict *d);
void				dict_free(t_dict *d);
void				dict_init
	(t_dict *d, size_t len, long (*hashf)(void *), t_cmp_f cmp_f);
void				dict_mem_reuse(t_dict *d, t_dict_ent *ent);
void				dict_regen(t_dict *d, size_t grow);
void				dict_str_add(t_dict *d, void *key, char *val);
void				dict_str_init(t_dict *d, size_t len);
void				dict_vect_add(t_dict *d, void *key, t_vect val);

#endif
