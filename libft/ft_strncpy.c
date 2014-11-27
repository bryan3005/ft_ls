/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 23:36:22 by mbryan            #+#    #+#             */
/*   Updated: 2014/11/14 12:30:03 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t z;

	z = 0;
	while (src[z] && z != n)
	{
		dst[z] = src[z];
		z++;
	}
	if (n > ft_strlen(src))
		while (dst[z])
		{
			dst[z] = '\0';
			z++;
		}
	return (dst);
}
