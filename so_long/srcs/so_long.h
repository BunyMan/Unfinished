/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:28:40 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/08 15:50:27 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct window_s{
	void	*mlx;
	void	*win;
	int		moves;
}			win_s;

int	close_x_button(win_s *ptr);
int	deal_key(int key, win_s *ptr);

#endif