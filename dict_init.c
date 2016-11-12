/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 03:34:39 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/12 01:37:28 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

void		dict_init
	(t_dict *d, size_t len, long (*hash_f)(void *), t_cmp_f cmp_f)
{
	d->ents = ft_memalloc(len * sizeof(*d->ents));
	d->total = len;
	d->used = 0;
	d->del = 0;
	d->hash_f = hash_f;
	d->cmp_f = cmp_f;
	d->free = NULL;
}
