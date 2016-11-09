/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_str_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 06:37:49 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/09 08:27:59 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict.h"
#include "../malloc.h"
#include "../libft/libft.h"

char		**dict_str_export(t_dict *d, char sep)
{
	char	**ret;
	size_t	keylen;
	size_t	i;
	size_t	j;

	MALLOC_N(ret, d->used + 1);
	i = 0;
	j = 0;
	while (j < d->used)
	{
		if (d->ents[i].key)
		{
			keylen = ft_strlen(d->ents[i].key);
			MALLOC_N(*ret, 2 + keylen + d->ents[i].val.used);
			*ret = ft_mempcpy(*ret, d->ents[i].key, keylen);
			*(*ret)++ = sep;
			*ret = ft_mempcpy(*ret, d->ents[i].val.data, d->ents[i].val.used);
			**ret = '\0';
			*ret++ -= 1 + keylen + d->ents[i].val.used;
			j++;
		}
		i++;
	}
	*ret = NULL;
	return (ret - d->used);
}
