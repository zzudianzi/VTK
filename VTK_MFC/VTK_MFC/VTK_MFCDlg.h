#pragma once

#include "vtkView.h"

// CVTK_MFCDlg dialog
class CVTK_MFCDlg : public CDialogEx
{
// Construction
public:
	CVTK_MFCDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VTK_MFC_DIALOG };
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
	afx_msg void OnBnClickedButtonLoadimg();
	DECLARE_MESSAGE_MAP()

private:
	CvtkView m_vtkView;
};
