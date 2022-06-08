/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:37:40 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/08 16:01:15 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_x_button(win_s *ptr) //closes the window when the red "x" button is pressed
{
	mlx_destroy_window(ptr->mlx, ptr->win);
	exit(42);
}

int	deal_key(int key, win_s *ptr) //closes the window when esc is pressed
{
	//printf("key = %d\n", key);
	ptr->moves++;
	printf("Moves = %d\n", ptr->moves);
	if (key == 53)
	{
		mlx_clear_window(ptr->mlx, ptr->win);
		mlx_destroy_window(ptr->mlx, ptr->win);
		exit(1);
	}
	return (1);
}
