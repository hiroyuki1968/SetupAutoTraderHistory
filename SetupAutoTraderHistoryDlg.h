// SetupAutoTraderHistoryDlg.h : �w�b�_�[ �t�@�C��
//

#if !defined(AFX_SETUPAUTOTRADERHISTORYDLG_H__E26B92C0_D90A_4D40_BD75_B6BB5A21F50D__INCLUDED_)
#define AFX_SETUPAUTOTRADERHISTORYDLG_H__E26B92C0_D90A_4D40_BD75_B6BB5A21F50D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSetupAutoTraderHistoryDlg �_�C�A���O

class CSetupAutoTraderHistoryDlg : public CDialog
{
// �\�z
public:
	CSetupAutoTraderHistoryDlg(CWnd* pParent = NULL);	// �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CSetupAutoTraderHistoryDlg)
	enum { IDD = IDD_SETUPAUTOTRADERHISTORY_DIALOG };
		// ����: ���̈ʒu�� ClassWizard �ɂ���ăf�[�^ �����o���ǉ�����܂��B
	//}}AFX_DATA

	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CSetupAutoTraderHistoryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �̃T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	HICON m_hIcon;

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CSetupAutoTraderHistoryDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CString ConvVer(const CString& strVer);
CString GetLastErrorMessage(DWORD dwLastError = NULL);
CString GetExceptionErrorMessage(CException* pEx);

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_SETUPAUTOTRADERHISTORYDLG_H__E26B92C0_D90A_4D40_BD75_B6BB5A21F50D__INCLUDED_)
