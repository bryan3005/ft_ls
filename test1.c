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


/*void	read(int argc, char const **argv)
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
}*/
void	read_list(argument *test1)
{
	while(test1)
	{
		ft_putendl(test1->name);
		test1 = test1->next;
	}
}
argument *addone(argument *test1,char *argv)
{
	argument *test;
	argument *tmp;

	tmp = test1;
	if ((test = (argument*)malloc(sizeof(argument))) == NULL)
		exit(EXIT_FAILURE);
	test->name = argv;
	test->next = NULL;
	if (test1 == NULL)
		return (test);
	else
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = test;
		return(test1);
	}

}

int main(int argc, char const *argv[])
{
	DIR *ret;
	struct dirent *ret2;
	argument *test;
	int x;
	test = (argument*)malloc(sizeof(argument));
	test = NULL;
	x = 0;

	while (x != argc)
	{
		if (x == 0)
			ret = opendir(".");
		while((ret2 = readdir(ret)) != NULL)
			test = addone(test, ret2->d_name);
		x++;
	}
	//test = addone(test, "bonjour");
	//test = addone(test, "hello");
	read_list(test);
		return 0;
}











