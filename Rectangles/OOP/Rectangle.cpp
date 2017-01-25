#include "Rectangle.h"

Rectangle::Rectangle(char c, int x, int y, int w, int h) : m_ch(c), m_x(x), m_y(y), m_w(w), m_h(h)
{
}


int Rectangle::area() const
{
	return m_w*m_h;
}
	
int Rectangle::perimeter() const
{
	return ((m_w*2) + (m_h*2)) -4;
}
	
double Rectangle::contains(const Rectangle& other) const
{
/*	if(x2 > x1 && y2 > y1 && w2< w1 && h2 < h1)
		return true;

	else
		return false;*/
}

std::ostream& operator<<(std::ostream& os, const Rectangle& r)
{
	os << "\n---------------" << std::endl;

	for(int i(0); i < m_y; i++)
	{
		os << std::endl;
	}


	for(int k(0); k < m_h; k++)
	{
		for(int j(0); j < m_x; j++)
		{
			os << " " ;
		}

		for(int l(0); l < m_w; l++)
		{
			os << m_ch;
		}

		os << std::endl;
	}
	os << "\n---------------" << std::endl;

	return os;
}


