/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:19:45 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/19 14:32:12 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_window	*ft_init_struct(void)
{
	t_window	*win;
	
	win = (t_window *)malloc(sizeof(t_window));
	if (!win)
		return (0);
	win->move_counter = 0;
	return (win);
}

void	ft_init_keys(t_window *win)
{
	win->keys.w = 0;
	win->keys.a = 0;
	win->keys.s = 0;
	win->keys.d = 0;
	win->keys.esc = 0;
}

void	ft_init_player(t_window *win)
{
	int	i;
	int	j;

	i = -1;
	while (win->map[++i])
	{
		j = -1;
		while (win->map[i][++j])
		{
			if (win->map[i][j] == 'P')
			{
				win->img_p.x = j * 64;
				win->img_p.y = i * 64;
			}
		}
	}
}

void	ft_init_window(t_window *win)
{
	win->mlx = mlx_init();
	win->window = mlx_new_window(win->mlx, win->win_x, \
	win->win_y, "So Long");
	ft_init_keys(win);
	ft_init_map(win);
	ft_init_player(win);
}