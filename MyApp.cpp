#include "MyApp.hpp"
#include "MyFrame.hpp"
#include "Constants.hpp"

bool MyApp::OnInit()
//------------------------------------------------------------------------
{
	MyFrame* frame = new MyFrame(wxT(APP_NAME), wxDefaultPosition, wxSize(APPLICATION_WIDTH, APPLICATION_HEIGHT));
	frame->Show(true);
	return true;
}