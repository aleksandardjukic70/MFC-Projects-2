
// DlgLessonView.cpp : implementation of the CDlgLessonView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "DlgLesson.h"
#endif

#include "DlgLessonDoc.h"
#include "DlgLessonView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "CData.h"


// CDlgLessonView

IMPLEMENT_DYNCREATE(CDlgLessonView, CView)

BEGIN_MESSAGE_MAP(CDlgLessonView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDlgLessonView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_DIALOG_LAUNCHDIALOG, &CDlgLessonView::OnDialogLaunchdialog)
END_MESSAGE_MAP()

// CDlgLessonView construction/destruction

CDlgLessonView::CDlgLessonView() noexcept
{
	// TODO: add construction code here

}

CDlgLessonView::~CDlgLessonView()
{
}

BOOL CDlgLessonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CDlgLessonView drawing

void CDlgLessonView::OnDraw(CDC* pDC)
{
	CDlgLessonDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CString strPrint;
	strPrint.Format(
		_T("Name: %s, Age: %d, Height: %.2f, ID: %d, Info: %s"),
		m_name, m_age, m_height, m_ID, m_info);

	// Printing text to the View
	pDC->TextOutW(10, 10, strPrint);
}


// CDlgLessonView printing


void CDlgLessonView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDlgLessonView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDlgLessonView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDlgLessonView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CDlgLessonView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDlgLessonView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDlgLessonView diagnostics

#ifdef _DEBUG
void CDlgLessonView::AssertValid() const
{
	CView::AssertValid();
}

void CDlgLessonView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDlgLessonDoc* CDlgLessonView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDlgLessonDoc)));
	return (CDlgLessonDoc*)m_pDocument;
}
#endif //_DEBUG


// CDlgLessonView message handlers


void CDlgLessonView::OnDialogLaunchdialog()
{
	CData dialog;

	// Initialising the dialog variables
	dialog.m_name = m_name;
	dialog.m_age = m_age;
	dialog.m_height = m_height;
	dialog.m_ID = m_ID;
	dialog.m_info = m_info;


	// If user press OK (IDOK) from the dialog box 
	// values from dialog variables are saved to variables from the View
	if (dialog.DoModal() == IDOK)
	{
		m_name		= dialog.m_name;
		m_age		= dialog.m_age;
		m_height	= dialog.m_height;
		m_ID		= dialog.m_ID;
		m_info		= dialog.m_info;
	}

	// Updating the View
	Invalidate();
	UpdateWindow();
}
