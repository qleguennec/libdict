/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 06:15:03 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/09 06:29:46 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict.h"
#include "../libft/libft.h"

void		lstfree(t_dict_fl *fl)
{
	t_dict_fl	*l;

	if (!fl)
		return ;
	l = fl->next;
	free(fl->p);
	free(fl);
	lstfree(l);
}

void		lstadd(t_dict *d, void *p)
{
	t_dict_fl	*fl;

	fl = ft_memalloc(sizeof(*fl));
	fl->p = p;
	if (d->fl)
		fl->next = d->fl;
	d->fl = fl;
}
