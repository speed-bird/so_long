/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:55:07 by jrobert           #+#    #+#             */
/*   Updated: 2022/01/12 17:38:10 by jrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_mal(t_game *game, int y, int fd)
{
	while (y--)
		free(game->map[y]);
	free(game->map);
	close(fd);
	return (1);
}

int	parse_map(char *file, t_game *game)
{
	int		fd;
	int		y;
	char	*line;

	game->map = (char **)malloc(sizeof(*game->map) * game->rows);
	if (!game->map)
		return (1);
	y = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_game(game, "Unable to read map file");
	while (ft_get_next_line(fd, &line))
	{
		game->map[y] = ft_strdup(line);
		if (!game->map[y])
			return (free_mal(game, y, fd));
		y++;
	}
	game->map[y] = ft_strdup(line);
	if (!game->map[y])
		return (free_mal(game, y, fd));
	close(fd);
	return (0);
}
