/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsh_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <kboddez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 12:30:58 by kboddez           #+#    #+#             */
/*   Updated: 2017/01/12 12:31:00 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int		dsh_cmd_space(t_dsh *viag)
{
	int	i;

	i = -1;
	while (CMD[++i])
		if (CMD[i] != ' ' && CMD[i] != '\t')
			return (1);
	return (0);
}

void	dsh_error(t_dsh *viag, int n_err)
{
	if (n_err == MALLOC_ERR)
	{
		ft_printf("%sError: %smalloc fail:\n", RED, WHITE);
		ft_printf("Check if you have the necessary rights for execution\n");
	}
	if (n_err == FORK_FAIL)
		ft_printf("%sError: %scan't to create a new process", RED, WHITE);
	dsh_free_viag(viag);
	exit(0);
}
