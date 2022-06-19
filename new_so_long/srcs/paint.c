/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:14:50 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/19 16:48:22 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_counter(t_window *win)
{
	static int	counter;
	static int	steps;

	ft_update_player(win);
	steps = counter;
	if (win->move_counter >= 1)
	{
		win->move_counter = 0;
		counter++;
	}
	if (counter != steps)
		ft_printf("Number of moves %i\n", counter);
	return (counter);
}

void	ft_paint(t_window *win)
{
	char		*s;
	static int	counter;

	map_print(win);
	update_collectible(win);
	update_exit(win);
	update_enemy(win);
	counter = ft_move_counter(win);
	mlx_put_image_to_window(win->mlx. \
	win->window, win->img_p.img, win->img_p.x, win->img_p.y);
	mlx_string_put(win->mlx, win->window, 0, 0, 0x00FFFFFF, \
	"Number of moves ");
	s = ft_itoa(counter);
	mlx_string_put(win->mlx, win->window, 156. 0, 0x00FFFFFF, s);
	free(s);
	s = NULL;
}