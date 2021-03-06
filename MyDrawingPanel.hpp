#ifndef __MyDrawingPanel_h__
#define __MyDrawingPanel_h__

#include "wx/wxprec.h"
#include "Element.hpp"
#include "Subject.hpp"

class MyDrawingPanel : public wxPanel, public Subject
	//------------------------------------------------------------------------
{
public:
	MyDrawingPanel(wxWindow* parent);
	void OpenFile(wxString fileName);
	void SaveFile(wxString fileName);

private:
	void OnMouseMove(wxMouseEvent& event);
	void OnMouseLeftDown(wxMouseEvent& event);
	void OnMouseRightDown(wxMouseEvent& event);
	void OnPaint(wxPaintEvent& event);
	wxPoint m_mousePoint;
	wxPoint m_onePoint;
};
#endif