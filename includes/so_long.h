/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:05:53 by jrobert           #+#    #+#             */
/*   Updated: 2022/01/12 17:42:43 by jrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# define WHI 0x00FFFFFF

typedef struct s_img
{
	void	*ptr;
	char	*px;
	int		w;
	int		h;
	int		bpp;
	int		ll;
	int		end;
}			t_img;

typedef struct s_mlx
{
	void	*ptr;
	void	*win_ptr;
	int		w;
	int		h;
}			t_mlx;

typedef struct s_game
{
	t_mlx	mlx;
	char	**map;
	int		cols;
	int		rows;
	int		c;
	int		e;
	int		p;
	int		moves;
	int		coins;
	int		pos_x;
	int		pos_y;
	int		end;
	t_img	panel;
	t_img	bg;
	t_img	mario;
	t_img	wall;
	t_img	exit;
	t_img	coin;
	t_img	success;
}			t_game;

void	check_border(t_game *game);
void	check_shape(char *file, t_game *game);
void	check_content_char(t_game *game, char c);
int		check_content(t_game *game);

void	draw_content(t_game *game);
void	draw_score(t_game *game);
void	draw_bg(t_game *game);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		rgb_to_int(int red, int green, int blue);

int		move_up(t_game *game);
int		move_down(t_game *game);
int		move_left(t_game *game);
int		move_right(t_game *game);

int		free_mal(t_game *game, int y, int fd);
int		parse_map(char *file, t_game *game);

void	update_panel(t_game *game);
void	reset_texture(t_game *game);
void	win(t_game *game);
int		deal_key(int key, t_game *game);

void	destroy_textures(t_game *game);
int		exit_game(t_game *game, char *error_txt);
int		close_win(t_game *game);

void	init_mlx(t_game *game);

void	create_textures_a(t_game *game);
void	create_textures_b(t_game *game);
void	create_textures(t_game *game);

#endif