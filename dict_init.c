/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 03:34:39 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/09 06:18:56 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict.h"
#include "../libft/libft.h"
#include "../malloc.h"

void		dict_init
	(t_dict *d, long (*hashf)(void *), int (*cmp)(void *, void *))
{
	d->ents = ft_memalloc(INIT_LEN * sizeof(*d->ents));
	d->total = INIT_LEN;
	d->used = 0;
	d->hashf = hashf;
	d->cmp = cmp;
	d->fl = NULL;
}
