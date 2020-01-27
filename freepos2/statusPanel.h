#ifndef STATUSPANEL_H
#define STATUSPANEL_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
  #include <wx/wx.h>
  #include <wx/timer.h>
#endif

#include "wx/sizer.h"

class StatusPanel: public wxPanel
{
public:
  StatusPanel(wxWindow *parent, const wxSize& size);
  virtual ~StatusPanel();

  void UpdateClock();
  
  void OnTimer(wxTimerEvent& event) {UpdateClock();event.Skip();}
  //void OnTimer(wxTimerEvent& WXUNUSED(event)) {UpdateClock();}
private:
  wxTimer m_timer;
  wxStaticText* stPanelText;
  wxBoxSizer* stPanBoxSizer;
  wxDECLARE_EVENT_TABLE();
};

#endif
