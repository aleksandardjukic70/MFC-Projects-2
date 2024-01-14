
// DlgLessonView.h : interface of the CDlgLessonView class
//

#pragma once


class CDlgLessonView : public CView
{
protected: // create from serialization only
	CDlgLessonView() noexcept;
	DECLARE_DYNCREATE(CDlgLessonView)

// Attributes
public:
	CDlgLessonDoc* GetDocument() const;

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
	virtual ~CDlgLessonView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDialogLaunchdialog();

private:
	// Variables that enable us to output information into LessonView (white area of our program)
	// *Note* 
	// In production setting this should go into DlgLessonDoc.h, 
	// it is wrong to do it this way, but for PRIVATE practice example it is acceptable 
	// in order to save time

	// Persons name
	CString m_name;
	// Persons age
	int m_age{0};
	// Persons height
	double m_height{0};
	// Persons ID
	int m_ID{0};
	// Persons info
	CString m_info;
};

#ifndef _DEBUG  // debug version in DlgLessonView.cpp
inline CDlgLessonDoc* CDlgLessonView::GetDocument() const
   { return reinterpret_cast<CDlgLessonDoc*>(m_pDocument); }
#endif

