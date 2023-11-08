
// ComboBoxDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "ComboBox.h"
#include "ComboBoxDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CComboBoxDlg dialog



CComboBoxDlg::CComboBoxDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_COMBOBOX_DIALOG, pParent)
	, m_latestComboSelection(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CComboBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_ComboBox1);
	DDX_Control(pDX, IDC_COMBO3, m_ComboBox2);
	DDX_Control(pDX, IDC_COMBO2, m_ComboBox3);
	DDX_Text(pDX, IDC_EDIT_SELECTED_ITEM, m_latestComboSelection);
}

BEGIN_MESSAGE_MAP(CComboBoxDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CComboBoxDlg::OnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CComboBoxDlg::OnSelchangeCombo3)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CComboBoxDlg::OnSelchangeCombo2)
	ON_BN_CLICKED(IDC_BUTTON2, &CComboBoxDlg::OnBnClickedButton2)
	ON_NOTIFY(BCN_DROPDOWN, IDC_BUTTON2, &CComboBoxDlg::OnDropdownButton2)
END_MESSAGE_MAP()


// CComboBoxDlg message handlers

BOOL CComboBoxDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CComboBoxDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CComboBoxDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CComboBoxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CComboBoxDlg::OnSelchangeCombo1()
{
	int comboBox1Item = m_ComboBox1.GetCurSel();
	if (comboBox1Item != LB_ERR)
	{
		//CString str;
		m_ComboBox1.GetLBText(comboBox1Item, m_latestComboSelection);
		//AfxMessageBox(str);
		m_latestComboSelection = _T("CB1:: ") + m_latestComboSelection;
		UpdateData(FALSE);
	}
}


void CComboBoxDlg::OnSelchangeCombo3()
{
	int comboBox3Item = m_ComboBox2.GetCurSel();
	if (comboBox3Item != LB_ERR)
	{
		//CString str;
		m_ComboBox2.GetLBText(comboBox3Item, m_latestComboSelection);
		//AfxMessageBox(str);
		m_latestComboSelection = _T("CB3:: ") + m_latestComboSelection;
		UpdateData(FALSE);
	}
}


void CComboBoxDlg::OnSelchangeCombo2()
{
	int comboBox2Item = m_ComboBox3.GetCurSel();
	if (comboBox2Item != LB_ERR)
	{
		//CString str;
		m_ComboBox3.GetLBText(comboBox2Item, m_latestComboSelection);
		//AfxMessageBox(str);
		m_latestComboSelection = _T("CB2:: ") + m_latestComboSelection;
		UpdateData(FALSE);
	}
}


void CComboBoxDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	m_ComboBox2.AddString(_T("John"));
	m_ComboBox3.AddString(_T("Cena"));
}


void CComboBoxDlg::OnDropdownButton2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMBCDROPDOWN pDropDown = reinterpret_cast<LPNMBCDROPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here
	

	*pResult = 0;
}
