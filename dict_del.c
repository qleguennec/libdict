/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 20:50:53 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/13 20:39:14 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

int		dict_del(t_dict *d, void *key)
{
	return (dict_modify(d, key, DICT_EXIST, &dict_ent_del));
}
