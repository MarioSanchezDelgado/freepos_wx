#ifndef SALESFRAME_H
#define SALESFRAME_H

#ifndef WX_PRECOMP
  #include "wx/wx.h"
  #include "wx/event.h"
  #include "wx/image.h"
  #include "wx/display.h"
#endif

#include <wx/richtext/richtextctrl.h>

class SalesFrame: public wxFrame
{
public:
  SalesFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
	virtual ~SalesFrame();

private:
	//wxBoxSizer* sfSizerSW;
	wxFlexGridSizer* sfSizerSW;
	wxRichTextCtrl* sfText;
	wxScrolledWindow* sfScrollW;

	wxBoxSizer* sfSizer;
	wxPanel* sfPanel;
	
	wxTextCtrl* tcNewCode;

	void OnEnterPressed(wxCommandEvent& event);

	wxDECLARE_EVENT_TABLE();
};


#endif

