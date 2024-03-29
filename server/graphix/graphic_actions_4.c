/*
** graphic_actions_4.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server/graphix
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Mon Jun 22 08:04:03 2015 Oscar
** Last update Tue Jun 23 15:10:25 2015 Oscar
*/

#include	<stdlib.h>
#include	<strings.h>
#include	<string.h>
#include	<unistd.h>
#include	"server.h"

int		gfx_pdi(t_game *data,
			t_graphix *client, int fd)
{
  char		end[56];

  (void) data;
  bzero(end, 56);
  sprintf(end, "pdi %d\n", fd);
  write(client->fd, end, strlen(end));
  return (0);
}

int		gfx_enw(t_game *data,
			t_graphix *client, t_egg *egg)
{
  char		end[56];

  (void) data;
  bzero(end, 56);
  sprintf(end, "enw %d %d %d %d\n",
	  egg->id, egg->owner, egg->x, egg->y);
  write(client->fd, end, strlen(end));
  return (0);
}

int		gfx_eht(t_game *data,
			t_graphix *client, int egg_id)
{
  char		end[56];

  (void) data;
  bzero(end, 56);
  sprintf(end, "eht %d\n", egg_id);
  write(client->fd, end, strlen(end));
  return (0);
}

int		gfx_ebo(t_game *data,
			t_graphix *client, int egg_id)
{
  char		end[56];

  (void) data;
  bzero(end, 56);
  sprintf(end, "ebo %d\n", egg_id);
  write(client->fd, end, strlen(end));
  return (0);
}
