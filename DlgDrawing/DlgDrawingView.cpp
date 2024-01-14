
// DlgDrawingView.cpp : implementation of the CDlgDrawingView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "DlgDrawing.h"
#endif

#include "DlgDrawingDoc.h"
#include "DlgDrawingView.h"
#include "CData.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDlgDrawingView

IMPLEMENT_DYNCREATE(CDlgDrawingView, CView)

BEGIN_MESSAGE_MAP(CDlgDrawingView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDlgDrawingView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(IDD_DIALOG_DRAW, &CDlgDrawingView::OnDialogDraw)
END_MESSAGE_MAP()

// CDlgDrawingView construction/destruction

CDlgDrawingView::CDlgDrawingView() noexcept
{
	// TODO: add construction code here

}

CDlgDrawingView::~CDlgDrawingView()
{
}

BOOL CDlgDrawingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CDlgDrawingView drawing

void CDlgDrawingView::OnDraw(CDC* /*pDC*/)
{
	CDlgDrawingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CDlgDrawingView printing


void CDlgDrawingView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDlgDrawingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDlgDrawingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDlgDrawingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CDlgDrawingView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDlgDrawingView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDlgDrawingView diagnostics

#ifdef _DEBUG
void CDlgDrawingView::AssertValid() const
{
	CView::AssertValid();
}

void CDlgDrawingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDlgDrawingDoc* CDlgDrawingView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDlgDrawingDoc)));
	return (CDlgDrawingDoc*)m_pDocument;
}
#endif //_DEBUG


// CDlgDrawingView message handlers


void CDlgDrawingView::OnDialogDraw()
{
	// TODO: Add your command handler code here
	CData dlgDrawing;
	dlgDrawing.DoModal();
}
