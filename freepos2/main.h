#ifndef MAIN_H
#define MAIN_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
		#include "wx/display.h"
#endif

#include "cashierFrame.h"
#include "frame1.h"

class MyApp: public wxApp
{
public:
    MyFrame* gloframe;
    virtual bool OnInit();
		int FilterEvent(wxEvent& event);
private:
	void OnExit(wxCommandEvent& event);
	wxDisplay* mDisp;
	MyFrame* frame;
	CashierFrame* cashierFrm;

};

#endif
