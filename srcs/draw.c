/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:53:36 by jrobert           #+#    #+#             */
/*   Updated: 2022/01/12 17:26:24 by jrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_content(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->rows)
	{
		x = -1;
		while (++x < game->cols)
		{
			mlx_put_image_to_window(game->mlx.ptr, game->mlx.win_ptr,
				game->bg.ptr, x * 35, y * 35);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx.ptr, game->mlx.win_ptr,
					game->wall.ptr, x * 35, y * 35);
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx.ptr, game->mlx.win_ptr,
					game->mario.ptr, x * 35, y * 35);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx.ptr, game->mlx.win_ptr,
					game->coin.ptr, x * 35, y * 35);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx.ptr, game->mlx.win_ptr,
					game->exit.ptr, x * 35, y * 35);
		}
	}
}

void	draw_score(t_game *game)
{
	mlx_string_put(game->mlx.ptr, game->mlx.win_ptr, 15, 16, WHI, "Moves = ");
	mlx_string_put(game->mlx.ptr, game->mlx.win_ptr, 70, 16, WHI, "0");
	mlx_string_put(game->mlx.ptr, game->mlx.win_ptr, 15, 28, WHI, "Score = ");
	mlx_string_put(game->mlx.ptr, game->mlx.win_ptr, 70, 28, WHI, "0");
}

void	draw_bg(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->rows)
	{
		x = -1;
		while (++x < game->cols)
			mlx_put_image_to_window(game->mlx.ptr, game->mlx.win_ptr,
				game->bg.ptr, x * 35, y * 35);
	}
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	int		a;
	int		b;

	a = 0;
	while (a++ < img->h)
	{
		b = 0;
		while (b++ < img->w)
		{
			dst = img->px + (y * img->ll + x * (img->bpp / 8));
			*(unsigned int *)dst = color;
			img->px += 4;
		}
	}
}

int	rgb_to_int(int red, int green, int blue)
{
	int	color;

	color = 0;
	color += red;
	color <<= 8;
	color += green;
	color <<= 8;
	color += blue;
	return (color);
}
