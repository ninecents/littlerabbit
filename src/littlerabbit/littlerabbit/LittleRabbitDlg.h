// LittleRabbitDlg.h : ͷ�ļ�
//

#pragma once


//��Ϣ����
#define WM_NOTI (WM_USER+1)

// CLittleRabbitDlg �Ի���
class CLittleRabbitDlg : public CDialog
{
// ����
public:
	CLittleRabbitDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LITTLERABBIT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	afx_msg void OnDestroy();
	afx_msg void OnNcPaint();
protected:
	NOTIFYICONDATA m_NotifyIconData;//����ͼ��
	void NotifyIconInit();
	void NotifyRealse();
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();

	CString mcstr;
};
