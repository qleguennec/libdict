/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdict_intern.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 06:20:55 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/11 20:03:00 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBDICT_INTERN_H
# define LIBDICT_INTERN_H

# include "libdict.h"

# define DELETED(e)				(e.key != NULL && e.val.used == 0)
# define USED(e)				(e.key != NULL && e.val.used != 0)
# define EXIST(e)				(e.key != NULL)
# define EMPTY(e)				(e.key == NULL)
# define AVAIL(e)				(e.val.used == 0)

# define MATCH(e, k)			(!d->cmp_f(e.key, k))

# define GROW_THRESHOLD			1.0 / DICT_GROWTH_FACTOR
# define REGEN_THRESHOLD		1.0 / 2.0
# define HASH_FACTOR			1000003

#endif
