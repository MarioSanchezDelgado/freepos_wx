#include "wx/wxprec.h"

#ifndef WX_PRECOMP
	#include "wx/wx.h"
	#include "wx/event.h"
#endif

#include "wx/event.h"
#include "wx/image.h"
#include "imageCanvas.h"


wxBEGIN_EVENT_TABLE(ImageCanvas, wxPanel)
    EVT_PAINT(ImageCanvas::OnPaint)
wxEND_EVENT_TABLE()

ImageCanvas::ImageCanvas(wxWindow *parent, const wxPoint &pos, const wxSize &size):wxPanel(parent, wxID_ANY, pos, size, wxTAB_TRAVERSAL, "")
{
  //SetBackgroundColour(* wxWHITE);
  
  wxImage image;

  if ( !image.LoadFile( wxT("./logo.png")) )
  {
    wxLogError(wxT("Can't load PNG image"));
  }
  else
  {
    picFromFile = wxBitmap( image.Scale(150, 150, wxIMAGE_QUALITY_HIGH));
  }
  
  //image.Destroy();
}

ImageCanvas::~ImageCanvas()
{

}

void ImageCanvas::OnPaint( wxPaintEvent &WXUNUSED(event) )
{
  wxPaintDC dc( this );
  PrepareDC(dc);
  if (picFromFile.IsOk())
  {
    dc.DrawBitmap( picFromFile, 0, 30 );
  }
}
