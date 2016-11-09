/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdict.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 00:15:41 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/09 05:19:07 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBDICT_H
# define LIBDICT_H

# include "../libvect/libvect.h"
# include  <stdlib.h>

# define GROW_TRESHOLD	2.0 / 3.0
# define HASH_FACTOR	1000003
# define INIT_LEN		4

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
	long			(*hashf)(void *);
	int				(*cmp)(void *, void *);
}					t_dict;

int					dict_del(t_dict *d, char *key);
long				dict_str_hash(char *s);
size_t				dict_find_slot(t_dict *d, void *key);
t_dict_ent			*dict_find_ent(t_dict *d, void *key);
t_dict_ent			*dict_str_lookup(t_dict *d, char *key);
t_dict_ent			*dict_lookup(t_dict *d, void *key);
void				dict_add(t_dict *d, void *key, void *val, size_t size);
void				dict_free(t_dict *d);
void				dict_grow(t_dict *d);
void				dict_init
	(t_dict *d, long (*hashf)(void *), int (*cmp)(void *, void *));
void				dict_str_add(t_dict *d, void *key, char *val);
void				dict_str_init(t_dict *d);
void				dict_vect_add(t_dict *d, void *key, t_vect val);

#endif
