/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_str_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 06:37:49 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/10 17:37:58 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict.h"
#include "../libft/malloc.h"

char		**dict_str_export(t_dict *d, char *sep)
{
	char		**ret;
	size_t		keylen;
	size_t		n;
	size_t		seplen;
	t_dict_ent	*ent;

	MALLOC_N(ret, d->used + 1);
	n = 0;
	ent = d->ents;
	seplen = ft_strlen(sep);
	while (dict_iter(d, &ent, &n))
	{
		keylen = ft_strlen(ent->key);
		MALLOC_N(*ret, 2 + keylen + ent->val.used);
		*ret = ft_mempcpy(*ret, ent->key, seplen);
		*ret = ft_mempcpy(*ret, sep, ft_strlen(sep));
		*ret = ft_mempcpy(*ret, ent->val.data, ent->val.used);
		**ret = '\0';
		*ret -= 1 + keylen + ent->val.used + seplen;
		ret++;
		ent++;
	}
	*ret = NULL;
	return (ret - d->used);
}
