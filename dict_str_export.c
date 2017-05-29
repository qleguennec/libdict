/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_str_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 06:37:49 by qle-guen          #+#    #+#             */
/*   Updated: 2017/05/29 14:59:58 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

char		**dict_str_export(t_dict *d, char *sep)
{
	char		**ret;
	size_t		keylen;
	size_t		n;
	size_t		seplen;
	t_dict_ent	*ent;

	if (!(ret = malloc(sizeof(*ret) * (d->used + 1))))
		return (NULL);
	n = 0;
	ent = d->ents;
	seplen = ft_strlen(sep);
	while (n < d->used && dict_iter(d, &ent, DICT_USED))
	{
		keylen = ft_strlen(ent->key);
		if (!(ret[n] = malloc(1 + keylen + seplen + ent->val.used)))
			return (NULL);
		ft_memcpy(ret[n], ent->key, keylen);
		ft_memcpy(ret[n] + keylen, sep, seplen);
		ft_memcpy(ret[n] + keylen + seplen, ent->val.data, ent->val.used);
		*(ret[n] + keylen + seplen + ent->val.used) = '\0';
		ent++;
		n++;
	}
	ret[n] = NULL;
	return (ret);
}
