/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 08:41:12 by mbryan            #+#    #+#             */
/*   Updated: 2014/12/15 10:13:36 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_LS_H
#define FT_LS_H

#include "libft.h"
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>

typedef struct			s_argument
{
	char 				*name;
	char				*path;
	struct s_argument	*next;
	struct s_argument	*previous;
}						t_argument;


t_argument				*take_argument(char **argv, int i);
void					take_inside(char *dir_name);
void					read_list(t_argument *test1);
t_argument 				*addone(t_argument *test1, char *argv);
t_argument 				*addone2(t_argument *test1, char *argv, char *dirname);
t_argument				*initiaze_list(t_argument *list);
int						check_option(char **argv);
void					a_option_l(char *t2);

#endif