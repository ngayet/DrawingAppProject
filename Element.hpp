#pragma once
#include <string>
#include "Node.hpp"

class Element : public Node
{
private:
	std::string m_id;
	std::string m_fill;
	std::string m_stroke;
	std::string m_strokeWidth;
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
	void SetStrokeWidth(std::string strokeWidth) { this->m_strokeWidth = strokeWidth; }
	void SetLock(bool b) { this->m_lock = b; }

	std::string GetId() { return m_id; }
	std::string GetFill() { return m_fill; }
	std::string Getstroke() { return m_stroke; }
	std::string GetStrokeWidth() { return m_strokeWidth; }
	bool GetLock() { return m_lock; }

	void SetX1(int x) { m_x1 = x; }
	void SetY1(int y) { m_y1 = y; }
	void SetX2(int x) { m_x2 = x; }
	void SetY2(int y) { m_y2 = y; }

	bool GetX1() { return m_x1; }
	bool GetY1() { return m_y1; }
	bool GetX2() { return m_x2; }
	bool GetY2() { return m_y2; }
	DrawingType GetType() { return m_type; }


};

enum DrawingType {
	EMPTY,
	LINE,
	CIRCLE
};