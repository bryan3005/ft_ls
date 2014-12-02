/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 09:57:50 by mbryan            #+#    #+#             */
/*   Updated: 2014/12/02 14:23:04 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "stdio.h"

// prend les argument passer en parametre puis les met dans une list t1
void	take_argument(int argc, char const *argv[])
{
	argument *t1;
	int x;

	x = 0;
	t1 = NULL;
	t1 = initiaze_list(t1);
	while(x != argc)
	{
		t1 = addone2(t1, argv[x]);
		x++;
	}
	//read_list(t1);
}
// lit l interieur des argument (pour l instant dossier uniquement)
void	take_inside(int argc, char const *argv[])
{
	argument *test1;
	DIR *ret;
	struct dirent *ret2;
	int x;

	test1 = NULL;
	test1 = initiaze_list(test1);
	x = 1;
	(void)argv;

	if (argc == 1)
	{
		x++;
		ret = opendir(".");
		while((ret2 = readdir(ret)) != NULL)
			test1 = addone(test1, ret2->d_name);
	}

	if (argc > 1)
	{
		while(argv[x])
		{
			if ((ret = opendir(argv[x])) == NULL)
			{
				ft_putstr_fd("ft_ls: ", 2);
				perror(argv[x]);
			}
			else
			{
				while((ret2 = readdir(ret)) != NULL)
				{
					//ft_putendl(ret2->d_name);
					test1 = addone(test1, ret2->d_name);
					//read_list(test1);
				}
			}
		x++;
		}
		//x++;
	}
	read_list(test1);
}

int main(int argc, char const *argv[])
{
	take_inside(argc, argv);
	take_argument(argc, argv);
	return 0;
}