/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:34:53 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/13 17:22:13 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_checker(char **map, win_s *welp, int x, int y)
{
	welp -> p = 0;
	welp -> e = 0;
	welp -> c = 0;
	while (map[y] != 0)
	{
		while (map[x][y] != '\n' || map[x][y] != '\0')
		{
			if ((map[0][x] != '1') || map[welp -> height -1][x] != '1')
				return (0);
			else if (map[y][0] != '1' || map[y][welp -> width - 1] != '1')
				return (0);
			if (map[x][y] == 'P')
				welp -> p = welp -> p + 1;
			if (map[x][y] == 'E')
				welp -> e = welp -> e + 1;
			if (map[x][y] == 'C')
				welp -> c = welp -> c + 1;
			x += 1;
		}
		x = 0;
		y += 1;
	}
	if (welp -> p != 1 || welp -> e != 1 || welp -> c != 1)
		return (0);
	return (1);
}

int	map_name(char *str)
{
	char	**valid;

	if (!ft_strchr(str, '.'))
		return (1);
	valid = ft_split(str, '.');
	if (ft_strncmp(valid[1], "ber", 3) == 0 && !valid[2])
		return (0);
	return (1);
}
