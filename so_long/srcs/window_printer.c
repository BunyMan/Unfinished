/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:05:21 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/13 14:27:35 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	edge_printer(t_win_s *ptr, int pool_x, int pool_y)
{
	if (ptr->niy >= 1 && ptr->niy <= ptr->win_y - 70)
	{
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->pool_ptr, ptr->nix, ptr->niy);
		ptr->nix += pool_x;
		if (ptr->nix >= ptr->win_x)
		{
			ptr->niy += pool_y - 1;
			ptr->nix = 0;
		}
	}
}

void	map_printer(t_win_s *ptr, int pool_x, int pool_y)
{
	while (ptr->nix < ptr->win_x && ptr->niy < ptr->win_y)
	{
		if (ptr->niy == 0 || ptr->niy >= ptr->win_y - 64)
		{
			mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->edge_ptr, ptr->nix, ptr->niy);
			ptr->nix += pool_x;
			if (ptr->nix == ptr->win_x)
				ptr->niy ++;
		}
		if (ptr->nix == 0 || ptr->nix >= ptr->win_x - 64)
		{
			mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->edge_ptr, ptr->nix, ptr->niy);
			ptr->nix += pool_x;
			if (ptr->nix == ptr->win_x)
				ptr->niy ++;
		}
		edge_printer(ptr, pool_x, pool_y);
	}
}

void	win_printer(t_win_s *ptr)
{
	int		pool_y;
	int		pool_x;
	char	*pool;
	char	*edge;

	pool = "sprites/pool.xpm";
	edge = "sprites/edge.xpm";
	ptr->mlx = mlx_init();
	ptr->pool_ptr = mlx_xpm_file_to_image(ptr->mlx, pool, &pool_x, &pool_y);
	ptr->edge_ptr = mlx_xpm_file_to_image(ptr->mlx, edge, &pool_x, &pool_y);
	ptr->win_x = pool_x * 13;
	ptr->win_y = pool_y * 10;
	ptr->win = mlx_new_window(ptr->mlx, ptr->win_x, ptr->win_y, "quack");
	ptr->nix = 0;
	ptr->niy = 0;
	map_printer(ptr, pool_x, pool_y);
}
