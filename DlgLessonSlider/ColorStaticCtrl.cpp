// ColorStaticCtrl.cpp : implementation file
//

#include "pch.h"
#include "DlgLessonSlider.h"
#include "ColorStaticCtrl.h"


// ColorStaticCtrl

IMPLEMENT_DYNAMIC(ColorStaticCtrl, CStatic)

ColorStaticCtrl::ColorStaticCtrl()
{

}

ColorStaticCtrl::~ColorStaticCtrl()
{
}


BEGIN_MESSAGE_MAP(ColorStaticCtrl, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// ColorStaticCtrl message handlers




void ColorStaticCtrl::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CStatic::OnPaint() for painting messages

	// Takes the whole View (Window)
	CRect rectWindow;
	GetClientRect(&rectWindow);

	// Hack to tell MFC where it can ONLY draw
	CRgn ClipRgn;
	if (ClipRgn.CreateRectRgnIndirect(&rectWindow))
		// Device contest select clip region of this rectangle (window/view)
		dc.SelectClipRgn(&ClipRgn);

	// macro that will create the color
	// and store that value in the 'color' variable
	auto color{ RGB(red, green, blue) };

	// Instancing brush for drawing
	CBrush brush(color);
	// Filling the rectangle (window/view) with brush ('brusgh') with color ('color')
	dc.FillRect(&rectWindow, &brush);

	// Instancing string
	CString strPoint;
	// Placing slider values into string 
	strPoint.Format(_T("RGB: %d, %d, %d"), red, green, blue);
	dc.TextOutW(10, 10, strPoint);

	dc.SelectClipRgn(NULL);
}
