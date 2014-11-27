/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:29:10 by mbryan            #+#    #+#             */
/*   Updated: 2014/11/10 11:11:45 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi(const char *str)
{
	int i;
	int result;
	int signe;

	i = 0;
	result = 0;
	signe = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		signe = (str[i] - 44) * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	result *= signe;
	return (result);
}
