/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 14:18:05 by mbryan            #+#    #+#             */
/*   Updated: 2014/12/02 14:20:00 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//lit les liste

void	read_list(argument *test1)
{
	while(test1)
	{
		ft_putendl(test1->name);
		test1 = test1->next;
	}
}

//met dans les liste les char * recus 

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
//met dans les liste les CONST char * recus 

argument *addone2(argument *test1, char const *argv)
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

// initialize les liste

argument	*initiaze_list(argument *list)
{
	list = (argument*)malloc(sizeof(argument));
	list = NULL;
	return (list);
}