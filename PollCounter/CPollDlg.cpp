// CPollDlg.cpp : implementation file
//

#include "pch.h"
#include "PollCounter.h"
#include "afxdialogex.h"
#include "CPollDlg.h"


// CPollDlg dialog

IMPLEMENT_DYNAMIC(CPollDlg, CDialog)


CPollDlg::CPollDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_RADIO_BUTTON, pParent)
	// setting default values for radio button groups here
	// (value 0 means HEAD button, value 1 means 2nd button, 
	// value 2 means 3rd button, and so on..)
	// 
	// In our case we are using constants instead of numbers
	// Hence: 
	// JOIN_POLL_LATER for value of 1 in m_pollOptions group
	// LIKES_CATS for value of 0 in m_likesCatsDog group
	, m_pollOptions(JOIN_POLL_LATER)
	, m_likesCatsDogs(LIKES_CATS)
{

}

CPollDlg::~CPollDlg()
{
}

void CPollDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO_POLL_NO, m_pollOptions);
	DDX_Radio(pDX, IDC_RADIO_LIKES_CATS, m_likesCatsDogs);
	DDX_Control(pDX, IDC_RADIO_LIKES_CATS, m_ctrlCats);
	DDX_Control(pDX, IDC_RADIO_LIKES_DOGS, m_ctrlDogs);
	DDX_Control(pDX, IDC_STATIC_CATS_DOGS, m_ctrlCatsDogs);
}


BEGIN_MESSAGE_MAP(CPollDlg, CDialog)
	ON_BN_CLICKED(IDC_RADIO_POLL_NO, &CPollDlg::OnBnClickedRadioPollNo)
	ON_BN_CLICKED(IDC_RADIO_POLL_LATER, &CPollDlg::OnBnClickedRadioPollLater)
	ON_BN_CLICKED(IDC_RADIO_POLL_YES, &CPollDlg::OnBnClickedRadioPollYes)
END_MESSAGE_MAP()


// CPollDlg message handlers

// Func implementation for showing and hidding group and radio buttons for cats and dogs
void CPollDlg::ShowCatsDogsGroup(bool show)
{
	// if show is true -> return SW_SHOW and store into cmdShow
	// if show is false -> return SW_HIDE and store into cmdShow
	int cmdShow = show ? SW_SHOW : SW_HIDE;

	// Shows Hidden group and radio buttons 
	// (m_ctrlCatsDogs, m_ctrlCats, m_ctrlDogs)
	m_ctrlCatsDogs.ShowWindow(cmdShow);
	m_ctrlCats.ShowWindow(cmdShow);
	m_ctrlDogs.ShowWindow(cmdShow);
}


void CPollDlg::OnBnClickedRadioPollNo()
{
	ShowCatsDogsGroup(false);
}


void CPollDlg::OnBnClickedRadioPollLater()
{
	ShowCatsDogsGroup(false);
}


void CPollDlg::OnBnClickedRadioPollYes()
{
	ShowCatsDogsGroup(true);
}


BOOL CPollDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	
	// if (m_pollOptions == JOIN_POLL_YES) -> Show cats and dogs group in dialog
	// else -> Hide cats and dogs group in dialog
	ShowCatsDogsGroup(m_pollOptions == JOIN_POLL_YES);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
