
// SDIbrowserView.h : CSDIbrowserView 类的接口
//
#include "SDIbrowserDoc.h"


#pragma once


class CSDIbrowserView : public CHtmlView
{
protected: // 仅从序列化创建
	CSDIbrowserView();
	DECLARE_DYNCREATE(CSDIbrowserView)

// 特性
public:
	CSDIbrowserDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CSDIbrowserView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // SDIbrowserView.cpp 中的调试版本
inline CSDIbrowserDoc* CSDIbrowserView::GetDocument() const
   { return reinterpret_cast<CSDIbrowserDoc*>(m_pDocument); }
#endif

