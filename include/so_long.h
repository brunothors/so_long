/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:33:17 by bnespoli          #+#    #+#             */
/*   Updated: 2024/05/11 20:17:24 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"

# define SIZE_IMG 64
# define PLAYER_L "./textures/player_l.png"
# define PLAYER_R "./textures/player_r.png"
# define FLOOR "./textures/floor.png"
# define WALL "./textures/wall.png"
# define GOLD "./textures/gold.png"
# define END "./textures/end.png"

typedef struct s_positions_elements
{
	int32_t	x_end;
	int32_t	y_end;
	int32_t	x_plyr;
	int32_t	y_plyr;
}	t_posix;

typedef struct s_content
{
	mlx_texture_t	*floor_png;
	mlx_image_t		*floor_img;
	mlx_texture_t	*wall_png;
	mlx_image_t		*wall_img;
	mlx_texture_t	*gold_png;
	mlx_image_t		*gold_img;
	mlx_texture_t	*player_png;
	mlx_image_t		*player_img;
	mlx_texture_t	*end_png;
	mlx_image_t		*end_img;
	int				side_player;
}	t_content;

typedef struct s_map
{
	char	c;
	char	*buffer;
	char	**matrix;
	int32_t	read_bytes;
	int32_t	size_map;
	int32_t	count_rows;
	int32_t	count_cols;
	int32_t	count_person;
	int32_t	count_gold;
	int32_t	count_end;
	int32_t	fd;
}	t_map;

typedef struct s_data
{
	mlx_t		*mlx;
	t_content	*content;
	t_map		*map;
	t_posix		*posix;
	int32_t		move;
}	t_data;

//---------------- START GAME ----------------
void	init_vars(t_data *data);
void	init_game(t_data *data);
//------------------- MAP --------------------
void	build_matrix(t_data *data, const char *av);
void	flood_fill(t_data *data);
int		check_wall(t_map *map, char **matrix);
void	count_elements(t_map *map, char **matrix);
int		check_newlines(char *buffer);
//----------------- IMAGE --------------------
int32_t	convert_png_to_texture(t_content *content);
void	convert_texture_to_image(mlx_t *mlx, t_content *content);
void	resize_image(t_content *content);
void	validation_images(t_content *content);
void	render_map(t_data *data);
void	print_player(t_data *data, int32_t x, int32_t y);
void	print_floor(t_data *data, int32_t x, int32_t y);
void	print_wall(t_data *data, int32_t x, int32_t y);
void	print_gold(t_data *data, int32_t x, int32_t y);
void	print_exit(t_data *data, int32_t x, int32_t y);
//------------ MOVIMENTS PLAYER --------------
void	up_move(t_data *data, int32_t move_x, int32_t move_y);
void	left_move(t_data *data, int32_t move_x, int32_t move_y);
void	down_move(t_data *data, int32_t move_x, int32_t move_y);
void	right_move(t_data *data, int32_t move_x, int32_t move_y);
void	move_player(mlx_key_data_t keyd, void *param);
void	render_move_player(t_data *data, int32_t col, int32_t row);
//------------ FREE/CLOSE GAME ---------------
void	free_matrix(char **matrix);
void	free_allocations(char *buffer, char **matrix);
void	delete_textures(t_content *content);
void	delete_images(mlx_t *mlx, t_content *content);
int		free_end_game(t_data *data);
void	close_window(void *key);

#endif