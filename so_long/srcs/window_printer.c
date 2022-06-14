/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:05:21 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/14 14:56:40 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	edge_printer(win_s *win, int pool_x, int pool_y)
{
	if (win->niy >= 1 && win->niy <= win->win_y - 70)
	{
		mlx_put_image_to_window(win->mlx, win->win, win->pool_ptr,
			win->nix, win->niy);
		win->nix += pool_x;
		if (win->nix >= win->win_x)
		{
			win->niy += pool_y - 1;
			win->nix = 0;
		}
	}
}

void	map_printer(win_s *win, int pool_x, int pool_y)
{
	while (win->nix < win->win_x && win->niy < win->win_y)
	{
		if (win->niy == 0 || win->niy >= win->win_y - 64)
		{
			mlx_put_image_to_window(win->mlx, win->win, win->edge_ptr,
				win->nix, win->niy);
			win->nix += pool_x;
			if (win->nix == win->win_x)
				win->niy ++;
		}
		if (win->nix == 0 || win->nix >= win->win_x - 64)
		{
			mlx_put_image_to_window(win->mlx, win->win, win->edge_ptr,
				win->nix, win->niy);
			win->nix += pool_x;
			if (win->nix == win->win_x)
				win->niy ++;
		}
		edge_printer(win, pool_x, pool_y);
	}
}

void	win_printer(win_s *win)
{
	int		pool_y;
	int		pool_x;
	char	*pool;
	char	*edge;

	pool = "sprites/pool.xpm";
	edge = "sprites/edge.xpm";
	win->mlx = mlx_init();
	win->pool_ptr = mlx_xpm_file_to_image(win->mlx, pool, &pool_x, &pool_y);
	win->edge_ptr = mlx_xpm_file_to_image(win->mlx, edge, &pool_x, &pool_y);
	win->win_x = pool_x * 13;
	win->win_y = pool_y * 10;
	win->win = mlx_new_window(win->mlx, win->win_x, win->win_y, "quack");
	win->nix = 0;
	win->niy = 0;
	map_printer(win, pool_x, pool_y);
}

void	starting_print(win_s *m, spr_s *s)
{
	int	i = 0;
	int	j = 0;

	while (i < m -> height)
	{
		while (j < m -> width)
		{
			if (m -> map[i][j] == '1')
				mlx_put_image_to_window(m -> mlx, m -> win, s -> edge, j * (s -> img_w), i * (s -> img_h));
			else
				mlx_put_image_to_window(m -> mlx, m -> win, s -> pool, j * (s -> img_w), i * (s -> img_h));
			if (m -> map[i][j] == 'C')
				mlx_put_image_to_window(m -> mlx, m -> win, s -> hat, j * (s -> img_w), i * (s -> img_h));
			else if (m -> map[i][j] == 'E')
				mlx_put_image_to_window(m -> mlx, m -> win, s -> hat, j * (s -> img_w), i * (s -> img_h));
			else if (m -> map[i][j] == 'P')
				mlx_put_image_to_window(m -> mlx, m -> win, s -> duck_front, j * (s -> img_w), i * (s -> img_h));
			else if (m -> map[i][j] == 'B')
				mlx_put_image_to_window(m -> mlx, m -> win, s -> gator, j * (s -> img_w), i * (s -> img_h));
			j++;
		}
		j = 0;
		i ++;
	}
}
