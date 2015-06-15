/*
** server.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Fri Jun  5 17:39:08 2015 Oscar
** Last update Sat Jun  6 11:30:14 2015 Oscar
*/

#include		<sys/select.h>
#include		<sys/time.h>
#include		<stdio.h>
#include		<unistd.h>
#include		"server.h"
#include		"timer.h"

int			make_cycle(t_game *game, t_server_info *server)
{
  t_player		*tmp;

  tmp = game->players;
  if (tmp == NULL)
    return (0);
  while (tmp != NULL)
    {
      if (player_process_cycle(game, tmp) == -1)
	return (-1);
      tmp = tmp->next;
    }
  return (0);
}

int			cyclify(int cycle_nb, t_game *game, t_server_info *server)
{
  int			i;

  i = 0;
  usleep(5000);
  while (i != cycle_nb)
    {
      if (make_cycle(game, server) == -1)
	return (-1);
      ++i;
    }
  return (0);
}

int		        run(t_game *game_data, t_server_info *server)
{
  struct timeval	cycle_start;
  struct timeval	cycle_finish;
  
  gettimeofday(&cycle_start, NULL);
  while (42)
    {
      gettimeofday(&cycle_finish, NULL);
      update_timer(game_data, server, &cycle_start, &cycle_finish);
      reset_sets(server, game_data);
      if (select(server->fd_max + 1,
		 server->fd_reads, NULL, NULL, server->cycle_end) == -1)
	{
	  perror("Select error: ");
	  return (-1);
	}
      gettimeofday(&cycle_start, NULL);
      if (server->cycle_end->tv_usec == 0)
	{
	  if (cyclify(1, game_data, server) == -1)
	    return (-1);
	}
      //else if (handle_server_interactions(server, game_data) == -1)
      //return (-1);
    }
  return (0);
}