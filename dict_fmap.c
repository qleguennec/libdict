/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_fmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 13:33:43 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/12 17:25:15 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict.h"

void		*dict_fmap
	(t_dict *d, int type, void *(*f)(t_dict *d, void *), void *ctxt)
{
	t_dict	new;
	void	*ret;

	dict_init(&new, d->used * GROWTH_FACTOR, d->hash_f, d->cmp_f);
	dict_map2(&new, d, type, &dict_ent_add);
	ret = f(&new, ctxt);
	dict_free(&new);
	return (ret);
}
