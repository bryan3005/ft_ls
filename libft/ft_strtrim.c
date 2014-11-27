/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:33:47 by mbryan            #+#    #+#             */
/*   Updated: 2014/11/17 08:45:01 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_len(const char *s)
{
	int	len;
	int i;
	int j;

	len = 0;
	i = 0;
	j = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == ',')
		i++;
	while (s[i])
	{
		j = i;
		while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t' || s[j] == ',')
		{
			j++;
			if (s[j] == '\0')
				return (len);
		}
		i++;
		len++;
	}
	return (len);
}

char	*ml(const char *s)
{
	char	*ptr;

	ptr = malloc((ft_len(s) + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr[ft_len(s)] = '\0';
	return (ptr);
}

char	*ft_strtrim(char const *s)
{
	char	*ptr;
	int		i;
	int		j;
	int		k;

	ptr = ml(s);
	i = 0;
	j = 0;
	k = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == ',')
		i++;
	while (s[i])
	{
		j = i;
		while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t' || s[j] == ',')
		{
			j++;
			if (s[j] == '\0')
				return (ptr);
		}
		ptr[k] = s[i];
		i++;
		k++;
	}
	return (ptr);
}
