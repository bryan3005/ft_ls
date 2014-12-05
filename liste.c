/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 14:18:05 by mbryan            #+#    #+#             */
/*   Updated: 2014/12/05 10:41:07 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//lit les liste

void	read_list(t_argument *test1)
{
	while(test1)
	{
		ft_putendl(test1->name);
		test1 = test1->next;
	}
}

//met dans les liste les char * recus 

t_argument *addone(t_argument *test1, char *argv)
{
	t_argument *test;
	t_argument *tmp;
//read_list(test1);
	tmp = test1;
	if ((test = (t_argument*)malloc(sizeof(t_argument))) == NULL)
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

t_argument	*initiaze_list(t_argument *list)
{
	if((list = (t_argument*)malloc(sizeof(t_argument))) == NULL)
		exit(EXIT_FAILURE);
	list = NULL;
	return (list);
}