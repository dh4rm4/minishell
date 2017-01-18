/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsh_getenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <kboddez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 12:33:32 by kboddez           #+#    #+#             */
/*   Updated: 2017/01/17 12:09:49 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
**	COPY THE BEHAVIOR OF "getenv" BUT WORK
**		WITH THE CURRENT ENV
*/

char	*dsh_getenv(t_dsh *viag, char *elem)
{
	char	*rtr;
	int		i;
	int		j;
	int		k;

	i = -1;
	while (ENV[++i])
	{
		j = 0;
		while (ENV[i][j] == elem[j])
			++j;
		if (j - 1 >= 0 && ENV[i][--j] == '=' && elem[j] == '=')
			break ;
	}
	if (!ENV[i])
		return (NULL);
	if (!(rtr = (char *)malloc(sizeof(*rtr) * (ft_strlen(ENV[i]) -
											ft_strlen(elem) + 1))))
		dsh_error(viag, -10);
	j = ft_strlen(elem) - 1;
	k = -1;
	while (ENV[i][++j])
		rtr[++k] = ENV[i][j];
	rtr[++k] = '\0';
	return (rtr);
}
