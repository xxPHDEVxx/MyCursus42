/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mario.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenaiss <rbenaiss@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:46:53 by rbenaiss          #+#    #+#             */
/*   Updated: 2023/03/11 17:47:56 by rbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mario.h"
#include <mlx.h>

/*
 * Initialize the game 
*/

void initialize(t_game *game) {
    if (game == NULL) {
        return;
    }
    game->map_x = 0;
    game->map_y = 0;
    game->map_area = 0;
    game->x = 0;
    game->y = 0;
    game->pixel = 0;
    game->player = 0;
    game->moove = 0;
    game->orientation = "./data/bas.xpm";
    game->points = 0;
    game->exit = 0;
}


int main(int argc, char **argv)
{
    t_game  game;

    check_arg(argc, argv);
    initialize(&game);
    map(argv, &game);
    window(&game);
    mlx_hook(game.window, 2, 0, keyboard, &game);
    mlx_hook(game.window, 17, 0, close, &game);
    mlx_loop(game.id);
    return  (0);
}