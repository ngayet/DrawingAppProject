#include "Controller.hpp"



Controller::Controller() {
	m_id = "";
	m_fill = "#FFFFFF";
	m_stroke = "#000000";
	m_strokeWidth = 0;
	m_lock = false;
	m_x = 0;
	m_y = 0;
	m_type = DrawingType::EMPTY;
}

Controller::Controller(MyFrame* myFrame) {
	m_id = "";
	m_fill = "#FFFFFF";
	m_stroke = "#000000";
	m_strokeWidth = 0;
	m_lock = false;
	m_x = 0;
	m_y = 0;
	m_type = DrawingType::EMPTY;

	MyFrame* frame = new MyFrame(wxT(APP_NAME), wxDefaultPosition, wxSize(APPLICATION_WIDTH, APPLICATION_HEIGHT));
	
	m_controlPanel = new MyControlPanel(myFrame);
	m_drawingPanel = new MyDrawingPanel(myFrame);
	m_controlPanel->AddObserver(this);
	m_drawingPanel->AddObserver(this);
	frame->Show(true);
	SetTopWindow(frame);

	IMPLEMENT_APP(MyApp)

}

void Controller::Update(Message msg) {

	switch (msg.m_msgType) {
	case TypesMessage::CONTROL_PANEL:
		if (msg.m_id != "\n") {
			m_id = msg.m_id;
		}

		if (msg.m_fill != "") {
			m_fill = msg.m_fill;
		}

		if (msg.m_stroke != "") {
			m_stroke = msg.m_stroke;
		}

		if (msg.m_strokeWidth != 0) {
			m_strokeWidth = msg.m_strokeWidth;
		}

		if (msg.m_lock) {
			m_lock = true;
		}
		else {
			m_lock = false;
		}

		if (m_type != DrawingType::EMPTY) {
			m_type = msg.m_type;
		}

		break;
	default:
		break;
	}

	//TODO -> REFRESH    
}

