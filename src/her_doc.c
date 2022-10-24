/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   her_doc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaifi <adaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:42:09 by adaifi            #+#    #+#             */
/*   Updated: 2022/10/24 12:28:07 by adaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../mini.h"

int	her_doc(t_lexer *arg)
{
	char	*s;
	int	file;
	int	tmp;

	file = open("/tmp/tmpfile", O_WRONLY | O_CREAT | O_TRUNC, 00777);
	tmp = dup(file);
	s = readline(">");
	if (s == NULL || !ft_strcmp(s, arg->content))
		return (free(s), file);
	s = ft_strjoin(s, "\n");
	write(tmp, s, ft_strlen(s));
	while (ft_strcmp(s, arg->content))
	{
		s = readline(">");
		if (s == NULL || !ft_strcmp(s, arg->content))
		{
			free(s);
			return (file);
		}
		s = ft_strjoin(s, "\n");
		write(tmp, s, ft_strlen(s));
	}
	free(s);
	return (file);
}
