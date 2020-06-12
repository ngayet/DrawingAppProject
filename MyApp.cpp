#include "MyApp.hpp"
#include "MyFrame.hpp"
#include "Constants.hpp"
#include "Controller.hpp"

bool MyApp::OnInit()
//------------------------------------------------------------------------
{
	SetTopWindow((new Controller())->GetFrame());
	return true;
}