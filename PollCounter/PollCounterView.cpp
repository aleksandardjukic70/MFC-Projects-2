
// PollCounterView.cpp : implementation of the CPollCounterView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "PollCounter.h"
#endif

#include "PollCounterDoc.h"
#include "PollCounterView.h"
#include "CPollDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPollCounterView

IMPLEMENT_DYNCREATE(CPollCounterView, CView)

BEGIN_MESSAGE_MAP(CPollCounterView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPollCounterView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_ACTION_POLL, &CPollCounterView::OnActionPoll)
END_MESSAGE_MAP()

// CPollCounterView construction/destruction

CPollCounterView::CPollCounterView() noexcept
{
	// TODO: add construction code here

}

CPollCounterView::~CPollCounterView()
{
}

BOOL CPollCounterView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CPollCounterView drawing

void CPollCounterView::OnDraw(CDC* pDC)
{
	CPollCounterDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

	// Printing strText object into the View
	CString strText;
	strText = _T("Poll result so far");
	pDC->TextOutW(10, 20, strText);
	strText.Format(_T("Cats: %d, Dogs: %d"), m_catCount, m_dogCount);
	pDC->TextOutW(10, 50, strText);
}


// CPollCounterView printing


void CPollCounterView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPollCounterView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPollCounterView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPollCounterView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CPollCounterView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPollCounterView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPollCounterView diagnostics

#ifdef _DEBUG
void CPollCounterView::AssertValid() const
{
	CView::AssertValid();
}

void CPollCounterView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPollCounterDoc* CPollCounterView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPollCounterDoc)));
	return (CPollCounterDoc*)m_pDocument;
}
#endif //_DEBUG


// CPollCounterView message handlers


void CPollCounterView::OnActionPoll()
{
	CPollDlg dlgPoll;

	// if Okay is pressed program goes inside if statement
	if (dlgPoll.DoModal() == IDOK)
	{
		// if m_pollOptions == JOIN_POLL_YES -> we add the counter
		if (dlgPoll.m_pollOptions == JOIN_POLL_YES)
		{
			// if m_likesCatsDogs == LIKES_CATS -> increase cat counter
			if (dlgPoll.m_likesCatsDogs == LIKES_CATS)
				++m_catCount;
			// else -> increase dog counter
			else
				++m_dogCount;
			// Whole screen needs "repainting" (refresh)
			Invalidate();
			// "Repainting" (refreshing) the screen
			UpdateWindow();
		}
	}
}
