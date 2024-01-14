
// DlgLessonSliderView.h : interface of the CDlgLessonSliderView class
//

#pragma once


class CDlgLessonSliderView : public CView
{
protected: // create from serialization only
	CDlgLessonSliderView() noexcept;
	DECLARE_DYNCREATE(CDlgLessonSliderView)

// Attributes
public:
	CDlgLessonSliderDoc* GetDocument() const;

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
	virtual ~CDlgLessonSliderView();
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
	afx_msg void OnDialogLaunchdlg();

private: 
	int red{ 255 }, green{ 255 }, blue{ 255 };
};

#ifndef _DEBUG  // debug version in DlgLessonSliderView.cpp
inline CDlgLessonSliderDoc* CDlgLessonSliderView::GetDocument() const
   { return reinterpret_cast<CDlgLessonSliderDoc*>(m_pDocument); }
#endif

