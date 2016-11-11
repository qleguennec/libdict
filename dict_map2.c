/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:58:04 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/11 15:39:10 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict.h"

void		dict_map2
	(t_dict *src, t_dict *dest, int type, void (*f)(t_dict *d, t_dict_ent *ent))
{
	t_dict_ent	*ent;

	ent = src->ents;
	while (dict_size(src, type) != dict_size(dest, type)
			&& dict_iter(src, &ent, type))
		f(dest, ent++);
}
