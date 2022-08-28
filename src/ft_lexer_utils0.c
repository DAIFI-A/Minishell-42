/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_utils0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 08:44:39 by med-doba          #+#    #+#             */
/*   Updated: 2022/08/20 17:57:10 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

int	ft_check_case(char c)
{
	if (c == '\0')
		return (-1);
	else if (c == '<' || c == '>' || c == '|')
		return (1);
	else if (c == ' ' || c == '\t')
		return (2);
	else if (c == '"' || c == '\'')
		return (3);
	else
		return (0);
}

int	ft_check_case_01(char c)
{
	if (c == '<' || c == '>' || c == '|' || c == ' ' || c == '\t')
		return (1);
	else
		return (0);
}

int	ft_check_case_02(char c)
{
	if ((c == '\0' || c == ' ' || c == '\t'))
		return (1);
	else
		return (0);
}

int	ft_check_case03(char c)
{
	if (c != '\0' && c != ' ' && c != '\t' && c != '|'
		&& c != '<' && c != '>')
		return (1);
	else
		return (0);
}

int	ft_skip_withespace(char *str, int i)
{
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	return (i);
}
