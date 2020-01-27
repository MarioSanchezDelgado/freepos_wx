#ifndef MAIN_H
#define MAIN_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif


class MyApp: public wxApp
{
public:
    MyFrame* gloframe;
    virtual bool OnInit();
		int FilterEvent(wxEvent& event);

};

#endif
