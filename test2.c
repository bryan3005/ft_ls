/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 09:57:50 by mbryan            #+#    #+#             */
/*   Updated: 2014/12/02 13:53:48 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "stdio.h"

void	read_list(argument *test1)
{
	while(test1)
	{
		ft_putendl(test1->name);
		test1 = test1->next;
	}
}


argument *addone(argument *test1, char *argv)
{
	argument *test;
	argument *tmp;
//read_list(test1);
	tmp = test1;
	if ((test = (argument*)malloc(sizeof(argument))) == NULL)
		exit(EXIT_FAILURE);
	test->previous = tmp;
	test->name = (char*)malloc((ft_strlen(argv)+1) * sizeof(char));
	//test->name = argv;
	ft_memmove(test->name, argv, (ft_strlen(argv) + 1));
	test->next = NULL;
	if (test1 == NULL)
		return (test);
	else
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
	tmp->next = test;
		
	return(test1);

}

void	take_argument(int argc, char const *argv[])
{
	argument *test1;
	DIR *ret;
	struct dirent *ret2;
	int x;

	test1 = (argument*)malloc(sizeof(argument));
	test1 = NULL;
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
				ft_putstr_fd("ft_ls", 2);
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
	take_argument(argc, argv);
	return 0;
}