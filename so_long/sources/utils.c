/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenaiss <rbenaiss@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:09:08 by rbenaiss          #+#    #+#             */
/*   Updated: 2023/03/11 17:50:54 by rbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mario.h"
#include "../printf/includes/ft_printf.h"
#include "../libft/libft.h"

void	check_arg(int argc, char **argv)
{
	size_t	len;

	if (argc != 2)
	{
		ft_printf("Error\n");
		exit(0);
	}
	len = ft_strlen(argv[1]);
	if (!(argv[1][len - 4] == '.' && argv[1][len - 3] == 'b' && \
		argv[1][len - 2] == 'e' && argv[1][len - 1] == 'r'))
	{
		ft_printf("Error\n wrong extension's file");
		exit (1);
	}
}

void	map(char **argv, t_game *game)
{
	int		fd;
	char	**map_x;
	char	*buf;

	fd = open(argv[1], 0_RDONLY);
	if (fd == -1)
	{
		ft_printf("file error\n");
		exit(1);
	}
	buf = get_map(fd);
	check_char(buf, game);
	game->map = ft_split(buf, '\n');
	map_x = game->map;
	while (game->map[0][game->map_x] != '\0')
		game->map_x++;
	check_map(buf, game);
	check_way(game);
	game->map = ft_split(buf,'\n');
	split_plus(buf, map_x, '\n');
	close(fd);
}

void	window(t_game *game)
{
	game->pixel = 50;
	game->id = mlx_init();
	game->window = mlx_new_window(game->id,
	(game->pixel * game->map_x),
	(game->pixel * game->map_y), "MARIO 42");
	fill(game);
}

