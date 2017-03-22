/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_str_import.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 05:24:42 by qle-guen          #+#    #+#             */
/*   Updated: 2017/03/22 14:46:28 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"
#include "../libft/malloc.h"

int	dict_str_import(t_dict *d, char *s, char *sep, int opts)
{
	char	*key;
	char	*s1;
	char	*val;
	size_t	len;
	t_list	*new;

	s1 = ft_strstr(s, sep);
	if (s1 == NULL || s1 == s)
		return (0);
	len = !!(opts & DICT_IMPORT_STR) + s1 - s;
	MALLOC_N(key, len);
	MALLOC1(new);
	new->p = key;
	new->next = d->free;
	d->free = new;
	ft_memcpy(key, s, s1 - s);
	if (opts & DICT_IMPORT_STR)
		key[s1 - s] = '\0';
	val = s1 + ft_strlen(sep);
	len = !!(opts & DICT_IMPORT_STR) + ft_strlen(val);
	if (opts & DICT_IMPORT_ADD)
		dict_add(d, key, val, len);
	else if (opts & DICT_IMPORT_SET)
		dict_set(d, key, val, len);
	return (1);
}
