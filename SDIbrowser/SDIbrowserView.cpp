
// SDIbrowserView.cpp : CSDIbrowserView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CHtmlView::OnFilePrint)
	ON_COMMAND(ID_FOWARD, &CSDIbrowserView::OnFoward)
	ON_COMMAND(ID_BACK, &CSDIbrowserView::OnBack)
	ON_COMMAND(ID_STOP, &CSDIbrowserView::OnStop)
	ON_COMMAND(ID_UPDATE, &CSDIbrowserView::OnUpdate)
	ON_COMMAND(ID_HOMEPAGE, &CSDIbrowserView::OnHomepage)
	ON_COMMAND(ID_SEARCH, &CSDIbrowserView::OnSearch)
END_MESSAGE_MAP()

// CSDIbrowserView ����/����

CSDIbrowserView::CSDIbrowserView()
{
	// TODO:  �ڴ˴���ӹ������

}

CSDIbrowserView::~CSDIbrowserView()
{
}

BOOL CSDIbrowserView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CHtmlView::PreCreateWindow(cs);
}

void CSDIbrowserView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	Navigate2(_T("http://www.baidu.com/"),NULL,NULL);
}


// CSDIbrowserView ��ӡ



// CSDIbrowserView ���

#ifdef _DEBUG
void CSDIbrowserView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CSDIbrowserView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CSDIbrowserDoc* CSDIbrowserView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDIbrowserDoc)));
	return (CSDIbrowserDoc*)m_pDocument;
}
#endif //_DEBUG


// CSDIbrowserView ��Ϣ�������

//ǰ��
void CSDIbrowserView::OnFoward()
{
	// TODO:  �ڴ���������������
	GoForward();
}

//����
void CSDIbrowserView::OnBack()
{
	// TODO:  �ڴ���������������
	GoBack();
}

//ֹͣ
void CSDIbrowserView::OnStop()
{
	// TODO:  �ڴ���������������
	Stop();
}

//ˢ��
void CSDIbrowserView::OnUpdate()
{
	// TODO:  �ڴ���������������
	Refresh();
}


void CSDIbrowserView::OnHomepage()
{
	// TODO:  �ڴ���������������
	GoHome();
}

//����
void CSDIbrowserView::OnSearch()
{
	// TODO:  �ڴ���������������
	GoSearch();
}

//�������������ҳ������ɺ󣬻ᴥ��OnDocumentComplete()�������ú����Ĳ���������������ҳ��URL
void CSDIbrowserView::OnDocumentComplete(LPCTSTR lpszURL)
{
	// TODO:  �ڴ����ר�ô����/����û���
	((CMainFrame*)GetParentFrame())->SetPage(lpszURL);


//	CHtmlView::OnDocumentComplete(lpszURL);
}
