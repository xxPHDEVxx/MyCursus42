/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenaiss <rbenaiss@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 05:05:40 by rbenaiss          #+#    #+#             */
/*   Updated: 2023/03/11 17:55:09 by rbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mario.h"
#include "../printf/includes/ft_printf.h"
#include "../libft/libft.h"

void   close_window(t_game *game)
{
    mlx_destroy_window(game->id, game->window);
    exit(1);
}

void fill_background(t_game *game)
{
    game->y = 0;
    while (game->y < game->map_y) {
        game->x = 0;
        while (game->x < game->map_x) {
            game->file = mlx_xpm_file_to_image(game->id,
                         "./images/surface.xpm", &game->pixel, &game->pixel);
            mlx_put_image_to_window(game->id, game->window,
                                    game->file, game->pixel * game->x,
                                    game->pixel * game->y);
            game->x++;
        }
        game->y++;
    }
}

void put_image_to_window(t_game *game, char *path)
{
    game->file = mlx_xpm_file_to_image(game->id, path, &game->pixel, &game->pixel);
    if (!game->file) {
        ft_printf("Error\nImpossible de lire l'image.\n");
        exit(1);
    }
    mlx_put_image_to_window(game->id, game->window, game->file, game->pixel * game->x, game->pixel * game->y);
}

void put_limits(t_game *game)
{
    put_image_to_window(game, "./images/arbre.xpm");
}

void put_floor(t_game *game)
{
    put_image_to_window(game, "./images/surface.xpm");
}

void put_points(t_game *game)
{
    put_image_to_window(game, "./images/point.xpm");
    game->points++;
}

void put_player(t_game *game)
{
    put_image_to_window(game, game->orientation);
    game->player_y = game->y;
    game->player_x = game->x;
}

void put_exit(t_game *game)
{
    char *path;
    if (game->points == 0)
        path = "./images/sortie.xpm";
    else
        path = "./images/bloque.xpm";

    put_image_to_window(game, path);
}



/*
 * Return the maximum score you can do in this map.
*/

int score_max(t_game *game) {
    int points = 0;
    int y = 0;
    int x = 0;
    
    while (y < game->map_y) {
        x = 0;
        while (x < game->map_x) {
            if (game->map[y][x] == 'C') {
                points++;
            }
            x++;
        }
        y++;
    }
    
    return points;
}

void    fill(t_game *game)
{
    game->points = score_max(game);
    fill_background(game);
    game->y = 0;
    while ((game->y) < (game->map_y))
    {
        game->x = 0;
        while ((game->x) < (game->map_x))
        {
            if (game->map[game->y][game->x] == '1')
				put_limits(game);
			if (game->map[game->y][game->x] == 'C')
				put_points(game);
			if (game->map[game->y][game->x] == 'P')
				put_player(game);
			if (game->map[game->y][game->x] == 'E')
				put_exit(game);
			game->x++;
        }
        game->y++;
    }
    ft_printf("Moove : %d\n", game->moove);
}