#include "wx/wxprec.h"

#ifndef WX_PRECOMP
  #include "wx/wx.h"
  #include "wx/event.h"
  #include "wx/image.h"
  #include "wx/display.h"
#endif

#include "salesFrame.h"
#include "frame1.h"


SalesFrame::SalesFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame(NULL, wxID_ANY, title, pos, size)
{
  CreateStatusBar();
  SetStatusText( "Sales Screen" );

  SetPosition(wxPoint(1280, 0));
  SetBackgroundColour(wxColour("SPRING GREEN"));
  ShowFullScreen( true, wxFULLSCREEN_NOMENUBAR);
	sfPanel = new wxPanel(this, wxID_ANY, wxPoint(0, 0), wxSize(10, 100));
	//sfPanel->SetBackgroundColour(wxColour("BLUE"));
	//sfPanel = new wxPanel(this, wxID_ANY, "", wxPoint(200, 200), wxSize(100, 100));

	sfScrollW = new wxScrolledWindow(this, 
																		wxID_ANY,
																		wxPoint(20, 10), 
																		wxSize(30, 1000), 
																		wxHSCROLL | wxVSCROLL );
	sfScrollW->SetBackgroundColour(wxColour("WHITE"));
	//sfSizerSW = new wxBoxSizer(wxVERTICAL);
	wxFlexGridSizer* sfSizerSW = new wxFlexGridSizer(1);
	for (int j = 0; j < 80; j++){
		wxStaticText* salesLine = new wxStaticText(sfScrollW, 
																								wxID_ANY, 
																								wxString::Format("CODIGO             \t\t     x%i\t\t\t\tDESCRIPCION PRODUCTO     \t\t\t\t\t      TOTAL VENTA",
																																j+1),
																								wxDefaultPosition,
																								wxDefaultSize,
																								wxALIGN_CENTRE_HORIZONTAL);
		//salesLine->SetBackgroundColour(wxColour("LIGHT STEEL BLUE"));
		salesLine->SetFont(wxFont(18,
												wxFONTFAMILY_DECORATIVE,
												wxFONTSTYLE_SLANT,
												wxFONTWEIGHT_NORMAL,
												false));
		sfSizerSW->Add(salesLine, 1, wxEXPAND | wxALL | wxALIGN_CENTRE_HORIZONTAL, 5);
	}
	/*sfText = new wxRichTextCtrl(sfScrollW, 
															wxID_ANY, 
															"", 
															wxPoint(50, 100), 
															wxSize(100, 200), 
															wxRE_MULTILINE, 
															wxDefaultValidator);*/
	//sfSizerSW->Add(sfText, 1, wxEXPAND | wxALL, 30);
	sfScrollW->SetSizer(sfSizerSW);
	sfScrollW->FitInside();
	sfScrollW->SetScrollRate(5,5);
	
	sfSizer = new wxBoxSizer(wxVERTICAL);
	sfSizer->Add(sfPanel, 1, wxEXPAND | wxALL, 30);
	sfSizer->Add(sfScrollW, 1, wxEXPAND | wxALL, 30);
	SetSizer(sfSizer);

	Show(true);
}

SalesFrame::~SalesFrame()
{

}

wxBEGIN_EVENT_TABLE(SalesFrame, wxFrame)
wxEND_EVENT_TABLE()
