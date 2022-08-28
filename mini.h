/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaifi <adaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:19:50 by med-doba          #+#    #+#             */
/*   Updated: 2022/08/28 22:51:13 by adaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include <sys/types.h>
# include <signal.h>
# include <sys/stat.h>
# include <paths.h>
# include <sys/wait.h>
# include <sys/signal.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <readline/history.h>
# include <readline/readline.h>
# include "libft/libft.h"

struct s_global
{
	int		id;
	pid_t	cpid;
	int		exit_status;
	char	*usr;
} var;

typedef struct fds
{
	int		in;
	int		out;
	int		*fd;
	int		flag;
}	t_fds;

typedef struct lexer{
	char			*content;
	char			ch;
	int				linked;
	int				flag;
	struct lexer	*next;
}t_lexer;

typedef struct environment
{
	char				*key;
	char				*value;
	int					index;
	int					yes;
	struct environment	*next;
}t_env;

//main
void	ft_header(void);
void	ft_handle(t_env *env);
void	ft_control_d(void);
void	ft_sighandler(int sig);
//expand
void	ft_expand(t_lexer **lexer, t_env *env);
char	*ft_parse_expand(char *str, t_env *env);
int		ft_put_dollar(char c);
char	*ft_tilde(char *str, t_env *env);
int		ft_if_condition(char c);
char	*ft_util_tilde(t_env **env, t_env **head, char *str, int *i);
char	*ft_join(char *rtn, char c);
char	*ft_join_value(t_env *env, char **stock, char *rtn);
int		ft_find_staus(char *str);
char	*ft_expand_status(char *str);
//envp
t_env	*ft_environment(char **envp, t_env *env);
void	ft_free_2d(char **ptr);
void	ft_while_env(t_env **env, char **envp, t_env **node, int *i);
//parser
void	ft_parser(t_lexer **lexer);
//utils
int		ft_check_case(char c);
int		ft_check_case_01(char c);
int		ft_check_case_02(char c);
int		ft_check_case03(char c);
char	*ft_char_to_str(char c);
int		ft_locate_char(char *str, char ch);
int		ft_find_char(char *str, char c);
int		ft_skip_withespace(char *str, int i);
//lexer
void	*ft_lexer(t_lexer **lexer, char *rtn, char **stock);
char	*ft_scan_quotes(char *str, char c, int *i);
char	*ft_scan_redirection(char *rtn, int *i, char c);
char	*ft_scan_pipe(char *str, char c, int *i);
int		ft_utils_pipe(char *str);
void	ft_add_node(t_lexer **lexer, char **stock, char ch, int linked);
int		ft_pipe(char **stock, char *str, int *i, t_lexer **lexer);
int		ft_redirection(char **stock, char *str, int *i, t_lexer **lexer);
void	ft_else(char *str, char **stock, int *i);
int		ft_string(t_lexer **lexer, char **stock, char *str, int *i);
char	*ft_qutes_util(char *str, char *rtn, int *i);
//node
void	ft_free_lst_env(t_env **head);
void	ft_lstadd_back_env(t_env **lst, t_env *new);
t_env	*ft_lstnew_env(char *name, char *value);
void	ft_free_lst(t_lexer **head);
void	ft_lstadd_back(t_lexer **lst, t_lexer *new);
t_lexer	*ft_lstnew(char *content, int linked);
//execution
void	cd_home(t_env *env);
int		check_type(char *arg);
void	builting(t_env **env, t_lexer *arg);
void	one_cmd(t_env **env, t_lexer *arg, char **envp, char *str);
void	check_cmd(t_env **env, t_lexer *arg, t_fds *fd);
void	pwd_env(void);
char	*get_path(char *cmd, t_env **env);
char	**search_path(t_env **env, char	**paths);
void	unset_env(t_env **env, t_lexer *arg);
t_env	*unset(t_env *env, t_env *tmp, t_lexer *arg);
void	free_env(t_env *env);
void	echo(t_lexer *arg);
char	**join_echo(t_lexer **arg);
void	echo_newline(char **s);
int		check_newline(char **str);
void	export_env(t_env **env, t_lexer *arg);
void	set_env_existed(t_env **env, t_lexer *arg, t_env **lst);
void	cd(t_env *env, t_lexer *arg);
t_env	*ft_lst_new1(char *key, char *value);
t_lexer	*ft_lst_new_prime(char *str);
void	ft_lstadd_back_prime(t_env **lst, t_env *node);
char	*get_keys(char *str, int c);
void	env_env(t_env *env);
char	**env_str(t_env *env);
void	execute_pipe(t_env *env, t_lexer *arg, t_fds *fds, int i);
void	pipe_handler(t_fds *fds, t_lexer *arg, t_env *env, int i);
void	content_handler(t_lexer **arg, t_env **env, t_fds *fds);
void	execute_redir(t_lexer *arg, t_env **env, t_fds *fds, char *str);
char	*redirection_handler(t_lexer **arg, t_fds *fds, char *str);
void	input(t_lexer **arg, t_fds *fds);
void	output(t_lexer **arg, t_fds *fds);
void	execute(char **cmd, t_env **env);
int		her_doc(t_lexer *arg);
char	*get_next_line(int fd);
void	update_pwd(t_env **lst, char *home);
int		ft_multiple_check(char *arg);
void	ft_print_exported(t_env **env);
void	ft_add_export(char *str, t_env **env);
void	ft_sort_env(t_env **env);
int		check_upper(char *str);
#endif
