#pragma once
#include "Element.hpp"

class Line : public Element
{
private:
	int m_x1;
	int m_y1;
	int m_x2;
	int m_y2;

public:
	Line();
	Line(const Line& n);
	virtual ~Line();//penser à l'enlever de parentNode
	Line& operator=(const Line& n);

	void SetX1(int x) { m_x1 = x; }
	void SetY1(int y) { m_y1 = y; }
	void SetX2(int x) { m_x2 = x; }
	void SetY2(int y) { m_y2 = y; }

	bool GetX1() { return m_x1; }
	bool GetY1() { return m_y1; }
	bool GetX2() { return m_x2; }
	bool GetY2() { return m_y2; }

};

