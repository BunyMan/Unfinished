/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:37:40 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/08 17:46:23 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_x_button(t_win_s *ptr)
{
	mlx_destroy_window(ptr->mlx, ptr->win);
	exit(42);
}

int	deal_key(int key, t_win_s *ptr)
{
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
