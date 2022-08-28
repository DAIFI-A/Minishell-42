/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:04:11 by adaifi            #+#    #+#             */
/*   Updated: 2022/08/18 09:30:31 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../mini.h"

void	env_env(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strcmp(tmp->value, "\0") != 0)
		{
			if (tmp && tmp->key && tmp->value)
				printf("%s=%s\n", tmp->key, tmp->value);
		}
		tmp = tmp->next;
	}
}
