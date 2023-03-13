/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenaiss <rbenaiss@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:34:53 by rbenaiss          #+#    #+#             */
/*   Updated: 2023/03/11 17:50:17 by rbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mario.h"
#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"

/*
 * Do as ft_strjoin but with a string and a char
 * and it free line at the end.
*/

char	*ft_join(char *line, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (line[i])
		i++;
	str = malloc(i + 2);
	i = 0;
	while (line[i])
	{
		str[i] = line[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(line);
	return (str);
}

/*
 * Checks whether a character string contains a complete line 
 * by searching for (\n) or (\0). 
 * If the line is complete, the function returns 1
 * The function also ensures that
*/

int     check_line(char *line)
{
    int i;

    if (!line)
        return (0);
    i = 0;
    while (line[i])
    {
        if (line[i] == '\0')
            return (1);
        i++;
    }
    return (0);
}


/*
 * Check if the map have : player, point, line and exit
 * by checking the map's characters.
*/

void    check_char(char *buf, t_game *game)
{
    int i;

    i = 0;
    while (buf[i])
    {
        if (buf[i] == 'P')
			game->player++;
		else if (buf[i] == 'C')
			game->points++;
		else if (buf[i] == 'E')
			game->exit++;
		else if (buf[i] == '\n')
			game->map_y++;
		else if (buf[i] != '0' && buf[i] != '1')
				game->char_invalid++;
		i++; 
    }
    if (game->player != 1 || game->points < 1 || game->exit != 1)
    {
        ft_printf("error about map's characters\n");
        exit(1);
    }
}
//recheck
void	good_way(int y, int x, t_game *game)
{
	if (game->map[y][x] == 'E')
		game->exit_way++;
	if (y < 0 || y > game->map_y || x < 0 || x > game->map_x
		|| game->map[y][x] == '1' || game->map[y][x] == 'E')
		return ;
	if (game->map[y][x] == 'C')
		game->point_way++;
	game->map[y][x] = '1';
	good_way(y, (x - 1), game);
	good_way(y, (x + 1), game);
	good_way((y - 1), x, game);
	good_way((y + 1), x, game);
	return ;
}
// recheck
void	check_way(t_game *game)
{
	game->y = 0;
	while ((game->y) < (game->map_y))
	{
	game->x = 0;
		while ((game->x) < (game->map_x))
		{
			if (game->map[game->y][game->x] == 'P')
			{
				good_way(game->y, game->x, game);
				if (game->points == game->point_way && game->exit_way)
				{
					game->x = 0;
					game->y = 0;
					return ;
				}
				else
				{
					ft_printf("error : no valid way");
					exit(1);
				}
			}
			game->x++;
		}
		game->y++;
	}
}
/*
 * separates the string of characters str
 * into words separated by the character c,
 * counts the number of words
 * and stores each word in an array of pointers ptr.
*/
void	split_plus(char *str, char **ptr, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	free(str);
	free_2D(ptr, count);
}

void	free_2D(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
}

void check_map(char *buf, t_game *game)
{
    int x;

    x = ft_strlen(buf);
    if (game->char_invalid)
    {
        ft_printf("error : invalid character");
        exit(1);
    }    
    game->map_area = x - game->map_y;
    if (buf[--x] != '\n')
        game->map_y++;
    if (game->map_area != game->map_x * game->map_y)
    {
        ft_printf("error : wrong map");
        exit(1);
    }
    check_limits(game);
}

/*
 * Checks the map's limits.
 * If there is no wall ('1') at the sides of the map
 * then it display an error's message.
*/
void check_limits(t_game *game) {
    check_sides_limits(game);
    check_upDown_limits(game);
}


void check_sides_limits(t_game *game)
{
    int y = 0;
    int x_left = 0;
    int x_right = game->map_x - 1;

    while (y < game->map_y)
    {
        if (game->map[y][x_left] != '1' || game->map[y][x_right] != '1')
		{
            ft_printf("error : limits\n");
			exit(1);
		}
        y++;
    }
}

void check_upDown_limits(t_game *game) {
    int x = 0;

    while (x < game->map_x && game->map[0][x] == '1') {
        x++;
    }
    if (x < game->map_x) 
	{
        ft_printf("error : limits\n");
		exit(1);
	}

    x = 0;
    while (x < game->map_x && game->map[game->map_y-1][x] == '1') {
        x++;
    }
    if (x < game->map_x)
	{
            ft_printf("error : limits\n");
			exit(1);
	}
}



/*
 * reads a file and returns its contents.
 * It allocates memory dynamically and 
 * reads the file line by line and checks for complete lines
 * using the check_line() function. 
 * If the end of the file is reached before 
 * a complete line is found
 * returns the last incomplete line.
*/
char    *get_map(int fd)
{
    char    buf;
    char    *line;
    int             rd_bytes;

    rd_bytes = 1;
    if (fd < 0)
        line = NULL;
    line = malloc(1);
    line[0] = '\0';
    while (!check_line(line) && rd_bytes > 0)
    {
        rd_bytes = read(fd, &buf, 1);
        if (rd_bytes == 0 && line[0] == '\0' || rd_bytes < 0)
        {
            free(line);
            ft_printf("empty map\n");
            exit(1);
        }
        if (rd_bytes == 0 && line[0] != '\0')
            return (line);
        line = ft_join(line, buf);
    }
    return (line);
}