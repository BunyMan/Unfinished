/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:54:49 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/13 16:32:51 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, '\n', 1);
	exit(1);
}

int	main(int argc, char **argv)
{
	spr_s	spr;
	win_s	win;

	if (argc != 2)
		error_msg("wrong number of arguments");
	win_printer(&win);
	spr_printer(&spr, &win);
	win.moves = 0;
	mlx_key_hook(win.win, deal_key, &win);
	mlx_hook(win.win, 17, 1L << 2, &close_x_button, &win);
	mlx_loop(win.mlx);
	return (0);
}
