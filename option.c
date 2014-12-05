/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 13:51:30 by mbryan            #+#    #+#             */
/*   Updated: 2014/12/05 10:41:06 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "stdio.h"

extern int option_a;
extern int option_l;
extern int option_r;
extern int option_r_caps;
extern int option_t;

void 	check_valide(char s)
{
	if (s == 'a')
		option_a = 1;
	else if (s == 'l')
		option_l = 1;
	else if (s == 't')
		option_t = 1;
	else if (s == 'r')
		option_r = 1;
	else if (s == 'R')
		option_r_caps = 1;
	else
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(s, 2);
		ft_putstr_fd("\nusage: ./ft_ls [-Ralrt] [file ...]\n", 2);
		exit(EXIT_FAILURE);
	}
}

int		check_option(char **argv)
{
	int			i;
	int			j;

	i = 1;
	while (argv[i] && argv[i][0] == '-')
	{
		j = 1;
		while (argv[i][j])
		{ 
			check_valide(argv[i][j]);
			j++;
		}
		i++;
	}
	return (i);
}
