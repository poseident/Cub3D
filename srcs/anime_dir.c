/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anime_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschweit <bschweit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:31:56 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/14 12:53:02 by bschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	anim_direction(t_game *legend, int key)
{
	(void) key;
	mlx_destroy_image(legend->mlx_ptr, legend->img.mlx_img);
	legend->img.mlx_img = mlx_new_image(legend->mlx_ptr, 162, 159);
	mlx_put_image_to_window(legend->mlx_ptr, legend->win_ptr, \
		legend->img.mlx_img, CUBE_X + 64, 403);
	mlx_do_sync(legend->mlx_ptr);
}
