/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_structure.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 03:37:35 by asouinia          #+#    #+#             */
/*   Updated: 2021/12/13 04:20:41 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	validate_map_name(char *map_file)
{
	int	i;

	if (map_file)
		return (0);
	i = ft_strlen(map_file);
	if (i < 4)
		return (0);
	if (map_file[i - 4] == '.')
		if (map_file[i - 3] == 'b')
			if (map_file[i - 2] == 'e')
				if (map_file[i - 1] == 'r')
					return (1);
	return (0);
}

int	validate_map_border(char **map)
{
    return (0);
}

int	validate_map_width(char *map_file)
{
    return (0);
}