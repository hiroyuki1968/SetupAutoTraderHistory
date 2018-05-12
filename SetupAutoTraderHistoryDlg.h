// SetupAutoTraderHistoryDlg.h : ヘッダー ファイル
//

#if !defined(AFX_SETUPAUTOTRADERHISTORYDLG_H__E26B92C0_D90A_4D40_BD75_B6BB5A21F50D__INCLUDED_)
#define AFX_SETUPAUTOTRADERHISTORYDLG_H__E26B92C0_D90A_4D40_BD75_B6BB5A21F50D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSetupAutoTraderHistoryDlg ダイアログ

class CSetupAutoTraderHistoryDlg : public CDialog
{
// 構築
public:
	CSetupAutoTraderHistoryDlg(CWnd* pParent = NULL);	// 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(CSetupAutoTraderHistoryDlg)
	enum { IDD = IDD_SETUPAUTOTRADERHISTORY_DIALOG };
		// メモ: この位置に ClassWizard によってデータ メンバが追加されます。
	//}}AFX_DATA

	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CSetupAutoTraderHistoryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV のサポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	HICON m_hIcon;

	// 生成されたメッセージ マップ関数
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
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_SETUPAUTOTRADERHISTORYDLG_H__E26B92C0_D90A_4D40_BD75_B6BB5A21F50D__INCLUDED_)
