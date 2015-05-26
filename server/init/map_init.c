/*
** map_init.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Tue May 26 14:46:28 2015 Oscar Morizet
** Last update Tue May 26 15:22:23 2015 Oscar Morizet
*/

#include	<stdlib.h>
#include	"server.h"
#include	"map.h"

int		init_map_case(t_map_case ***map, int x, int y)
{
  t_map_case	*new_case;

  if ((new_case = malloc(sizeof(t_map_case))) == NULL)
    return (-1);
  new_case->obj = LINEMATE;
  new_case->next = NULL;
  map[y][x] = new_case;
  return (0);
}

int		init_map(t_game *game)
{
  int		x;
  int		y;
  size_t	xsize;

  y = 0;
  if ((game->map = malloc(sizeof(t_map_case *) * game->map_size_y)) == NULL)
    return (-1);
  xsize = sizeof(t_map_case) * game->map_size_x;
  while (y != game->map_size_y)
    {
      x = 0;
      if ((game->map[y] = malloc(xsize)) == NULL)
	return (-1);
      while (x != game->map_size_x)
	{
	  game->map[y][x] = NULL;
	  ++x;
	}
      ++y;
    }
  map_spawn_items(game);
  dump_map(game);
  return (0);
}