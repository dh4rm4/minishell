/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsh_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <kboddez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:57:41 by kboddez           #+#    #+#             */
/*   Updated: 2017/01/16 17:56:11 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	dsh_condition(char *final, t_dsh *viag, int *i, int *j)
{
	if (CMD[*i] != '\t')
		final[++(*j)] = CMD[*i];
	else
		final[++(*j)] = ' ';
}

/*
**	CLEAN THE CMD OF ALL THE '\t' AND ' '
*/

int			dsh_parse(t_dsh *viag)
{
	int		i;
	int		j;
	char	*final;

	j = -1;
	i = -1;
	if (!CMD)
		return (-1);
	while (CMD[++i])
		if ((CMD[i] != '\t' && CMD[i] != ' ') || ((CMD[i] == '\t' ||
			CMD[i] == ' ') && CMD[i - 1] != '\t' && CMD[i - 1] != ' '))
			++j;
	final = ft_strnew(++j);
	i = -1;
	j = -1;
	while (CMD[++i])
		if ((CMD[i] != ' ' && CMD[i] != '\t') ||
			((CMD[i] == ' ' || CMD[i] == '\t') &&
			(CMD[i - 1] && CMD[i - 1] != ' ' && CMD[i - 1] != '\t')))
			dsh_condition(final, viag, &i, &j);
	final[++j] = '\0';
	if (CMD)
		free(CMD);
	CMD = final;
	return (0);
}
