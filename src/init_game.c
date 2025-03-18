/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 23:43:50 by bnespoli          #+#    #+#             */
/*   Updated: 2024/05/11 19:50:24 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_game(t_data *data)
{
	data->mlx = mlx_init((SIZE_IMG * data->map->count_cols),
			(SIZE_IMG * data->map->count_rows), "so-long (bnespoli)", true);
	convert_png_to_texture(data->content);
	convert_texture_to_image(data->mlx, data->content);
	resize_image(data->content);
	validation_images(data->content);
	render_map(data);
	mlx_key_hook(data->mlx, &move_player, data);
	mlx_loop_hook(data->mlx, &close_window, data);
	mlx_loop(data->mlx);
}
