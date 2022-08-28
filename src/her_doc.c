/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   her_doc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaifi <adaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:42:09 by adaifi            #+#    #+#             */
/*   Updated: 2022/08/25 20:36:44 by adaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../mini.h"

int	her_doc(t_lexer *arg)
{
	char	*s;
	int		tmp;

	tmp = open("tmp", O_RDWR | O_CREAT | O_TRUNC, 00777);
	s = get_next_line(0);
	arg->content = ft_strjoin(arg->content, "\n");
	if (s == NULL || !ft_strcmp(s, arg->content))
		return (free(s), tmp);
	write(tmp, s, ft_strlen(s));
	while (ft_strcmp(s, arg->content))
	{
		s = get_next_line(0);
		if (s == NULL || !ft_strcmp(s, arg->content))
		{
			free(s);
			return (tmp);
		}
		write(tmp, s, ft_strlen(s));
	}
	free(s);
	return (tmp);
}
