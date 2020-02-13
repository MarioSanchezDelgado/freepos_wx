#include "wx/wxprec.h"

#ifndef WX_PRECOMP
  #include "wx/wx.h"
  #include "wx/event.h"
  #include "wx/image.h"
  #include "wx/display.h"
#endif

#include "salesFrame.h"
#include "cashierFrame.h"
#include "frame1.h"


CashierFrame::CashierFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame(NULL, wxID_ANY, title, pos, size)
{
  CreateStatusBar();
  SetStatusText( "Cashier Screen" );

  wxPanel* mPanel = new wxPanel(this);

  //mPanel->Bind(wxEVT_CHAR_HOOK, &CashierFrame::OnKeyDown, this); 
  SetPosition(wxPoint(1280, 0));
  SetBackgroundColour(wxColour("SPRING GREEN"));
  ShowFullScreen( true, wxFULLSCREEN_NOMENUBAR);

	cashierStBox = new wxStaticBox(mPanel, wxID_ANY, wxT("Cashier Login"), wxPoint(30,30), wxSize(350, 120), wxALIGN_CENTRE_HORIZONTAL);
	fprintf(stdout, "aca1\n");
	//cashierStBox->SetBackgroundColour(wxColour("SKY BLUE"));
	cashierStBox->SetBackgroundColour(wxColour("AQUAMARINE"));
	fprintf(stdout, "aca2\n");
	wxStaticText* codCashier = new wxStaticText(cashierStBox, wxID_ANY, "CASHIER CODE ", wxPoint(10,10), wxSize(100, 20));
	codCashier->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxBOLD, false));
	ccTextCtrl = new wxTextCtrl(cashierStBox, wxID_ANY, wxT(""), wxPoint(160, 5), wxSize(150, 30));
	fprintf(stdout, "ac22\n");
	strCashierCode = new wxString(ccTextCtrl->GetLineText(0));
	fprintf(stdout, "aca3\n");
	wxStaticText* cashierPassword = new wxStaticText(cashierStBox, wxID_ANY, "PASSWORD  ", wxPoint(10, 50), wxSize(100, 20));
	cashierPassword->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxBOLD, false));
	fprintf(stdout, "aca4\n");
	cpTextCtrl = new wxTextCtrl(cashierStBox, wxID_ANY, wxT(""), wxPoint(160, 45), wxSize(150, 30), wxTE_PASSWORD | wxTE_PROCESS_ENTER);
	strCashierPass = new wxString(cpTextCtrl->GetLineText(0).GetData());

}

/*void CashierFrame::OnKeyDown(wxKeyEvent& event)
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
}*/
CashierFrame::~CashierFrame()
{
	//cfSalesFrame->Destroy();
}

void CashierFrame::OnReturn()
{
	cfSalesFrame->Destroy();
}

void CashierFrame::OnEnterPressed(wxCommandEvent& event)
{
	//Validate
	fprintf(stdout, "Presiono enter\n");
	wxStaticText* txtResult = new wxStaticText(cashierStBox, wxID_ANY, "Validating...", wxPoint(120, 80), wxSize(30, 150));
	strCashierPass->operator=(cpTextCtrl->GetLineText(0).GetData());
	strCashierCode->operator=(ccTextCtrl->GetLineText(0));
	fprintf(stdout, "por validar1 %s\n", (const char *)strCashierCode->mb_str().data());
	fprintf(stdout, "por validar1 %s\n", (const char *)strCashierPass->mb_str().data());
	if((strncmp((const char *)strCashierCode->mb_str(wxConvUTF8), "7777", 4)==0) &&
			(strncmp((const char *)strCashierPass->mb_str(wxConvUTF8), "6969", 4)==0)){
		txtResult->SetLabel("User Validated");
		sleep(1);
		Hide();
		cfSalesFrame = new SalesFrame("", wxPoint(1280,0), wxSize(1000,1000));

	}
	else 
		txtResult->SetLabel("User Not Found");
}


wxBEGIN_EVENT_TABLE(CashierFrame, wxFrame)
	//EVT_KEY_DOWN(CashierFrame::OnKeyDown)
	EVT_TEXT_ENTER(wxID_ANY, CashierFrame::OnEnterPressed)
wxEND_EVENT_TABLE()
