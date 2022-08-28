/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:23:41 by med-doba          #+#    #+#             */
/*   Updated: 2022/08/17 14:23:42 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len(int nbr)
{
	int	length;

	length = 0;
	if (nbr <= 0)
		length++;
	while (nbr != 0)
	{
		length++;
		nbr /= 10;
	}
	return (length);
}

int	ft_to(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		taille;

	taille = len(n);
	str = malloc(sizeof(char) * (taille + 1));
	if (str == NULL)
		return (NULL);
	str[taille] = '\0';
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		--taille;
		str[taille] = ft_to(n % 10) + 48;
		n = n / 10;
	}
	return (str);
}
