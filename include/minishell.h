/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <kboddez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 09:49:13 by kboddez           #+#    #+#             */
/*   Updated: 2017/01/16 17:58:24 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
**	INCLUDE LIBS
*/
# include <dirent.h>
# include <pwd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include "../libft/libft.h"
# include "../ft_printf/libftprintf.h"

/*
**	TEST && OTHERS MACROS
*/
# define RED "\033[31m"
# define WHITE "\033[;0m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define YELLOW "\033[33m"
# define ITALIC "\x1b[3m"
# define SBUG(x) ft_printf("%s\n", x)

/*
**	BASICS ENV VARIABLES
*/
# define BASIC_ENV_PATH "PATH=/bin:/usr/bin:/sbin:/usr/sbin"
# define BASIC_ENV_USER "USER=boid"

/*
**	TYPE MACROS
*/
# define T_STAT struct stat
# define T_DIRENT struct dirent

/*
**	ERROS MACROS
*/
# define MALLOC_ERR -10
# define FORK_FAIL -11
# define NO_CMD "dsh: command not found: %s\n"
# define CD_NO_FILE_DIR "cd: no such file or directory: %s\n"
# define CD_NO_EX "cd: permission denied: %s\n"
# define NO_FILE_DIR "dsh: no such file or directory: %s\n"
# define NO_EX "dsh: permission denied: %s\n"
# define HOME_ERROR "%s/!\\ NO HOME DEFINE /!\\ \n%s"
# define SETENV_ERROR "%sError: %ssetenv: incorrect option\n"
# define BAD_UNSETENV "%sError: %sBad idea to delete this\n"

/*
**	ENV MACROS
*/
# define ENV_USER "USER="
# define ENV_PATH "PATH="
# define ENV_HOME "HOME="
# define ENV_PWD "PWD="
# define ENV_OLDPWD "OLDPWD="

/*
**	MACROS FOR STUCT VIAG
*/
# define ENV viag->env
# define CMD viag->cmd
# define CMD_SPLIT viag->cmd_split

typedef struct	s_dsh
{
	char	**env;
	char	*cmd;
	char	**cmd_split;
}				t_dsh;

typedef struct	s_idsh
{
	int			i;
	int			j;
	int			k;
	int			l;
}				t_idsh;

void			dsh_computer(void);

int				dsh_parse(t_dsh *viag);
int				dsh_tilde(t_dsh *viag);
int				dsh_flemme(int i, char **usr, t_dsh *viag);
int				dsh_cmd(t_dsh *viag);
int				dsh_cmd_exe(t_dsh *viag);

char			**dsh_init_env(char **env, int len_env, char *exept);
int				dsh_print_env(t_dsh *viag);
int				dsh_envlen(char **env);
int				dsh_ex(char *cmd_path, t_dsh *viag);

int				dsh_echo(t_dsh *viag);
int				dsh_cd(t_dsh *viag);
char			*dsh_getenv(t_dsh *viag, char *elem);
int				dsh_setenv(t_dsh *viag, char **tmp_env, char *elem);
int				dsh_unsetenv(t_dsh *viag, char *elem);
void			dsh_default_env(char **rtr);
int				dsh_reset_env(t_dsh *viag);

void			dsh_free_viag(t_dsh *viag);
void			dsh_error(t_dsh *viag, int n_err);
int				dsh_cmd_space(t_dsh *viag);

#endif
