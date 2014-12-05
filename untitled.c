/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   untitled.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 10:05:55 by mbryan            #+#    #+#             */
/*   Updated: 2014/12/05 10:46:43 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "stdio.h"

int option_a = 0;
int option_l = 0;
int option_r = 0;
int option_r_caps = 0;
int option_t = 0;

/*
** prend les t_argument passer en parametre puis les met dans une list t1
*/

t_argument	*take_argument(char **argv, int i)
{
	t_argument *t1;

	t1 = NULL;
	t1 = initiaze_list(t1);
	while(argv[i])
	{

		t1 = addone(t1, argv[i]);
		i++;
	}
	return (t1);
}

/*
** lit l interieur des t_argument (pour l instant dossier uniquement) // -a -l dans readlist // -r -t dans take_arg
** -R dans take_inside
*/

void	take_inside(char *dir_name)
{
	t_argument *test1;
	DIR *ret;
	struct dirent *ret2;

	test1 = NULL;
	test1 = initiaze_list(test1);
	if ((ret = opendir(dir_name)) == NULL)
	{
		perror("opendir");
		return ;
	}
	while((ret2 = readdir(ret)) != NULL)
		test1 = addone(test1, ret2->d_name);
	read_list(test1);
}

int main(int argc, char **argv)
{
	t_argument *t1;
	int nb_opt;

	nb_opt = check_option(argv);
	t1 = take_argument(argv, nb_opt);
	if (argc == nb_opt)
		take_inside(".");
	else if (argc > nb_opt)
	{
		while (t1)
		{
			take_inside(t1->name);
			t1 = t1->next;
		}
	}
	return (0);
}
