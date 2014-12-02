/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 08:41:12 by mbryan            #+#    #+#             */
/*   Updated: 2014/12/02 13:48:42 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_LS_H
#define FT_LS_H

#include "libft.h"
#include <dirent.h>
#include <stdlib.h>

typedef struct  option
{
	int option_a;
	int option_l;
	int option_r;
	int	option_R;
	int option_t;
}option;

typedef struct argument
{
	char *name;
	struct argument *next;
	struct argument *previous;
}				argument;

#endif