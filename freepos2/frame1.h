#ifndef FRAME1_H
#define FRAME1_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "statusPanel.h"

class MyFrame: public wxFrame
{
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
  void OnHello(wxCommandEvent& event);
  void OnExit(wxCommandEvent& event);
  void OnAbout(wxCommandEvent& event);

  void OnKeyDown(wxKeyEvent& event);
  void OnSizeEvent(wxSizeEvent& event);
  
  StatusPanel* mStPanel;

  wxDECLARE_EVENT_TABLE();
};

enum
{
    ID_Hello = 1,
    ID_CASHIER_FRAME
};


#endif

