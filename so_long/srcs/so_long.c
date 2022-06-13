/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:54:49 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/13 16:11:08 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	spr_s	spr;
	win_s	win;

	win_printer(&win);
	spr_printer(&spr, &win);
	win.moves = 0;
	mlx_key_hook(win.win, deal_key, &win);
	mlx_hook(win.win, 17, 1L << 2, &close_x_button, &win);
	mlx_loop(win.mlx);
	return (0);
}
