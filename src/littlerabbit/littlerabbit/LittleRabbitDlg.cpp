// LittleRabbitDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LittleRabbit.h"
#include "LittleRabbitDlg.h"
#include <Gdiplus.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CLittleRabbitDlg �Ի���




CLittleRabbitDlg::CLittleRabbitDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLittleRabbitDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_LITRABBIT);
}

void CLittleRabbitDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLittleRabbitDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_DESTROY()

	ON_WM_NCPAINT()
	ON_BN_CLICKED(IDOK, &CLittleRabbitDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CLittleRabbitDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CLittleRabbitDlg ��Ϣ�������

BOOL CLittleRabbitDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	NotifyIconInit();
	
	mcstr = _T("123");

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CLittleRabbitDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CLittleRabbitDlg::OnPaint()
{
	CPaintDC dc(this); // ���ڻ��Ƶ��豸������
	if (IsIconic())
	{


		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		//dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
	CString str("etwewtwetwe");
	dc.TextOut(10,10,mcstr);
	dc.DrawIcon(30, 30, m_hIcon);
}

void CLittleRabbitDlg::OnNcPaint()
{
	CWindowDC dc(this);
	if ( GetSafeHwnd() == NULL ) return;
	CRect rtWnd, rtTitle, rtButtons;
	GetWindowRect(&rtWnd); 
	//������߿�
	CPoint point;
	point.x = 20;
	point.y = rtWnd.Height();
	dc.FillSolidRect(0, 23, point.x, point.y, RGB(10,10,10));

	dc.SetBkColor((DWORD)(0x10505050));
	dc.SetTextColor(RGB(0, 0, 255));
	CString str("etwewtwetwe");
	dc.TextOut(0,0,mcstr);

}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CLittleRabbitDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CLittleRabbitDlg::OnDestroy()
{
	CDialog::OnDestroy();
	NotifyRealse();
}

void CLittleRabbitDlg::NotifyIconInit()
{
	/* ����ͼ��ĳ�ʼ������ ************************************************************************/
	//��ʼ�� m_NotifyIconData �ڴ�ռ�
	memset(&m_NotifyIconData, 0, sizeof(NOTIFYICONDATA));
	//ʹ������ͼ���Ӧ�ڱ�����,����������԰�����ͼ����¼����͸��������
	m_NotifyIconData.hWnd = GetSafeHwnd();
	ASSERT(m_NotifyIconData.hWnd != NULL);
	//������ͼ������¼�ʱ�򷢳����¼�
	m_NotifyIconData.uCallbackMessage = WM_NOTI;
	//���ṹ��Ĵ�С
	m_NotifyIconData.cbSize = sizeof(NOTIFYICONDATA);
	//��������ͼ��(������Ĭ�ϵ���Դͼ��)
	m_NotifyIconData.hIcon = AfxGetApp()->LoadIcon(IDI_LITRABBIT);
	//��������ƶ�������ͼ��ʱ�����ʾ����
	memcpy (m_NotifyIconData.szTip,L"С����",sizeof(L"С����"));
	//��������ͼ�������
	m_NotifyIconData.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	//��������ͼ���ͼ����Դ ID
	m_NotifyIconData.uID = IDR_MAINFRAME;

	/* ��ʾ����ͼ�� *********************************************************************************/
	Shell_NotifyIcon(NIM_ADD, &m_NotifyIconData);
}

void CLittleRabbitDlg::NotifyRealse()
{
	Shell_NotifyIcon(NIM_DELETE, &m_NotifyIconData);
}
void CLittleRabbitDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//OnOK();
	mcstr = _T("OK");
	Invalidate();
}

void CLittleRabbitDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//OnCancel();
	mcstr = _T("Cancel");
	Invalidate();
}
