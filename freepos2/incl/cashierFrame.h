#ifndef CASHIERFRAME_H
#define CASHIERFRAME_H

#ifndef WX_PRECOMP
  #include "wx/wx.h"
  #include "wx/event.h"
  #include "wx/image.h"
  #include "wx/display.h"
#endif

#include "salesFrame.h"


class CashierFrame: public wxFrame
{
public:
  CashierFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
	virtual ~CashierFrame();
	void OnReturn();

private:
	wxString* strCashierCode;
	wxString* strCashierPass;
	wxStaticBox* cashierStBox;
	wxTextCtrl* ccTextCtrl;
	wxTextCtrl* cpTextCtrl;
  void OnKeyDown(wxKeyEvent& event);
  void OnEnterPressed(wxCommandEvent& event);
  //void OnCashierFrameTrggr(wxKeyEvent& event);
	
	SalesFrame* cfSalesFrame;

  wxDECLARE_EVENT_TABLE();
};


#endif

