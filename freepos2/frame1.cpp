#include "frame1.h"
#include "statusPanel.h"
#include "imageCanvas.h"

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame(NULL, wxID_ANY, title, pos, size)
{
  wxMenu *menuFile = new wxMenu;
  menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                   "Help string shown in status bar for this menu item");
  menuFile->AppendSeparator();
  menuFile->Append(wxID_EXIT);
  wxMenu *menuHelp = new wxMenu;
  menuHelp->Append(wxID_ABOUT);
  wxMenuBar *menuBar = new wxMenuBar;
  menuBar->Append( menuFile, "&File" );
  menuBar->Append( menuHelp, "&Help" );
  SetMenuBar( menuBar );
  CreateStatusBar();
  SetStatusText( "Welcome to The Free POS!" );

  wxPanel* mPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxWANTS_CHARS);
  mPanel->Bind(wxEVT_CHAR_HOOK, &MyFrame::OnKeyDown, this); 
	
  wxSize mSize = this->GetSize();
	ImageCanvas* m_canvas = new ImageCanvas(this, wxPoint(mSize.GetWidth()/2 - 75,30), wxSize(200,200) );
  mStPanel = new StatusPanel(this, wxSize(mSize.GetWidth(), 30));
  mStPanel->Show();
	SetBackgroundColour(wxColour("SPRING GREEN"));
	ShowFullScreen( true, wxFULLSCREEN_NOMENUBAR);
	Show(true);
}

void MyFrame::OnExit(wxCommandEvent& event)
{
  Close( true );
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "This is a wxWidgets' App",
                  "About My App", wxOK | wxICON_INFORMATION );
}

void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Avanzando!");
}

void MyFrame::OnKeyDown(wxKeyEvent& event)
{
/*	 SetStatusText(wxString::Format("KeyDown: %i\n", (int)event.GetKeyCode()));
  if ( ((wxKeyEvent&)event).GetKeyCode() == 67 )
  {
    CashierFrame* cashierFrm = new CashierFrame( "Cashier Screen", wxPoint(50, 50), wxSize(450, 340) );
    cashierFrm->Show(TRUE);
    Close(true);
  }
*/
  event.Skip();	
}

void MyFrame::OnSizeEvent(wxSizeEvent& event)
{
  wxSize cSize = event.GetSize();
  //mStPanel->Close();
  //mStPanel = new StatusPanel(this, wxSize(cSize.GetWidth(), 30));
  mStPanel->SetSize(cSize.GetWidth(), 30);
  //mStPanel->Show();
  event.Skip();
}
 
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
  EVT_MENU(ID_Hello,   MyFrame::OnHello)
  EVT_MENU(wxID_EXIT,  MyFrame::OnExit)
  EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
  EVT_SIZE(MyFrame::OnSizeEvent)
wxEND_EVENT_TABLE()
