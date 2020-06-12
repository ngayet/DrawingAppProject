#include "MyApp.hpp"
#include "MyFrame.hpp"
#include "Constants.hpp"
#include "Controller.hpp"

bool MyApp::OnInit()
//------------------------------------------------------------------------
{
	Controller c = Controller();
	
	SetTopWindow(c.GetFrame());
	return true;
}