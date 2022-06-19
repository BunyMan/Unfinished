/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:09:56 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/19 16:14:40 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_key_hook_down(int keycode, t_window *win)
{
	if (keycode == W)
		win->keys.w = 1;
	if (keycode == A)
		win->keys.a = 1;
	if (keycode == S)
		win->keys.s = 1;
	if (keycode == D)
		win->keys.d = 1;
	if (keycode == ESC)
		exit_s(win);
	return (1);
}
int ft_key_hook_up(int keycode, t_window *win)
{
	if (keycode == W)
		win->keys.w = 0;
	if (keycode == A)
		win->keys.a = 0;
	if (keycode == S)
		win->keys.s = 0;
	if (keycode == D)
		win->keys.d = 0;
	if (keycode == ESC)
		exit_s(win);
	return (1);
}

int	ft_hook(t_window *win)
{
	ft_move_counter(win);
	ft_paint(win);
	return (1);
}
