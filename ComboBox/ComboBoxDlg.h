
// ComboBoxDlg.h : header file
//

#pragma once


// CComboBoxDlg dialog
class CComboBoxDlg : public CDialogEx
{
// Construction
public:
	CComboBoxDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COMBOBOX_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_ComboBox1;
	CComboBox m_ComboBox2;
	CComboBox m_ComboBox3;
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnSelchangeCombo3();
	afx_msg void OnSelchangeCombo2();
	CString m_latestComboSelection;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnDropdownButton2(NMHDR* pNMHDR, LRESULT* pResult);
};
