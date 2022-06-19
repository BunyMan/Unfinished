/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 13:28:13 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/19 14:10:58 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_map(t_window *win)
{
	win->img_0.img = mlx_put_image_to_window(win->mlx, \
	"pool.xpm", &win->img_0.width, &win->img_0.height);
	win->img_1.img = mlx_put_image_to_window(win->mlx, \
	"edge.xpm", &win->img_1.width, &win->img_1.height);
	win->img_c.img = mlx_put_image_to_window(win->mlx, \
	"hat.xpm", &win->img_c.width, &win->img_c.height);
	win->img_e.img = mlx_put_image_to_window(win->mlx, \
	"goose.xpm", &win->img_e.width, &win->img_e.height);
}

int	ft_checker(t_window *win, char **argv)
{
	int		fd;

	fd = get_fd(argv);
	win->map = read_map(fd);
	if (win->map = NULL)
		return (0);
	if (!check_map_size(win, win->map))
	{
		ft_printf("Wrong map size\n");
		return (0);
	}
	if (!check_map_close(win->map))
	{
		ft_printf("Map isn't closed\n");
		return (0);
	}
	if (!check_map_playable(win, win->map))
	{
		ft_printf("The map sin't playable\n");
		return (0);
	}
	return (1);
}

void	colider_print(t_window *win)
{
	int	i;
	int	j;

	i = -1;
	while (win->map[++i])
	{
		j = -1;
		while (win->map [i][++j])
		{
			if (win->map[i][j] == 'C')
				mlx_put_image_to_window(win->mlx, win->window, \
				win->img_c.img, j * 64, i * 64);
		}
	}
}

void	map_print(t_window *win)
{
	int	i;
	int	j;

	i = -1;
	while (win->map[++i])
	{
		j = -1;
		while (win->map[i][++j])
		{
			if (win->map[i][j] == '1')
				mlx_put_image_to_window(win->mlx, win->window, \
				win->img_1.img, j * 64, i * 64);
			else
				mlx_put_image_to_window(win->mlx, win->window, \
				win->img_0.img, j * 64, i * 64);
		}
	}
}