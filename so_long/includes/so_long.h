/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:28:40 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/13 16:11:02 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct window_s{
	void	*mlx;
	void	*win;
	int		moves;
	void	*pool_ptr;
	void	*edge_ptr;
	int		win_x;
	int		win_y;
	int		nix;
	int		niy;
	int		p;
	int		e;
	int		c;
	int		width;
	int		height;
	void	*img_ptr;
}			win_s;

typedef struct sprites_s{
	int		img_x;
	int		img_y;
	char	*duck_front;
	char	*duck_frnt_hat;
	char	*duck_back;
	char	*duck_back_hat;
	char	*duck_left;
	char	*duck_left_hat;
	char	*duck_right;
	char	*duck_rght_hat;
	char	*edge;
	char	*gator;
	char	*hat;
	char	*goose;
}			spr_s;

//interactions.c
int		close_x_button(win_s *ptr);
int		deal_key(int key, win_s *ptr);
//window_printer.c
void	win_printer(win_s *ptr);
void	map_printer(win_s *ptr, int pool_x, int pool_y);
void	edge_printer(win_s *ptr, int pool_x, int pool_y);
//sprite_printer.c
void	spr_printer(spr_s *spr, win_s *win);

#endif
