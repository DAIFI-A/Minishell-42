/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:34:05 by med-doba          #+#    #+#             */
/*   Updated: 2022/08/26 18:13:49 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

void	ft_sighandler(int sig)
{
	if (sig == 2 && var.id == 0)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		var.exit_status = 1;
	}
	else if (sig == 2 && var.id == 1 && ft_strncmp(var.usr, "./minishell", 11))
	{
		var.exit_status = 130;
		printf("\n");
	}
	if (sig == 3 && var.id == 1 && ft_strncmp(var.usr, "./minishell", 11))
	{
		var.exit_status = 131;
		printf("Quit: 3");
		printf("\n");
	}
}

void	ft_control_d(void)
{
	printf("\033[11C\033[1A exit\n");
	var.exit_status = 0;
	exit(0);
}

void	ft_handle(t_env *env)
{
	char	*rtn;
	t_lexer	*lexer;
	t_lexer	*top;
	t_fds	fd;
	char	*stock;

	stock = NULL;
	while (1)
	{
		lexer = NULL;
		var.id = 0;
		rtn = readline("MiniShell>$");
		var.usr = rtn;
		if (rtn == NULL)
			return (free(rtn), ft_control_d());
		add_history(rtn);
		ft_lexer(&lexer, rtn, &stock);
		top = lexer;
		ft_expand(&lexer, env);
		ft_parser(&lexer);
		check_cmd(&env, lexer, &fd);
		if (lexer != NULL)
			ft_free_lst(&lexer);
		free(rtn);
	}
}

void	ft_init_global(void)
{
	var.exit_status = 0;
	var.id = 0;
	var.cpid = 0;
	var.usr = NULL;
}

int	main(int ac, char **av, char **envp)
{
	t_env	*env;

	env = NULL;
	ft_header();
	(void)ac;
	(void)av;
	ft_init_global();
	signal(2, ft_sighandler);
	signal(3, ft_sighandler);
	env = ft_environment(envp, env);
	ft_handle(env);
	ft_free_lst_env(&env);
	return (0);
}
