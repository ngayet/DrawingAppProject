#include "MyControlPanel.hpp"
#include "Constants.hpp"
#include "Message.hpp"
#include "Element.hpp"


MyControlPanel::MyControlPanel(wxWindow* parent) : wxPanel(parent)
//------------------------------------------------------------------------
// In this constructor, create the controls and associate each of them (bind) a method
{
	int w, h, y;
	GetParent()->GetSize(&w, &h);
	SetSize(wxRect(wxPoint(0, 0), wxPoint(WIDGET_PANEL_WIDTH, h)));
	SetBackgroundColour(*wxLIGHT_GREY);

	//Button Line
	y = WIDGET_Y0;
	m_ButtonLine = new wxButton(this, ID_BUTTON_LINE, wxT("Line"), wxPoint(10, y));
	Bind(wxEVT_BUTTON, &MyControlPanel::OnButtonLine, this, ID_BUTTON_LINE);

	//Button Circle
	y += WIDGET_Y_STEP;
	m_ButtonCircle = new wxButton(this, ID_BUTTON_CIRCLE, wxT("Circle"), wxPoint(10, y));
	Bind(wxEVT_BUTTON, &MyControlPanel::OnButtonCircle, this, ID_BUTTON_CIRCLE);

	//Colour Picker Background (fill)
	y += WIDGET_Y_STEP;
	new wxStaticText(this, wxID_ANY, wxT("Color Background"), wxPoint(10, y));
	y += 15;
	m_colorFill = new wxColourPickerCtrl(this, ID_COLOR_FILL, *wxWHITE, wxPoint(10, y));
	Bind(wxEVT_COLOURPICKER_CHANGED, &MyControlPanel::OnColorPickerFillChanged, this, ID_COLOR_FILL);

	//Color Picker Stroke
	y += WIDGET_Y_STEP;
	new wxStaticText(this, wxID_ANY, wxT("Color Stroke"), wxPoint(10, y));
	y += 15;
	m_colorStroke = new wxColourPickerCtrl(this, ID_COLOR_STROKE, *wxBLACK, wxPoint(10, y));
	Bind(wxEVT_COLOURPICKER_CHANGED, &MyControlPanel::OnColorPickerStrokeChanged, this, ID_COLOR_STROKE);

	//Slider Strke Width
	y += WIDGET_Y_STEP;
	new wxStaticText(this, wxID_ANY, wxT("Stroke Width"), wxPoint(10, y));	
	y += 15;
	m_sliderWidthStroke = new wxSlider(this, ID_SLIDER_STROKE, 10, 2, 100, wxPoint(10, y), wxSize(100, 20));
	Bind(wxEVT_SCROLL_THUMBTRACK, &MyControlPanel::OnSliderStroke, this, ID_SLIDER_STROKE);

	//CheckBox Lock
	y += WIDGET_Y_STEP;
	m_checkBoxLock = new wxCheckBox(this, ID_CHECKBOX_LOCK, "Lock", wxPoint(10, y), wxSize(100, 20));
	Bind(wxEVT_CHECKBOX, &MyControlPanel::OnCheckBoxLock, this, ID_CHECKBOX_LOCK);
}

//------------------------------------------------------------------------
void MyControlPanel::OnButtonLine(wxCommandEvent& event)
//------------------------------------------------------------------------
{
	Message msg = Message();

	msg.m_msgType = TypesMessage::CONTROL_PANEL;
	msg.m_type = DrawingType::LINE;
	notifyObservers(&msg);
	
	//wxMessageBox(wxT("You just pressed the button!"));
}

//------------------------------------------------------------------------
void MyControlPanel::OnButtonCircle(wxCommandEvent& event)
//------------------------------------------------------------------------
{
	Message msg = Message();

	msg.m_msgType = TypesMessage::CONTROL_PANEL;
	msg.m_type = DrawingType::CIRCLE;
	notifyObservers(&msg);
	//wxMessageBox(wxT("You just pressed the button!"));
}

void MyControlPanel::OnColorPickerFillChanged(wxColourPickerEvent& event) {
	wxString colour = m_colorFill->GetColour().GetAsString(wxC2S_HTML_SYNTAX).AfterFirst('#');
	//AfterFirst -> remove #
	//wxMessageBox(colour);
	Message msg = Message();

	msg.m_msgType = TypesMessage::CONTROL_PANEL;
	msg.m_fill = colour;
	notifyObservers(&msg);
}

//------------------------------------------------------------------------
void MyControlPanel::OnColorPickerStrokeChanged(wxColourPickerEvent& event)
//------------------------------------------------------------------------
{
	wxString colour = m_colorStroke->GetColour().GetAsString(wxC2S_HTML_SYNTAX).AfterFirst('#');

	Message msg = Message();

	msg.m_msgType = TypesMessage::CONTROL_PANEL;
	msg.m_stroke = colour;
	notifyObservers(&msg);
}

//------------------------------------------------------------------------
void MyControlPanel::OnSliderStroke(wxScrollEvent& event)
//------------------------------------------------------------------------
{
	int width = m_sliderWidthStroke->GetValue();

	Message msg = Message();

	msg.m_msgType = TypesMessage::CONTROL_PANEL;
	msg.m_strokeWidth = width;
	notifyObservers(&msg);
}



//------------------------------------------------------------------------
void MyControlPanel::OnCheckBoxLock(wxCommandEvent& event)
//------------------------------------------------------------------------
{
	bool lock = m_checkBoxLock->GetValue();

	Message msg = Message();

	msg.m_msgType = TypesMessage::CONTROL_PANEL;
	msg.m_lock = lock;
	notifyObservers(&msg);
	//MyFrame* frame = (MyFrame*)GetParent();
	//frame->RefreshDrawing();	// update the drawing panel
}

