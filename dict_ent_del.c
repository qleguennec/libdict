/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_ent_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:46:21 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/13 20:06:28 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

void	dict_ent_del(t_dict *d, t_dict_ent *ent)
{
	if (DELETED((*ent)))
		return ;
	d->del++;
	d->used--;
	ent->val.used = 0;
}
