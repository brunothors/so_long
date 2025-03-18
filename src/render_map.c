/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:39:24 by bnespoli          #+#    #+#             */
/*   Updated: 2024/05/11 20:11:24 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_move_player(t_data *data, int32_t col, int32_t row)
{
	if (data->content->side_player == 0)
	{
		mlx_delete_image(data->mlx, data->content->player_img);
		mlx_delete_texture(data->content->player_png);
		data->content->player_png = mlx_load_png(PLAYER_R);
		data->content->player_img = mlx_texture_to_image(data->mlx, \
			data->content->player_png);
		mlx_resize_image(data->content->player_img, SIZE_IMG, SIZE_IMG);
		mlx_image_to_window(data->mlx, data->content->player_img, \
			(SIZE_IMG * col), (SIZE_IMG * row));
	}
	else if (data->content->side_player == 1)
	{
		mlx_delete_image(data->mlx, data->content->player_img);
		mlx_delete_texture(data->content->player_png);
		data->content->player_png = mlx_load_png(PLAYER_L);
		data->content->player_img = mlx_texture_to_image(data->mlx, \
			data->content->player_png);
		mlx_resize_image(data->content->player_img, SIZE_IMG, SIZE_IMG);
		mlx_image_to_window(data->mlx, data->content->player_img, \
			(SIZE_IMG * col), (SIZE_IMG * row));
	}
}

void	move_player(mlx_key_data_t keyd, void *param)
{
	t_data	*data;
	int32_t	x;
	int32_t	y;

	data = (t_data *)param;
	data->posix->x_plyr = data->content->player_img->instances->x / SIZE_IMG;
	data->posix->y_plyr = data->content->player_img->instances->y / SIZE_IMG;
	x = data->posix->x_plyr;
	y = data->posix->y_plyr;
	if (keyd.key == MLX_KEY_W && keyd.action == MLX_PRESS \
		&& data->map->matrix[y - 1][x] != '1')
		up_move(data, x, y);
	if (keyd.key == MLX_KEY_A && keyd.action == MLX_PRESS
		&& data->map->matrix[y][x - 1] != '1')
		left_move(data, x, y);
	if (keyd.key == MLX_KEY_S && keyd.action == MLX_PRESS
		&& data->map->matrix[y + 1][x] != '1')
		down_move(data, x, y);
	if (keyd.key == MLX_KEY_D && keyd.action == MLX_PRESS
		&& data->map->matrix[y][x + 1] != '1')
		right_move(data, x, y);
}

void	close_window(void *key)
{
	t_data	*data;

	data = (t_data *)key;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		free_end_game(data);
}

void	put_elements_map(t_data *data, int32_t cols, int32_t rows)
{
	print_floor(data, (SIZE_IMG * cols), (SIZE_IMG * rows));
	if (data->map->matrix[rows][cols] == '1')
		print_wall(data, (SIZE_IMG * cols), (SIZE_IMG * rows));
	if (data->map->matrix[rows][cols] == 'C')
		print_gold(data, (SIZE_IMG * cols), (SIZE_IMG * rows));
	if (data->map->matrix[rows][cols] == 'P')
		print_player(data, (SIZE_IMG * cols), (SIZE_IMG * rows));
	if (data->map->matrix[rows][cols] == 'E')
		print_exit(data, (SIZE_IMG * cols), (SIZE_IMG * rows));
}

void	render_map(t_data *data)
{
	int32_t	x;
	int32_t	y;

	if (data->mlx == NULL)
		return ;
	y = 0;
	while (y < data->map->count_rows)
	{
		x = 0;
		while (x < data->map->count_cols)
		{
			put_elements_map(data, x, y);
			x++;
		}
		y++;
	}
}
