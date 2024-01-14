// CData.cpp : implementation file
//

#include "pch.h"
#include "DlgLesson.h"
#include "afxdialogex.h"
#include "CData.h"


// CData dialog

IMPLEMENT_DYNAMIC(CData, CDialog)

CData::CData(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG, pParent)
	, m_name(_T("John Doe"))
	, m_age(0)
	, m_height(0)
	, m_ID(5)
	, m_info(_T(""))
	, m_details(_T(""))
{

}

CData::~CData()
{
}

void CData::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDX_Text(pDX, IDC_EDIT_AGE, m_age);
	DDV_MinMaxInt(pDX, m_age, 0, 1000);
	DDX_Text(pDX, IDC_EDIT_HEIGHT, m_height);
	DDX_Text(pDX, IDC_EDIT_ID, m_ID);
	DDV_MinMaxInt(pDX, m_ID, 0, 10000);
	DDX_Text(pDX, IDC_EDIT_PERSON_INFO, m_info);
	DDX_Text(pDX, IDC_EDIT_DETAILS, m_details);
}


BEGIN_MESSAGE_MAP(CData, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_PERSON_DETAILS, &CData::OnBnClickedButtonPersonDetails)
END_MESSAGE_MAP()


// CData message handlers


void CData::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
}


void CData::OnBnClickedButtonPersonDetails()
{
	// Changing the text inside of m_ details text box on button press

	// UpdateData(TRUE) takes values from text boxes 
	// and it puts them in variables (m_name, m_age, m_height) 
	// defined in 'm_details.Format' (m
	UpdateData(TRUE);
	m_details.Format(
		_T("Name: %s, Age: %d, Height: %.2f, \r\n"
		"It is nice to learn to program using MFC.\r\n"
		"It is nice to learn to program using MFC.\r\n"
		"It is nice to learn.\r\n"
		"It is nice to learn to program using MFC.\r\n"
		"It is.\r\n"
		"It is nice to learn to program.\r\n"
		"It is nice to learn to program using MFC.\r\n"

		),
		m_name, m_age, m_height);
	
	// UpdateData(FALSE) takes updated values from above 'm_details.Format' and outputs them into 
	// designated text box (m_details)
	UpdateData(FALSE);
}
