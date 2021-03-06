
// MainDlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "Professor_timetable.h"
#include "MainDlg.h"
#include "afxdialogex.h"
#include "Professor_Dlg.h"
#include <string>
#include <vector>

//#include "ExcelReader.h"
//#include "ExLab.h"

#include "data.hpp"
#include "start.hpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� ���� CAboutDlg ������������ ��� �������� �������� � ����������

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

// ����������
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// ���������� ���� MainDlg



MainDlg::MainDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC_CURSACH_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_PATH, path_list);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_HELP, &MainDlg::OnBnClickedBtnHelp)
	ON_BN_CLICKED(IDC_BTN_GET_FILE_NAME, &MainDlg::OnBnClickedBtnGetFileName)
	ON_BN_CLICKED(IDC_BTN_ADD_ALL_FILES, &MainDlg::OnBnClickedBtnAddAllFiles)
	ON_BN_CLICKED(IDC_BTN_DELETE, &MainDlg::OnBnClickedBtnDelete)
END_MESSAGE_MAP()


// ����������� ��������� MainDlg

BOOL MainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���������� ������ "� ���������..." � ��������� ����.

	// IDM_ABOUTBOX ������ ���� � �������� ��������� �������.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ������ ������ ��� ����� ����������� ����.  ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	HRESULT hRes = E_FAIL;
	CoInitialize(NULL);
	hRes = theApp.pApp.CreateInstance("Excel.Application");
	if (FAILED(hRes))
	{
		MessageBox( L"Excel �� ������!", L"������", MB_OK);
		OnOK();
	}
	
	path_list.InsertColumn(0, L"������ ��� �����", LVCFMT_LEFT, 1000);
	// TODO: �������� �������������� �������������

	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

void MainDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������.  ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void MainDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR MainDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//�� �������� ������� ���������, �� �������� ���������� � �������������, � ������� ������ ������������� �� ������� ������ �� ���� �������� ��� �� � ������
//

void MainDlg::OnBnClickedBtnHelp()
{
	CString help_messege;

	help_messege = L" ������� �� \"�����\", ����� ������� ����.\n";
	help_messege += L" ��������� ���� ����� ����� �������� � ������.\n";
	help_messege += L" ���������, ��� �� �������� ��� �����.\n\n";
	help_messege += L" ���� �� �������� � ������� �����, ������� �� ��� ��� �\n";
	help_messege += L" ������, ����� ������� ������ \"�������\".\n\n";
	help_messege += L" ��� ����� ������ ����� ���������� \".xlsx\".\n\n";
	help_messege += L" ����� ����, ��� �� �������� ��� ����������� �����,\n";
	help_messege += L" ������� �� ������ \"��������� �����\" � ��������� ��������� �����. ����� ��������� ������� ����� ����� ��������� ��������� � ��������� ���������\n\n";
	help_messege += L" �� ������� ��������� � ��� ����\n";
	help_messege += L" ���� ��� ����������� ���������� ��� �����.\n\n";
	MessageBox(help_messege, L"������", MB_OK | MB_ICONINFORMATION);
}


void MainDlg::OnBnClickedBtnGetFileName()
{
	CFileDialog f_dlg(TRUE);
	if (f_dlg.DoModal() == IDOK)
	{
		CString file_name;
		file_name = f_dlg.m_ofn.lpstrFile;
		if (CFileFind().FindFile(file_name) == TRUE)
		{
			if (file_name.Find(L".xlsx", 0) != -1)
			{
				LVFINDINFO info;
				info.flags = LVFI_PARTIAL | LVFI_STRING;
				info.psz = file_name;
				if (path_list.FindItem(&info, -1) == -1)
				{
					//MessageBox(L"���� �������� 1 ���", L"OK", MB_OK | MB_ICONINFORMATION);
					path_list.InsertItem(path_list.GetItemCount(), file_name, -1);
					//path_list.SetItemData()
				}
				else
				{
					MessageBox(L"���� ��� ���� � ������", L"ERROR", MB_OK | MB_ICONERROR);
				}

			}
			else
			{
				MessageBox(L"���� �� .xlsx", L"ERROR", MB_OK | MB_ICONERROR);
			}
		}
		else
		{
			MessageBox(L"���� �� ����������", L"ERROR", MB_OK | MB_ICONERROR);
		}
	}
}


void MainDlg::OnBnClickedBtnAddAllFiles()
{
	if (path_list.GetItemCount() == 0)
	{
		MessageBox(L"������ ������ ����", L"������", MB_OK | MB_ICONERROR);
		return;
	}


		theApp.data = new Data;
		int all = path_list.GetItemCount();
		POSITION pos = path_list.GetFirstSelectedItemPosition();
		int index = path_list.GetNextSelectedItem(pos);
		MessageBox(L"�������� ������ ����� ������ ��������� ������.\n ������� �� � �����, ���� ��������� ������ ��������������", L"��������", MB_OK | MB_ICONINFORMATION);
		for (int i = 0; i < all; i++)
		{
			Start* starter = new Start;
			starter->start(path_list.GetItemText(index + 1 + i, 0), theApp.data, theApp.pApp);
			delete starter;
		}
		Professor_Dlg Prof_dlg;
		Prof_dlg.DoModal();
		delete theApp.data;
	
}


void MainDlg::OnBnClickedBtnDelete()
{
	POSITION pos = path_list.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		MessageBox(L"�������� ����, ������� ������ ������ �� ������", L"", MB_OK);
	}
	else
	{
		int item_ind = path_list.GetNextSelectedItem(pos);
		CString temp_name = L"�� �������, ��� ������ ������� ���� � ������\n "
			+ path_list.GetItemText(item_ind, -1);
		if (MessageBox(temp_name, L"������� �� ������?", MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			path_list.DeleteItem(item_ind);
		}
	}
}
