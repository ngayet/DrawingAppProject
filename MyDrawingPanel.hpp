#ifndef __MyDrawingPanel_h__
#define __MyDrawingPanel_h__

#include "wx/wxprec.h"

class MyDrawingPanel : public wxPanel
//------------------------------------------------------------------------
{
public:
	MyDrawingPanel(wxWindow* parent);
	void OpenFile(wxString fileName);
	void SaveFile(wxString fileName);

private:
	void OnMouseMove(wxMouseEvent& event);
	void OnMouseLeftDown(wxMouseEvent& event);
	void OnPaint(wxPaintEvent& event);
	wxPoint m_mousePoint;
	wxPoint m_onePoint;
};
#endif