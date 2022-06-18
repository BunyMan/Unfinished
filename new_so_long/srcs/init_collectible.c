/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_collectible.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:59:03 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/18 18:06:53 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_collectible(t_window *win)
{
	static int	i;
	static int	pace;

	win->img_e.img_w[0] = mlx_xpm_file_to_image(win->mlx, \
	"collectible1.xpm", &win->img_e.width, &win->img_e.height);
	win->img_e.img_w[0] = mlx_xpm_file_to_image(win->mlx, \
	"collectible2.xpm", &win->img_e.width, &win->img_e.height);
	win->img_e.img_w[0] = mlx_xpm_file_to_image(win->mlx, \
	"collectible3.xpm", &win->img_e.width, &win->img_e.height);
	win->img_e.img = win->img_e.img_w[i];
	if (pace++ < 7)
		return ;
	pace = 0;
	i ++;
	if (i == 2)
		i = 0;
}

void	puff(t_window *win, int i, int j)
{
	if (win->img_p.x == i * 64 && win->img_p.y == j * 64)
	{
		win->map[i][j] = '0';
		win->img_c.counter++;
	}
	
}