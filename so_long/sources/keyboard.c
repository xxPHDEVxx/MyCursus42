/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenaiss <rbenaiss@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:29:01 by rbenaiss          #+#    #+#             */
/*   Updated: 2023/03/11 17:53:31 by rbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mario.h"
#include "../printf/include/ft_printf.h"

void	haut(t_game *game)
{
	game->map[game->player_y][game->player_x] = '0';
	game->map[game->player_y - 1][game->player_x] = 'P';
	game->moove++;
	fill(game);
}

void	bas(t_game *game)
{
	game->map[game->player_y][game->player_x] = '0';
	game->map[game->player_y + 1][game->player_x] = 'P';
	game->moove++;
	fill(game);
}

void	gauche(t_game *game)
{
	game->map[game->player_y][game->player_x] = '0';
	game->map[game->player_y][game->player_x - 1] = 'P';
	game->moove++;
	fill(game);
}

void	droite(t_game *game)
{
	game->map[game->player_y][game->player_x] = '0';
	game->map[game->player_y][game->player_x + 1] = 'P';
	if (game)
	game->moove++;
	fill(game);
}

int	keyboard(int keyhook, t_game *game)
{
	if (keyhook == 53)
		close(game);
	if (game->points == 0
		&& ((keyhook == 2 && game->map[game->player_y][game->player_x + 1] == 'E')
		|| (keyhook == 1 && game->map[game->player_y + 1][game->player_x] == 'E')
		|| (keyhook == 0 && game->map[game->player_y][game->player_x - 1] == 'E')
		|| (keyhook == 13 && game->map[game->player_y - 1][game->player_x] == 'E')))
	{
		ft_printf("WINNER\n");
		close(game);
	}
	if (keyhook == 13 && game->map[game->player_y - 1][game->player_x] != '1'
		&& game->map[game->player_y - 1][game->player_x] != 'E')
		haut(game);
	if (keyhook == 0 && game->map[game->player_y][game->player_x - 1] != '1'
		&& game->map[game->player_y][game->player_x - 1] != 'E')
		gauche(game);
	if (keyhook == 1 && game->map[game->player_y + 1][game->player_x] != '1'
		&& game->map[game->player_y + 1][game->player_x] != 'E')
		bas(game);
	if (keyhook == 2 && game->map[game->player_y][game->player_x + 1] != '1'
		&& game->map[game->player_y][game->player_x + 1] != 'E')
		droite(game);
	return (0);
}