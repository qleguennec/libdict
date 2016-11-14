/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_str_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 21:25:27 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/14 16:15:54 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

void	dict_str_set(t_dict *d, void *key, char *val)
{
	return (dict_set(d, key, val, 1 + ft_strlen(val)));
}
