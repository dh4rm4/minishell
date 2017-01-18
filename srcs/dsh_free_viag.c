/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsh_free_viag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 09:44:09 by kboddez           #+#    #+#             */
/*   Updated: 2017/01/13 12:48:57 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	dsh_free_viag(t_dsh *viag)
{
	int		i;

	i = -1;
	if (CMD)
	{
		free(CMD);
		CMD = NULL;
	}
	i = -1;
	if (ENV)
	{
		while (ENV[++i] != NULL)
			free(ENV[i]);
		free(ENV);
		ENV = NULL;
	}
}
