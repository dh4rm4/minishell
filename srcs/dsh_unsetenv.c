/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsh_unsetenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <kboddez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 09:16:50 by kboddez           #+#    #+#             */
/*   Updated: 2017/01/10 13:40:14 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
**	DELETE AN ELEMENT IN ENV
*/

int	dsh_unsetenv(t_dsh *viag, char *elem)
{
	int		i;
	char	**tmp;

	if (elem)
	{
		if (!ft_strcmp(elem, "OLDPWD=") ||
			!ft_strcmp(elem, "OLDPWD") ||
			!ft_strcmp(elem, "PWD=") ||
			!ft_strcmp(elem, "PWD") ||
			!ft_strcmp(elem, "PATH") ||
			!ft_strcmp(elem, "PATH="))
			return (ft_printf(BAD_UNSETENV, RED, WHITE));
		else
		{
			tmp = dsh_init_env(ENV, dsh_envlen(ENV), elem);
			i = -1;
			while (ENV[++i])
				free(ENV[i]);
			if (ENV)
				free(ENV);
			ENV = tmp;
		}
	}
	return (0);
}
