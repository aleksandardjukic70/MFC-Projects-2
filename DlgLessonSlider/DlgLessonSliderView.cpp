
// DlgLessonSliderView.cpp : implementation of the CDlgLessonSliderView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "DlgLessonSlider.h"
#endif

#include "DlgLessonSliderDoc.h"
#include "DlgLessonSliderView.h"
#include "SliderDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDlgLessonSliderView

IMPLEMENT_DYNCREATE(CDlgLessonSliderView, CView)

BEGIN_MESSAGE_MAP(CDlgLessonSliderView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDlgLessonSliderView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_DIALOG_LAUNCHCOLORDLG, &CDlgLessonSliderView::OnDialogLaunchdlg)
END_MESSAGE_MAP()

// CDlgLessonSliderView construction/destruction

CDlgLessonSliderView::CDlgLessonSliderView() noexcept
{
	// TODO: add construction code here

}

CDlgLessonSliderView::~CDlgLessonSliderView()
{
}

BOOL CDlgLessonSliderView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CDlgLessonSliderView drawing

void CDlgLessonSliderView::OnDraw(CDC* pDC)
{
	CDlgLessonSliderDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// Drawing dialog color into View
	// Takes the whole View (Window)
	CRect rectWindow;
	GetClientRect(&rectWindow);


	// macro that will create the color
	// and store that value in the 'color' variable
	auto color{ RGB(red, green, blue) };

	// Instancing brush for drawing
	CBrush brush(color);
	// Filling the rectangle (window/view) with brush ('brusgh') with color ('color')
	pDC->FillRect(&rectWindow, &brush);

}


// CDlgLessonSliderView printing


void CDlgLessonSliderView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDlgLessonSliderView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDlgLessonSliderView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDlgLessonSliderView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CDlgLessonSliderView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDlgLessonSliderView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDlgLessonSliderView diagnostics

#ifdef _DEBUG
void CDlgLessonSliderView::AssertValid() const
{
	CView::AssertValid();
}

void CDlgLessonSliderView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDlgLessonSliderDoc* CDlgLessonSliderView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDlgLessonSliderDoc)));
	return (CDlgLessonSliderDoc*)m_pDocument;
}
#endif //_DEBUG


// CDlgLessonSliderView message handlers


void CDlgLessonSliderView::OnDialogLaunchdlg()
{
	SliderDlg dlg;

	// Setting dialog variables with values from View Variables 
	// To make slider positions match the last picked color
	dlg.red = red;
	dlg.green = green;
	dlg.blue = blue;

	if (dlg.DoModal() == IDOK)
	{
		red = dlg.red;
		green = dlg.green;
		blue = dlg.blue;

		Invalidate();
		UpdateWindow();
	}
}
