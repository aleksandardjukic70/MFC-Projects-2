#pragma once
#include "afxdialogex.h"


// CPollDlg dialog

// *Note*
// Radio Buttons are always in groups, 
// group of one or group of many, 
// but its always group!

// Constants for radio button default values
const int JOIN_POLL_NO{ 0 };
const int JOIN_POLL_LATER{ 1 };
const int JOIN_POLL_YES{ 2 };

const int LIKES_CATS{ 0 };
const int LIKES_DOGS{ 1 };

class CPollDlg : public CDialog
{
	DECLARE_DYNAMIC(CPollDlg)

public:
	CPollDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CPollDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_RADIO_BUTTON };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

private:
	// Func for showing and hidding group and radio buttons for cats and dogs
	void ShowCatsDogsGroup(bool show);

public:

	// We instance variable for the HEAD (1st) radio button in the group
	// We dont initialise variables for the rest of the buttons
	// because when 1st (HEAD) button is selected, it gets value 0 
	// and for the rest its just ++ 
	// (value 1 means 2nd button, value 2 means 3rd button, and so on..) 
	// 
	// Example:
	// m_pollOptions = 0 -> poll button No is selected
	// m_pollOptions = 1 -> poll button Maybe is selected
	// m_pollOptions = 2 -> poll button Yes is selected
	
	// Poll Button No 
	int m_pollOptions;
	// Likes Cats Button
	int m_likesCatsDogs;
	afx_msg void OnBnClickedRadioPollNo();
	afx_msg void OnBnClickedRadioPollLater();
	afx_msg void OnBnClickedRadioPollYes();
	
	// Cats radio button
	CButton m_ctrlCats;
	// Dogs radio button
	CButton m_ctrlDogs;
	// Cats and dogs buttons group
	CStatic m_ctrlCatsDogs;
	virtual BOOL OnInitDialog();
};
