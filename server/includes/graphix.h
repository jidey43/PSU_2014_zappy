/*
** graphiX.h for Zappy in /home/oscar/Projets/PSU_2014_zappy/server/includes
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Sun Jun 21 12:36:27 2015 Oscar
** Last update Sun Jun 21 13:43:56 2015 Oscar
*/

#ifndef			GRAPHIX_H_
# define		GRAPHIX_H_

# define		GRAPHIX_INTRODUCTION	"GRAPHIC"

typedef struct		s_graphix
{
  int			fd;
  struct s_graphix	*next;
}			t_graphix;
  
#endif			/* !GRAPHIX_H_ */
