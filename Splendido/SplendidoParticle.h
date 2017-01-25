#ifndef SPLENDIDO_PARTICLE_H
#define SPLENDIDO_PARTICLE_H

#include "ParticleBase.h"
#include <gtkmm/drawingarea.h>
#include "ParticlePlayground.h"

class SplendidoParticle : public ParticleBase
{
public:
    SplendidoParticle(double x, double y, double w, double h, 
        double vX, double vY, ParticlePlayground& playground, bool r)
          : ParticleBase(x, y, w, h), m_vX(vX), m_vY(vY), m_playground(playground), rogue(r), happy(true) { };
    virtual void draw(int win_height, int win_width, 
  		const Cairo::RefPtr<Cairo::Context>& cr);
    virtual ~SplendidoParticle() {};
    virtual void tick(long t);

   	double getVX() { return m_vX; }
   	double getVY() { return m_vY; }
   	void setVX(double vx) { m_vX = vx; }
   	void setVY(double vy) { m_vY = vy; }
    void reverse();
    void beam(double dX, double dY);
    void toggleColor();


private:
	double m_vX;
	double m_vY;
  int m_win_width;
  int m_win_height;
  ParticlePlayground& m_playground;
  bool rogue; 
  bool happy;
};

#endif