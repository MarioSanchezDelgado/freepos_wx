#include "wx/wxprec.h"

#ifndef WX_PRECOMP
  #include "wx/wx.h"
  #include "wx/event.h"
	#include "wx/image.h"
	#include "wx/display.h"
#endif

#include "main.h"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
  if ( !wxApp::OnInit() )
        return false;
	
	mDisp = new wxDisplay(1);
	//wxInitAllImageHandlers();
  wxImage::AddHandler(new wxPNGHandler);
  //fprintf(stdout, "Displays %d\n", mDisp.GetCount());

  frame = new MyFrame( "Free POS", wxPoint(1280, 0), mDisp->GetClientArea().GetSize() );
	cashierFrm = new CashierFrame( "Cashier Screen", wxPoint(50, 50), wxSize(450, 340) );
	//delete mDisp;
	cashierFrm->Hide();
  frame->Show( true );
/*  frame->SetBackgroundColour(wxColour("SPRING GREEN"));
  frame->ShowFullScreen( true, wxFULLSCREEN_NOMENUBAR);
*/
  return true;
}
void MyApp::OnExit(wxCommandEvent& event)
{
  fprintf(stdout, "Entro al onexit\n");
	delete frame;
	delete cashierFrm;
}

int MyApp::FilterEvent(wxEvent& event)
{
	int keyvalue;
	
  if (event.GetEventType() == wxEVT_KEY_DOWN) { 
		keyvalue = ((wxKeyEvent&)event).GetKeyCode();
		switch(keyvalue){
			case WXK_F1:
				wxLogMessage( "KeyDown F1" );
				break;
			case 67:
				//if(frame != NULL){
		    frame->Hide();
				cashierFrm->Show(TRUE);
				//}
				break;
			case 82:
				cashierFrm->Hide();
				cashierFrm->OnReturn();
				frame->Show(TRUE);
				break;

			default:
				break;
		}
  }
  if (event.GetEventType() ==  wxEVT_CLOSE_WINDOW){
	//	delete frame;
		//cashierFrm->~CashierFrame();
		cashierFrm->Destroy();
		//cashierFrm->Close();
	}

  return -1;
}
