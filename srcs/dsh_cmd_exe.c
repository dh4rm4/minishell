/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsh_cmd_exe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <kboddez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:22:52 by kboddez           #+#    #+#             */
/*   Updated: 2017/01/10 14:47:54 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
**	MANAGE THE EXECUTION AND THE ERROR OF CMD AND EXE FILES
*/

int	dsh_ex(char *cmd_path, t_dsh *viag)
{
	pid_t	pid;
	T_STAT	stat;

	if (lstat(cmd_path, &stat))
		return (ft_printf(NO_FILE_DIR, cmd_path));
	if (access(cmd_path, X_OK))
		return (ft_printf(NO_EX, cmd_path));
	pid = fork();
	if (pid == 0)
		execve(cmd_path, &CMD_SPLIT[0], ENV);
	else
		waitpid(pid, NULL, 0);
	return (0);
}

/*
**	MANAGE THE EXECUTION OF EXE FILE
*/

int	dsh_cmd_exe(t_dsh *viag)
{
	char	*path;
	char	*home;
	int		i;
	int		j;

	if (CMD_SPLIT[0][0] == '~')
	{
		i = -1;
		j = 0;
		home = dsh_getenv(viag, "HOME=");
		if (!(path = (char *)malloc(sizeof(*path) * \
			(ft_strlen(home) + ft_strlen(CMD_SPLIT[0])))))
			dsh_error(viag, -10);
		while (home[++i])
			path[i] = home[i];
		while (CMD_SPLIT[0][++j])
			path[i++] = CMD_SPLIT[0][j];
		path[++i] = '\0';
		free(home);
	}
	else
		path = ft_strdup(CMD_SPLIT[0]);
	dsh_ex(path, viag);
	free(path);
	return (0);
}
