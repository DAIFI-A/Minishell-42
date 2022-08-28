/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scan_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:27:29 by med-doba          #+#    #+#             */
/*   Updated: 2022/08/20 16:53:53 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

int	ft_utils_pipe(char *str)
{
	int	i;

	i = 0;
	i = ft_skip_withespace(str, i);
	if (str[i] == '|')
	{
		ft_putendl_fd("Error: syntax `|'", 2);
		return (1);
	}
	i = ft_strlen(str);
	i--;
	while (str[i] == ' ' || str[i] == '\t')
		i--;
	if (str[i] == '|')
	{
		ft_putendl_fd("Error: > ...", 2);
		return (1);
	}
	return (0);
}

char	*ft_qutes_util(char *str, char *rtn, int *i)
{
	char	*tmp;

	(*i)++;
	if (str[*i] && (str[*i] == '"' || str[*i] == '\'' ))
	{
		tmp = ft_scan_quotes(str, str[*i], i);
		rtn = ft_strjoin(rtn, tmp);
		free(tmp);
	}
	return (rtn);
}
