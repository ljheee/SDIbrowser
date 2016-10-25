
// SDIbrowserView.h : CSDIbrowserView ��Ľӿ�
//
#include "SDIbrowserDoc.h"


#pragma once


class CSDIbrowserView : public CHtmlView
{
protected: // �������л�����
	CSDIbrowserView();
	DECLARE_DYNCREATE(CSDIbrowserView)

// ����
public:
	CSDIbrowserDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CSDIbrowserView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFoward();
	afx_msg void OnBack();
	afx_msg void OnStop();
	afx_msg void OnUpdate();
	afx_msg void OnHomepage();
	afx_msg void OnSearch();
	virtual void OnDocumentComplete(LPCTSTR lpszURL);
};

#ifndef _DEBUG  // SDIbrowserView.cpp �еĵ��԰汾
inline CSDIbrowserDoc* CSDIbrowserView::GetDocument() const
   { return reinterpret_cast<CSDIbrowserDoc*>(m_pDocument); }
#endif

