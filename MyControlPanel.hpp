#ifndef __MyControlPanel_h__
#define __MyControlPanel_h__

#include "wx/wxprec.h"

#include <wx/clrpicker.h>

class MyControlPanel : public wxPanel
	//------------------------------------------------------------------------
{
public:
	MyControlPanel(wxWindow* parent);
	int GetSliderValue() { return m_sliderWidthStroke->GetValue(); };

private:
	void OnButtonLine(wxCommandEvent& event);
	void OnButtonCircle(wxCommandEvent& event);
	void OnColorPickerFillChanged(wxColourPickerEvent& event);
	void OnColorPickerStrokeChanged(wxColourPickerEvent& event);
	void OnSliderStroke(wxScrollEvent& event);

	wxButton* m_ButtonLine;
	wxButton* m_ButtonCircle;
	wxColourPickerCtrl* m_colorFill;
	wxColourPickerCtrl* m_colorStroke;
	wxSlider* m_sliderWidthStroke;
	//wxCheckBox* m_checkBox;
};

#endif