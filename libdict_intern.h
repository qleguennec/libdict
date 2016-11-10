/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdict_intern.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 06:20:55 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/10 07:47:04 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBDICT_INTERN_H
# define LIBDICT_INTERN_H

#include "libdict.h"

# define USED(e)		(e.val.used)
# define EXISTS(e)		(e.key)
# define AVAIL(e)		(!USED(e))
# define DELETED(e)		(AVAIL(e) && EXISTS(e))
# define MATCH(e, k)	(!d->cmp(e.key, k))

void		lstadd(t_dict_fl **fl, void *mem);
void		lstfree(t_dict_fl *fl);

#endif
