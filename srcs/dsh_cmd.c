/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsh_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <kboddez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:08:50 by kboddez           #+#    #+#             */
/*   Updated: 2017/01/17 12:14:37 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
**	EXECUTE THE INPUT CMD
*/

static int	dsh_exec(char *cmd_path, t_dsh *viag)
{
	char	*full_name;
	int		i;
	int		j;

	if (!(full_name = (char *)malloc(ft_strlen(CMD) + ft_strlen(cmd_path) + 2)))
		dsh_error(viag, -10);
	i = -1;
	j = -1;
	while (cmd_path[++i])
		full_name[++j] = cmd_path[i];
	full_name[++j] = '/';
	i = -1;
	while (CMD_SPLIT[0][++i])
		full_name[++j] = CMD_SPLIT[0][i];
	full_name[++j] = '\0';
	dsh_ex(full_name, viag);
	free(full_name);
	free(cmd_path);
	return (0);
}

/*
**	CHECK IF CMD IS PRESENT IN DIR path
*/

static int	dsh_find_exec(t_dsh *viag, char *path)
{
	DIR			*s_dir;
	T_DIRENT	*rt_dir;

	if ((s_dir = opendir(path)) == NULL)
		return (0);
	while ((rt_dir = readdir(s_dir)) != NULL)
	{
		if (!(ft_strcmp(CMD_SPLIT[0], rt_dir->d_name)))
		{
			closedir(s_dir);
			return (1);
		}
	}
	closedir(s_dir);
	return (0);
}

/*
**	PART II OF DSH_CMD
*/

static int	dsh_cmd_ii(t_dsh *viag, char *all_cmd_path, char *cur_path)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (all_cmd_path[++j])
	{
		if (all_cmd_path[j] != ':')
			cur_path[++i] = all_cmd_path[j];
		if (all_cmd_path[j] == ':' || !(all_cmd_path[j + 1]))
		{
			cur_path[++i] = '\0';
			if (dsh_find_exec(viag, cur_path))
			{
				free(all_cmd_path);
				return (dsh_exec(cur_path, viag));
			}
			i = -1;
		}
	}
	return (1);
}

/*
**	CHECK IF INPUT IS A VALID BUILTIN OR COMMAND
*/

int			dsh_cmd(t_dsh *viag)
{
	char	*tmp;
	char	*all_cmd_path;
	char	*cur_path;

	if ((CMD_SPLIT[0][0] == '.' && CMD_SPLIT[0][1] == '/') ||
		CMD_SPLIT[0][0] == '/' || CMD_SPLIT[0][0] == '~')
		return (dsh_cmd_exe(viag));
	if ((cur_path = malloc(sizeof(*cur_path) * 512)) == NULL)
		dsh_error(viag, -10);
	tmp = dsh_getenv(viag, ENV_PATH);
	all_cmd_path = ft_strdup(tmp);
	free(tmp);
	if (dsh_cmd_ii(viag, all_cmd_path, cur_path) == 0)
		return (0);
	free(cur_path);
	free(all_cmd_path);
	ft_printf(NO_CMD, CMD_SPLIT[0]);
	return (1);
}
