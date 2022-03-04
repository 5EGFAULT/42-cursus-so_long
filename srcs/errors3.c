/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:08:51 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/04 12:24:46 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ERROR_MAP_NOT_FOUND()
{
	ft_putstr_fd("ERROR_MAP_NOT_FOUND", 1);
	exit(ERROR_MAP_NOT_FOUND);
}

void	ERROR_MAP_NOT_VALID()
{
	ft_putstr_fd("ERROR_MAP_NOT_VALID", 1);
	exit(ERROR_MAP_NOT_VALID);
}

void	ERROR_MAP_NOT_BER_EXTENTION()
{
	ft_putstr_fd("ERROR_MAP_NOT_BER_EXTENTION", 1);
	exit(ERROR_MAP_NOT_BER_EXTENTION);
}

void	ERROR_GAME_IS_NULL()
{
	ft_putstr_fd("ERROR_GAME_IS_NULL", 1);
	exit(ERROR_GAME_IS_NULL);
}

void	ERROR_MAP_WIDTH()
{
	ft_putstr_fd("ERROR_MAP_WIDTH", 1);
	exit(ERROR_MAP_WIDTH);
}
