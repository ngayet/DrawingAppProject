// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include<wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>


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