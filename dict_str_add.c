/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_str_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 02:22:36 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/12 21:43:47 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

void	dict_str_add(t_dict *d, void *key, char *val)
{
	dict_add(d, key, val, ft_strlen(val) + 1);
}
