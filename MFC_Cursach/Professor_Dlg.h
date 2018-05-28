#pragma once
#include "afxcmn.h"


// ���������� ���� Professor_Dlg

class Professor_Dlg : public CDialog
{
	DECLARE_DYNAMIC(Professor_Dlg)

public:
	Professor_Dlg(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~Professor_Dlg();

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROFESSOR_LIST_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg
		BOOL OnInitDialog();
	void OnBnClickedBtnProfessorSelect();
	afx_msg void OnBnClickedBtnEditProfessorList();
	CListCtrl professor_list;
	afx_msg void OnNMClickListProfessor(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedBtnHelp();
};
