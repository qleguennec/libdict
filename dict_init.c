/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 03:34:39 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/10 04:16:01 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict.h"
#include "../libft/libft.h"

void		dict_init
	(t_dict *d, size_t len, long (*hashf)(void *), int (*cmp)(void *, void *))
{
	d->ents = ft_memalloc(len * sizeof(*d->ents));
	d->total = len;
	d->used = 0;
	d->del = 0;
	d->hashf = hashf;
	d->cmp = cmp;
	d->free = NULL;
}
