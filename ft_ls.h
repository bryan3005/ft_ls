/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 08:41:12 by mbryan            #+#    #+#             */
/*   Updated: 2014/12/02 14:50:04 by mbryan           ###   ########.fr       */
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


argument	*take_argument(int argc, char const *argv[]);
argument	*take_inside(int argc, char const *argv[]);
void	read_list(argument *test1);
argument *addone(argument *test1, char *argv);
argument *addone2(argument *test1, char const *argv);
argument	*initiaze_list(argument *list);
int		check_option(argument *list);

#endif