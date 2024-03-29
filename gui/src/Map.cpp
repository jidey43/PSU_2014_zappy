# include "Map.hh"

Map::Map(std::pair<int, int> size) : _size(size), _hudLookAt(-1, -1), 
				     _gameOver(std::make_pair(false, ""))
{
}

void				Map::setHud(std::pair<int, int> pos)
{
  _hudLookAt = pos;
}

std::pair<int, int>	        Map::getHud()
{
  return (_hudLookAt);
}

Player*				Map::getPlayerSprite(size_t i)
{
  if (players.size() - 1 < i || players.size() == 0)
    return (NULL);  
  return (players[i]);
}

void				Map::deleteEgg(int egg)
{
  for (std::vector<Egg*>::iterator i = _eggs.begin(); i != _eggs.end();)
    {
      if ((*i)->getId() == egg)
	i = _eggs.erase(i);
      else
	i++;
    }
}

Egg*				Map::getEgg(size_t i)
{
  if (i > _eggs.size() - 1 || _eggs.size() == 0)
    return (NULL);
  return (_eggs[i]);  
}

Case*				Map::getCase(size_t i)
{
  if (i > _cases.size() - 1 || _cases.size() == 0)
    return (NULL);
  return (_cases[i]);
}

Case*				Map::getCaseFromPos(std::pair<int, int> pos)
{
  for (size_t i = 0; i != _cases.size(); i++)
    {
      if (_cases[i]->getPos() == pos)
	return (_cases[i]);
    }
  return (NULL);  
}

Player*				Map::getPlayerFromId(int id)
{
  for (size_t i = 0; i != players.size(); i++)
    {
      if (players[i]->getPid() == id)
	return (players[i]);
    }
  return (NULL);
}

Player*				Map::getPlayerFromPos(std::pair<int, int> pos)
{
  for (size_t i = 0; i != players.size(); i++)
    {
      if (players[i]->getPos() == pos)
	return (players[i]);
    }
  return (NULL);
}

void				Map::startBroadcast(int pid, std::string)
{
  for (std::vector<Player*>::iterator i = players.begin(); i != players.end(); i++)
    {
      if ((*i)->getPid() == pid)
	(*i)->startBroadcast();
    }
  
}

void				Map::movePlayer(int pid, std::pair<int ,int> pos, 
						     t_orientation orientation)
{
  Player			*tmpPlayer = this->getPlayerFromId(pid);

  if (pos.first > _size.first - 1 || pos.second > _size.second - 1)
    return ;
  if (tmpPlayer == NULL)
    return ;
  tmpPlayer->setPos(pos);
  tmpPlayer->setOrientation(orientation);
}

void				Map::updatePlayers()
{
  for (size_t i = 0; i != players.size(); i++)
    {
      players[i]->update();
    }
}

void				Map::updateCases()
{
  for (size_t i = 0; i != _cases.size(); i++)
    {
      _cases[i]->update();
    }
}

void				Map::updateInventory(int pid, 
						     std::map<t_ressource, int> newInv)
{
  Player			*tmpPlayer = this->getPlayerFromId(pid);

  if (tmpPlayer == NULL)
    return ;
  tmpPlayer->updateInventory(newInv);
}

void				Map::pexPlayer(int pid, int level)
{
  Player			*tmpPlayer = this->getPlayerFromId(pid);

  if (tmpPlayer == NULL)
    return ;
  tmpPlayer->setLevel(level);
}


void				Map::deletePlayer(int pid)
{
  for (std::vector<Player*>::iterator i = players.begin(); i != players.end();)
    {
      if ((*i)->getPid() == pid)
	i = players.erase(i);
      else
	i++;
    }
}

void				Map::addPlayer(int pid, std::pair<int, int> pos,
						    t_orientation orientation, int level,
						    std::string teamName)
{
  Player			*bob = new Player(pid, pos, orientation, level, teamName);
 
  if (pos.first > _size.first - 1 || pos.second > _size.second - 1)
    return ;
  this->players.push_back(bob);  
}

void				Map::addEgg(int eggId, int pid, std::pair<int, int> pos)
{
  if (pos.first > _size.first - 1 || pos.second > _size.second - 1)
    return ;
  _eggs.push_back(new Egg(eggId, pid, pos));
}

std::pair<int, int>		Map::getSize()
{
  return (_size);
}

void				Map::resizeMap(std::pair<int ,int> newSize)
{
  _size = newSize;
}

void			        Map::updateCase(std::pair<int, int> pos,
						std::map<t_ressource, int> res)
{
  for(size_t i = 0; i != _cases.size(); i++)
    {
      if (pos == _cases[i]->getPos())
      	{
	  for (size_t j = 0; j != 7; j++)
	    {
	      if (res[(t_ressource)j] != 0)
		break;
	      if (j == 6)
		{	
		  _cases.erase(_cases.begin() + i);
		  return ;
		}	
	    }
	  _cases[i]->setRessources(res);
	  return ;
      	}
    }
  _cases.push_back(new Case(pos));
  _cases.back()->setRessources(res);
}

std::pair<bool, std::string>	Map::getGameOver()
{
  return (_gameOver);
}

void				Map::gameOver(std::string winTeam)
{
  _gameOver = std::make_pair(true, winTeam);
}

t_incant		        Map::getCaseStatus(std::pair<int, int> pos)
{
  for (size_t i = 0; i != _cases.size(); i++)
    {
      if (_cases[i]->getPos() == pos)
	{
	  return _cases[i]->getStatus();
	}
    }
  return (NO);
}

void				Map::startIncant(std::pair<int, int> pos, int)
{
  for (size_t i = 0; i != _cases.size(); i++)
    {
      if (_cases[i]->getPos() == pos)
	{
	  _cases[i]->startIncant();
	  return ;
	}
    }
  _cases.push_back(new Case(pos));
  _cases.back()->startIncant();
}

void			        Map::resultIncant(std::pair<int, int> pos, bool isFail)
{
  for (size_t i = 0; i != _cases.size(); i++)
    {
      if (_cases[i]->getPos() == pos)
	{
	  _cases[i]->resultIncant(isFail);
	  return ;
	}
    }
  _cases.push_back(new Case(pos));
  _cases.back()->resultIncant(isFail);
}

