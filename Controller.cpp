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

	m_frame = new MyFrame(wxT(APP_NAME), wxDefaultPosition, wxSize(APPLICATION_WIDTH, APPLICATION_HEIGHT));
	m_frame->AddObserver(this);

	m_controlPanel = new MyControlPanel(m_frame);
	m_controlPanel->AddObserver(this);
	
	m_drawingPanel = new MyDrawingPanel(m_frame);
	m_drawingPanel->AddObserver(this);

	m_frame->Show(true);

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

	case TypesMessage::MYFRAME_ON_CLOSE:
		delete m_controlPanel;
		delete m_drawingPanel;
		break;

	case TypesMessage::MYFRAME_ON_SIZE:
		int w, h;
		m_frame->GetSize(&w, &h);
		m_controlPanel->SetSize(wxRect(wxPoint(0, 0), wxPoint(WIDGET_PANEL_WIDTH, h)));
		m_drawingPanel->SetSize(wxRect(wxPoint(WIDGET_PANEL_WIDTH, 0), wxPoint(w, h)));
		break;

	default:
		break;
	}

	//TODO -> REFRESH    
}

