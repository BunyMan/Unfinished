/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 13:17:47 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/19 13:27:51 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	ft_init_enemy(t_window *win)
{
	static int	i;
	static int	pace;
	
	win->img_x.img_w[0] = mlx_put_image_to_window(win->mlx, \
	"enemy0.xpm", &win->img_x.width, &win->img_x.height);
	win->img_x.img_w[0] = mlx_put_image_to_window(win->mlx, \
	"enemy1.xpm", &win->img_x.width, &win->img_x.height);
	win->img_x.img_w[0] = mlx_put_image_to_window(win->mlx, \
	"enemy2.xpm", &win->img_x.width, &win->img_x.height);
	win->img_x.img = win->img_x.img_w[i];
	if (pace++ < 7)
		return ;
	pace = 0;
	i++;
	if (i == 2)
		i = 0;
}

void	puff_enemy(t_window *win)
{
	int	i;
	int	j;

	i = -1;
	ft_init_enemy(win);
	while (win->map[++i])
	{
		j = -1;
		while (win->map[i][j++])
		{
			if (win->map[i][j] == 'X')
			{
				win->img_x.x = j * 64;
				win->img_x.y = i * 64;
				puff_enemy(win, i, j);
			}
		}
	}
}