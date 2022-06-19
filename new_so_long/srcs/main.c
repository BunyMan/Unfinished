/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:28:41 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/19 15:36:48 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_x_button(t_window *win)
{
	mlx_destroy_window(win->mlx, win->window);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_window *win;
	if (argc != 2)
	{
		ft_printf("Wrong number of arguments\n");
		exit(EXIT_SUCCESS);
	}
	win = ft_init_struct();
	if (!ft_checker(win, argv))
		exit(EXIT_SUCCESS);
	ft_init_window(win);
	mlx_hook(win->window, 17, 1L, << 2, &close_x_button, win);
	mlx_hook(win->window, 2, 1, ft_key_hook_down, win);
	mlx_hook(win->window, 3, 1, ft_key_hook_up, win);
	mlx_loop_hook(win->mlx, ft_hook, win);
	mlx_loop(win->mlx);
	exit_s(win);
}