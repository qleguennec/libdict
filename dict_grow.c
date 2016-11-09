/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_grow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 00:51:48 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/09 02:58:29 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict.h"
#include "../malloc.h"
#include "../libft/libft.h"

void		dict_grow(t_dict *d)
{
	t_dict_ent	*old;
	size_t		i;

	old = d->ents;
	d->total *= GROWTH_FACTOR;
	MALLOC(d->ents, d->total);
	ft_bzero(d->ents, d->total * sizeof(*d->ents));
	i = -1;
	while (++i < d->used)
		dict_vect_add(d, old[i].key, old[i].val);
}
