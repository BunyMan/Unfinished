/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:24:28 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/18 16:53:27 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx"
#include <fcntl.h>
#include <stdio.h>

typedef struct s_keys {
	int	w;
	int	a;
	int	s;
	int	d;
	int	esc;
}	t_keys;

typedef struct s_sprites {
	void	*img_f[3];
	void	*img_b[3];
	void	*img_l[3];
	void	*img_r[3];
	void	*img;
	char	**addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	int		height;
	int		width;
	int		pace;
	int		nbr;
	int		counter;
	int		x;
	int		y;
}	t_sprites;

typedef struct s_window {
	void	*mlx;
	void	*window;
	char	**map;
	int		win_x;
	int		win_y;
	int		moves;
	char	*scream;
	t_sprites img_0;
	t_sprites img_1;
	t_sprites img_p;
	t_sprites img_e;
	t_sprites imc_c;
	t_sprites img_x;
	t_keys keys;
}	t_window;

t_window	*ft_init_struct(void);
void		ft_init_window(t_window *win);
void		init_keys(t_window *win);
int			ft_key_hook_up(int keycode, t_window *win);
int			ft_key_hook_down(int keycode, t_window *win);
int			ft_hook(t_window *win);
void		ft_init_player(t_window *win);
void		ft_init_player_animation(t_window *win);
void		update_player(t_window *win);
int			move_counter(t_window *win);
void		ft_paint(t_window *win);
int			get_fd(char **argv);
char 		**read_map(int fd);
void		ft_init_map(t_window *win);
int			ft_checker(t_window *win, char **argv);
int			check_map_close(char **map);
int			check_map_size(t_window *win, char *map);
int			check_map_playable(t_window *win, char *map);
void		map_print(t_window *win);
void		update_enemmy(t_window *win);
void		update_collectible(t_window *win);
void		update_exit(t_window *win);
void		exit_s(t_window *win);
void		colider(t_window *win);

#endif
