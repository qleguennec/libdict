/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_ent_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:02:56 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/11 14:04:47 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict.h"

void	dict_ent_dup(t_dict *d, t_dict_ent *ent)
{
	dict_add(d, ent->key, ent->val.data, ent->val.used);
}
