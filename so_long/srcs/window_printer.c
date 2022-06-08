/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:05:21 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/08 16:15:24 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_printer(win_s *ptr)
{
		void	*img_ptr;
	int		img_x;
	int		img_y;
	int		win_x;
	int		win_y;
	int		nix;
	int		niy;

	ptr->mlx = mlx_init();
	img_ptr = mlx_xpm_file_to_image(ptr->mlx, "includes/back.xpm", &img_x, &img_y);
	win_x = img_x * 10;
	win_y = img_y * 10;
	ptr->win = mlx_new_window(ptr->mlx, win_x, win_y, "Testes do mlx");
	nix = 0;
	niy = 0;
	while (nix < win_x && niy < win_y)
	{
		mlx_put_image_to_window(ptr->mlx, ptr->win, img_ptr, nix, niy);
		nix += img_x;
		if (nix >= win_x)
		{
			niy += img_y;
			nix = 0;
		}

	}
}
