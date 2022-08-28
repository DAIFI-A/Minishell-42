/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaifi <adaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:49:30 by med-doba          #+#    #+#             */
/*   Updated: 2022/08/26 01:46:29 by adaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	int		j;
	long	nb;
	long	f;

	j = 0;
	nb = 1;
	f = 0;
	while (str[j] == ' ' || str[j] == '\t' || str[j] == '\n'
		|| str[j] == '\r' || str[j] == '\v' || str[j] == '\f')
		j++;
	if (str[j] == '-' || str[j] == '+')
	{
		if (str[j] == '-')
			nb *= -1;
		j++;
	}
	while (str[j] >= '0' && str[j] <= '9')
	{
		f = (f * 10) + str[j] - 48;
		j++;
	}
	if ((f * nb) > __INT_MAX__ && (f * nb) < INT_MIN)
		return (ft_putendl_fd("Error: nbr overflow", 2), exit(1), 0);
	return (f * nb);
}
