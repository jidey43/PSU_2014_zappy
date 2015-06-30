##
## Makefile for zappy in /home/voinne_c/rendu/PSU_2014_zappy
## 
## Made by Cédric Voinnet
## Login   <voinne_c@epitech.net>
## 
## Started on  Thu May 28 08:16:21 2015 Cédric Voinnet
## Last update Thu May 28 08:42:46 2015 Cédric Voinnet
##

SERVER	=	server/

GUI	=	gui/

CLIENT	=	client/

NAME_C	=	zappy_ai

NAME_G	=	zappy_gui

NAME_S	=	zappy_server

all:		$(NAME_C) $(NAME_S) $(NAME_G)

$(NAME_C):
	cd $(CLIENT) && $(MAKE)

$(NAME_G):
	cd $(GUI) && $(MAKE)

$(NAME_S):
	cd $(SERVER) && $(MAKE)

clean:
	cd $(CLIENT) && $(MAKE) $@
	cd $(SERVER) && $(MAKE) $@
	cd $(GUI) && $(MAKE) $@

fclean: clean
	cd $(CLIENT) && $(MAKE) $@
	cd $(SERVER) && $(MAKE) $@
	cd $(GUI) && $(MAKE) $@

re: fclean all

.PHONY: re all fclean clean
