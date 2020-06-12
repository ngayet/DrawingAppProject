#include "Element.hpp"

Element::Element()
{
	m_id = "";
	m_fill = "";
	m_stroke = "";
	m_strokeWidth = "";
	m_lock = false;
	m_x1 = 0;
	m_y1 = 0;
	m_x2 = 0;
	m_y2 = 0;
	m_type = EMPTY;
}

Element::Element(DrawingType type)
{
	m_id = "";
	m_fill = "";
	m_stroke = "";
	m_strokeWidth = "";
	m_lock = false;
	m_x1 = 0;
	m_y1 = 0;
	m_x2 = 0;
	m_y2 = 0;
	m_type = type;
}

Element::~Element()
{

}

Element::Element(const Element& e)
{
	m_id = e.m_id;
	m_fill = e.m_fill;
	m_stroke = e.m_stroke;
	m_strokeWidth = e.m_strokeWidth;
	m_lock = e.m_lock;
}

Element& Element::operator=(const Element& e)
{
	Node::operator=(e);
	m_id = e.m_id;
	m_fill = e.m_fill;
	m_stroke = e.m_stroke;
	m_strokeWidth = e.m_strokeWidth;
	m_lock = e.m_lock;

	return *this;
}