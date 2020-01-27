#ifndef CASHIERFRAME_H
#define CASHIERFRAME_H

#ifndef WX_PRECOMP
  #include "wx/wx.h"
  #include "wx/event.h"
  #include "wx/image.h"
  #include "wx/display.h"
#endif


class CashierFrame: public wxFrame
{
public:
  CashierFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
	wxDisplay* mDisp;

	wxString* strCashierCode;
	wxString* strCashierPass;
	wxStaticBox* cashierStBox;
  void OnKeyDown(wxKeyEvent& event);
  //void OnEnterPressed(wxCommandEvent& event);
  //void OnCashierFrameTrggr(wxKeyEvent& event);

  wxDECLARE_EVENT_TABLE();
};


#endif

