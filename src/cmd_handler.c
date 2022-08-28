/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:32:48 by adaifi            #+#    #+#             */
/*   Updated: 2022/08/18 09:21:19 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../mini.h"

int	check_type(char *arg)
{
	if (arg == NULL)
		return (0);
	if (!ft_strcmp(arg, "pwd"))
		return (1);
	else if (!ft_strcmp(arg, "export"))
		return (1);
	else if (!ft_strcmp(arg, "unset"))
		return (1);
	else if (!ft_strcmp(arg, "env"))
		return (1);
	else if (!ft_strcmp(arg, "exit"))
		return (1);
	else if (!ft_strcmp(arg, "cd"))
		return (1);
	else if (!ft_strcmp(arg, "echo"))
		return (1);
	return (0);
}

void	builting(t_env **env, t_lexer *arg)
{
	if (!ft_strcmp(arg->content, "pwd"))
		pwd_env();
	else if (!ft_strcmp(arg->content, "cd"))
		cd(*env, arg);
	else if (!ft_strcmp(arg->content, "unset"))
		unset_env(env, arg);
	else if (!ft_strcmp(arg->content, "echo"))
		echo(arg);
	else if (!ft_strcmp(arg->content, "export"))
		export_env(env, arg);
	else if (!ft_strcmp(arg->content, "env"))
		env_env(*env);
	else if (!ft_strcmp(arg->content, "exit"))
	{
		if (!arg->next)
			exit(var.exit_status);
		else if (arg->next->next)
			return (var.exit_status = 1, printf("too many args\n"), (void)arg);
		else if (arg->next)
			exit(ft_atoi(arg->next->content));
	}
}

void	check_cmd(t_env **env, t_lexer *arg, t_fds *fds)
{
	int		i;
	t_lexer	*tmp;

	i = 0;
	if (!arg)
		return ;
	tmp = arg;
	while (tmp)
	{
		if (!ft_strcmp(tmp->content, "|") && tmp->ch != '"' && tmp->ch != '\'')
			i++;
		tmp = tmp->next;
	}
	if (i == 0)
	{
		fds->in = dup(STDIN_FILENO);
		fds->out = dup(STDOUT_FILENO);
		content_handler(&arg, env, fds);
	}
	else
		execute_pipe(*env, arg, fds, i);
}
