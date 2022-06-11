/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:28:40 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/08 18:05:32 by jbuny-fe         ###   ########.fr       */
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
	void	*img_ptr;
	int		win_x;
	int		win_y;
	int		nix;
	int		niy;
	int		p;
	int		e;
	int		c;
	int		width;
	int		height;
}			t_win_s;

int		close_x_button(t_win_s *ptr);
int		deal_key(int key, t_win_s *ptr);
void	win_printer(t_win_s *ptr);
int		map_checker(char **map, t_win_s *m, int x, int y);
int		check_valid_map_name(char *str);
#endif
