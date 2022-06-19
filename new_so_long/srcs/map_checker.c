/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:37:15 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/19 16:09:44 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_fd(char **argv)
{
	int	fd;
	
	fd = open(argv[1], O_RDONLY);
	if ((fd) == -1)
	{
		ft_printf("Unable to open file\n");
		exit(EXIT_SUCCESS);
	}
	return (fd);
}

char	**read_map(int fd)
{
	char	*str;
	char	*buf;
	char	**map;
	char	*tmp;

	str = ft_strdup("");
	buf = get_next_line(fd);
	while (buf != NULL)
	{
		tmp = ft_strjoin(str, buf);
		free(str);
		str = tmp;
		free(buf);
		buf = get_next_line(fd);
	}
	map = ft_split(str, '\n');
	free(str);
	str = NULL;
	free(buf);
	buf = NULL;
	return (map);
}

int	check_map_close(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[0][j] != '1')
				return (0);
			if (map[i][0] != '1')
				return (0);
		}
		if (map[i][--j] != '1')
			return (0);
	}
	j = -1;
	i = -1;
	while (map[i][++j])
		if (map[i][j] != '1')
			return (0);
	return (1);
}

int	check_map_size(t_window *win, char **map)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (map[++i])
	{
		j = -1;
		if (ft_strlen(map[0]) != ft_strlen(map[i]))
			return (ft_printf("Incoherent map size\n") - 25);
		while (map[i][j] != 0)
			j++;
	}
	win->win_x = j * 64;
	win->win_y = i * 64;
	return (1);
}

int	check_map_playable(t_window *win, char **map)
{
	int			i;
	int			j;
	static int	e;
	static int	p;
	
	i = -1;
	win->img_c.nbr = 0;
	while (map[i++])
	{
		j = -1;
		while(map[i][++j])
		{
			if (map[i][j] == 'P')
				win->img_p.nbr++;
			if (map[i][j] == 'E')
				win->img_e.nbr++;
			if (map[i][j] == 'C')
				win->img_c.nbr++;
		}
	}
	if (in->img_c.nbr < 1 || p < 1 || e < 1)
		return (ft_printf("Invalid map component count\n") - 70);
	return (1);
}