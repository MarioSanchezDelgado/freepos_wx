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
	SetFont(wxFont(18,
                        wxFONTFAMILY_DECORATIVE,
                        wxFONTSTYLE_SLANT,
                        wxFONTWEIGHT_NORMAL,
                        false));
  SetBackgroundColour(wxColour("SPRING GREEN"));
  ShowFullScreen( true, wxFULLSCREEN_NOMENUBAR);
	sfPanel = new wxPanel(this, wxID_ANY, wxPoint(0, 0), wxSize(10, 200));
	//sfPanel->SetBackgroundColour(wxColour("BLUE"));
	//sfPanel = new wxPanel(this, wxID_ANY, "", wxPoint(200, 200), wxSize(100, 100));
	wxStaticText* stNewCode = new wxStaticText(sfPanel, -1, wxT("Codigo: "),
																							wxPoint(50, 150));
	tcNewCode = new wxTextCtrl(sfPanel, -1, wxT(""), wxPoint(150, 150), wxSize(230, 30), wxTE_PROCESS_ENTER);
	
	
	
	wxPanel* titlePanel = new wxPanel(this, wxID_ANY, wxPoint(0,0), wxSize(10,30));
	titlePanel->SetBackgroundColour(wxColour("PALE GREEN"));
	wxFlexGridSizer* sfTitleSizerSW = new wxFlexGridSizer(4);
	wxStaticText* stCode = new wxStaticText(titlePanel, -1, wxT("CODIGO    "));
	wxStaticText* stQuantity = new wxStaticText(titlePanel, -1, wxT("CANTIDAD    "));
	wxStaticText* stDescription = new wxStaticText(titlePanel, -1, wxT("DESCRIPCION"));
	wxStaticText* stTotal = new wxStaticText(titlePanel, -1, wxT("TOTAL   "));
	sfTitleSizerSW->AddGrowableCol(2, 1);
	titlePanel->SetSizer(sfTitleSizerSW);
  titlePanel->FitInside();




	sfTitleSizerSW->Add(stCode);
	sfTitleSizerSW->Add(stQuantity, 1, wxEXPAND);
	sfTitleSizerSW->Add(stDescription, 1, wxEXPAND);
	sfTitleSizerSW->Add(stTotal, 1, wxEXPAND);

	sfScrollW = new wxScrolledWindow(this, 
																		wxID_ANY,
																		wxPoint(0, 0), 
																		wxSize(30, 900), 
																		wxHSCROLL | wxVSCROLL );
	sfScrollW->SetBackgroundColour(wxColour("WHITE"));
	//sfSizerSW = new wxBoxSizer(wxVERTICAL);

	sfSizerSW = new wxFlexGridSizer(4, 0, 0);
	sfSizerSW->AddGrowableCol(2, 1);

	/*for (int j = 0; j < 80; j++){
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
	}*/
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
	sfSizer->Add(sfPanel, 1, wxEXPAND);
	sfSizer->Add(titlePanel, 1, wxEXPAND | wxRIGHT | wxLEFT, 30 );
	sfSizer->Add(sfScrollW, 1, wxEXPAND | wxRIGHT	| wxLEFT | wxBOTTOM, 30);
	SetSizer(sfSizer);

	Show(true);
}

SalesFrame::~SalesFrame()
{

}

void SalesFrame::OnEnterPressed(wxCommandEvent& event)
{
	fprintf(stdout, "Entro a validar code %s\n", (const char *)tcNewCode->GetLineText(0).mb_str(wxConvUTF8));

	if(strncmp((const char *)tcNewCode->GetLineText(0).mb_str(wxConvUTF8), 
							"123", 3) == 0)
	{
		fprintf(stdout, "Lo valido\n");
		sfSizerSW->Add(new wxStaticText(sfScrollW, 
																		-1,
																		wxString::Format("%-12s", "123")),
																		1, wxEXPAND, 0);
		sfSizerSW->Add(new wxStaticText(sfScrollW, 
																		-1,
																		wxString::Format("%-15s", "15")), 
																		1, wxEXPAND);
		sfSizerSW->Add(new wxStaticText(sfScrollW, 
																		-1,
																		wxT("Alcohol Pepita")), 
																		1, wxEXPAND);
		sfSizerSW->Add(new wxStaticText(sfScrollW, 
																		-1,
																		wxString::Format("%-7s", "10.95")),
																		1, wxEXPAND);

		sfScrollW->SetSizer(sfSizerSW);
		sfScrollW->FitInside();																		
	}
	else 
	{
		;
	}
}

wxBEGIN_EVENT_TABLE(SalesFrame, wxFrame)
	EVT_TEXT_ENTER(wxID_ANY, SalesFrame::OnEnterPressed)
wxEND_EVENT_TABLE()

