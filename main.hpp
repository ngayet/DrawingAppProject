// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include<wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>


//------------------------------------------------------------------------
// Some constants
//------------------------------------------------------------------------
#define APPLICATION_WIDTH	600
#define APPLICATION_HEIGHT	500 
#define WIDGET_PANEL_WIDTH	150
#define WIDGET_Y0			30
#define WIDGET_Y_STEP		50
#define APP_NAME "M1102 Skeleton 1.0"

//------------------------------------------------------------------------
// Some enums for widgets
//------------------------------------------------------------------------
enum
{
	ID_QUIT = 1,
	ID_ABOUT,
	ID_LOAD,
	ID_SAVE,
	ID_BUTTON1,
	ID_SLIDER1,
	ID_CHECKBOX1
};