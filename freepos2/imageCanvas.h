#ifndef IMAGECANVAS_H
#define IMAGECANVAS_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
  #include <wx/wx.h>
  #include <wx/timer.h>
#endif

class ImageCanvas: public wxPanel
{
public:
  ImageCanvas(wxWindow *parent, const wxPoint &pos, const wxSize& size);
  virtual ~ImageCanvas();

  
  void OnPaint(wxPaintEvent& WXUNUSED(event));
private:
  wxBitmap picFromFile;
  wxDECLARE_EVENT_TABLE();
};

#endif
