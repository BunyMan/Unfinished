/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:38:39 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/18 17:57:58 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_exit(t_window *win)
{
	static int	i;
	static int	pace;

	win->img_e.img_w[0] = mlx_xpm_file_to_image(win->mlx, \
	"exit1.xpm", &win->img_e.width, &win->img_e.height);
	win->img_e.img_w[0] = mlx_xpm_file_to_image(win->mlx, \
	"exit2.xpm", &win->img_e.width, &win->img_e.height);
	win->img_e.img_w[0] = mlx_xpm_file_to_image(win->mlx, \
	"exit3.xpm", &win->img_e.width, &win->img_e.height);
	win->img_e.img = win->img_e.img_w[i];
	if (pace++ < 7)
		return ;
	pace = 0;
	i ++;
	if (i == 2)
		i = 0;
}

void	update_exit(t_window *win)
{
	int	i;
	int	j;

	i = -1;
	ft_init_exit(win);
	while (win->map[++i])
	{
		j = -1;
		while (win->map[i][++j])
		{
			if (win->map[i][j] == 'E')
			{
				win->img_e.x = i * 64;
				win->img_e.y = j * 64;
				mlx_put_image_to_window(win->mlx, win->window, \
				win->img_e.img, win->img_e.x, win_img_e.y);
				if (win->img_p.x == j * 64 && win->img_p.y == i * 64)
					if (win->img_c.counter >= win->img_c.nbr)
						exit_s(win);
			}
		}
	}
}
