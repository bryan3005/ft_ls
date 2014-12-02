/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 09:57:50 by mbryan            #+#    #+#             */
/*   Updated: 2014/12/02 16:18:10 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "stdio.h"

int option_a = 0;
int option_l = 0;
int option_r = 0;
int option_r_caps = 0;
int option_t = 0;

// prend les argument passer en parametre puis les met dans une list t1
argument	*take_argument(int argc, char const *argv[])
{
	argument *t1;
	int x;

	x = 1;
	t1 = NULL;
	t1 = initiaze_list(t1);
	while(x != argc)
	{
		t1 = addone2(t1, argv[x]);
		x++;
	}
	return (t1);
}
// lit l interieur des argument (pour l instant dossier uniquement)
argument	*take_inside(int argc, char const *argv[])
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
					test1 = addone(test1, ret2->d_name);
				}
			}
		x++;
		}
	}
	return (test1);
}

int main(int argc, char const *argv[])
{
	argument *t1;
	argument *test1;
	int trye;
	test1 = take_inside(argc, argv);
	t1 = take_argument(argc, argv);
	trye = check_option(t1);
	printf("%d\n", trye);
	read_list(test1);
	ft_putendl("\n----------------\n");
	read_list(t1);
	return 0;
}