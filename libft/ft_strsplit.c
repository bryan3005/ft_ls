/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 09:56:06 by mbryan            #+#    #+#             */
/*   Updated: 2014/11/17 08:39:53 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_strslenmot(char const *s, char c)
{
	int i;
	int mot;

	i = 0;
	mot = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i - 1] == c) || (s[0] != c && i == 0))
			mot++;
		i++;
	}
	return (mot);
}

int		ft_letterbyword(char const *s, int index, char c)
{
	int i;
	int nbmot;
	int len;

	len = 0;
	i = -1;
	nbmot = 0;
	while (nbmot != index + 1)
	{
		i++;
		if ((s[i] != c && s[i - 1] == c) || (s[0] != c && i == 0))
		{
			nbmot++;
		}
	}
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

char	**mallop(char const *s, char c)
{
	int		t;
	char	**cpy;
	int		i;

	t = 0;
	i = 0;
	t = ft_strslenmot(s, c);
	cpy = malloc((t + 1) * sizeof(char *));
	if (cpy == NULL)
		return (NULL);
	cpy[t] = '\0';
	while (t > 0)
	{
		cpy[i] = malloc((ft_letterbyword(s, i, c) + 1) * sizeof(char));
		if (cpy[i] == NULL)
			return (NULL);
		cpy[i][ft_letterbyword(s, i, c) + 1] = '\0';
		i++;
		t--;
	}
	return (cpy);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**cpy;
	int		i;
	int		j;
	int		e;

	j = 0;
	i = 0;
	e = 0;
	cpy = mallop(s, c);
	while (s[e])
	{
		while (s[e] == c && s[e])
			e++;
		while (s[e] != c && s[e])
		{
			cpy[i][j] = s[e];
			e++;
			j++;
		}
		while (s[e] == c && s[e])
			e++;
		j = 0;
		i++;
	}
	return (cpy);
}
