/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_lookup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 00:46:39 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/12 21:01:33 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

t_dict_ent		*dict_lookup(t_dict *d, void *key)
{
	return (dict_find_match(d, key, DICT_USED));
}
