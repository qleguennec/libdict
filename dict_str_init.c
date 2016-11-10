/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_str_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 03:44:03 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/10 17:45:27 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict.h"

void		dict_str_init(t_dict *d, size_t len)
{
	dict_init(d, len
		, (long (*)(void *))&dict_str_hash
		, (int (*)(void *, void *))&ft_strcmp);
}
