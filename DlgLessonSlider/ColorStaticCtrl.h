#pragma once


// ColorStaticCtrl
// This class inherits CStatic
class ColorStaticCtrl : public CStatic
{
	DECLARE_DYNAMIC(ColorStaticCtrl)

public:
	ColorStaticCtrl();
	virtual ~ColorStaticCtrl();

	int red{ 255 }, green{ 0 }, blue{ 0 };

	void ReDraw()
	{
		// Window needs refresh
		Invalidate();
		// Refreshing the window
		UpdateWindow();
	}

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};


