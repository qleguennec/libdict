/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_fmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 13:33:43 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/14 16:55:31 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict.h"

void		*dict_fmap
	(t_dict *d, int type, void *(*f)(t_dict *d, void *), void *ctxt)
{
	size_t	newsize;
	t_dict	new;
	void	*ret;

	newsize = d->used ? d->used * GROWTH_FACTOR : 1;
	dict_init(&new, newsize, d->hash_f, d->cmp_f);
	dict_map2(&new, d, type, &dict_ent_add);
	ret = f(&new, ctxt);
	dict_free(&new);
	return (ret);
}
