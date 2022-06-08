/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:54:49 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/08 16:13:46 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	win_s ptr;
	void	*img_ptr;
	int		img_x;
	int		img_y;
	// int		win_x;
	// int		win_y;
	// int		nix;
	// int		niy;

	// ptr.mlx = mlx_init();
	// img_ptr = mlx_xpm_file_to_image(ptr.mlx, "includes/back.xpm", &img_x, &img_y);
	// win_x = img_x * 10;
	// win_y = img_y * 10;
	// ptr.win = mlx_new_window(ptr.mlx, win_x, win_y, "Testes do mlx");
	// nix = 0;
	// niy = 0;
	// while (nix < win_x && niy < win_y)
	// {
	// 	mlx_put_image_to_window(ptr.mlx, ptr.win, img_ptr, nix, niy);
	// 	nix += img_x;
	// 	if (nix >= win_x)
	// 	{
	// 		niy += img_y;
	// 		nix = 0;
	// 	}
		
	// }
	win_printer(&ptr);
	img_ptr = mlx_xpm_file_to_image(ptr.mlx, "includes/atk.xpm", &img_x, &img_y);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img_ptr, 320, 320);
	ptr.moves = 0;
	mlx_key_hook(ptr.win, deal_key, &ptr);
	mlx_hook(ptr.win, 17, 1L << 2, &close_x_button, &ptr);
	mlx_loop(ptr.mlx);
	return(0);
}
