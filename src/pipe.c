/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaifi <adaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 19:38:47 by adaifi            #+#    #+#             */
/*   Updated: 2022/08/28 22:58:36 by adaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../mini.h"

char	*redirection_handler(t_lexer **arg, t_fds *fds, char *str)
{
	fds->flag = 0;
	while ((*arg) && (ft_strcmp((*arg)->content, "|")
			|| (*arg)->ch == '"' || (*arg)->ch == '\''))
	{
		if (!ft_strncmp((*arg)->content, "<", 1))
			input(arg, fds);
		else if (!ft_strncmp((*arg)->content, ">", 1))
			output(arg, fds);
		else
		{
			str = ft_strjoin(str, (*arg)->content);
			str = ft_strjoin(str, " ");
		}
		(*arg) = (*arg)->next;
	}
	if (str[0] != '\0' && fds->flag == 1)
		str = ft_strjoin(str, "tmp");
	return (str);
}

void	content_handler(t_lexer **arg, t_env **env, t_fds *fds)
{
	char	*str;
	t_lexer	*tmp;
	int		tmp_in;
	int		tmp_out;
	int		i;

	tmp = *arg;
	i = 0;
	str = ft_strdup("");
	tmp_in = dup(0);
	tmp_out = dup(1);
	str = redirection_handler(arg, fds, str);
	if (str[0] == '\0' && fds->flag == 1)
		return ;
	if (*str == '\0')
		return (printf("command not found\n"), var.exit_status = 127, free(str));
	dup2(tmp_in, STDIN_FILENO);
	dup2(tmp_out, STDOUT_FILENO);
	close(tmp_in);
	close(tmp_out);
	execute_redir(tmp, env, fds, str);
	free(str);
	unlink("tmp");
}

void	execute_redir(t_lexer *arg, t_env **env, t_fds *fds, char *str)
{
	char	**cmd;
	int		tmp_in;
	int		tmp_out;

	if (fds->in < 0 || fds->out < 0)
		return (var.exit_status = 1, ft_putendl_fd("fd rerror", 2));
	cmd = ft_split(str, ' ');
	tmp_in = dup(0);
	tmp_out = dup(1);
	dup2(fds->in, STDIN_FILENO);
	dup2(fds->out, STDOUT_FILENO);
	close(fds->in);
	close(fds->out);
	if (check_type(cmd[0]))
		builting(env, arg);
	else
		execute(cmd, env);
	dup2(tmp_in, STDIN_FILENO);
	dup2(tmp_out, STDOUT_FILENO);
	close(tmp_in);
	close(tmp_out);
	ft_free_2d(cmd);
}

void	execute(char **cmd, t_env **env)
{
	char	**envp;
	int		stat;

	stat = 0;
	var.cpid = fork();
	if (var.cpid < 0)
		return (printf("fork error"), var.exit_status = 1, ft_free_2d(cmd));
	var.id = 1;
	if (var.cpid == 0)
	{
		envp = env_str(*env);
		if (execve(get_path(cmd[0], env), cmd, envp) == -1
			|| check_upper(cmd[0]) || !get_path(cmd[0], env))
		{
			ft_free_2d(envp);
			ft_free_2d(cmd);
			return (ft_putendl_fd("command not found", 2), exit(127));
		}
		ft_free_2d(envp);
	}
	wait(&stat);
	var.exit_status = WEXITSTATUS(stat);
}

void	execute_pipe(t_env *env, t_lexer *arg, t_fds *fds, int i)
{
	int		j;
	int		tmp_in;
	int		tmp_out;

	j = 0;
	fds->fd = (int *)malloc((i * 2) * sizeof(int));
	tmp_in = dup(0);
	tmp_out = dup(1);
	while (j < i * 2)
	{
		pipe(fds->fd + j);
		j += 2;
	}
	i = i + 1;
	pipe_handler(fds, arg, env, i);
	j = -1;
	while (++j < i + 1)
		close(fds->fd[(j - 1) * 2]);
	dup2(tmp_in, STDIN_FILENO);
	dup2(tmp_out, STDOUT_FILENO);
	close(tmp_in);
	close(tmp_out);
	close(fds->in);
	close(fds->out);
	free(fds->fd);
}
