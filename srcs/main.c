/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <kboddez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 09:46:12 by kboddez           #+#    #+#             */
/*   Updated: 2017/01/16 17:58:02 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
**	REDIRECT CMD BETWEEN BUILTIN - COMMAND
*/

static int	dsh_redirect_cmd(t_dsh *viag)
{
	CMD_SPLIT = ft_strsplit(CMD, ' ');
	dsh_tilde(viag);
	if (!ft_strcmp(CMD_SPLIT[0], "echo"))
		return (dsh_echo(viag));
	if (!ft_strcmp(CMD_SPLIT[0], "env"))
		return (dsh_print_env(viag));
	if (!ft_strcmp(CMD_SPLIT[0], "setenv") && CMD_SPLIT[1])
		return (dsh_setenv(viag, dsh_init_env(ENV, dsh_envlen(ENV), NULL), \
						CMD_SPLIT[1]));
	else if (!ft_strcmp(CMD_SPLIT[0], "setenv"))
		return (ft_printf("Error: invalid option for setenv\n"));
	else if (!ft_strcmp("unsetenv", CMD_SPLIT[0]))
		return (dsh_unsetenv(viag, CMD_SPLIT[1]));
	else if (!ft_strcmp(CMD_SPLIT[0], "cd"))
		return (dsh_cd(viag));
	else if (!ft_strcmp(CMD_SPLIT[0], "reset"))
		return (dsh_reset_env(viag));
	return (dsh_cmd(viag));
}

/*
**	PRINT / MANAGE THE PROMPT
*/

static int	dsh_prompt(t_dsh *viag)
{
	int		i;
	char	*usr;

	usr = dsh_getenv(viag, ENV_USER);
	ft_printf("%sx%sX%sx %s%s", GREEN, YELLOW, RED, "\033[0;44m", usr);
	ft_printf("%s %sx%sX%sx%s> ", "\033[32;0m", GREEN, YELLOW, RED, WHITE);
	i = -1;
	if ((CMD = ft_strnew(2048)) == NULL)
		dsh_error(viag, -10);
	while (!ft_strchr(CMD, '\n'))
		read(0, &CMD[++i], 1);
	CMD[i] = '\0';
	dsh_parse(viag);
	dsh_flemme(i, &usr, viag);
	i = -1;
	while (CMD_SPLIT[++i])
		free(CMD_SPLIT[i]);
	if (CMD_SPLIT)
		free(CMD_SPLIT);
	return (dsh_prompt(viag));
}

/*
**	NEXT STEP OF
*/

int			dsh_flemme(int i, char **usr, t_dsh *viag)
{
	if (i == 0)
		return (dsh_prompt(viag));
	if (!dsh_cmd_space(viag))
	{
		free(CMD);
		CMD = NULL;
		return (dsh_prompt(viag));
	}
	if (CMD && !ft_strcmp(CMD, "exit"))
	{
		if (*usr)
			free(*usr);
		dsh_free_viag(viag);
		exit(0);
	}
	dsh_redirect_cmd(viag);
	if (CMD)
		free(CMD);
	CMD = NULL;
	if (*usr)
		free(*usr);
	*usr = NULL;
	return (0);
}

int			main(int ac, char *av[], char **env)
{
	t_dsh	viag;

	dsh_computer();
	viag.cmd = NULL;
	viag.cmd_split = NULL;
	viag.env = dsh_init_env(env, dsh_envlen(env), NULL);
	dsh_prompt(&viag);
	return (0);
}
