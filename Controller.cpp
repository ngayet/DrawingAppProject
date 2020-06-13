#include "Controller.hpp"



Controller::Controller() {
	m_id = "";
	m_fill = "#FFFFFF";
	m_stroke = "#000000";
	m_strokeWidth = 0;
	m_lock = false;
	m_x = 0;
	m_y = 0;
	m_type = DrawingType::LINE;

	m_currentElement = Element(m_type);

	m_frame = new MyFrame(wxT(APP_NAME), wxDefaultPosition, wxSize(APPLICATION_WIDTH, APPLICATION_HEIGHT));
	m_frame->AddObserver(this);

	m_controlPanel = new MyControlPanel(m_frame);
	m_controlPanel->AddObserver(this);

	m_drawingPanel = new MyDrawingPanel(m_frame);
	m_drawingPanel->AddObserver(this);

	m_frame->Show(true);

}

void Controller::Update(Message* msg) {

	switch (msg->m_msgType) {
	case TypesMessage::CONTROL_PANEL:
		if (msg->m_id != "\n") {
			m_id = msg->m_id;
		}

		if (msg->m_fill != "") {
			m_fill = msg->m_fill;
		}

		if (msg->m_stroke != "") {
			m_stroke = msg->m_stroke;
		}

		if (msg->m_strokeWidth != 0) {
			m_strokeWidth = msg->m_strokeWidth;
		}

		if (msg->m_lock) {
			m_lock = true;
		}
		else {
			m_lock = false;
		}

		if (msg->m_type != DrawingType::EMPTY) {
			m_type = msg->m_type;
		}

		break;

	case DRAWING_MOUSE_LEFT_DOWN:
		if (m_currentElement.GetX1() == 0) {
			m_currentElement.SetId(m_id);
			m_currentElement.SetFill(m_fill);
			m_currentElement.SetStroke(m_stroke);
			m_currentElement.SetStrokeWidth(m_strokeWidth);
			m_currentElement.SetLock(m_lock);
			m_currentElement.SetType(m_type);

			m_currentElement.SetX1(msg->m_x);
			m_currentElement.SetY1(msg->m_y);
		}
		else {
			m_currentElement.SetX2(msg->m_x);
			m_currentElement.SetY2(msg->m_y);
			m_elements.push_back(new Element(m_currentElement));
			m_currentElement = Element(m_type);
			m_drawingPanel->Refresh();
		}
		break;

	case DRAWING_MOUSE_MOVE:
		if (m_currentElement.GetX1() > 0) {
			m_currentElement.SetX2(msg->m_x);
			m_currentElement.SetY2(msg->m_y);

			m_drawingPanel->Refresh();
		}
		break;

	case TypesMessage::MYFRAME_ON_CLOSE:

		delete m_controlPanel;
		delete m_drawingPanel;
		delete this;
		break;

	case TypesMessage::DRAWING_ON_PAINT:
	{
		wxPaintDC dc(m_drawingPanel);

		for (Element* element : m_elements) {
			if (element->GetType() == DrawingType::LINE)
				dc.DrawLine(wxPoint(element->GetX1(), element->GetY1()), wxPoint(element->GetX2(), element->GetY2()));
			else if (element->GetType() == DrawingType::CIRCLE)
				dc.DrawCircle(wxPoint(element->GetX1(), element->GetY1()), sqrt(pow(element->GetX2() - element->GetX1(), 2) + pow(element->GetY2() - element->GetY1(), 2)));
		}

		if (m_currentElement.GetX2() > 0) {
			if (m_currentElement.GetType() == DrawingType::LINE)
				dc.DrawLine(wxPoint(m_currentElement.GetX1(), m_currentElement.GetY1()), wxPoint(m_currentElement.GetX2(), m_currentElement.GetY2()));
			else if (m_currentElement.GetType() == DrawingType::CIRCLE)
				dc.DrawCircle(wxPoint(m_currentElement.GetX1(), m_currentElement.GetY1()), sqrt(pow(m_currentElement.GetX2() - m_currentElement.GetX1(), 2) + pow(m_currentElement.GetY2() - m_currentElement.GetY1(), 2)));
		}
		break;
	}
	case TypesMessage::MYFRAME_ON_SIZE:
		int w, h;
		m_frame->GetSize(&w, &h);
		m_controlPanel->SetSize(wxRect(wxPoint(0, 0), wxPoint(WIDGET_PANEL_WIDTH, h)));
		m_drawingPanel->SetSize(wxRect(wxPoint(WIDGET_PANEL_WIDTH, 0), wxPoint(w, h)));
		break;

	default:
		break;
	}


}

bool Controller::isInTheLine(int x1, int y1, int x2, int y2, int p_x, int p_y) {
	if (x1 > x2) {
		int temp = x1;
		x1 = x2;
		x2 = temp;
		temp = y1;
		y1 = y2;
		y2 = temp;
	}

	if (p_x >= x1 && p_x <= x2) {

		float a = (y2 - y1) / (x2 - x1);
		float b = y1 - a * x1;

		if (p_y == (a * p_x + b)) {
			return true;
		}
		else {
			return false;
		}
	}
}