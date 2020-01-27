#include "statusPanel.h"

#include "wx/font.h"

StatusPanel::StatusPanel(wxWindow *parent, const wxSize& size):
  wxPanel(parent, wxID_ANY, wxPoint(0,0), size, wxTAB_TRAVERSAL, "")
    , m_timer(this)
{
  stPanBoxSizer = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* hboxClock = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* hboxStatus = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* hboxCompany = new wxBoxSizer(wxHORIZONTAL);
  //wxBoxSizer* hboxClock  = new wxBoxSizer(wxVERTICAL);
  //wxBoxSizer* hboxCompany = new wxBoxSizer(wxVERTICAL);
  //wxBoxSizer* hboxStatus = new wxBoxSizer(wxVERTICAL);
  
  SetBackgroundColour(wxColour("WHITE"));
  m_timer.Start(1000);
  stPanelText = new wxStaticText(this, wxID_ANY, "HOLA caracola");
  wxStaticText* title = new wxStaticText(this, wxID_ANY, "DAICHIN INTERNATIONAL CO");
  title->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxBOLD, false));

  hboxClock->Add(10,0);
  hboxClock->Add(stPanelText, 0, wxALIGN_CENTER_VERTICAL);
  //hboxClock->Add(10,0);
  hboxCompany->Add(title, 0, wxALIGN_CENTER_VERTICAL); 
  //hboxClock->Add(10,0);
  hboxStatus->Add(new wxStaticText(this, wxID_ANY, "STATUS: CLOSED"), 0, wxALIGN_CENTER_VERTICAL );
  hboxStatus->Add(10,0);

  stPanBoxSizer->Add(hboxClock, 1, wxEXPAND | wxRIGHT, 500);
  stPanBoxSizer->AddStretchSpacer();
  stPanBoxSizer->Add(hboxCompany, 1, wxEXPAND | wxALL, 1);
  stPanBoxSizer->AddStretchSpacer();
  stPanBoxSizer->Add(hboxStatus, 1,  wxEXPAND | wxLEFT , 500);
  fprintf(stdout, "st pan %d %d\n", this->GetSize().GetWidth(), this->GetSize().GetHeight());
  SetSizer(stPanBoxSizer);
  SetAutoLayout(true);
  //fprintf(stdout, "stp  %d %d\n", hboxClock->GetPoint().x, hboxClock->GetPoint().y);
  fprintf(stdout, "st pan szr %d %d\n", stPanBoxSizer->GetSize().GetWidth(), stPanBoxSizer->GetSize().GetHeight());
}

StatusPanel::~StatusPanel()
{
  if ( m_timer.IsRunning() )
  {   
    m_timer.Stop();
  }
}

void StatusPanel::UpdateClock()
{
  stPanelText->SetLabel(wxDateTime::Now().FormatISOCombined(' '));
  //stPanBoxSizer->Fit(this);
  //Refresh();
}

wxBEGIN_EVENT_TABLE(StatusPanel, wxPanel)
  EVT_TIMER(wxID_ANY, StatusPanel::OnTimer)
wxEND_EVENT_TABLE()


