/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:54:49 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/07 10:40:21 by jbuny-fe         ###   ########.fr       */
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

int	deal_key(int key, win_s *ptr) //closes the window when esc is pressed
{
	printf("key = %d\n", key);
	if (key == 53)
	{
		mlx_clear_window(ptr->mlx, ptr->win);
		mlx_destroy_window(ptr->mlx, ptr->win);
		exit(1);
	}
	return (0);
}

int	main(void)
{
	win_s ptr;

	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, 500, 500, "Testes do mlx");
	int	i;
	int	j;
	i = 0;
	j = 0;
	while (i < 500 && j < 500)
	{
		mlx_pixel_put(ptr.mlx, ptr.win, i, j, 0x00FF0000);
		i += 9;
		if (i >= 500)
		{
			i = 0;
			j += 9;
		}
		mlx_pixel_put(ptr.mlx, ptr.win, i, j, 0x0000FF00);
		i += 9;
		if (i >= 500)
		{
			i = 0;
			j += 9;
		}
		mlx_pixel_put(ptr.mlx, ptr.win, i, j, 0x000000FF);
		i += 9;
		if (i >= 500)
		{
			i = 0;
			j += 9;
		}
	}
	mlx_key_hook(ptr.win, deal_key, &ptr);
	mlx_hook(ptr.win, 17, 1L << 2, &close_x_button, &ptr);
	mlx_loop(ptr.mlx);
	return(0);
}
