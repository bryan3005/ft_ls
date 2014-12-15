/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 13:50:05 by mbryan            #+#    #+#             */
/*   Updated: 2014/12/15 11:08:14 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>
#include "ft_ls.h"

void	rigthgrp(int test, mode_t mode, char right)
{
	if ((test & mode) != 0)
		ft_putchar(right);
	else
		ft_putchar('-');
}
/*
int		check_size_link(int	nb_link)
{
	char 	*nb_link_c;
	int 	i;

	i = 0;
	nb_link_c = ft_itoa(nb_link);
	i = ft_strlen(nb_link_c);
	printf("try:%d", i );
	return (i);
}*/



void	a_option_l(char *t2)
{
	struct stat 	*ptr;
	mode_t			mode;
	char			*date;

	ptr = (struct stat*)malloc(sizeof(struct stat));
	lstat(t2,ptr);
	mode = ptr->st_mode;
	date = (char*)malloc(ft_strlen(((ctime(&(ptr->st_mtime)) + 4)) + 1) * sizeof(char));
	ft_strcpy(date, ctime(&(ptr->st_mtime)) + 4);
	date[12] = '\0';
	if (S_ISREG(ptr->st_mode) != 0)
		ft_putchar('-');
	if (S_ISDIR(ptr->st_mode) != 0)
		ft_putchar('d');
	rigthgrp(S_IRUSR, ptr->st_mode, 'r');
	rigthgrp(S_IWUSR, ptr->st_mode, 'w');
	rigthgrp(S_IXUSR, ptr->st_mode, 'x');
	rigthgrp(S_IRGRP, ptr->st_mode, 'r');
	rigthgrp(S_IWGRP, ptr->st_mode, 'w');
	rigthgrp(S_IXGRP, ptr->st_mode, 'x');
	rigthgrp(S_IROTH, ptr->st_mode, 'r');
	rigthgrp(S_IWOTH, ptr->st_mode, 'w');
	rigthgrp(S_IXOTH, ptr->st_mode, 'x');
//	check_size_link(ptr->st_nlink);
	ft_putstr("  ");
	ft_putnbr(ptr->st_nlink);
	ft_putstr(" ");
	ft_putstr(getpwuid(ptr->st_uid)->pw_name);
	ft_putstr("  ");
	ft_putstr(getgrgid(ptr->st_gid)->gr_name);
	ft_putstr("  ");
	ft_putnbr(ptr->st_size);
	ft_putstr(" ");
	ft_putstr(date);
	ft_putstr(" ");
	free(date);
	free(ptr);
}