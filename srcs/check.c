/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:08:02 by jrobert           #+#    #+#             */
/*   Updated: 2022/01/14 19:09:37 by jrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_border(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	while (++x < game->cols)
		if (game->map[0][x] != '1')
			exit_game(game, "Map border - top");
	y = 0;
	while (++y < game->rows - 1)
	{
		if (game->map[y][0] != '1'
			|| game->map[y][game->cols - 1] != '1')
			exit_game(game, "Map border - left/right");
	}
	x = -1;
	while (++x < game->cols)
		if (game->map[game->rows - 1][x] != '1')
			exit_game(game, "Map border - bottom");
}

void	check_shape(char *file, t_game *game)
{
	int		fd;
	size_t	len;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_game(game, "File not found");
	len = 0;
	if (ft_get_next_line(fd, &line))
	{
		len = ft_strlen(line);
		game->rows = 2;
	}
	while (ft_get_next_line(fd, &line))
	{
		game->rows++;
		if (ft_strlen(line) != len)
			exit_game(game, "Wrong map shape");
	}
	if (ft_strlen(line) != len)
		exit_game(game, "Wrong map shape");
	game->cols = len;
	close(fd);
	if (game->rows < 3 || game->cols < 3)
		exit_game(game, "Wrong map shape");
}

void	check_content_char(t_game *game, char c)
{
	if (c != 'P' && c != '1'
		&& c != '0' && c != 'C'
		&& c != 'E')
		exit_game(game, "Wrong map content");
}

int	check_content(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->rows)
	{
		x = -1;
		while (++x < game->cols)
		{
			check_content_char(game, game->map[y][x]);
			if (game->map[y][x] == 'P' && game->p)
				game->map[y][x] = '0';
			else if (game->map[y][x] == 'P' && !game->p)
			{
				game->pos_x = x;
				game->pos_y = y;
			}
			game->p += (game->map[y][x] == 'P');
			game->e += (game->map[y][x] == 'E');
			game->c += (game->map[y][x] == 'C');
		}
	}
	if (game->c < 1 || game->e < 1 || game->p < 1)
		exit_game(game, "Map content missing");
	return (0);
}
