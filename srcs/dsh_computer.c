/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsh_computer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <kboddez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:30:34 by kboddez           #+#    #+#             */
/*   Updated: 2017/01/12 14:48:59 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	dsh_computer_ii(void)
{
	SBUG("`..........YBRPFT?!::::::::::::::::::::::::;iof68bo.      WBBBBbo.");
	SBUG("  `..........:::::::::::::::::::::::;iof688888888888b.     `YBBBP^'");
	SBUG("    `........::::::::::::::::;iof688888888888888888888b.     `");
	SBUG("     `......:::::::::;iof688888888888888888888888888888b.");
	SBUG("       `....:::;iof688888888888888888888888888888888899fT!");
	SBUG("         `..::!8888888888888888888888888888888899fT|!^\"'");
	SBUG("           `' !!988888888888888888888888899fT|!^\"'");
	SBUG("             `!!8888888888888888899fT|!^\"'");
	SBUG("               `!988888888899fT|!^\"'");
	SBUG("                 `!9899fT|!^\"'");
	SBUG("                   `!^\"'\n");
}

void		dsh_computer(void)
{
	SBUG("\n                      .,,uod8B8bou,,.");
	SBUG("             ..,uod8BBBBBBBBBBBBBBBBRPFT?l!i:.");
	SBUG("         ,=m8BBBBBBBBBBBBBBBRPFT?!||||||||||||||");
	SBUG("         !...:!TVBBBRPFT||||||||||!!^^\"\"'   ||||");
	SBUG("         !.......:!?|||||!!^^\"\"'            ||||");
	SBUG("         !.........||||                     ||||");
	ft_printf("         !.........||||     %s%s%s", GREEN, "## > ", ITALIC);
	ft_printf("%s%s%s        ||||\n", BLUE, "dsh", "\x1b[0m", WHITE);
	SBUG("         !.........||||                     ||||");
	SBUG("         !.........||||                     ||||");
	SBUG("         !.........||||                     ||||");
	SBUG("         !.........||||                     ||||");
	SBUG("         `.........||||                    ,||||");
	SBUG("          .;.......||||               _.-!!|||||");
	SBUG("   .,uodWBBBBb.....||||       _.-!!|||||||||!:'");
	SBUG("!YBBBBBBBBBBBBBBb..!|||:..-!!|||||||!iof68BBBBBb....");
	SBUG("!..YBBBBBBBBBBBBBBb!!||||||||!iof68BBBBBBRPFT?!::   `.");
	SBUG("!....YBBBBBBBBBBBBBBbaaitf68BBBBBBRPFT?!:::::::::     `.");
	SBUG("!......YBBBBBBBBBBBBBBBBBBBRPFT?!::::::;:!^\"`;:::       `.");
	SBUG("!........YBBBBBBBBBBRPFT?!::::::::::^''...::::::;         iBBbo.");
	dsh_computer_ii();
}
