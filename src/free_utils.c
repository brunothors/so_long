/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:21:25 by bnespoli          #+#    #+#             */
/*   Updated: 2024/05/11 18:25:42 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_matrix(char **matrix)
{
	int	y;

	y = 0;
	while (matrix[y])
	{
		free(matrix[y]);
		y++;
	}
	free(matrix);
}

void	free_allocations(char *buffer, char **matrix)
{
	free_matrix(matrix);
	free(buffer);
	exit(EXIT_FAILURE);
}

void	delete_textures(t_content *content)
{
	mlx_delete_texture(content->floor_png);
	mlx_delete_texture(content->wall_png);
	mlx_delete_texture(content->player_png);
	mlx_delete_texture(content->gold_png);
	mlx_delete_texture(content->end_png);
}

void	delete_images(mlx_t *mlx, t_content *content)
{
	mlx_delete_image(mlx, content->floor_img);
	mlx_delete_image(mlx, content->wall_img);
	mlx_delete_image(mlx, content->player_img);
	mlx_delete_image(mlx, content->gold_img);
	mlx_delete_image(mlx, content->end_img);
}

int	free_end_game(t_data *data)
{
	delete_textures(data->content);
	delete_images(data->mlx, data->content);
	mlx_close_window(data->mlx);
	mlx_terminate(data->mlx);
	free_matrix(data->map->matrix);
	exit (EXIT_SUCCESS);
}
