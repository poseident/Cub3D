/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nb_player_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschweit <bschweit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:54:50 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/14 12:56:21 by bschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	count_char(char *str, char c)
{
	int	x;
	int	count;

	x = 0;
	count = 0;
	while (str[x] != '\0' && ft_isprint(str[x]) != '\0')
	{
		if (str[x] == c)
			count++;
		x++;
	}
	return (count);
}

void	check_nb_player(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.lines)
	{
		game->map.nb_player += count_char(game->map.tab[i], 'N');
		game->map.nb_player += count_char(game->map.tab[i], 'E');
		game->map.nb_player += count_char(game->map.tab[i], 'S');
		game->map.nb_player += count_char(game->map.tab[i], 'W');
		if (game->map.nb_player == 1)
			init_player_position(game, game->map.tab[i], i);
		i++;
	}
	if (game->map.nb_player != 1)
		error_msg("Error:\n, aucun ou plus de 1 joueur!");
	printf("le nombre de joueur est de 1\n");
}
