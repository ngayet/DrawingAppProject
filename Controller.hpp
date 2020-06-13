#ifndef __Controller_h__
#define __Controller_h__

#include "string"
#include "Element.hpp"
#include "Message.hpp"
#include "MyFrame.hpp"
#include "MyDrawingPanel.hpp"
#include "MyControlPanel.hpp"



class Controller : public Observer
{
private:
	// Control informations
	std::string m_id;
	std::string m_fill;
	std::string m_stroke;
	int m_strokeWidth;
	bool m_lock;
	int m_x;
	int m_y;
	DrawingType m_type;

	Element m_currentElement;
	std::vector<Element*> m_elements;

	// Panels
	MyControlPanel* m_controlPanel;
	MyDrawingPanel* m_drawingPanel;
	MyFrame* m_frame;

	bool isInTheLine(int x1, int y1, int x2, int y2, int p_x, int p_y);


public:
	Controller();
	void Update(Message* msg);
	MyFrame* GetFrame() { return m_frame; }
};

#endif