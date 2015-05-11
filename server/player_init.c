/*
** player_init.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 11 17:08:21 2015 Oscar Morizet
** Last update Mon May 11 17:22:13 2015 Oscar Morizet
*/

#include	<stdlib.h>
#include	"server.h"

void		gen_position(int *x, int *y)
{
  *x = 15;
  *y = 15;
}

void		init_client(t_player *player)
{
  int		x;
  int		y;

  gen_position(&x, &y);
  player->orientation = UP;
  player->x = x;
  player->y = y;
}