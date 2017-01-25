#include "SimApp.h"
#include "SimpleParticle.h"
#include "SplendidoParticle.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

long t = 0;
SimApp * win = NULL;

int handleTime(void *)
{
	t++;
	win->tick(t);
	return TRUE;
}

double SimApp::s_secPerTick = 0.1;
double SimApp::s_metersPerPixel = 1.0;

SimApp::SimApp(int argc, char *argv[], string title, int w, int h) 
	: m_playground(), m_window(), m_app()
{
	srand(time(NULL));

  	m_app = Gtk::Application::create(argc, argv,
      "SimPack");

 	m_window.set_default_size(w, h);
 	m_window.set_title(title.c_str());
 
	cout << "Sim Window Created" << endl;

	m_window.add(m_playground);

	for(int i(0); i < 100+50; i++)
	{
		int tx(0);
		int ty(0);
		tx = rand() % w;
		ty = rand() % h;

		m_playground.add(new SplendidoParticle(tx, ty, 10, 10, rand() % 10 - 20, rand() % 10 - 20, m_playground, false));
	}
		m_playground.add(new SplendidoParticle(rand() % w, rand() % h, 10, 10, rand() % (10 - 20) *2 , rand() % (10 - 20) *2, m_playground, true));	
	// units for x,y,w,h are in meters...

   	m_playground.show();
 	
 	win = this;
 	g_timeout_add(s_secPerTick*1000,handleTime,NULL);
 	
 	m_app->run(m_window);
}



