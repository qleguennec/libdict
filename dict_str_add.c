/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_str_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 02:22:36 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/09 06:03:56 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict.h"
#include "../libft/libft.h"

void		dict_str_add(t_dict *d, void *key, char *val)
{
	char	*k;

	k = ft_strdup(key);
	dict_add(d, k, val, ft_strlen(val));
}
