
#ifndef GRAPHICS_HH_
# define GRAPHICS_HH_

# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>
# include <utility>
# include <vector>
# include <map>
# include <iostream>
# include <sstream>
# include "Event.hh"
# include "Player.hh"
# include "Map.hh"
# include "Definition.hh"

class							Graphics;

typedef	void						(Graphics::*printRsPtr)
(std::pair<int, int>);

class							Graphics
{
private:
  sf::Image						_grassImage;
  sf::Image						_grassIncant;
  sf::Image						_grassIncantFailed;
  sf::Image						_grassIncantPassed;  
  sf::Image						_backgroundImage;
  sf::Image						_hightlightGrassImage;
  sf::Image						_scrollImage;
  sf::Image						_bullImage;
  sf::Image						_gameOverImage;
  sf::Image						_starImage;
  std::map<t_ressource, sf::Image>			_ressourcesImage;
  sf::Font						_font;
  sf::Music						_music;

private:
  sf::RenderWindow					*app;
  sf::View						_view;
  std::map<t_ressource, sf::Vector2f>			_ressourcesPadding;
  std::map<t_eventName, sf::Vector2f>			_bindMove;
  float							_zoomCoeff;
  sf::Vector2f						_offsetCoeff;
  int							_playerHightLightId;

private:
  void							printBackground();
  void							cleanMap(Map *map);
  void							printRessources(Map *map);
  void							printEggs(Map *map);
  void							printPlayers(Map *map);
  void							printBull(std::pair<int, int> pos);
  void							printThisRessourceAtPos
  (t_ressource, std::pair<int, int>);
  
public:
  Graphics(std::pair<int, int>);
  ~Graphics();

  void							handleEvent(std::vector<Event> &);
  void							refreshScreen(Map *map);

public:
  Player*						getPlayerHightlight(std::pair<int, int>
									    , Map *map);
  void							nothingToHud();
  void							highlightCase(std::pair<int, int>);
  void							printHud(Map *map);
  void							printPlayerOnHud(Player *player);
  void							printCaseOnHud(Case *currentCase);
  void							printGameOver(std::string);

public:
  void							moveView(t_eventName key);
};

#endif
