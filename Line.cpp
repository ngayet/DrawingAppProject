#include "Line.hpp"

Line::Line()
{
	m_x1 = m_y1 = m_x2 = m_y2 = 0;
}

Line::~Line()
{

}

Line::Line(const Line& c)
{
	m_x1 = c.m_x1;
	m_y1 = c.m_y1;
	m_x2 = c.m_x2;
	m_y2 = c.m_y2;
}

Line& Line::operator=(const Line& c)
{
	Element::operator=(c);
	m_x1 = c.m_x1;
	m_y1 = c.m_y1;
	m_x2 = c.m_x2;
	m_y2 = c.m_y2;

	return *this;
}