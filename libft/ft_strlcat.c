/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:54:21 by med-doba          #+#    #+#             */
/*   Updated: 2021/11/26 16:20:38 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	s;
	size_t	d;
	size_t	j;

	d = ft_strlen(dst);
	s = ft_strlen(src);
	j = 0;
	if (dstsize == 0)
		return (s);
	if (dstsize <= d)
		return (dstsize + s);
	while (src[j] != '\0' && (d + j) < dstsize - 1)
	{
		dst[d + j] = src[j];
		j++;
	}
	dst[d + j] = '\0';
	return (d + s);
}
