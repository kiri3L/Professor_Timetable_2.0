
// MainDlg.h : ���� ���������
//

#pragma once
#include "afxcmn.h"



// ���������� ���� MainDlg
class MainDlg : public CDialogEx
{
// ��������
public:
	MainDlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_CURSACH_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnHelp();
	afx_msg void OnBnClickedBtnGetFileName();
	afx_msg void OnBnClickedBtnAddAllFiles();
	afx_msg void OnBnClickedBtnDelete();
	CListCtrl path_list;
};
