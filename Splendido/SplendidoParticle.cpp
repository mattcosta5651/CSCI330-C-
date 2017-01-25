#include "SplendidoParticle.h"
#include "SimApp.h"
#include <iostream>
#include <cmath>

using namespace std;

void SplendidoParticle::draw(int win_height, int win_width, 
  const Cairo::RefPtr<Cairo::Context>& cr)
{
  m_win_width = win_width;
  m_win_height = win_height;

  double xpix = getX() / SimApp::getMetersPerPixel();
  double ypix = getY() / SimApp::getMetersPerPixel();
  double wpix = getW() / SimApp::getMetersPerPixel();
  double hpix = getH() / SimApp::getMetersPerPixel();

  cr->save();

  cr->set_line_width(1.0);

  if(happy)
    cr->set_source_rgba(0.0, 0.0, 0.8, 0.6);
  else if(!happy)
    cr->set_source_rgba(0.8, 0.0, 0.0, 0.6);
  if(rogue)
    cr->set_source_rgba(0.0, 0.8, 0.0, 0.6);


  cr->arc(xpix, ypix, wpix / 2.0, 0.0, 2.0 * M_PI);
  cr->fill_preserve();
  cr->stroke();
}

void SplendidoParticle::tick(long t)
{
	double deltaX = ((getVX() / SimApp::getMetersPerPixel()) * SimApp::getSecPerTick());
	double deltaY = ((getVY() / SimApp::getMetersPerPixel()) * SimApp::getSecPerTick());


  if(getX()+deltaX >= m_win_width)
    beam(deltaX, deltaY);
  else if(getX()+deltaX <= 0)
    beam(deltaX, deltaY);
  else if(getY()+deltaY >= m_win_height)
    beam(deltaX, deltaY); 
  else if(getY()+deltaY<=0)
    beam(deltaX, deltaY);
  else
  {
    if(!rogue)
      reverse();
   

	  setX(getX() + deltaX);
	  setY(getY() + deltaY);
  }
}

void SplendidoParticle::reverse()
{
  happy = true;
  for(int i(0); i < m_playground.getParticles().size(); i++)
  {
    ParticleBase *p = m_playground.getParticles()[i];

    if(p != this)
    {
      if(sqrt(pow(p->getX()-getX(),2) + pow(p->getY()-getY(),2)) <=50)
      {
          if(p->getX() > getX())
          {
            if(getVX() > 0)
              setVX(-1 * getVX());
          }
          else if(p->getX() < getX())
          {
            if(getVX() < 0)
              setVX(-1 * getVX());
          }
    
          if(p->getY() > getY())
          {
            if(getVY() > 0)
              setVY(-1 * getVY());
          }
          else if(p->getY() < getY())
          {
            if(getVY() < 0)
              setVY(-1 * getVY());
          }
          happy = false;
        
      }
    //  else
      //  happy = true;
    }
  }
}

void SplendidoParticle::beam(double dX, double dY)
{
  if(dX+getX() >= m_win_width)
    setX(0 + dX);
  if(dX+getX() <= 0)
    setX(m_win_width + dX);
  if(dY+getY() >= m_win_height)
    setY(0 + dY);
  if(dY+getY() <= 0)
    setY(m_win_height+dY);
}

