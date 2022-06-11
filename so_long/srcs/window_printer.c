/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:05:21 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/08 18:15:45 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_printer(t_win_s *ptr)
{
	int		img_x;
	int		img_y;
	char	*b_path;

	b_path = "includes/pool.xpm";
	ptr->mlx = mlx_init();
	ptr->img_ptr = mlx_xpm_file_to_image(ptr->mlx, b_path, &img_x, &img_y);
	ptr->win_x = img_x * 11;
	ptr->win_y = img_y * 10;
	ptr->win = mlx_new_window(ptr->mlx, ptr->win_x, ptr->win_y, "quack quack motherfvcker");
	ptr->nix = 0;
	ptr->niy = 0;
	while (ptr->nix < ptr->win_x && ptr->niy < ptr->win_y)
	{
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img_ptr, ptr->nix, ptr->niy);
		ptr->nix += img_x;
		if (ptr->nix >= ptr->win_x)
		{
			ptr->niy += img_y;
			ptr->nix = 0;
		}
	}
}
