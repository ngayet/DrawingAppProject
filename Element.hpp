#pragma once
#include <string>
#include "Node.hpp";

class Element : public Node
{
private:
	std::string m_id;
	std::string m_fill;
	std::string m_stroke;
	std::string m_strokeWidth;
	bool m_lock;

public:
	Element();
	Element(const Element& n);
	virtual ~Element();//penser à l'enlever de parentNode
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
};

