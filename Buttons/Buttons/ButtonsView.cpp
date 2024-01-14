
// ButtonsView.cpp : implementation of the CButtonsView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Buttons.h"
#endif

#include "ButtonsDoc.h"
#include "ButtonsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CButtonsView

IMPLEMENT_DYNCREATE(CButtonsView, CView)

BEGIN_MESSAGE_MAP(CButtonsView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CButtonsView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	// Ukazujemo MFC-u šta želimo da se desi kada se dugme pritisne
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1Clicked)

	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_BUTTON_MOVE, &CButtonsView::OnButtonMove)
END_MESSAGE_MAP()

// CButtonsView construction/destruction

CButtonsView::CButtonsView() noexcept
{
	// TODO: add construction code here

}

CButtonsView::~CButtonsView()
{
}

BOOL CButtonsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CButtonsView drawing

void CButtonsView::OnDraw(CDC* pDC)
{
	CButtonsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// rectangle of the white area of the window
	CRect rectClient;
	// selecting that white area
	GetClientRect(rectClient);
	// if true, rectangle area prelazi iz bele u crvenu boju
	if (m_redBackCol)
		pDC->FillSolidRect(rectClient, RGB(255, 0, 0));
}


// CButtonsView printing


void CButtonsView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CButtonsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CButtonsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CButtonsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing

}

void CButtonsView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CButtonsView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CButtonsView diagnostics

#ifdef _DEBUG
void CButtonsView::AssertValid() const
{
	CView::AssertValid();
}

void CButtonsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CButtonsDoc* CButtonsView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CButtonsDoc)));
	return (CButtonsDoc*)m_pDocument;
}
#endif //_DEBUG


// CButtonsView message handlers

// FUNCTION FOR CENTERING BUTTON ON THE CURSOR
// This is GLOBAL function, it is not the member of this class, we dont have to include it in header file,
// but we will make it "friend" of CButtonsView class in the header file 
// becuase we need access to private function MoveButton()
LRESULT CALLBACK ButtonProcedure(HWND hWnd, UINT uMsg, WPARAM wParam,
	LPARAM lParam, UINT_PTR uIdSubClass, DWORD_PTR dwRefData)
{	//LPARAM - contains coordinates cursor coordinates

	// Konvertujemo dwRefData vrednost (int?) da bi mogli da je prosledimo (ubacimo) u CButtonsView pointer
	CButtonsView* view = reinterpret_cast<CButtonsView*>(dwRefData);

	switch (uMsg)
	{
	case WM_MOUSEMOVE:
		// Kada dugme ustanovi da se kursor pomera u njemu (unutar njegovih granica(dugmeta)), 
		// traži od CButtonsView-a da ga pomeri(dugme) iz raloga jer se kursor pomerio u njemu(dugmetu) 
		// i onda je dugmetu potrebno da ga CButtonsView pomeri
		// da bi cursor mogao da bude u sredini dugmeta (da bi se dugme centriralo na kursor)
		view->MoveButton(CPoint{ GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam)}, true);
								 // Tražimo od LPARAM da nam prosledi koordinate kursora
		return TRUE;
	}
	return DefSubclassProc(hWnd, uMsg, wParam, lParam);
}


int CButtonsView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	// This creates the View
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// Creating the button(text, tip dugmeta,
	// koordinate dimenzija dugmeta(left, top, bottom, right), parent window, ID dugmeta)
	m_button.Create(_T("To Red"), BS_PUSHBUTTON, 
		CRect(300, 100, 380, 150), this, IDC_BUTTON1);

	// Making the button to center itself on the cursor (While button is following the cursor)
	SetWindowSubclass(m_button, ButtonProcedure, 0, reinterpret_cast<DWORD_PTR>(this));
												// Moramo da konvertujemo int vrednost CButtonsView-a (this)
											    // da bi mogli da je prosledimo (ubacimo) u DWORD_PTR (pointer)  
												 
	// We tell  button to show itself (ShowWindow shows any window)
	m_button.ShowWindow(SW_SHOW);

	return 0;
}

// Kreiramo funkciju za našu mapu (CbuttonsView:: - znači da je naša funkcija član ove klase
void CButtonsView::OnButton1Clicked()
{
	// Dok je uključena funkcija OnButtonMove, dugme prati kursor i ne možemo da menjamo boju pozadine
	// m_followMouse - true, ako je true prebacice se na false, OnButtonMove se gasi i dugme ne prati cursor
	if (m_followMouse)
	{
		// Kada pritisnemo dugme, dugme prestaje da prati kursor
		// Tj. prekida se funkcija OnButtonMove (dugme sa crvenim M u toolbaru)
		m_followMouse = false;
	}
	else // m_followMouse - false, ako je false, možemo da promenimo boju pozadine na pritisak dugmeta
	{
		m_redBackCol = !m_redBackCol;
		// if true window are to white, else window area to red
		if (m_redBackCol)
			m_button.SetWindowTextW(L"To White");
		else
			m_button.SetWindowTextW(L"To Red");

		// Redrawing the window on update
		Invalidate();
		UpdateWindow();
	}
}


void CButtonsView::OnMouseMove(UINT nFlags, CPoint point)
{
	// Uslov m_followMouse - true
	if (m_followMouse)
	{
		MoveButton(point);
	}

	CView::OnMouseMove(nFlags, point);

}

// Funkcija zbog koje će *Ovaj View da pomera dugme 
// ?parametar central označava sredinu dugmeta?
void CButtonsView::MoveButton(CPoint central, bool buttonCoordinate)
											// Ako je buttonCoordinate true, 
											// onda je ovaj central parametar koordinata dugmeta
{
	// Ako je ugašena funkcija OnButtonMove (crveno M dugme), i dugme ne prati kursor, ovde se ništa ne dešava 
	if (!m_followMouse)
		return;
	
	// U ovom slučaju ključna reč 'else' nije neophodna zato što se u ovom kontekstu podrazumeva da će se kod 
	// ispod povratne naredbe (return;) izvršiti ako if uslov nije ispunjen
	
	// Getting the size of the button window
	CRect rectButton;

	// Getting screen cooridantes of the button 
	// (Ali ne koordinate unutar prozora programa(View area) već od CELOG EKRANA)
	m_button.GetWindowRect(rectButton);

	// Ovo transferuje koordinate celog ekrana(GetWindowRect) na prozor programa
	ScreenToClient(rectButton);

	// buttonCoordinate - true 
	// onda central vrednosti dodeljujemo vrednost gornjeg levog ugla dugmeta 
	//											(jer se po defaultu kursor fixira u gornji levi deo) 													
	if (buttonCoordinate)
		central += rectButton.TopLeft();

	// Ovo će pomeriti lokaciju dugmeta na lokaciju cursora 
	// ?Prva dva parametra služe kao koordinate za sam centar dugmeta?
	m_button.MoveWindow(central.x - rectButton.Width()/2, 
		central.y - rectButton.Height()/2, rectButton.Width(), rectButton.Height());

}

// Ovu Funkciju smo vezali za dugme sa crvenim M u toolbaru
void CButtonsView::OnButtonMove()
{
	// button follow cursor (true - button is following the cursor)
	m_followMouse = true;
}
