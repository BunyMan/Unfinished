/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:11:38 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/19 14:19:36 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_player_front(t_window *win)
{
	win->img_p.img_s[0] = mlx_xpm_file_to_image(win->mlx, \
	"front.xpm", &win->img_p.width, &win->img_p.height);
	win->img_p.img_s[1] = mlx_xpm_file_to_image(win->mlx, \
	"front1.xpm", &win->img_p.width, &win->img_p.height);
	win->img_p.img_s[2] = mlx_xpm_file_to_image(win->mlx, \
	"front2.xpm", &win->img_p.width, &win->img_p.height);
}

void	ft_init_player_back(t_window *win)
{
	win->img_p.img_s[0] = mlx_xpm_file_to_image(win->mlx, \
	"back.xpm", &win->img_p.width, &win->img_p.height);
	win->img_p.img_s[1] = mlx_xpm_file_to_image(win->mlx, \
	"back1.xpm", &win->img_p.width, &win->img_p.height);
	win->img_p.img_s[2] = mlx_xpm_file_to_image(win->mlx, \
	"back2.xpm", &win->img_p.width, &win->img_p.height);
}

void	ft_init_player_left(t_window *win)
{
	win->img_p.img_s[0] = mlx_xpm_file_to_image(win->mlx, \
	"left.xpm", &win->img_p.width, &win->img_p.height);
	win->img_p.img_s[1] = mlx_xpm_file_to_image(win->mlx, \
	"left1.xpm", &win->img_p.width, &win->img_p.height);
	win->img_p.img_s[2] = mlx_xpm_file_to_image(win->mlx, \
	"left2.xpm", &win->img_p.width, &win->img_p.height);
}

void	ft_init_player_right(t_window *win)
{
	win->img_p.img_s[0] = mlx_xpm_file_to_image(win->mlx, \
	"right.xpm", &win->img_p.width, &win->img_p.height);
	win->img_p.img_s[1] = mlx_xpm_file_to_image(win->mlx, \
	"right1.xpm", &win->img_p.width, &win->img_p.height);
	win->img_p.img_s[2] = mlx_xpm_file_to_image(win->mlx, \
	"right2.xpm", &win->img_p.width, &win->img_p.height);
}

void	ft_init_player_animation(t_window *win)
{
	ft_init_player_front(win);
	ft_init_player_back(win);
	ft_init_player_left(win);
	ft_init_player_right(win);
}