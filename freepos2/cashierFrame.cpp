#include "wx/wxprec.h"

#ifndef WX_PRECOMP
  #include "wx/wx.h"
  #include "wx/event.h"
  #include "wx/image.h"
  #include "wx/display.h"
#endif

#include "cashierFrame.h"
#include "frame1.h"


CashierFrame::CashierFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame(NULL, wxID_ANY, title, pos, size)
{
  CreateStatusBar();
  SetStatusText( "Cashier Screen" );
	mDisp = new wxDisplay(1);

  wxPanel* mPanel = new wxPanel(this, wxID_ANY, wxPoint(0, 0), wxDefaultSize, wxWANTS_CHARS);
  mPanel->Bind(wxEVT_CHAR_HOOK, &CashierFrame::OnKeyDown, this); 
  SetPosition(wxPoint(1280, 0));
  SetBackgroundColour(wxColour("SPRING GREEN"));
  ShowFullScreen( true, wxFULLSCREEN_NOMENUBAR);

	cashierStBox = new wxStaticBox(this, wxID_ANY, wxT("Cashier Login"), wxPoint(30,30), wxSize(350, 120), wxALIGN_CENTRE_HORIZONTAL);
	fprintf(stdout, "aca1\n");
	//cashierStBox->SetBackgroundColour(wxColour("SKY BLUE"));
	cashierStBox->SetBackgroundColour(wxColour("AQUAMARINE"));
	fprintf(stdout, "aca2\n");
	wxStaticText* codCashier = new wxStaticText(cashierStBox, wxID_ANY, "CASHIER CODE ", wxPoint(10,10), wxSize(100, 20));
	codCashier->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxBOLD, false));
	wxTextCtrl* ccTextCtrl = new wxTextCtrl(cashierStBox, wxID_ANY, wxT(""), wxPoint(160, 5), wxSize(150, 30));
	fprintf(stdout, "ac22\n");
	//strCashierCode = new wxString(ccTextCtrl->GetLineText(0));
	fprintf(stdout, "aca3\n");
	wxStaticText* cashierPassword = new wxStaticText(cashierStBox, wxID_ANY, "PASSWORD  ", wxPoint(10, 50), wxSize(100, 20));
	cashierPassword->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxBOLD, false));
	fprintf(stdout, "aca4\n");
	wxTextCtrl* cpTextCtrl = new wxTextCtrl(cashierStBox, wxID_ANY, wxT(""), wxPoint(160, 45), wxSize(150, 30), wxTE_PASSWORD);
	//strCashierPass = new wxString(cpTextCtrl->GetLineText(0).GetData());
	fprintf(stdout, "aca5\n");

}

void CashierFrame::OnKeyDown(wxKeyEvent& event)
{
	SetStatusText(wxString::Format("KeyDown: %i\n", (int)event.GetKeyCode()));
	if((int)event.GetKeyCode() == 82){
		MyFrame* frame = new MyFrame( "Free POS", wxPoint(1280, 0), mDisp->GetClientArea().GetSize() );
		frame->SetBackgroundColour(wxColour("SPRING GREEN"));
		frame->ShowFullScreen( true, wxFULLSCREEN_NOMENUBAR);
		frame->Show( true );
		Close(true);
	}

	event.Skip();	
}
/*
void CashierFrame::OnEnterPressed(wxCommandEvent& event)
{
	//Validate
	fprintf(stdout, "Presiono enter\n");
	wxStaticText* txtResult = new wxStaticText(cashierStBox, wxID_ANY, "Validating...", wxPoint(30, 50), wxSize(30, 150));
	fprintf(stdout, "por validar\n");

	if((wcscmp(strCashierCode->GetData(),  wxString("7777"))==0) && (wcscmp(strCashierPass->GetData(), wxString("6969"))==0))
		txtResult->SetLabel("User Validated");
	else 
		txtResult->SetLabel("User Not Found");

}
*/

wxBEGIN_EVENT_TABLE(CashierFrame, wxFrame)
	//EVT_KEY_DOWN(CashierFrame::OnKeyDown)
	//EVT_TEXT_ENTER(wxID_ANY, CashierFrame::OnEnterPressed)
wxEND_EVENT_TABLE()
