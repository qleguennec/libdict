/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_modify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:20:01 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/11 13:24:18 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict.h"

int			dict_modify(t_dict *d, void *key, void (*f)(t_dict *, t_dict_ent *))
{
	t_dict_ent	*ent;

	ent = dict_lookup(d, key);
	if (!ent)
		return (0);
	f(d, ent);
	return (1);
}
