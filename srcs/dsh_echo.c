/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsh_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <kboddez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 12:30:26 by kboddez           #+#    #+#             */
/*   Updated: 2017/01/13 15:25:57 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
**	PUTSTR BUT NOT THE FIRST AND LAST DOUBLE QUOTE
*/

static void	dsh_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] != '\"')
			ft_putchar(str[i]);
}

/*
**	BUILTIN echo
*/

int			dsh_echo(t_dsh *viag)
{
	int	i;

	i = 0;
	if (CMD_SPLIT[1])
	{
		while (CMD_SPLIT[++i])
		{
			dsh_putstr(CMD_SPLIT[i]);
			if (CMD_SPLIT[i + 1])
				ft_putchar(' ');
		}
	}
	ft_putchar('\n');
	return (0);
}
