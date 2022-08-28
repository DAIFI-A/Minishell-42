/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaifi <adaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 09:31:15 by med-doba          #+#    #+#             */
/*   Updated: 2022/08/23 23:15:42 by adaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

void	ft_expand(t_lexer **lexer, t_env *env)
{
	char		*tmp;
	t_lexer		*head;

	head = (*lexer);
	while ((*lexer))
	{
		if ((*lexer)->ch != '\'' && (ft_find_char((*lexer)->content, '$') == 0))
		{
			tmp = ft_parse_expand((*lexer)->content, env);
			(*lexer)->content = ft_strdup(tmp);
			free(tmp);
		}
		if ((*lexer)->ch != '"' && (*lexer)->ch != '\''
			&& (ft_find_char((*lexer)->content, '~') == 0))
			(*lexer)->content = ft_strdup(ft_tilde((*lexer)->content, env));
		if ((*lexer)->ch != '\'' && (ft_find_staus((*lexer)->content) == 0))
			(*lexer)->content = ft_expand_status((*lexer)->content);
		(*lexer) = (*lexer)->next;
	}
	(*lexer) = head;
}

char	*ft_parse_expand(char *str, t_env *env)
{
	char	*rtn;
	char	*stock;
	int		i;

	i = 0;
	rtn = ft_strdup("");
	stock = ft_strdup("");
	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			if (ft_if_condition(str[i]) == 0)
			{
				while (ft_if_condition(str[i]) == 0)
					stock = ft_join(stock, str[i++]);
				rtn = ft_join_value(env, &stock, rtn);
			}
			else if (ft_put_dollar(str[i]) == 0)
				rtn = ft_join(rtn, '$');
		}
		if (str[i] != '$' && str[i] != '\0')
			rtn = ft_join(rtn, str[i++]);
	}
	return (free(stock), free(str), rtn);
}

char	*ft_join_value(t_env *env, char **stock, char *rtn)
{
	while (env)
	{
		if (ft_strcmp((env)->key, *stock) == 0)
		{
			free(*stock);
			*stock = ft_strdup((env)->value);
			rtn = ft_strjoin(rtn, *stock);
			break ;
		}
		env = (env)->next;
	}
	free(*stock);
	*stock = ft_strdup("");
	return (rtn);
}

char	*ft_join(char *rtn, char c)
{
	char	*tmp;

	tmp = ft_char_to_str(c);
	rtn = ft_strjoin(rtn, tmp);
	free(tmp);
	return (rtn);
}

char	*ft_tilde(char *str, t_env *env)
{
	char	*rtn;
	t_env	*head;
	int		i;

	i = 1;
	if ((str[0] == '~' && str[1] == '\0') || (str[0] == '~' && str[1] == '/'))
	{
		rtn = ft_util_tilde(&env, &head, str, &i);
		free(str);
		return (rtn);
	}
	else
		rtn = ft_strdup(str);
	free(str);
	return (rtn);
}
