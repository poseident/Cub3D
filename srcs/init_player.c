/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschweit <bschweit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:07:52 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/14 13:33:14 by bschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_angle_player(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	while (++x < game->map.lines)
	{
		y = -1;
		while (++y < game->map.columns)
		{
			if (game->map.tab[x][y] == SOUTH)
				game->map.p.apos = ((3 * M_PI) / 2);
			else if (game->map.tab[x][y] == EAST)
				game->map.p.apos = M_PI;
			else if (game->map.tab[x][y] == NORTH)
				game->map.p.apos = (M_PI / 2);
			else if (game->map.tab[x][y] == WEST)
				game->map.p.apos = 0;
		}
	}
}

void	init_var_player(t_game *game)
{
	game->map.nb_player = 0;
	game->map.p.speed = 1.5;
	game->map.p.rotspeed = 0.3;
	game->map.hit_wall = 0;
	game->rapport_player = DEFINITION_TEXTURES;
	init_angle_player(game);
	printf("init player OK\n");
}

void	init_player_position(t_game *game, char *line, int y)
{
	int	x;

	x = 0;
	while ((line[x] != '\0') && find_player(line[x], "NSEW") == 0)
	x++;
	if (line[x] == '\0')
		return ;
	game->map.p.pos.x = x * game->rapport_player;
	game->map.p.pos.y = y * game->rapport_player;
}
