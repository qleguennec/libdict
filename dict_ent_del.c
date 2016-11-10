/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_ent_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:46:21 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/10 17:17:14 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

void	dict_ent_del(t_dict *d, t_dict_ent *ent)
{
	ent->val.used = 0;
	d->del++;
	d->used--;
	if ((float)d->del / (float)d->used > REGEN_TRESHOLD)
		dict_regen(d, 0);
}
