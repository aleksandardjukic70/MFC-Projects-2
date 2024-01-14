#pragma once
#include "afxdialogex.h"


// CData dialog

class CData : public CDialog
{
	DECLARE_DYNAMIC(CData)

public:
	CData(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CData();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	// Persons name
	CString m_name;
	// Persons age
	int m_age;
	// Persons height
	double m_height;
	// Persons ID
	int m_ID;
	// Persons info
	CString m_info;
	afx_msg void OnBnClickedButton1();
	// Persons details sum
	CString m_details;
	afx_msg void OnBnClickedButtonPersonDetails();
};
