/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:54:49 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/08 14:06:14 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct window_s{
	void	*mlx;
	void	*win;
}			win_s;

int	close_x_button(win_s *ptr) //closes the window when the red "x" button is pressed
{
	mlx_destroy_window(ptr->mlx, ptr->win);
	exit(42);
}

int	i = 0;

int	deal_key(int key, win_s *ptr) //closes the window when esc is pressed
{
	//printf("key = %d\n", key);
	i++;
	printf("Moves = %d\n", i);
	if (key == 53)
	{
		mlx_clear_window(ptr->mlx, ptr->win);
		mlx_destroy_window(ptr->mlx, ptr->win);
		exit(1);
	}
	return (1);
}

int	main(void)
{
	win_s ptr;
	void	*img_ptr;
	int		img_x;
	int		img_y;
	int		win_x;
	int		win_y;
	int		nix;
	int		niy;

	ptr.mlx = mlx_init();
	img_ptr = mlx_xpm_file_to_image(ptr.mlx, "includes/atk.xpm", &img_x, &img_y);
	win_x = img_x * 10;
	win_y = img_y * 10;
	ptr.win = mlx_new_window(ptr.mlx, win_x, win_y, "Testes do mlx");
	nix = 0;
	niy = 0;
	// int	x;
	// int	y;
	// x = 0;
	// y = 0;
	// while (x < win_x && y < win_y)
	// {
	// 	mlx_pixel_put(ptr.mlx, ptr.win, x, y, 0x00FF0000);
	// 	x += 10;
	// 	if (x >= win_x)
	// 	{
	// 		x = 0;
	// 		y += 10;
	// 	}
	// 	mlx_pixel_put(ptr.mlx, ptr.win, x, y, 0x0000FF00);
	// 	x += 10;
	// 	if (x >= win_x)
	// 	{
	// 		x = 0;
	// 		y += 10;
	// 	}
	// 	mlx_pixel_put(ptr.mlx, ptr.win, x, y, 0x000000FF);
	// 	x += 10;
	// 	if (x >= win_x)
	// 	{
	// 		x = 0;
	// 		y += 10;
	// 	}
	//}
	mlx_put_image_to_window(ptr.mlx, ptr.win, img_ptr, nix, niy);
	mlx_key_hook(ptr.win, deal_key, &ptr);
	mlx_hook(ptr.win, 17, 1L << 2, &close_x_button, &ptr);
	mlx_loop(ptr.mlx);
	return(0);
}
