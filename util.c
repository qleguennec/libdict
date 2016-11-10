/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 06:15:03 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/10 04:14:23 by qle-guen         ###   ########.fr       */
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
	free(fl->mem);
	free(fl);
	lstfree(l);
}

void		lstadd(t_dict_fl **fl, void *mem)
{
	t_dict_fl	*new;

	new = ft_memalloc(sizeof(*fl));
	new->mem = mem;
	new->next = *fl;
	*fl = new;
}
