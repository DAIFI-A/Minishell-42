/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_scan.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaifi <adaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:19:15 by med-doba          #+#    #+#             */
/*   Updated: 2022/08/24 21:11:49 by adaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

char	*ft_scan_quotes(char *str, char c, int *i)
{
	char	*rtn;

	rtn = ft_strdup("");
	(*i)++;
	while (1)
	{
		if (str[*i] == c)
		{
			(*i)++;
			return (rtn);
		}
		if (str[*i] == '\0')
			return (free(rtn), ft_putendl_fd("Error: quote >...", 2), NULL);
		rtn = ft_join(rtn, str[*i]);
		(*i)++;
	}
	return (rtn);
}

char	*ft_scan_pipe(char *str, char c, int *i)
{
	char	*rtn;
	char	*tmp;

	if (ft_utils_pipe(str) == 0)
	{
		rtn = ft_strdup("");
		if (str[(*i) + 1] == c)
		{
			ft_putendl_fd("Error: syntax `|'", 2);
			return (free(rtn), NULL);
		}
		tmp = ft_char_to_str(str[*i]);
		rtn = ft_strjoin(rtn, tmp);
		free(tmp);
		(*i)++;
		if (str[*i] == ' ' || str[*i] == '\t')
		{
			(*i) = ft_skip_withespace(str, *i);
			if (str[*i] == '|')
				return (ft_putendl_fd("Error: syntax `|'", 2), free(rtn), NULL);
		}
		return (rtn);
	}
	return (NULL);
}

char	*ft_scan_redirection(char *str, int *i, char c)
{
	char	*rtn;
	char	*tmp;
	int		count;

	count = 0;
	rtn = ft_strdup("");
	while (str[*i] == c)
	{
		if (count == 2 || str[*i] == '\0' || str[*i + 1] == '\0')
			return (free(rtn), ft_putendl_fd("Error:(< | >)", 2), NULL);
		tmp = ft_char_to_str(str[*i]);
		rtn = ft_strjoin(rtn, tmp);
		free(tmp);
		(*i)++;
		if (str[*i] == ' ' || str[*i] == '\t')
		{
			(*i) = ft_skip_withespace(str, *i);
			if (str[*i] == '<' || str[*i] == '>')
				return (free(rtn),
					ft_putendl_fd("Error:(< | >)", 2), NULL);
		}
		count++;
	}
	return (rtn);
}
