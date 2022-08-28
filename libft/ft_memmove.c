/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:23:18 by med-doba          #+#    #+#             */
/*   Updated: 2022/08/17 14:23:21 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*ptrd;
	const unsigned char	*ptrs;
	unsigned char		*d;
	const unsigned char	*s;

	ptrd = dst;
	ptrs = src;
	if (!src && !dst)
		return (NULL);
	if (ptrd < ptrs)
	{
		while (n--)
			*ptrd++ = *ptrs++;
	}
	else
	{
		d = ptrd + (n - 1);
		s = ptrs + (n - 1);
		while (n--)
			*d-- = *s--;
	}
	return (dst);
}
