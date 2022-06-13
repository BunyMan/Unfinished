/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:35:34 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/13 16:12:34 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	spr_printer(spr_s *spr, win_s *win)
{
	spr->duck_front = "sprites/duck-front.xpm";
	win->img_ptr = mlx_xpm_file_to_image(win->mlx, spr->duck_front,
			&(spr->img_x), &(spr->img_y));
	mlx_put_image_to_window(win->mlx, win->win, win->img_ptr, 384, 320);
}
