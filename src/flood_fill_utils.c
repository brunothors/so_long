/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 22:14:30 by bnespoli          #+#    #+#             */
/*   Updated: 2024/05/11 20:15:37 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_newlines(char *buffer)
{
	int	index;

	index = 0;
	if (buffer[0] == '\n')
	{
		ft_printf("ERROR. Invalid map (exceeds newline limit).\n");
		free(buffer);
		exit (EXIT_FAILURE);
	}
	while (buffer[index] != '\0')
	{
		if ((buffer[index] == '\n' && buffer[index - 1] != '1')
			|| (buffer[index] == '\n' && buffer[index + 1] == '\n'))
		{
			ft_printf("ERROR. Invalid map (exceeds newline limit).\n");
			free(buffer);
			exit (EXIT_FAILURE);
		}
		index++;
	}
	return (EXIT_SUCCESS);
}

void	count_elements(t_map *map, char **matrix)
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
				map->count_person++;
			if (matrix[y][x] == 'C')
				map->count_gold++;
			if (matrix[y][x] == 'E')
				map->count_end++;
			x++;
		}
		y++;
	}
	if (map->count_person != 1 || map->count_end != 1
		|| map->count_gold < 1)
	{
		ft_printf("ERROR. Invalid map (incorrect quantities of elements).\n");
		free_allocations(map->buffer, matrix);
	}
}

int	check_wall(t_map *map, char **matrix)
{
	int32_t	x;
	int32_t	y;

	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x] != '\0')
		{
			if (matrix[0][x] != '1'
				|| matrix[map->count_rows - 1][x] != '1'
				|| matrix[y][0] != '1'
				|| matrix[y][map->count_cols - 1] != '1')
			{
				ft_printf("ERROR. Contents of the wall invalid.\n");
				free_allocations(map->buffer, matrix);
			}
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}
