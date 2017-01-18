/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsh_tilde.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <kboddez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:54:48 by kboddez           #+#    #+#             */
/*   Updated: 2017/01/16 17:59:24 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
**	CHECK IF THERE IS A TILDe IN THE ARG
*/

static int	dsh_check_tilde(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
		if (arg[i] == '~')
			return (1);
	return (0);
}

/*
**	dsh_tilde PART II
*/

static void	dsh_tilde_ii(t_dsh *viag, char *rp, char *home, t_idsh *c)
{
	c->j = -1;
	c->k = -1;
	rp = ft_strnew(ft_strlen(CMD_SPLIT[c->i]) + ft_strlen(home));
	while (CMD_SPLIT[c->i][++c->j])
		if (CMD_SPLIT[c->i][c->j] == '~')
		{
			c->l = -1;
			while (home[++c->l])
				rp[++c->k] = home[c->l];
		}
		else
			rp[++c->k] = CMD_SPLIT[c->i][c->j];
	rp[++c->k] = '\0';
	free(CMD_SPLIT[c->i]);
	CMD_SPLIT[c->i] = rp;
}

/*
**  CHECK IF THERE IS SOME TILDE IN CMD_SPLIT
**  AND CHANGE THEM WITH THE GOOD VALUE
*/

int			dsh_tilde(t_dsh *viag)
{
	t_idsh	c;
	char	*rp;
	char	*home;

	rp = NULL;
	c.i = -1;
	home = dsh_getenv(viag, "HOME=");
	if (home)
		while (CMD_SPLIT[++c.i])
			if (dsh_check_tilde(CMD_SPLIT[c.i]))
				dsh_tilde_ii(viag, rp, home, &c);
	if (home)
		free(home);
	return (0);
}
