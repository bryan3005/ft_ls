/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:14:28 by mbryan            #+#    #+#             */
/*   Updated: 2014/11/16 13:20:49 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	z;
	char	*ptr;

	z = 0;
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = malloc(i * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (s1[z])
	{
		ptr[z] = s1[z];
		z++;
	}
	i = 0;
	while (s2[i])
	{
		ptr[z] = s2[i];
		z++;
		i++;
	}
	ptr[z] = '\0';
	return (ptr);
}
