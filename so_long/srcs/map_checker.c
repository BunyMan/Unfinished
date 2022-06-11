/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:45:10 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/11 20:05:40 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_checker(char **map, t_win_s *m, int x, int y)
{
	m -> p = 0;
	m -> e = 0;
	m -> c = 0;
	while (map[y] != 0)
	{
		while (map[y][x] != '\n' && map [x][y] != '\0')
		{
			if ((map[0][x] != '1') || map[m -> height -1][x != '1'])
				return (0);
			else if (map[y][0] != '1' || map[y][m -> width -1] != '1')
				return (0);
			if (map[y][x] == 'P')
				m -> p++;
			if (map[y][x] == 'E')
				m -> e++;
			if (map[y][x] == 'C')
				m -> c++;
			x++;
		}
		x = 0;
		y++;
	}
	if (m -> p == 1 && m -> e == 1 && m -> c > 0)
		return (1);
	return (0);
}

