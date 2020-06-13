#include "Controller.hpp"

#define ACCURACY 15 //for the selection of Elements, in pixel

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

	case TypesMessage::DRAWING_MOUSE_RIGHT_DOWN:
		for (Element* element : m_elements) {
			if (element->GetType() == DrawingType::LINE) {
				if (isInTheLine(element->GetX1(), element->GetY1(), element->GetX2(), element->GetY2(), msg->m_x, msg->m_y))
				{
					m_id = element->GetId();
					m_controlPanel->GetId()->SetLabel(m_id);
					m_controlPanel->Refresh();
				}
			}
		}
		break;

	default:
		break;
	}


}

bool Controller::isInTheLine(int x1, int y1, int x2, int y2, int p_x, int p_y) {

	if (x1 <= x2) {
		if (x1-ACCURACY > p_x || x2+ ACCURACY < p_x) return false;
	}
	else {
		if (x2 - ACCURACY > p_x || x1 + ACCURACY < p_x) return false;
	}

	float a, b;
	int y;

	if (x1 == x2) {
		a = (float)(y2 - y1);
	}
	else {
		a = (float)(y2 - y1) / (float)(x2 - x1);
	}
	b = y1 - a * x1;
	y = a * p_x + b;

	return p_y > y - ACCURACY && p_y < y + ACCURACY;
}