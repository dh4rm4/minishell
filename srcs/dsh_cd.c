/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <kboddez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:50:47 by kboddez           #+#    #+#             */
/*   Updated: 2017/01/17 12:32:15 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
**	CHECK IF VARIABLE elem EXIST IN ENV
*/

int			dsh_find_env(t_dsh *viag, char *elem)
{
	int	i;
	int	j;

	i = -1;
	while (ENV[++i])
	{
		j = 0;
		while (ENV[i][j] == elem[j])
			++j;
		if (j - 1 >= 0 && ENV[i][--j] == '=' && elem[j] == '=')
			break ;
	}
	if (!ENV[i] && !elem[j] && ENV[i - 1][j - 1] == elem[j - 1])
		return (0);
	return (1);
}

/*
**	CHANGE VARIABLE PWD && OLDPWD
*/

static int	dsh_cd_do(t_dsh *viag)
{
	char	*dst;
	char	*tmp;
	char	*old_dst;
	char	*get_cwd;

	tmp = dsh_getenv(viag, "PWD=");
	get_cwd = getcwd(NULL, 0);
	dst = ft_strjoin("PWD=", get_cwd);
	dsh_setenv(viag, dsh_init_env(ENV, dsh_envlen(ENV), NULL), dst);
	free(dst);
	old_dst = ft_strjoin("OLDPWD=", tmp);
	dsh_setenv(viag, dsh_init_env(ENV, dsh_envlen(ENV), NULL), old_dst);
	free(tmp);
	free(old_dst);
	free(get_cwd);
	return (0);
}

/*
**	CHANGE VARIABLE PWD ** OLDPWD FOR "cd -"
*/

static int	dsh_cd_back(t_dsh *viag)
{
	char	*dst;
	char	*path;
	char	*tmp;
	char	*old_dst;

	tmp = dsh_getenv(viag, "PWD=");
	path = getcwd(NULL, 0);
	dst = ft_strjoin("PWD=", path);
	free(path);
	dsh_setenv(viag, dsh_init_env(ENV, dsh_envlen(ENV), NULL), dst);
	free(dst);
	old_dst = ft_strjoin("OLDPWD=", tmp);
	dsh_setenv(viag, dsh_init_env(ENV, dsh_envlen(ENV), NULL), old_dst);
	free(tmp);
	free(old_dst);
	return (0);
}

/*
**	CHECK IF cd IS POSSIBLE AND MAKE IT
*/

static int	dsh_check_move(t_dsh *viag)
{
	T_STAT	stat;
	char	*dst;
	int		check;

	dst = NULL;
	if (!CMD_SPLIT[1] || !ft_strcmp("~", CMD_SPLIT[1]) ||
		!ft_strcmp("--", CMD_SPLIT[1]))
		dst = dsh_getenv(viag, "HOME=");
	else if (!ft_strcmp(CMD_SPLIT[1], "-"))
		dst = dsh_getenv(viag, "OLDPWD=");
	else
		dst = ft_strdup(CMD_SPLIT[1]);
	check = 0;
	if (!dst)
		return (ft_printf("%sError: %scan't reach dest\n", RED, WHITE));
	if (lstat(dst, &stat))
		check = ft_printf(CD_NO_FILE_DIR, dst);
	if (!check && access(dst, X_OK))
		check = ft_printf(CD_NO_EX, dst);
	if (!check && chdir(dst))
		check = 1;
	if (dst)
		free(dst);
	return (check);
}

int			dsh_cd(t_dsh *viag)
{
	char	*tmp;

	tmp = NULL;
	if (!dsh_check_move(viag))
	{
		if (!CMD_SPLIT[1] || (CMD_SPLIT[1] &&
							(!ft_strcmp(CMD_SPLIT[1], "~") ||
							!ft_strcmp(CMD_SPLIT[1], "--"))))
			if (!dsh_find_env(viag, "HOME="))
				return (ft_printf(HOME_ERROR, RED, WHITE));
			else
				return (dsh_cd_do(viag));
		else if (!ft_strcmp(CMD_SPLIT[1], "-"))
			return (dsh_cd_back(viag));
		return (dsh_cd_do(viag));
	}
	return (0);
}
