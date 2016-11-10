/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_str_hash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 02:11:15 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/10 17:46:14 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

long		dict_str_hash(char *s)
{
	long	h;
	size_t	len;

	h = *s << 7;
	len = 0;
	while (*s)
	{
		h = (HASH_FACTOR * h) ^ *s++;
		len++;
	}
	return (h ^ len);
}
