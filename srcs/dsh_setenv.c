/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsh_setenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <kboddez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:19:26 by kboddez           #+#    #+#             */
/*   Updated: 2017/01/17 12:16:44 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
**	CHECK IF THE VALUE GIVE TO SETENV ALREADY
**	EXIST. IF YES : REMPLACE THE CURRENT
**		VALUE BY THE NEW ONE
*/

static int	dsh_exist_env(t_dsh *viag, char *elem, char *start)
{
	int		i;
	int		j;

	i = -1;
	while (ENV[++i])
	{
		j = 0;
		while (ENV[i][j] && elem[j] && ENV[i][j] == start[j])
			++j;
		if (j - 1 >= 0 && ENV[i][j - 1] == start[j - 1] && !start[j])
			break ;
	}
	if (!ENV[i])
		return (1);
	free(ENV[i]);
	ENV[i] = ft_strdup(elem);
	return (0);
}

/*
**	ISOATE THE FIRST ELEMENT OF AN ENV VARIABLE
**		-> from 1s char to '='
*/

static char	*dsh_isolation(char *str)
{
	int		i;
	char	*rtr;

	i = 0;
	while (str[i] && ((i - 1 >= 0 && str[i - 1] != '=') || i == 0))
		++i;
	if (!str[i] || (!(rtr = (char *)malloc(sizeof(*rtr) * i + 1))))
		return (NULL);
	i = -1;
	while (str[++i] != '=')
		rtr[i] = str[i];
	rtr[i] = '\0';
	return (rtr);
}

/*
**  ADD A NEW ELEMENT IN A COPY OF THE CURRENT ENV
**  AND RETURN IT && FREE THE CURRENT ENV
*/

int			dsh_setenv(t_dsh *viag, char **tmp_env, char *elem)
{
	int		i;
	char	*start;

	start = dsh_isolation(elem);
	!start ? ft_printf(SETENV_ERROR, RED, WHITE) : ft_printf("");
	if (start && dsh_exist_env(viag, elem, start))
	{
		i = -1;
		while (ENV[++i])
			free(ENV[i]);
		free(ENV);
		if (!(ENV = (char **)malloc(sizeof(ENV) * (dsh_envlen(tmp_env) + 2))))
			dsh_error(viag, -10);
		i = -1;
		while (tmp_env[++i])
			ENV[i] = ft_strdup(tmp_env[i]);
		ENV[i] = ft_strdup(elem);
		ENV[++i] = NULL;
	}
	(start) ? free(start) : ft_printf("");
	i = -1;
	while (tmp_env[++i])
		free(tmp_env[i]);
	(tmp_env) ? free(tmp_env) : ft_printf("");
	return (0);
}
