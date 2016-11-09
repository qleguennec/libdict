/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdict_intern.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 06:20:55 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/09 06:32:09 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBDICT_INTERN_H
# define LIBDICT_INTERN_H

#include "libdict.h"

void		lstadd(t_dict *d, void *p);
void		lstfree(t_dict_fl *fl);

#endif
