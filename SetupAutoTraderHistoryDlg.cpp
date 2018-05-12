// SetupAutoTraderHistoryDlg.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "SetupAutoTraderHistory.h"
#include "SetupAutoTraderHistoryDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetupAutoTraderHistoryDlg ダイアログ

CSetupAutoTraderHistoryDlg::CSetupAutoTraderHistoryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetupAutoTraderHistoryDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetupAutoTraderHistoryDlg)
		// メモ: この位置に ClassWizard によってメンバの初期化が追加されます。
	//}}AFX_DATA_INIT
	// メモ: LoadIcon は Win32 の DestroyIcon のサブシーケンスを要求しません。
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSetupAutoTraderHistoryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetupAutoTraderHistoryDlg)
		// メモ: この場所には ClassWizard によって DDX と DDV の呼び出しが追加されます。
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSetupAutoTraderHistoryDlg, CDialog)
	//{{AFX_MSG_MAP(CSetupAutoTraderHistoryDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetupAutoTraderHistoryDlg メッセージ ハンドラ

BOOL CSetupAutoTraderHistoryDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// このダイアログ用のアイコンを設定します。フレームワークはアプリケーションのメイン
	// ウィンドウがダイアログでない時は自動的に設定しません。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンを設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンを設定
	
	// TODO: 特別な初期化を行う時はこの場所に追加してください。
	
	return TRUE;  // TRUE を返すとコントロールに設定したフォーカスは失われません。
}

// もしダイアログボックスに最小化ボタンを追加するならば、アイコンを描画する
// コードを以下に記述する必要があります。MFC アプリケーションは document/view
// モデルを使っているので、この処理はフレームワークにより自動的に処理されます。

void CSetupAutoTraderHistoryDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画用のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// クライアントの矩形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンを描画します。
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// システムは、ユーザーが最小化ウィンドウをドラッグしている間、
// カーソルを表示するためにここを呼び出します。
HCURSOR CSetupAutoTraderHistoryDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSetupAutoTraderHistoryDlg::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	
//	char szPersonalDPath[_MAX_PATH];
//	SHGetSpecialFolderPath(m_hWnd, szPersonalDPath, CSIDL_PERSONAL, FALSE);

//	CString strPersonalDPath = szPersonalDPath;
	CString strPersonalDPath = "D:\\home";
	CString strAutoTraderDPath = strPersonalDPath + "\\Visual Studio Projects\\AutoTrader";

	int i;
	int j;
	int nTemp;
	CString strTemp;
	CString strFPath;
	CString strFPathC;
	CString strLine;
	CString strKey0;
	CString strKey1;
	CString strKey2;
	int nKeyLen0;
	int nKeyLen1;
	int nKeyLen2;

	CString strBaseVer;
	CString strVer;

	try {
		strFPath = strAutoTraderDPath + "\\AutoTraderVer.h";

		strKey0 = "#define BASE_VER	";
		nKeyLen0 = strKey0.GetLength();

		strKey1 = "#define THIS_VER	";
		nKeyLen1 = strKey1.GetLength();

		char pszVer[MAX_PATH];

		CStdioFile Sf(strFPath, CFile::modeRead);
		while (Sf.ReadString(strLine)) {
			if (strLine.Left(nKeyLen0) == strKey0) {
				if (sscanf(strLine, "%*s %*s %s", pszVer) == 1)
					strBaseVer = pszVer;
			} else if (strLine.Left(nKeyLen1) == strKey1) {
				if (sscanf(strLine, "%*s %*s %s", pszVer) == 1)
					strVer = pszVer;
				break;
			}
		}
		Sf.Close();
	}
	catch (CException* pEx) {
		MessageBox(GetExceptionErrorMessage(pEx), NULL, MB_ICONSTOP);
		pEx->Delete();
		return;
	}

	int nBaseVerLen = strBaseVer.GetLength();
	CString strMajorBaseVer = strBaseVer.Left(nBaseVerLen - 4);
	CString strMinorBaseVer = strBaseVer.Mid(nBaseVerLen - 4, 2);
	CString strRevBaseVer = strBaseVer.Right(2);
	int nBaseVer = atoi(strBaseVer);
	int nMajorBaseVer = atoi(strMajorBaseVer);
	int nMinorBaseVer = atoi(strMinorBaseVer);
	int nRevBaseVer = atoi(strRevBaseVer);
	
	int nVerLen = strVer.GetLength();
	CString strMajorVer = strVer.Left(nVerLen - 4);
	CString strMinorVer = strVer.Mid(nVerLen - 4, 2);
	CString strRevVer = strVer.Right(2);
	int nVer = atoi(strVer);
	int nMajorVer = atoi(strMajorVer);
	int nMinorVer = atoi(strMinorVer);
	int nRevVer = atoi(strRevVer);
	CString strAlphaBeta;
	if (nRevVer)
		if (nRevVer < 51)
			strAlphaBeta = "α";
		else
			strAlphaBeta = "β";

	CStringArray SaDate;
	CStringArray SaVer;
	CStringArray SaDetail;

	try {
		strFPath = strPersonalDPath + "\\LIB\\AutoTraderHistory.txt";

		BOOL bDate = FALSE;
		BOOL bVer = FALSE;

		CStdioFile Sf(strFPath, CFile::modeRead);
		i = 0;
		while (Sf.ReadString(strLine)) {
			if (strLine.IsEmpty()) {
				bDate = FALSE;
				bVer = FALSE;
				i ++;
			} else
				if (! bDate) {
					bDate = TRUE;
					SaDate.Add(strLine);
				} else if (! bVer) {
					bVer = TRUE;
					SaVer.Add(strLine);
					SaDetail.Add("");
				} else {
					if (SaDetail[i].GetLength())
						SaDetail[i] += "\n";
					SaDetail[i] += strLine;
				}
		}
		Sf.Close();
	}
	catch (CException* pEx) {
		MessageBox(GetExceptionErrorMessage(pEx), NULL, MB_ICONSTOP);
		pEx->Delete();
		return;
	}

	strFPath = strAutoTraderDPath + "\\HTML Help\\AutoTrader.htm";
	strFPathC = strFPath + '~';
	try {
		strKey0 = "<H4 STYLE=\"color: #FFFFFF; background-color: #0000FF;\">バージョン履歴</H4>";
		nKeyLen0 = strKey0.GetLength();

		strKey1 = "<TABLE>";
		nKeyLen1 = strKey1.GetLength();

		strKey2 = "</TABLE>";
		nKeyLen2 = strKey2.GetLength();

		BOOL bVerHistory = FALSE;
		BOOL bTable = FALSE;

		CStdioFile Sf(strFPath, CFile::modeRead);
		CStdioFile SfC(strFPathC, CFile::modeCreate | CFile::modeWrite);
		while (Sf.ReadString(strLine)) {
			if (bTable)
				if (strLine.Left(nKeyLen2) == strKey2)
					bVerHistory = bTable = FALSE;
				else
					continue;
			else if (bVerHistory) {
				if (strLine.Left(nKeyLen1) == strKey1) {
					bTable = TRUE;
					strLine += '\n';
					for (i = 0; i < SaVer.GetSize(); i ++)
						if (atoi(SaVer[i]) <= nVer) {
							strLine += "	<TR>\n";

							strLine += "		<TD VALIGN=\"top\">" + SaDate[i].Left(4) + '/' + SaDate[i].Mid(4, 2) + '/' + SaDate[i].Mid(6) + "</TD>\n";

							strLine += "		<TD>";
							if (i == 0)
								strLine += "&nbsp;";
							strLine += "</TD>\n";

							strLine += "		<TD VALIGN=\"top\">Ver." + ConvVer(SaVer[i]) + "</TD>\n";

							strLine += "		<TD>\n";
							strLine += "			<UL TYPE=\"disc\">\n";

							strTemp = SaDetail[i];
							if (strTemp.IsEmpty()) {
								nTemp = atoi(SaVer[i].Mid(4));
								if (nTemp == 0) {
									for (j = i + 1; j < SaVer.GetSize(); j ++)
										if (atoi(SaVer[j].Mid(4)) >= 51)
											break;
									strTemp = "AutoTrader Ver." + ConvVer(SaVer[j]) + " を安定版としてリリース。";
								} else if (nTemp >= 51) {
									for (j = i + 1; j < SaVer.GetSize(); j ++) {
										nTemp = atoi(SaVer[j].Mid(4));
										if (nTemp  &&  nTemp < 51)
											break;
									}
									strTemp = "AutoTrader Ver." + ConvVer(SaVer[j]) + " をβ版としてリリース。";
								} else {
									for (j = i + 1; j < SaVer.GetSize(); j ++)
										if (atoi(SaVer[j].Mid(4)) >= 51)
											break;
									strTemp = "AutoTrader Ver." + ConvVer(SaVer[j]) + " のアップデート内容を適用。";
								}
							}
							strTemp.Replace("\n", "\n				<LI>");
							strLine += "				<LI>" + strTemp + '\n';

							strLine += "			</UL>\n";
							strLine += "		</TD>\n";

							strLine += "	</TR>\n";
						}
					strLine.TrimRight();
				}
			} else if (strLine.Left(nKeyLen0) == strKey0)
				bVerHistory = TRUE;
			SfC.WriteString(strLine + "\n");
		}
		SfC.Close();
		Sf.Close();
	}
	catch (CException* pEx) {
		MessageBox(GetExceptionErrorMessage(pEx), NULL, MB_ICONSTOP);
		pEx->Delete();
		return;
	}
	if (! DeleteFile(strFPath)) {
		MessageBox("DeleteFile(): " + GetLastErrorMessage(), NULL, MB_ICONSTOP);
		return;
	}
	if (! MoveFile(strFPathC, strFPath)) {
		MessageBox("MoveFile(): " + GetLastErrorMessage(), NULL, MB_ICONSTOP);
		return;
	}

	CString strLibDName;
	for (i = 0; i < 2; i ++) {
		strFPath = strPersonalDPath + "\\LIB\\WEB\\共通\\";

		strLibDName.Empty();
		if (i)
			strLibDName += '0';
		strLibDName += "lib";
		if (nRevVer >= 51)
			strLibDName += "-beta";
		else if (nRevVer  &&  nRevVer < 51)
			strLibDName += "-alpha";

		strFPath += strLibDName + "\\update-autotrader.txt";

		try {
			CStdioFile Sf(strFPath, CFile::modeCreate | CFile::modeWrite);
			strTemp.Format("%02d%02d%02d %02d%02d%02d", nMajorBaseVer, nMinorBaseVer, nRevBaseVer, nMajorVer, nMinorVer, nRevVer);
			strTemp += " http://www8.tok2.com/home2/hashikun/" + strLibDName + '/';
			Sf.WriteString(strTemp + "\n");
			for (j = 0; j < SaDate.GetSize(); j ++)
				if (atoi(SaVer[j]) <= nVer) {
					Sf.WriteString("\n");
					Sf.WriteString(SaDate[j] + '\n');
					Sf.WriteString(SaVer[j] + '\n');
					if (SaDetail[j].GetLength())
						Sf.WriteString(SaDetail[j] + '\n');
				}
			Sf.Close();
		}
		catch (CException* pEx) {
			MessageBox(GetExceptionErrorMessage(pEx), NULL, MB_ICONSTOP);
			pEx->Delete();
			return;
		}
	}

	CDialog::OnOK();
}

CString ConvVer(const CString& strVer)
{
	CString strRv;

	int nMajor = atoi(strVer.Left(2));
	int nMinor = atoi(strVer.Mid(2, 2));
	int nRev = atoi(strVer.Mid(4));

	if (nRev == 0)
		strRv.Format("%d.%d", nMajor, nMinor);
	else if (nRev >= 51)
		strRv.Format("%d.%d.%dβ", nMajor, nMinor, nRev);
	else
		strRv.Format("%d.%d.%dα", nMajor, nMinor, nRev);

	return strRv;
}

CString GetLastErrorMessage(DWORD dwLastError)
{
	LPVOID lpMsgBuf;
	FormatMessage( 
		FORMAT_MESSAGE_ALLOCATE_BUFFER | 
		FORMAT_MESSAGE_FROM_SYSTEM | 
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		dwLastError ? dwLastError : GetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
		(LPTSTR) &lpMsgBuf,
		0,
		NULL 
	);
	// Process any inserts in lpMsgBuf.
	CString strMsg((LPCTSTR)lpMsgBuf);
	// Free the buffer.
	LocalFree( lpMsgBuf );

	return strMsg;
}

CString GetExceptionErrorMessage(CException* pEx)
{
	TCHAR   szCause[255];

	pEx->GetErrorMessage(szCause, 255);
	return szCause;
}
