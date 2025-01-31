/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_text_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschweit <bschweit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:01:40 by chajjar           #+#    #+#             */
/*   Updated: 2023/02/14 13:00:47 by bschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	find_texture(char *path, int index, t_game *cube)
{
	char	**temp;
	int		i;

	i = -1;
	temp = ft_split(path, ' ');
	temp[1][ft_strlen(temp[1]) - 1] = '\0';
	if (!temp[1] || temp[2])
		error_msg("Erreur : impossible de charger la texture !");
	cube->name_text[index] = ft_strdup(temp[1]);
	while (temp[++i])
		free (temp[i]);
	free (temp);
	return (1);
}

int	find_cell(char *path, t_game *cube)
{
	char	**temp;
	char	**temp2;
	int		i;

	i = -1;
	temp = ft_split(path, ' ');
	if (!temp[1] || temp[2])
		error_msg("Error:\nimpossible de charger la couleur du plafond !");
	temp2 = ft_split (temp[1], ',');
	if (!temp2[2] || temp2[3])
		error_msg("Error:\nimpossible de charger la couleur du plafond !");
	cube->r_c = ft_atoi(temp2[0]);
	cube->g_c = ft_atoi(temp2[1]);
	cube->b_c = ft_atoi(temp2[2]);
	if (!check_color(cube->r_c, cube->g_c, cube->b_c))
		error_msg("Error:\nimpossible de charger la couleur du plafond !");
	while (temp[++i])
		free(temp[i]);
	free (temp);
	i = -1;
	while (temp2[++i])
		free(temp2[i]);
	free (temp2);
	return (1);
}

int	find_floor(char *path, t_game *cube)
{
	char	**temp;
	char	**temp2;
	int		i;

	i = -1;
	temp = ft_split(path, ' ');
	if (!temp[1] || temp[2])
		error_msg("Error:\nimpossible de charger la couleur du sol !");
	temp2 = ft_split (temp[1], ',');
	if (!temp2[2] || temp2[3])
		error_msg("Error:\nimpossible de charger la couleur du sol !");
	cube->r_f = ft_atoi(temp2[0]);
	cube->g_f = ft_atoi(temp2[1]);
	cube->b_f = ft_atoi(temp2[2]);
	if (!check_color(cube->r_f, cube->g_f, cube->b_f))
		error_msg("Error:\nimpossible de charger la couleur du sol !");
	while (temp[++i])
		free(temp[i]);
	free (temp);
	i = -1;
	while (temp2[++i])
		free(temp2[i]);
	free (temp2);
	return (1);
}

void	parse_text_and_color(char *path, t_game *cube, t_game *game)
{
	if (path[0] == 'N' && path[1] == 'O')
		game->parse.flag_n += find_texture(path, 0, cube);
	else if (path[0] == 'S' && path[1] == 'O')
		game->parse.flag_s += find_texture(path, 1, cube);
	else if (path[0] == 'E' && path[1] == 'A')
		game->parse.flag_e += find_texture(path, 3, cube);
	else if (path[0] == 'W' && path[1] == 'E')
		game->parse.flag_w += find_texture(path, 2, cube);
	else if (path[0] == 'C')
		game->parse.flag_c += find_cell(path, cube);
	else if (path[0] == 'F')
		game->parse.flag_f += find_floor(path, cube);
	else if (parse_flag(game) && (!empty_line(path)))
		game->parse.read_map = 1;
	else if ((!empty_line(path)) && game->parse.read_map == 0)
		error_msg("Error:\nimpossible d'ouvir la map!");
}
