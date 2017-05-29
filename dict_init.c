/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 03:34:39 by qle-guen          #+#    #+#             */
/*   Updated: 2017/05/29 14:55:56 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

void		dict_init
	(t_dict *d, size_t len, long (*hash_f)(void *), t_cmp_f cmp_f)
{
	d->ents = malloc(len);
	if (d->ents == NULL)
		return ;
	ft_bzero(d->ents, len);
	d->total = len;
	d->used = 0;
	d->del = 0;
	d->hash_f = hash_f;
	d->cmp_f = cmp_f;
	d->free = NULL;
}
