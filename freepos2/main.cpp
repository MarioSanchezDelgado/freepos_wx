#include "wx/wxprec.h"

#ifndef WX_PRECOMP
  #include "wx/wx.h"
  #include "wx/event.h"
	#include "wx/image.h"
	#include "wx/display.h"
#endif

#include "frame1.h"
#include "main.h"


wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
  if ( !wxApp::OnInit() )
        return false;
//	wxInitAllImageHandlers();
  wxImage::AddHandler(new wxPNGHandler);
	wxDisplay* mDisp = new wxDisplay(1);
  fprintf(stdout, "Displays %d\n", mDisp->GetCount());

  MyFrame* frame = new MyFrame( "Free POS", wxPoint(1280, 0), mDisp->GetClientArea().GetSize() );
  frame->SetBackgroundColour(wxColour("SPRING GREEN"));
  frame->Show( true );
  frame->ShowFullScreen( true, wxFULLSCREEN_NOMENUBAR);
  return true;
}

int MyApp::FilterEvent(wxEvent& event)
{

  if ((event.GetEventType() == wxEVT_KEY_DOWN) &&
      (((wxKeyEvent&)event).GetKeyCode() == WXK_F1))
  {
    wxLogMessage( "KeyDown F1" );
    return true;
  }

  return -1;
}
