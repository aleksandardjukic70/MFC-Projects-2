#include <afxwin.h> // MFC core and standard components


// Class for the application object
// It needs to inherit the CWinApp
class SmallestWinApp : public CWinApp
{

public: 
	// Init function that starts before main function
	BOOL InitInstance();
};
// Application object 
// The application object is created globally so it will be created
// before the programs main() function is called

SmallestWinApp g_theApplication;

// Instancing the init function
BOOL SmallestWinApp::InitInstance()
{
	CWinApp::InitInstance();

	// Creating the object for main window
	m_pMainWnd = new CFrameWnd;
	// Creating the main window itself
	dynamic_cast<CFrameWnd*>(m_pMainWnd)->Create(NULL, _T("Smallest MFC APP"));
	// Displaying the main Window
	m_pMainWnd->ShowWindow(SW_SHOW);

	return TRUE;
}