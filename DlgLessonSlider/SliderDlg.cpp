// SliderDlg.cpp : implementation file
//

#include "pch.h"
#include "DlgLessonSlider.h"
#include "afxdialogex.h"
#include "SliderDlg.h"


// SliderDlg dialog

IMPLEMENT_DYNAMIC(SliderDlg, CDialog)

SliderDlg::SliderDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_SLIDER, pParent)
{

}

SliderDlg::~SliderDlg()
{
}

void SliderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER_RED, m_sliderRed);
	DDX_Control(pDX, IDC_SLIDER_GREEN, m_sliderGreen);
	DDX_Control(pDX, IDC_SLIDER_BLUE, m_sliderBlue);
	DDX_Control(pDX, IDC_STATIC_COLOR, m_staticColor);
}


BEGIN_MESSAGE_MAP(SliderDlg, CDialog)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDOK, &SliderDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// SliderDlg message handlers

// Helper function to update to color of the window (static text)
void SliderDlg::UpdateColorStaticCtrl()
{
	// Passing values from slider position into color variables
	m_staticColor.red = m_sliderRed.GetPos();
	m_staticColor.green = m_sliderGreen.GetPos();
	m_staticColor.blue = m_sliderBlue.GetPos();
	
	// Updating the window
	m_staticColor.ReDraw();
}



void SliderDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// Updating the window color when slider position changes
	UpdateColorStaticCtrl();

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}


BOOL SliderDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Setting the range in which sliders will operate
	m_sliderRed.SetRange(0, 255);
	m_sliderBlue.SetRange(0, 255);
	m_sliderGreen.SetRange(0, 255);

	// Setting positions of the sliders according to values from View variables (red, green, blue)
	m_sliderRed.SetPos(red);
	m_sliderGreen.SetPos(green);
	m_sliderBlue.SetPos(blue);

	// Updating the window color on dialog init
	UpdateColorStaticCtrl();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void SliderDlg::OnBnClickedOk()
{
	// Storing the slider values into variables for the View
	red = m_sliderRed.GetPos();
	green = m_sliderGreen.GetPos();
	blue = m_sliderBlue.GetPos();

	CDialog::OnOK();
}
