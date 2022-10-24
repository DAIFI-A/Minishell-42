/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaifi <adaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:55:52 by adaifi            #+#    #+#             */
/*   Updated: 2022/08/26 20:20:37 by adaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/// SEG when we run cd test/test1 then rm -rf ../../test then cd ..
/// => https://stackoverflow.com/questions/67251953/implement-cd-command-in-c#:~:text=%2D%20is%20a%20special%20argument%20for,directory%20in%20a%20global%20array.

#include"../mini.h"

void	cd_home(t_env *env)
{
	t_env	*lst;
	char	*home;
	char	oldpwd[1024];

	lst = env;
	home = NULL;
	getcwd(oldpwd, 1024);
	while (env)
	{
		if (!ft_strcmp(env->key, "HOME"))
		{
			home = env->value;
			break ;
		}
		env = env->next;
	}
	if (!home)
		return (var.exit_status = 1, ft_putendl_fd("Home not set", 2));
	else
		chdir(home);
	update_pwd(&lst, oldpwd);
}

void	cd(t_env *env, t_lexer *arg)
{
	t_env	*lst;
	char	oldpwd[1024];

	lst = env;
	getcwd(oldpwd, 1024);
	if (!arg->next || (ft_multiple_check(arg->next->content) == 2
			&& arg->ch != 0))
		cd_home(env);
	while (arg->next)
	{
		if (ft_multiple_check(arg->next->content) == 2)
			break ;
		if (chdir(arg->next->content) && getcwd(arg->next->content, 1024))
		{
			var.exit_status = 1;
			return (ft_putendl_fd("No such file or directory", 2));
		}
		update_pwd(&lst, oldpwd);
		arg = arg->next;
	}
}

void	update_pwd(t_env **lst, char *home)
{
	//char	*old_pwd;
	t_env	*env;

	env = (*lst);
	//old_pwd = home;
	while ((*lst))
	{
		if (!ft_strcmp((*lst)->key, "PWD"))
		{
			getcwd((*lst)->value, 1024);
			break ;
		}
		(*lst) = (*lst)->next;
	}
	*lst = env;
	while ((*lst))
	{
		if (!ft_strcmp((*lst)->key, "OLDPWD"))
		{
			free((*lst)->value);
			(*lst)->value = ft_strdup(home);
			break ;
		}
		(*lst) = (*lst)->next;
	}
}
