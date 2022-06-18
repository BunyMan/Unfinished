/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:23:42 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/18 17:24:50 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	ft_update_up(t_window *win)
{
	static int	w;

	if (win->keys.w && !base->keys.s && !base->keys.a && !base->keys.d)
	{
		win->img_p.img = img_p.img_w[w];
		win->img_p.y -= win->img_p.pace;
		if (win->map[win->img_p.y / 64][win->img_p.x / 64] == '1')
			win->img_p.y += win->img_p.pace;
		win->move_counter += 1;
		if (w < 2)
			w += 1;
		else
			w = 0;
	}
}

void	ft_update_down(t_window *win)
{
	static int	s;

	if (win->keys.s && !base->keys.w && !base->keys.a && !base->keys.d)
	{
		win->img_p.img = img_p.img_s[s];
		win->img_p.y -= win->img_p.pace;
		if (win->map[win->img_p.y / 64][win->img_p.x / 64] == '1')
			win->img_p.y += win->img_p.pace;
		win->move_counter += 1;
		if (s < 2)
			s += 1;
		else
			s = 0;
	}
}

void	ft_update_left(t_window *win)
{
	static int	a;

	if (win->keys.a && !base->keys.w && !base->keys.s && !base->keys.d)
	{
		win->img_p.img = img_p.img_a[a];
		win->img_p.y -= win->img_p.pace;
		if (win->map[win->img_p.y / 64][win->img_p.x / 64] == '1')
			win->img_p.y += win->img_p.pace;
		win->move_counter += 1;
		if (a < 2)
			a += 1;
		else
			a = 0;
	}
}

void	ft_update_down(t_window *win)
{
	static int	d;

	if (win->keys.d && !base->keys.w && !base->keys.a && !base->keys.s)
	{
		win->img_p.img = img_p.img_d[d];
		win->img_p.y -= win->img_p.pace;
		if (win->map[win->img_p.y / 64][win->img_p.x / 64] == '1')
			win->img_p.y += win->img_p.pace;
		win->move_counter += 1;
		if (d < 2)
			d += 1;
		else
			d = 0;
	}
}

void ft_update_player(t_window *win)
{
	static int pace;

	if (pace++ < 5)
		return;
	pace = 0;
	ft_update_up(win);
	ft_update_down(win);
	ft_update_letf(win);
	ft_update_right(win);
}