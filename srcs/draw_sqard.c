/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sqard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschweit <bschweit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:36:49 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/14 12:59:10 by bschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_square(t_game *game, int posx, int posy, int color)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (game->win_ptr == NULL)
		return ;
	while (++i < 10)
	{
		while (++j < 10)
			img_pix_put(game, posy + i, posx + j, color);
		j = -1;
	}
}
