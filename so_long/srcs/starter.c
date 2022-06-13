/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:31:05 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/13 17:29:16 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_size(win_s *m)
{
	m -> width = 0;
	m -> height = 0;
	while (m -> map[0][m->width] != '\n')
		m->width = m->width + 1;
	while (m -> map[m->height] != 0)
		m->height = m->height + 1;
}

char	**map_info(int fd, char **map, int counter)
{
	char	*a;

	a = get_next_line(fd);
	if (a)
		map = map_info(fd, map, counter + 1);
	if (!map)
		map = malloc(sizeof(char *) * counter + 1);
	map[counter] = a;
	counter = counter + 1;
	return (map);
}

int	starter(win_s *idk, char *arg)
{
	if (map_name(arg) != 0)
		error("Map name is invalid");
	idk -> map_f = open(arg, O_RDONLY);
	if (idk -> map_f < 0)
		error("Map not found");
	idk -> map_f = NULL;
	idk -> map_f = map_info(idk -> map_f, idk -> map, 0);
	if (!(idk -> map))
		error("Map wasn't read");
	map_size(idk);
	if (idk -> width <= 2 || idk ->height <= 2)
		error("Map size is invalid");
	if(map_checker(idk -> map, idk, 0, 0) == 0)
		error("Invalid map");
	return (0);
}

void img_loader(win_s *i)
{
	
}
