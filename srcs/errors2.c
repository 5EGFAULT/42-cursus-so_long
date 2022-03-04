/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:08:51 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/04 12:29:12 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ERROR_MAP_BORDER()
{
	ft_putstr_fd("ERROR_MAP_BORDER", 1);
	exit(ERROR_MAP_BORDER);
}

void	ERROR_MAP_PLAYER()
{
	ft_putstr_fd("ERROR_MAP_PLAYER", 1);
	exit(ERROR_MAP_PLAYER);
}

void	ERROR_MAP_EXIT()
{
	ft_putstr_fd("ERROR_MAP_EXIT", 1);
	exit(ERROR_MAP_WIDTH);
}

void	ERROR_MAP_FOUND_FORBIDDEN_OBJECT()
{
	ft_putstr_fd("ERROR_MAP_FOUND_FORBIDDEN_OBJECT", 1);
	exit(ERROR_MAP_FOUND_FORBIDDEN_OBJECT);
}
