#include "MyDrawingPanel.hpp"
#include "Constants.hpp"
#include <math.h>
//------------------------------------------------------------------------
MyDrawingPanel::MyDrawingPanel(wxWindow* parent) : wxPanel(parent)
//------------------------------------------------------------------------
// In this constructor, bind some mouse events and the paint event with the appropriate methods
{
	int w, h;
	GetParent()->GetClientSize(&w, &h);
	SetSize(wxRect(wxPoint(WIDGET_PANEL_WIDTH, 0), wxPoint(w, h)));
	SetBackgroundColour(wxColour(0xFF, 0xFF, 0xFF));
	Bind(wxEVT_MOTION, &MyDrawingPanel::OnMouseMove, this);
	Bind(wxEVT_LEFT_DOWN, &MyDrawingPanel::OnMouseLeftDown, this);
	Bind(wxEVT_PAINT, &MyDrawingPanel::OnPaint, this);
	m_onePoint.x = (w - WIDGET_PANEL_WIDTH) / 2;
	m_onePoint.y = h / 2;
	m_mousePoint = m_onePoint;
}

//------------------------------------------------------------------------
void MyDrawingPanel::OnMouseMove(wxMouseEvent& event)
//------------------------------------------------------------------------
// called when the mouse is moved
{
	Message msg = Message();
	msg.m_msgType = TypesMessage::DRAWING_MOUSE_MOVE;
	msg.m_x = event.m_x;
	msg.m_y = event.m_y;
	notifyObservers(&msg);
}

//------------------------------------------------------------------------
void MyDrawingPanel::OnMouseLeftDown(wxMouseEvent& event)
//------------------------------------------------------------------------
// called when the mouse left button is pressed
{
	Message msg = Message();

	msg.m_msgType = TypesMessage::DRAWING_MOUSE_LEFT_DOWN;
	msg.m_x = event.m_x;
	msg.m_y = event.m_y;
	notifyObservers(&msg);
}

//------------------------------------------------------------------------
void MyDrawingPanel::OnPaint(wxPaintEvent& event)
//------------------------------------------------------------------------
// called automatically when the panel is shown for the first time or
// when the panel is resized
// You have to call OnPaint with Refresh() when you need to update the panel content
{
	Message msg = Message();
	msg.m_msgType = TypesMessage::DRAWING_ON_PAINT;
	notifyObservers(&msg);

	/*dc.DrawLine(m_mousePoint, m_onePoint);
	if (m_elements) {
		for (Element* element : *m_elements) {
			DrawingThis(&dc, element);
		}
	}*/


		
	
}

//------------------------------------------------------------------------
void MyDrawingPanel::OpenFile(wxString fileName)
//------------------------------------------------------------------------
{
	// just to open (and close) any file 
	FILE* f = fopen(fileName, "r");
	if (f)
	{
		wxMessageBox(wxT("The file was opened then closed"));
		fclose(f);
	}
}

//------------------------------------------------------------------------
void MyDrawingPanel::SaveFile(wxString fileName)
//------------------------------------------------------------------------
{
	// just to create a tiny file
	FILE* f = fopen(fileName, "w");
	if (!f)
		wxMessageBox(wxT("Cannot save file"));
	else
	{
		fprintf(f, "S1102 software can create and write a file");
		wxMessageBox(wxT("The file was saved"));
		fclose(f);
	}
}