
// SDIbrowser.h : SDIbrowser Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CSDIbrowserApp:
// �йش����ʵ�֣������ SDIbrowser.cpp
//

class CSDIbrowserApp : public CWinApp
{
public:
	CSDIbrowserApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSDIbrowserApp theApp;
