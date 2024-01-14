
// PollCounterView.h : interface of the CPollCounterView class
//

#pragma once


class CPollCounterView : public CView
{
protected: // create from serialization only
	CPollCounterView() noexcept;
	DECLARE_DYNCREATE(CPollCounterView)

// Attributes
public:
	CPollCounterDoc* GetDocument() const;

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
	virtual ~CPollCounterView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

private:
	// Initializing variables for counting votes 
	int m_catCount{ 0 };
	int m_dogCount{ 0 };

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnActionPoll();
};

#ifndef _DEBUG  // debug version in PollCounterView.cpp
inline CPollCounterDoc* CPollCounterView::GetDocument() const
   { return reinterpret_cast<CPollCounterDoc*>(m_pDocument); }
#endif

