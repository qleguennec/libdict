/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdict_intern.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 06:20:55 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/10 23:25:04 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBDICT_INTERN_H
# define LIBDICT_INTERN_H

# include "libdict.h"

# define USED(e)				(e.key != NULL && e.val.used != 0)
# define EXIST(e)				(e.key != NULL)
# define AVAIL(e)				(e.val.used == 0)
# define DELETED(e)				(e.key != NULL && e.val.used == 0)
# define EMPTY(e)				(e.key == NULL)

# define MATCH(e, k)			(!d->cmp_f(e.key, k))

# define GROW_TRESHOLD			1.0 / DICT_GROWTH_FACTOR
# define REGEN_TRESHOLD			1.0 / 4.0
# define HASH_FACTOR			1000003

#endif
