/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:18:47 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/10 21:08:35 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict.h"

void		dict_clean(t_dict *d)
{
	size_t		n;
	t_dict_ent	*ent;

	n = 0;
	ent = d->ents;
	while (dict_iter(d, &ent, &n, DICT_EXIST))
		free(ent++->val.data);
}
