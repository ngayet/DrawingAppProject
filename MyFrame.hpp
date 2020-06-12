#ifndef __MyFrame_h__
#define __MyFrame_h__

#include "wx/wxprec.h"
#include "Constants.hpp"
#include "Subject.hpp"

//------------------------------------------------------------------------
class MyFrame : public wxFrame, public Subject
	//------------------------------------------------------------------------
{
public:
	MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
protected:
	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnOpenFile(wxCommandEvent& WXUNUSED(event));
	void OnSaveFile(wxCommandEvent& WXUNUSED(event));
	void OnClose(wxCloseEvent& event);
	void OnSize(wxSizeEvent& event);
};

#endif