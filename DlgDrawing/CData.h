#pragma once
#include "afxdialogex.h"
#include "ColorStaticCtrl.h"


// CData dialog

class CData : public CDialog
{
	DECLARE_DYNAMIC(CData)

public:
	CData(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CData();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DRAW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	// The control means the window
	// This is window object
	ColorStaticCtrl m_staticDraw;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};
