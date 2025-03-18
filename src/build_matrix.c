/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:07:59 by bnespoli          #+#    #+#             */
/*   Updated: 2024/05/11 20:20:36 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int32_t	open_file(const char *av)
{
	int32_t	fd;

	fd = open(av, O_RDONLY, 0666);
	if (fd < 0)
	{
		ft_printf("Error. Invalid fd (%d).\n", fd);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

static int	check_char_str(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (EXIT_SUCCESS);
		i++;
	}
	return (EXIT_FAILURE);
}

void	read_file(const char *av, t_map *map)
{
	map->fd = open_file(av);
	while (map->read_bytes > 0)
	{
		map->read_bytes = read(map->fd, &map->c, 1);
		if (check_char_str(map->c, "\n01CEP") != 0)
		{
			ft_printf("Error. Invalid map (NULL or invalid char).\n");
			exit (EXIT_FAILURE);
		}
		map->size_map++;
	}
	close(map->fd);
	map->fd = open_file(av);
	map->buffer = ft_calloc(map->size_map, sizeof(char));
	if (!map->buffer)
	{
		ft_printf("ERROR. Memory allocation failed.\n");
		exit (EXIT_FAILURE);
	}
	map->read_bytes = read(map->fd, map->buffer, map->size_map);
	close(map->fd);
}

static void	check_dimensions(t_map *map)
{
	int	i;
	int	cols;

	i = 0;
	cols = 0;
	while (map->buffer[i])
	{
		if (map->buffer[i] == '1' || map->buffer[i] == '0'
			|| map->buffer[i] == 'C' || map->buffer[i] == 'E'
			|| map->buffer[i] == 'P')
			cols++;
		if (i > 0 && (map->buffer[i - 1] == '1' \
			&& map->buffer[i] == '\n' \
			&& map->buffer[i + 1] == '1'))
			map->count_rows++;
		i++;
	}
	map->count_rows++;
	map->count_cols = cols / map->count_rows;
}

void	build_matrix(t_data *data, const char *av)
{
	read_file(av, data->map);
	if (data->map->size_map < 17)
	{
		free (data->map->buffer);
		ft_printf("ERROR. Impossible map valid.\n");
		exit(EXIT_FAILURE);
	}
	check_newlines(data->map->buffer);
	check_dimensions(data->map);
	flood_fill(data);
	data->map->matrix = ft_split(data->map->buffer, '\n');
	free(data->map->buffer);
}
