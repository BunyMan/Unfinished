/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:25:07 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/18 17:38:12 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_window *win)
{
	int	i;
	int	j;
	
	i = -1;
	j = -1;
	while (win->map[i++])
		free(win->map[i]);
	free(win->map);
	mlx_destroy_image(win->mlx, win->img_0.img);
	mlx_destroy_image(win->mlx, win->img_1.img);
}

void	free_player(t_window *win)
{
	int	i;

	i = -1;
	mlx_destroy_image(win->mlx, win->img_p.img);
	while (i++)
	{
		mlx_destroy_image(win->mlx, win_img_p.img_w[i]);
		mlx_destroy_image(win->mlx, win_img_p.img_a[i]);
		mlx_destroy_image(win->mlx, win_img_p.img_s[i]);
		mlx_destroy_image(win->mlx, win_img_p.img_d[i]);
	}
}

void	free_collectible_and_enemy(t_window *win)
{
	int	i;
	
	i = -1;
	mlx_destroy_image(win->mlx, win->img_c.img);
	mlx_destroy_image(win->mlx, win->img_x.img);
	while (i++)
	{
		mlx_destroy_image(win->mlx, win->img_c.img_w);
		mlx_destroy_image(win->mlx, win->img_x.img_w);
	}
}

void	free_exit(t_window *win)
{
	free (win->img_e.img);
	mlx_destroy_image(win->mlx, win->img_e.img);
	mlx_destroy_image(win->mlx, win->img_e.img_w);
}

void	exit_s(t_window *win)
{
	free_map(win);
	free_player(win);
	free_collectible_and_enemy(win);
	mlx_destroy_window(win->mlx, win->window);
	free(win);
	exit(EXIT_SUCCESS);
}