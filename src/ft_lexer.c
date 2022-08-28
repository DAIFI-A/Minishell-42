/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:59:27 by med-doba          #+#    #+#             */
/*   Updated: 2022/08/20 17:56:19 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

void	*ft_lexer(t_lexer **lexer, char *str, char **stock)
{
	int		i;

	i = 0;
	while (str[i])
	{
		i = ft_skip_withespace(str, i);
		if (ft_check_case(str[i]) == 0 || ft_check_case(str[i]) == 3)
		{
			if (ft_string(lexer, stock, str, &i) == 1)
				return (ft_free_lst(lexer), NULL);
		}
		else if (str[i] == '|')
		{
			if (ft_pipe(stock, str, &i, lexer) == 1)
				return (ft_free_lst(lexer), NULL);
		}
		else if (str[i] == '<' || str[i] == '>')
		{
			if (ft_redirection(stock, str, &i, lexer) == 1)
				return (ft_free_lst(lexer), NULL);
		}
		else if (str[i] != '\0')
			i++;
	}
	return (NULL);
}

int	ft_pipe(char **stock, char *str, int *i, t_lexer **lexer)
{
	*stock = ft_scan_pipe(str, str[*i], i);
	if (*stock == NULL)
		return (1);
	ft_add_node(lexer, stock, 0, 0);
	return (0);
}

int	ft_redirection(char **stock, char *str, int *i, t_lexer **lexer)
{
	*stock = ft_scan_redirection(str, i, str[*i]);
	if (*stock == NULL)
		return (1);
	ft_add_node(lexer, stock, 0, 0);
	return (0);
}
