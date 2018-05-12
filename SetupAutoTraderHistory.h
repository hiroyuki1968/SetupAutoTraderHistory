// SetupAutoTraderHistory.h : SETUPAUTOTRADERHISTORY アプリケーションのメイン ヘッダー ファイルです。
//

#if !defined(AFX_SETUPAUTOTRADERHISTORY_H__6F305590_6D90_4440_B7AE_E4B7395F3E0A__INCLUDED_)
#define AFX_SETUPAUTOTRADERHISTORY_H__6F305590_6D90_4440_B7AE_E4B7395F3E0A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// メイン シンボル

/////////////////////////////////////////////////////////////////////////////
// CSetupAutoTraderHistoryApp:
// このクラスの動作の定義に関しては SetupAutoTraderHistory.cpp ファイルを参照してください。
//

class CSetupAutoTraderHistoryApp : public CWinApp
{
public:
	CSetupAutoTraderHistoryApp();

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CSetupAutoTraderHistoryApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// インプリメンテーション

	//{{AFX_MSG(CSetupAutoTraderHistoryApp)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_SETUPAUTOTRADERHISTORY_H__6F305590_6D90_4440_B7AE_E4B7395F3E0A__INCLUDED_)
