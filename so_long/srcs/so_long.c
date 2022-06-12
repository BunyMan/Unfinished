/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:54:49 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/12 15:33:46 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_spr_s spr;
	t_win_s	ptr;
	void	*img_ptr;
	int		img_x;
	int		img_y;

	win_printer(&ptr);
	spr.duck_front = "sprites/duck-front.xpm";
	img_ptr = mlx_xpm_file_to_image(ptr.mlx, spr.duck_front, &img_x, &img_y);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img_ptr, 64, 320);
	spr.duck_front_hat = "sprites/duck-front-hat.xpm";
	img_ptr = mlx_xpm_file_to_image(ptr.mlx, spr.duck_front_hat, &img_x, &img_y);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img_ptr, 128, 320);
	spr.duck_back = "sprites/duck-back.xpm";
	img_ptr = mlx_xpm_file_to_image(ptr.mlx, spr.duck_back, &img_x, &img_y);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img_ptr, 192, 320);
	spr.duck_back_hat = "sprites/duck-back-hat.xpm";
	img_ptr = mlx_xpm_file_to_image(ptr.mlx, spr.duck_back_hat, &img_x, &img_y);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img_ptr, 256, 320);
	spr.duck_left = "sprites/duck-left.xpm";
	img_ptr = mlx_xpm_file_to_image(ptr.mlx, spr.duck_left, &img_x, &img_y);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img_ptr, 320, 320);
	spr.duck_left_hat = "sprites/duck-left-hat.xpm";
	img_ptr = mlx_xpm_file_to_image(ptr.mlx, spr.duck_left_hat, &img_x, &img_y);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img_ptr, 384, 320);
	spr.duck_right = "sprites/duck-right.xpm";
	img_ptr = mlx_xpm_file_to_image(ptr.mlx, spr.duck_right, &img_x, &img_y);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img_ptr, 448, 320);
	spr.duck_right_hat = "sprites/duck-right-hat.xpm";
	img_ptr = mlx_xpm_file_to_image(ptr.mlx, spr.duck_right_hat, &img_x, &img_y);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img_ptr, 512, 320);
	spr.gator = "sprites/gator.xpm";
	img_ptr = mlx_xpm_file_to_image(ptr.mlx, spr.gator, &img_x, &img_y);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img_ptr, 576, 320);
	spr.hat = "sprites/hat.xpm";
	img_ptr = mlx_xpm_file_to_image(ptr.mlx, spr.hat, &img_x, &img_y);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img_ptr, 640, 320);
	spr.goose = "sprites/goose.xpm";
	img_ptr = mlx_xpm_file_to_image(ptr.mlx, spr.goose, &img_x, &img_y);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img_ptr, 704, 320);
	ptr.moves = 0;
	mlx_key_hook(ptr.win, deal_key, &ptr);
	mlx_hook(ptr.win, 17, 1L << 2, &close_x_button, &ptr);
	mlx_loop(ptr.mlx);
	return (0);
}
