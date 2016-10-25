
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "SDIbrowser.h"
#include "SDIbrowserView.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(IDOK, OnNew)     //�Լ�����Ϣӳ��꣺��ON_COMMAND�����IDOK��Ϣ�ʹ�����OnNew��ӳ���ϵ

END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO:  �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT | TBSTYLE_TRANSPARENT) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}
	if (!m_wndDlgBar.Create(this, IDR_MAINFRAME, CBRS_ALIGN_TOP, AFX_IDW_DIALOGBAR))
	{
		TRACE0("δ�ܴ����Ի���\n");
		return -1;		// δ�ܴ���
	}

	if (!m_wndReBar.Create(this) || !m_wndReBar.AddBar(&m_wndToolBar) || !m_wndReBar.AddBar(&m_wndDlgBar))
	{
		TRACE0("δ�ܴ��� Rebar\n");
		return -1;      // δ�ܴ���
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO:  �������Ҫ������ʾ���򽫴��Ƴ�
	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() | CBRS_TOOLTIPS | CBRS_FLYBY);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return TRUE;
}

// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame ��Ϣ�������

//�����ַ���س�ʱ �򸸴��ڷ���IDOK��Ϣ������ô˺���---��ȡ��ַ��ת��
void  CMainFrame::OnNew()
{
	CString  pp;//����û��ڵ�ַ���������URL

	//m_wndDlgBar�Ǵ����ַ���ı������ڵĶԻ������ؼ��ĳ�Ա��������������Ӧ�ó����ܵ�ʱ���Զ�������
	m_wndDlgBar.GetDlgItem(IDC_ADDR)->GetWindowText(pp);
	//���ָ������ҳ
	((CSDIbrowserView*)GetActiveView())->Navigate(pp);
}


//������������ʱ��ַ����ͬ������
void CMainFrame::SetPage(LPCTSTR lpszURL)
{
	m_wndDlgBar.GetDlgItem(IDC_ADDR)->SetWindowText(lpszURL);
}
