/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:53:51 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/11 14:47:34 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict.h"

void		dict_map(t_dict *d, int type, void (*f)(t_dict *, t_dict_ent *))
{
	t_dict_ent	*ent;

	ent = d->ents;
	while (dict_size(d, type) && dict_iter(d, &ent, type))
		f(d, ent++);
}
