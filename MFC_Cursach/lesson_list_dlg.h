#pragma once
#include "afxcmn.h"


// ���������� ���� lesson_list_dlg

class lesson_list_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(lesson_list_dlg)

public:
	lesson_list_dlg(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~lesson_list_dlg();

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LESSONS_LIST_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl lesson_list;
};
