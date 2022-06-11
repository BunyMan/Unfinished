/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:54:49 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/08 18:04:03 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_win_s	ptr;
	void	*img_ptr;
	int		img_x;
	int		img_y;
	char	*duck_front;
	char	*duck_front_hat;
	char	*duck_back;
	char	*duck_back_hat;
	char	*duck_left;
	char	*duck_left_hat;
	char	*duck_right;
	char	*duck_right_hat;
	char	*edge;
	char	*gator;
	char	*hat;

	win_printer(&ptr);
	duck_front = "sprites/duck-front.xpm";
	img_ptr = mlx_xpm_file_to_image(ptr.mlx, duck_front, &img_x, &img_y);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img_ptr, 0, 320);
	duck_front_hat = "sprites/duck-front-hat.xpm";
	img_ptr = mlx_xpm_file_to_image(ptr.mlx, duck_front_hat, &img_x, &img_y);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img_ptr, 64, 320);
	duck_back = "sprites/duck-back.xpm";
	img_ptr = mlx_xpm_file_to_image(ptr.mlx, duck_back, &img_x, &img_y);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img_ptr, 128, 320);
	duck_back_hat = "sprites/duck-back-hat.xpm";
	img_ptr = mlx_xpm_file_to_image(ptr.mlx, duck_back_hat, &img_x, &img_y);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img_ptr, 192, 320);
	duck_left = "sprites/duck-left.xpm";
	img_ptr = mlx_xpm_file_to_image(ptr.mlx, duck_left, &img_x, &img_y);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img_ptr, 256, 320);
	duck_left_hat = "sprites/duck-left-hat.xpm";
	img_ptr = mlx_xpm_file_to_image(ptr.mlx, duck_left_hat, &img_x, &img_y);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img_ptr, 320, 320);
	duck_right = "sprites/duck-right.xpm";
	img_ptr = mlx_xpm_file_to_image(ptr.mlx, duck_right, &img_x, &img_y);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img_ptr, 384, 320);
	duck_right_hat = "sprites/duck-right-hat.xpm";
	img_ptr = mlx_xpm_file_to_image(ptr.mlx, duck_right_hat, &img_x, &img_y);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img_ptr, 448, 320);
	edge = "sprites/edge.xpm";
	img_ptr = mlx_xpm_file_to_image(ptr.mlx, edge, &img_x, &img_y);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img_ptr, 512, 320);
	gator = "sprites/gator.xpm";
	img_ptr = mlx_xpm_file_to_image(ptr.mlx, gator, &img_x, &img_y);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img_ptr, 576, 320);
	hat = "sprites/hat.xpm";
	img_ptr = mlx_xpm_file_to_image(ptr.mlx, hat, &img_x, &img_y);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img_ptr, 640, 320);
	ptr.moves = 0;
	mlx_key_hook(ptr.win, deal_key, &ptr);
	mlx_hook(ptr.win, 17, 1L << 2, &close_x_button, &ptr);
	mlx_loop(ptr.mlx);
	return (0);
}
