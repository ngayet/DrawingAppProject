#ifndef __Controller_h__
#define __Controller_h__

#include "main.hpp"
#include "string"
#include "Element.hpp"

#include "Message.hpp"

class Controller : public Observer
{
private:
	std::string m_id;
	std::string m_fill;
	std::string m_stroke;
	int m_strokeWidth;
	bool m_lock;
	int m_x;
	int m_y;
	DrawingType m_type;
	MyControlPanel* m_controlPanel;
	MyDrawingPanel* m_drawingPanel;

public:
	Controller();
	Controller(MyFrame* mainFrame);
	virtual void Update(Message msg);
};

#endif