/*
** main.c for zappy in /home/oscar/rendu/PSU_2014_zappy/server
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Tue Apr 28 18:48:21 2015 Oscar Morizet
<<<<<<< HEAD
** Last update Sun Jun 21 14:05:38 2015 Oscar
=======
** Last update Sat Jun  6 11:21:07 2015 Oscar
>>>>>>> 3141335fa5c789223ce696fe9cbab98a99a514f8
*/

#include		<stdio.h>
#include		<time.h>
#include		<stdlib.h>
#include		"server.h"

void			pre_init(t_game *game_data)
{
  srand(time(NULL));
  game_data->standby_clients = NULL;
  game_data->players = NULL;
  game_data->cameras = NULL;
  game_data->teams = NULL;
}

int			main(int ac, char **av)
{
  t_game		game_data;
  t_server_info		server_info;

  pre_init(&game_data);
  if (!parse_parameters(--ac, ++av, &game_data, &server_info))
    return (-1);
  if (!check_args(&game_data, &server_info))
    return (-1);
  if (init(&game_data, &server_info) == -1)
    return (-1);
  if (run(&game_data, &server_info) == -1)
    return (-1);
  return (0);
}