/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsh_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <kboddez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 09:47:38 by kboddez           #+#    #+#             */
/*   Updated: 2017/01/16 16:40:22 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
**	RETURN THE NBR OF ELEMENTS IN env
*/

int			dsh_envlen(char **env)
{
	int rtr;

	rtr = 0;
	while (env[rtr])
		++rtr;
	return (rtr);
}

/*
**	PRINT THE CURRENT tmp_env
*/

int			dsh_print_env(t_dsh *viag)
{
	int	i;

	i = -1;
	while (ENV[++i])
		ft_strendl(ENV[i]);
	return (0);
}

/*
**	CHECK IF elem IS A VARIABLE IN ENV
*/

static int	dsh_envcmp(char *strenv, char *elem)
{
	int	i;

	i = 0;
	if (!elem)
		return (0);
	while (strenv[i] && elem[i] && strenv[i] == elem[i])
		++i;
	if (!elem[i] && elem[i - 1] == strenv[i - 1] &&
		(strenv[i] == '=' || strenv[i - 1] == '='))
		return (1);
	return (0);
}

/*
**	GIVE TO ENV DEFAULT VALUES
*/

void		dsh_default_env(char **rtr)
{
	int		i;
	char	*get_cwd;

	i = 0;
	rtr[i] = ft_strdup(BASIC_ENV_PATH);
	rtr[++i] = ft_strdup(BASIC_ENV_USER);
	get_cwd = getcwd(NULL, 0);
	rtr[++i] = ft_strjoin("PWD=", get_cwd);
	rtr[++i] = ft_strjoin(ENV_OLDPWD, get_cwd);
	free(get_cwd);
	rtr[++i] = NULL;
	ft_printf(HOME_ERROR, RED, WHITE);
}

/*
**	MAKE A COPY OF THE INITAL ENV AND RETURN IT
**	IF AN ELEMENT IN env == exept, THEN THIS ELEM IS NOT COPY
*/

char		**dsh_init_env(char **env, int len_env, char *exept)
{
	char	**rtr;
	int		i;
	int		j;

	i = -1;
	j = -1;
	len_env = (!len_env) ? 4 : len_env;
	if (!(rtr = (char **)malloc(sizeof(rtr) * ++len_env)))
		return (NULL);
	while (env[++i])
		if (!exept || !dsh_envcmp(env[i], exept))
			rtr[++j] = ft_strdup(env[i]);
	rtr[++j] = NULL;
	if (i == 0)
		dsh_default_env(rtr);
	else
		ft_printf("%s", WHITE);
	return (rtr);
}
