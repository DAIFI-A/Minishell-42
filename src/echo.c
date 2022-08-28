/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaifi <adaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:06:02 by adaifi            #+#    #+#             */
/*   Updated: 2022/08/24 20:30:00 by adaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../mini.h"

void	echo(t_lexer *arg)
{
	char	**s;
	int		i;
	int		k;

	i = 0;
	if (arg && (!arg->next || !ft_strcmp(arg->next->content, "\0")))
		return (ft_putendl_fd("", 1));
	s = join_echo(&arg);
	k = check_newline(s);
	if (k != 0)
	{
		i = k;
		while (s[i])
		{
			printf("%s ", s[i]);
			i++;
		}
	}
	else
		echo_newline(s);
	ft_free_2d(s);
}

void	echo_newline(char **s)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strdup("");
	while (s[i])
	{
		str = ft_strjoin(str, s[i]);
		str = ft_strjoin(str, " ");
		i++;
	}
	printf("%s\n", str);
	free(str);
}

char	**join_echo(t_lexer **arg)
{
	char	*output;
	char	**s;

	output = ft_strdup("");
	while ((*arg)->next && ft_multiple_check((*arg)->next->content) != 2)
	{
		output = ft_strjoin(output, (*arg)->next->content);
		output = ft_strjoin(output, " ");
		(*arg) = (*arg)->next;
	}
	s = ft_split(output, ' ');
	free(output);
	return (s);
}

int	check_newline(char **str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = 1;
	while (str[i])
	{
		if (str[i][0] == '-' && str[i][j] == 'n')
			k++;
		i++;
		j++;
	}
	return (k);
}
