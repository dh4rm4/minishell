/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsh_reset_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <kboddez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:16:40 by kboddez           #+#    #+#             */
/*   Updated: 2017/01/16 17:59:09 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
**	RESET ENV TO DEFAULT ENV
*/

int		dsh_reset_env(t_dsh *viag)
{
	int		i;

	i = -1;
	while (ENV[++i])
		free(ENV[i]);
	if (ENV)
		free(ENV);
	if (!(ENV = (char **)malloc(sizeof(ENV) * 5)))
		return (-1);
	dsh_default_env(ENV);
	return (0);
}
