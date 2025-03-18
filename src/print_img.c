/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:57:53 by bnespoli          #+#    #+#             */
/*   Updated: 2024/05/11 17:59:34 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_floor(t_data *data, int32_t x, int32_t y)
{
	mlx_image_to_window(data->mlx, data->content->floor_img, x, y);
}

void	print_wall(t_data *data, int32_t x, int32_t y)
{
	mlx_image_to_window(data->mlx, data->content->wall_img, x, y);
}

void	print_player(t_data *data, int32_t x, int32_t y)
{
	mlx_image_to_window(data->mlx, data->content->player_img, x, y);
}

void	print_exit(t_data *data, int32_t x, int32_t y)
{
	data->content->end_img->enabled = false;
	mlx_image_to_window(data->mlx, data->content->end_img, x, y);
}

void	print_gold(t_data *data, int32_t x, int32_t y)
{
	mlx_image_to_window(data->mlx, data->content->gold_img, x, y);
}
