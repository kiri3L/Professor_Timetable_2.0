
// MFC_Cursach.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������
#include "ExLab.h"
#include "data.hpp"


// CMFC_CursachApp:
// � ���������� ������� ������ ��. MFC_Cursach.cpp
//

class Professor_timetableApp : public CWinApp
{
public:
	Professor_timetableApp();
	Excel::_ApplicationPtr pApp;//������ ���������� ���������� ��� � ������ ����
	Data* data;
	CString MergeName;

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern Professor_timetableApp theApp;
