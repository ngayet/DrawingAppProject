#include "MyFrame.hpp"

//************************************************************************
//************************************************************************
// Frame class (the main window)
//************************************************************************
//************************************************************************

//------------------------------------------------------------------------
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame((wxFrame*)NULL, -1, title, pos, size)
	//------------------------------------------------------------------------
	// The constructor of the main frame that creates the menu stuffs and the 2 panels
{

	wxMenu* fileMenu = new wxMenu();
	fileMenu->Append(ID_LOAD, wxT("&Open file..."));
	fileMenu->Append(ID_SAVE, wxT("&Save file..."));
	fileMenu->Append(ID_ABOUT, wxT("&About..."));
	fileMenu->AppendSeparator();
	fileMenu->Append(ID_QUIT, wxT("&Exit"));

	wxMenuBar* menuBar = new wxMenuBar();
	menuBar->Append(fileMenu, wxT("&File"));

	Bind(wxEVT_MENU, &MyFrame::OnOpenFile, this, ID_LOAD);
	Bind(wxEVT_MENU, &MyFrame::OnSaveFile, this, ID_SAVE);
	Bind(wxEVT_MENU, &MyFrame::OnQuit, this, ID_QUIT);
	Bind(wxEVT_MENU, &MyFrame::OnAbout, this, ID_ABOUT);
	Bind(wxEVT_CLOSE_WINDOW, &MyFrame::OnClose, this);
	Bind(wxEVT_SIZE, &MyFrame::OnSize, this);

	SetMenuBar(menuBar);

	CreateStatusBar();
	SetStatusText(wxT("click in the right panel and tune the controls of the left panel. Visit the File menu!"));
	Centre(); // Guess what it does ;-)
}

//------------------------------------------------------------------------
void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
//------------------------------------------------------------------------
{
	Close(true);
}

//------------------------------------------------------------------------
void MyFrame::OnClose(wxCloseEvent& event)
//------------------------------------------------------------------------
{

	Message msg = Message();
	msg.m_msgType = TypesMessage::MYFRAME_ON_CLOSE;
	notifyObservers(&msg);
	event.Skip();

}

//------------------------------------------------------------------------
void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
//------------------------------------------------------------------------
{
	wxMessageBox(wxT("How to .. \n\n- use 2 panels (one for controls, one for drawings)\n- manage basic events (so that controls impact drawings)\n\n... with wxWidgets (3.0.2)\n\nPascal Bertolino UGA - GIPSA-lab, Grenoble - France\npascal.bertolino@gipsa-lab.fr"),
		wxT(APP_NAME), wxOK | wxICON_INFORMATION);
}

//------------------------------------------------------------------------
void MyFrame::OnOpenFile(wxCommandEvent& WXUNUSED(event))
//------------------------------------------------------------------------
{
	//wxString filename = wxFileSelector(wxT("Select file"));
	//if (!filename.empty())
	//	m_drawingPanel->OpenFile(filename);
}

//------------------------------------------------------------------------
void MyFrame::OnSaveFile(wxCommandEvent& WXUNUSED(event))
//------------------------------------------------------------------------
{
	//wxString filename = wxSaveFileSelector(wxT("Save file as"), wxT("*.txt"), wxT("data"));
	//if (!filename.empty())
	//	m_drawingPanel->SaveFile(filename);
}

//------------------------------------------------------------------------
void MyFrame::OnSize(wxSizeEvent& event)
//------------------------------------------------------------------------
// Called when you resize the frame
{
	//if (ObserveurIsSet()) {
		Message msg = Message();
		msg.m_msgType = TypesMessage::MYFRAME_ON_SIZE;
		notifyObservers(&msg);
	//}
}