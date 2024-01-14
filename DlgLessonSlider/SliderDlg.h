#pragma once
#include "afxdialogex.h"
#include "ColorStaticCtrl.h"


// SliderDlg dialog

class SliderDlg : public CDialog
{
	DECLARE_DYNAMIC(SliderDlg)

public:
	SliderDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~SliderDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SLIDER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int red{ 255 }, green{ 255 }, blue{ 255 };

	// Red color slider
	CSliderCtrl m_sliderRed;
	// Green color slider
	CSliderCtrl m_sliderGreen;
	// Blue color slider
	CSliderCtrl m_sliderBlue;
	// Static text field for displaying color from sliders
	ColorStaticCtrl m_staticColor;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

private:
	void UpdateColorStaticCtrl();
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
