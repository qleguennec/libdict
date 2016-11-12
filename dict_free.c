/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:25:17 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/12 21:51:20 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

void		dict_free(t_dict *d)
{
	dict_clear(d);
	dict_map(d, DICT_DELETED, &dict_ent_free);
	free(d->ents);
	ft_lstfree(d->free);
}
