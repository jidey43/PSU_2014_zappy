//
// Camera.cpp for zappy in /home/roman/Documents/dev/PSU_2014_zappy/gui/src
// 
// Made by grout_r
// Login   <roman@epitech.net>
// 
// Started on  Tue Apr 28 15:30:33 2015 grout_r
// Last update Wed May  6 10:26:23 2015 grout_r
//

#include "Camera.hh"

Camera::Camera()
{
  this->graph = new Graphics();
  this->net = new Network();
}

Camera::~Camera()
{
}

void				Camera::start()
{
  // int i = 0;

  this->graph->addPlayer(1, std::make_pair(5, 5), SOUTH, 0, "Les patates en folies");
  if (this->net->initNetwork() == false)
    exit(-1);
  while (true)
    {
      this->graph->refreshScreen();
      this->graph->handleEvent();
      this->net->handleEvent(this->graph);
      //sleep(1);
    }
}
