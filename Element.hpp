#ifndef __Element_h__
#define __Element_h__

#include <string>
#include "Node.hpp"

enum DrawingType {
	EMPTY,
	LINE,
	CIRCLE
};

class Element : public Node
{
private:
	std::string m_id;
	std::string m_fill;
	std::string m_stroke;
	int m_strokeWidth;
	bool m_lock;
	int m_x1;
	int m_y1;
	int m_x2;
	int m_y2;
	DrawingType m_type;

public:
	Element();
	Element(DrawingType type);
	Element(const Element& n);
	virtual ~Element();
	Element& operator=(const Element& n);

	void SetId(std::string id) { this->m_id = id; }
	void SetFill(std::string fill) { this->m_fill = fill; }
	void SetStroke(std::string stroke) { this->m_stroke = stroke; }
	void SetStrokeWidth(int strokeWidth) { this->m_strokeWidth = strokeWidth; }
	void SetLock(bool b) { this->m_lock = b; }

	std::string GetId() { return m_id; }
	std::string GetFill() { return m_fill; }
	std::string Getstroke() { return m_stroke; }
	int GetStrokeWidth() { return m_strokeWidth; }
	bool GetLock() { return m_lock; }

	void SetX1(int x) { m_x1 = x; }
	void SetY1(int y) { m_y1 = y; }
	void SetX2(int x) { m_x2 = x; }
	void SetY2(int y) { m_y2 = y; }
	void SetType(DrawingType type) { m_type = type; }

	int GetX1() { return m_x1; }
	int GetY1() { return m_y1; }
	int GetX2() { return m_x2; }
	int GetY2() { return m_y2; }
	DrawingType GetType() { return m_type; }


};



#endif