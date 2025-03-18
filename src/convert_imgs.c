/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_imgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 23:47:58 by bnespoli          #+#    #+#             */
/*   Updated: 2024/05/10 23:56:01 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int32_t	convert_png_to_texture(t_content *content)
{
	content->floor_png = mlx_load_png(FLOOR);
	content->wall_png = mlx_load_png(WALL);
	content->gold_png = mlx_load_png(GOLD);
	content->player_png = mlx_load_png(PLAYER_R);
	content->end_png = mlx_load_png(END);
	if (!content->floor_png
		|| !content->wall_png
		|| !content->gold_png
		|| !content->player_png
		|| !content->end_png)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	convert_texture_to_image(mlx_t *mlx, t_content *content)
{
	content->floor_img = mlx_texture_to_image(mlx, content->floor_png);
	content->wall_img = mlx_texture_to_image(mlx, content->wall_png);
	content->gold_img = mlx_texture_to_image(mlx, content->gold_png);
	content->player_img = mlx_texture_to_image(mlx, content->player_png);
	content->end_img = mlx_texture_to_image(mlx, content->end_png);
}

void	resize_image(t_content *content)
{
	mlx_resize_image(content->floor_img, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(content->wall_img, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(content->gold_img, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(content->player_img, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(content->end_img, SIZE_IMG, SIZE_IMG);
}

void	validation_images(t_content *content)
{
	if (content->floor_img == NULL || content->wall_img == NULL
		|| content->gold_img == NULL || content->player_img == NULL
		|| content->end_img == NULL)
		ft_printf("Image loading failed!\n");
}
