/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:25:17 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/11 14:36:03 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict.h"

void		dict_free(t_dict *d)
{
	dict_map(d, DICT_EXIST, &dict_ent_free);
	free(d->ents);
	ft_lstfree(d->free);
}
