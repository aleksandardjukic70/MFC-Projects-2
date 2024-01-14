
// ButtonsView.h : interface of the CButtonsView class
//

#pragma once

// Definišemo ID dugmeta kao unssigned int, IDC - konvencija imenovanja u MFC-u, {neka vrednost}
constexpr UINT IDC_BUTTON1{101};

class CButtonsView : public CView
{
protected: // create from serialization only
	CButtonsView() noexcept;
	DECLARE_DYNCREATE(CButtonsView)

// Attributes
public:
	CButtonsDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CButtonsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions (message handlers)
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	// Message handler za našu funkciju iz ButtonsView.cpp/MESSAGE MAP sekcije
	afx_msg void OnButton1Clicked();
	DECLARE_MESSAGE_MAP()

private:
	CButton m_button;

	// bool za promenu background boje na pritisak dugmeta (Koristimo pDC pointer za crtanje u View.cpp)
	bool m_redBackCol{false};

	// bool za button follow cursor (false - button isnt following the cursor)
	bool m_followMouse{};

	// Funkcija zbog koje će *Ovaj View da pomera dugme 
	void MoveButton(CPoint point, bool buttonCoordinate = false);

	friend LRESULT CALLBACK ButtonProcedure(HWND hWnd, UINT uMsg, WPARAM wParam,
		LPARAM lParam, UINT_PTR uIdSubClass, DWORD_PTR dwRefData);


public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnButtonMove();
};

#ifndef _DEBUG  // debug version in ButtonsView.cpp
inline CButtonsDoc* CButtonsView::GetDocument() const
   { return reinterpret_cast<CButtonsDoc*>(m_pDocument); }
#endif

