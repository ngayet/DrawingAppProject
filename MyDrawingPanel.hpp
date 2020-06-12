#ifndef __MyDrawingPanel_h__
#define __MyDrawingPanel_h__

#include "wx/wxprec.h"
#include "Element.hpp"

class MyDrawingPanel : public wxPanel
	//------------------------------------------------------------------------
{
public:
	MyDrawingPanel(wxWindow* parent);
	void OpenFile(wxString fileName);
	void SaveFile(wxString fileName);
	bool IsDrawing() { return m_isDrawing; }
	void ToogleIsDrawing() { m_isDrawing = m_isDrawing ? false : true; }

private:
	void OnMouseMove(wxMouseEvent& event);
	void OnMouseLeftDown(wxMouseEvent& event);
	void OnPaint(wxPaintEvent& event);
	void drawingThis(wxPaintDC* dc, Element* element);
	Element* m_currentElement;
	std::vector<Element*>* m_elements;
	bool m_isDrawing;
	wxPoint m_mousePoint;
	wxPoint m_onePoint;
};
#endif