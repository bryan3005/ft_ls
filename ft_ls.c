/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 08:40:56 by mbryan            #+#    #+#             */
/*   Updated: 2014/12/01 14:49:19 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "stdio.h"

int option_a;
int option_l;
int option_r;
int	option_R;
int option_t;

void	Check_option(char l)
{
	static int x = 0;

	if (x == 0)
	{
		option_a = 0;
		option_l = 0;
		option_r = 0;
		option_R = 0;
		option_t = 0;
		x++;
	}
	if (l == 'a')
		option_a = 1;
	if (l == 'r')
		option_r = 1;
	if (l == 'l')
		option_l = 1;
	if (l == 'R')
		option_R = 1;
	if (l == 't')
		option_t = 1;
}	

void	option_char(char const ** argv)
{
	int x;
	int i;

	x = 1;
	i = 1;
	while(argv[x] && argv[x][0] == '-')
	{
		while(argv[x][i])
		{
			Check_option(argv[x][i]);
			i++;
		}
		x++;
		i = 1;
	}
}

int		Check_files(char const **argv)
{
	int x;

	x = 1;
	while (argv[x])
	{
		if(argv[x][0] == '-')
			x++;
	}
	if (x == 1)
		return (0);
	return (1);
}

void	read(int argc, char const **argv)
{
	int x;
	DIR *ret;
	struct dirent *ret2;

	x = 1;
	if (Check_files(argv) == 0)
	{
		ret = opendir(".");
		while ((ret2 = readdir(ret)) != NULL)
		{
			ft_putendl(ret2->d_name);
		}
	}
	while (x != argc)
	{
		if(argv[x][0] == '-')
			x++;
		ret = opendir(argv[x]);
		while ((ret2 = readdir(ret)) != NULL)
		{
			ft_putendl(ret2->d_name);
		}
		x++;
	}
}

int main(int argc, char const *argv[])
{
	option test;
	read(argc, argv);

	if (option_a == 1)
	{
		ft_putendl("try");
	}

	return 0;
}