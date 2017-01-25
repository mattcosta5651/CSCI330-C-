#include "ParticlePlayground.h"
#include <cairomm/context.h>
#include <iostream>
#include <cmath>

using namespace std;

ParticlePlayground::ParticlePlayground()
  : m_particles(), m_destroyed()
{ }

ParticlePlayground::~ParticlePlayground()
{
    for (vector<ParticleBase*>::const_iterator it = m_particles.begin(); 
        it!=m_particles.end(); it++) 
    {
        delete (*it);
    }    
}

void ParticlePlayground::add(ParticleBase* p)
{
    m_particles.push_back(p);
}

bool ParticlePlayground::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
    cr->save();

    Gtk::Allocation allocation = get_allocation();
    const int win_width = allocation.get_width();
    const int win_height = allocation.get_height();
    
    for (vector<ParticleBase*>::const_iterator it = m_particles.begin(); 
        it!=m_particles.end(); it++) 
    {
        (*it)->draw(win_height, win_width, cr);
    }

    cr->restore();

    return true;
}


void ParticlePlayground::tick(long t)
{
    m_destroyed.clear();
   
    for (auto it = m_particles.begin(); 
        it!=m_particles.end(); it++) 
    {
        for(auto it2 = m_particles.begin(); 
            it2 != m_particles.end(); it2++)
        {
            if((abs((*it2)->getX()-(*it)->getX())<=(*it2)->getW() && abs((*it2)->getY()-(*it)->getY())<=(*it2)->getH()) && (*it)!=(*it2))
            {
                if((*it)->getPower() && (*it2)->getPower())
                {
                    m_destroyed.push_back(*it);
                    m_destroyed.push_back(*it2); 
                }

                else if((*it)->getPower() && !(*it2)->getPower())
                    m_destroyed.push_back(*it2);

                else if(!(*it)->getPower() && (*it2)->getPower())
                    m_destroyed.push_back(*it);
            }
        }

    } 

    if(m_destroyed.size() > 0)
    {
        for(auto itDestroyed = m_destroyed.begin(); 
            itDestroyed != m_destroyed.end(); itDestroyed++)
        {
            auto x = find(m_particles.begin(), m_particles.end(), *itDestroyed);

            if(x!=m_particles.end())
                m_particles.erase(x);
        }
    }

    for(auto itFinal = m_particles.begin(); itFinal!=m_particles.end(); itFinal++)
        (*itFinal)->tick(t);

    queue_draw();
}