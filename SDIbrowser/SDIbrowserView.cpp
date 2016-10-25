
// SDIbrowserView.cpp : CSDIbrowserView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "SDIbrowser.h"
#endif

#include "SDIbrowserDoc.h"
#include "SDIbrowserView.h"
#include "MainFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSDIbrowserView

IMPLEMENT_DYNCREATE(CSDIbrowserView, CHtmlView)

BEGIN_MESSAGE_MAP(CSDIbrowserView, CHtmlView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CHtmlView::OnFilePrint)
	ON_COMMAND(ID_FOWARD, &CSDIbrowserView::OnFoward)
	ON_COMMAND(ID_BACK, &CSDIbrowserView::OnBack)
	ON_COMMAND(ID_STOP, &CSDIbrowserView::OnStop)
	ON_COMMAND(ID_UPDATE, &CSDIbrowserView::OnUpdate)
	ON_COMMAND(ID_HOMEPAGE, &CSDIbrowserView::OnHomepage)
	ON_COMMAND(ID_SEARCH, &CSDIbrowserView::OnSearch)
END_MESSAGE_MAP()

// CSDIbrowserView 构造/析构

CSDIbrowserView::CSDIbrowserView()
{
	// TODO:  在此处添加构造代码

}

CSDIbrowserView::~CSDIbrowserView()
{
}

BOOL CSDIbrowserView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CHtmlView::PreCreateWindow(cs);
}

void CSDIbrowserView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	Navigate2(_T("http://www.baidu.com/"),NULL,NULL);
}


// CSDIbrowserView 打印



// CSDIbrowserView 诊断

#ifdef _DEBUG
void CSDIbrowserView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CSDIbrowserView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CSDIbrowserDoc* CSDIbrowserView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDIbrowserDoc)));
	return (CSDIbrowserDoc*)m_pDocument;
}
#endif //_DEBUG


// CSDIbrowserView 消息处理程序

//前进
void CSDIbrowserView::OnFoward()
{
	// TODO:  在此添加命令处理程序代码
	GoForward();
}

//后退
void CSDIbrowserView::OnBack()
{
	// TODO:  在此添加命令处理程序代码
	GoBack();
}

//停止
void CSDIbrowserView::OnStop()
{
	// TODO:  在此添加命令处理程序代码
	Stop();
}

//刷新
void CSDIbrowserView::OnUpdate()
{
	// TODO:  在此添加命令处理程序代码
	Refresh();
}


void CSDIbrowserView::OnHomepage()
{
	// TODO:  在此添加命令处理程序代码
	GoHome();
}

//搜索
void CSDIbrowserView::OnSearch()
{
	// TODO:  在此添加命令处理程序代码
	GoSearch();
}

//当点击超链接网页下载完成后，会触发OnDocumentComplete()函数，该函数的参数就是所下载网页的URL
void CSDIbrowserView::OnDocumentComplete(LPCTSTR lpszURL)
{
	// TODO:  在此添加专用代码和/或调用基类
	((CMainFrame*)GetParentFrame())->SetPage(lpszURL);


//	CHtmlView::OnDocumentComplete(lpszURL);
}
