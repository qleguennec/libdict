/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_mem_reuse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:57:30 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/10 18:02:57 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict.h"

void		dict_mem_reuse(t_dict *d, t_dict_ent *ent)
{
	t_list	*l;

	if (!d->avail)
		return ;
	if (!(l = ft_lstpop(&d->avail)))
		return ;
	ent->val.data = l->mem;
	ent->val.total = l->size;
	free(l);
}
