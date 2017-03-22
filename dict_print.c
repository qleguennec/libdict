/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 04:39:04 by qle-guen          #+#    #+#             */
/*   Updated: 2017/03/21 15:39:26 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"
#include "../libft/libft.h"
#include <unistd.h>

void		dict_print(t_dict *d, char *sep, char *nl)
{
	char	**exp;
	size_t	i;

	exp = dict_str_export(d, sep);
	ft_qsort((void **)exp, d->used, (int (*)(void *, void *))&ft_strcmp, 0);
	i = 0;
	while (exp[i])
	{
		write(1, exp[i], ft_strlen(exp[i]));
		write(1, nl, ft_strlen(nl));
		free(exp[i]);
		i++;
	}
	free(exp);
}
