/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_ent_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 03:15:20 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/12 17:24:33 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

void	dict_ent_add(t_dict *d, t_dict_ent *ent)
{
	return (dict_add(d, ent->key, ent->val.data, ent->val.used));
}
