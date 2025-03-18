/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 21:35:02 by bnespoli          #+#    #+#             */
/*   Updated: 2024/05/13 14:09:30 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	position_elements(t_posix *posix, char **matrix)
{
	int32_t	x;
	int32_t	y;

	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x])
		{
			if (matrix[y][x] == 'P')
			{
				posix->y_plyr = y;
				posix->x_plyr = x;
			}
			if (matrix[y][x] == 'E')
			{
				posix->y_end = y;
				posix->x_end = x;
			}
			x++;
		}
		y++;
	}
}

void	check_format(t_map *map, char **matrix)
{
	int	x;
	int	y;

	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x])
			x++;
		if (x != map->count_cols)
		{
			ft_printf("ERROR. Invalid map (not rectangular).\n");
			free_allocations(map->buffer, matrix);
		}
		y++;
	}
}

static void	fill_map(t_map *map, char **matrix, int x, int y)
{
	if (x < 0 || x >= map->count_cols - 1 || y < 0 || y >= map->count_rows - 1
		|| matrix[y][x] == '1')
		return ;
	matrix[y][x] = '1';
	fill_map(map, matrix, x + 1, y);
	fill_map(map, matrix, x - 1, y);
	fill_map(map, matrix, x, y + 1);
	fill_map(map, matrix, x, y - 1);
}

static int	check_flood_fill(char **matrix)
{
	int	x;
	int	y;

	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x] != '\0')
		{
			if ((matrix[y][x] == 'P')
				|| (matrix[y][x] == 'E') || (matrix[y][x] == 'C'))
			{
				return (EXIT_FAILURE);
			}
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

void	flood_fill(t_data *data)
{
	char	**matrix;

	matrix = ft_split(data->map->buffer, '\n');
	check_format(data->map, matrix);
	position_elements(data->posix, matrix);
	count_elements(data->map, matrix);
	check_wall(data->map, matrix);
	fill_map(data->map, matrix, data->posix->x_plyr, data->posix->y_plyr);
	if (check_flood_fill(matrix) == EXIT_FAILURE)
	{
		ft_printf("ERROR. Invalid map (elements blocked by walls).\n");
		free_allocations(data->map->buffer, matrix);
	}
	free_matrix(matrix);
}
