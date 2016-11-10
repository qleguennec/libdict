/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdict_intern.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 06:20:55 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/10 18:35:02 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBDICT_INTERN_H
# define LIBDICT_INTERN_H

# include "libdict.h"

# define USED(e)				(e.val.used)
# define EXIST(e)				(e.key != NULL)
# define AVAIL(e)				(!USED(e))
# define DELETED(e)				(AVAIL(e) && EXIST(e))
# define EMPTY(e)				(AVAIL(e) && !USED(e))
# define MATCH(e, k)			(!d->cmp_f(e.key, k))

# define DICT_GROWTH_FACTOR		GROWTH_FACTOR
# define GROW_TRESHOLD			1.0 / DICT_GROWTH_FACTOR
# define REGEN_TRESHOLD			1.0 / 2.0
# define HASH_FACTOR			1000003

#endif
