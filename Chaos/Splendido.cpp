#include "Splendido.h"
#include "SimApp.h"
#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <ctime>

using namespace std;

Splendido::Splendido(double x, double y, double w, double h, 
    double vX, double vY, bool fire, ParticlePlayground& playground)
      : ParticleBase(x, y, w, h), m_vX(vX), m_vY(vY), 
        m_win_w (0), m_win_h(0), m_fire(fire), m_playground(playground) 
{

}

void Splendido::draw(int win_height, int win_width, 
  const Cairo::RefPtr<Cairo::Context>& cr)
{
    m_win_w = win_width;
    m_win_h = win_height;

    double xpix = getX() / SimApp::getMetersPerPixel();
    double ypix = getY() / SimApp::getMetersPerPixel();
    double wpix = getW() / SimApp::getMetersPerPixel();
    double hpix = getH() / SimApp::getMetersPerPixel();

    cr->save();

    Glib::RefPtr<Gdk::Pixbuf> image;

    if(m_fire)
        image = Gdk::Pixbuf::create_from_file("flames.gif");

    else
        image = Gdk::Pixbuf::create_from_file("ice.png"); 
   

    Gdk::Cairo::set_source_pixbuf(cr, image, xpix, ypix); 


    cr->rectangle(xpix, ypix, image->get_width(), image->get_height()); 
    cr->fill(); 
    cr->stroke();

    cr->restore();
}

bool Splendido::getPower()
{
    return m_fire;
}

void Splendido::tick(long t)
{
	double deltaX = ((getVX() / SimApp::getMetersPerPixel()) * SimApp::getSecPerTick());
	double deltaY = ((getVY() / SimApp::getMetersPerPixel()) * SimApp::getSecPerTick());
	
    srand(time(NULL));

    int random = rand()%10;

    if(random == 0)
    {
        if(deltaX < 0)
            deltaX = deltaX - 1;
        else if(deltaX > 0)
            deltaX = deltaX + 1;
        if(deltaY < 0)
            deltaY = deltaY - 1;
        else if(deltaY > 0)
            deltaY = deltaY + 1;
    }

    setX(getX() + deltaX);
	setY(getY() + deltaY);

    if (m_win_w > 0 && m_win_h)
    {
        double xpix = getX() / SimApp::getMetersPerPixel();
        double ypix = getY() / SimApp::getMetersPerPixel();
        double wpix = getW() / SimApp::getMetersPerPixel();
        double hpix = getH() / SimApp::getMetersPerPixel();        

        if (xpix > m_win_w)
            xpix = wpix/2.0;
        else if (xpix < 0)
            xpix = m_win_w-(wpix/2.0);

        if (ypix > m_win_h)
            ypix = (hpix/2.0);
        else if (ypix < 0)
            ypix = m_win_h-(hpix/2.0);
        
        setX(xpix * SimApp::getMetersPerPixel());
        setY(ypix * SimApp::getMetersPerPixel());
    }
}


