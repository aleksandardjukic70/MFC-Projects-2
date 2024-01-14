#pragma once


// ColorStaticCtrl
// This class inherits CStatic

class ColorStaticCtrl : public CStatic
{
	DECLARE_DYNAMIC(ColorStaticCtrl)

public:
	ColorStaticCtrl();
	virtual ~ColorStaticCtrl();

	int red, green, blue;
	CPoint point;
	
	void reDraw() 
	{
		Invalidate();
		UpdateWindow();
	}

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};


