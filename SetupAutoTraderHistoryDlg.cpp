// SetupAutoTraderHistoryDlg.cpp : �C���v�������e�[�V���� �t�@�C��
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
// CSetupAutoTraderHistoryDlg �_�C�A���O

CSetupAutoTraderHistoryDlg::CSetupAutoTraderHistoryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetupAutoTraderHistoryDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetupAutoTraderHistoryDlg)
		// ����: ���̈ʒu�� ClassWizard �ɂ���ă����o�̏��������ǉ�����܂��B
	//}}AFX_DATA_INIT
	// ����: LoadIcon �� Win32 �� DestroyIcon �̃T�u�V�[�P���X��v�����܂���B
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSetupAutoTraderHistoryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetupAutoTraderHistoryDlg)
		// ����: ���̏ꏊ�ɂ� ClassWizard �ɂ���� DDX �� DDV �̌Ăяo�����ǉ�����܂��B
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSetupAutoTraderHistoryDlg, CDialog)
	//{{AFX_MSG_MAP(CSetupAutoTraderHistoryDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetupAutoTraderHistoryDlg ���b�Z�[�W �n���h��

BOOL CSetupAutoTraderHistoryDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���̃_�C�A���O�p�̃A�C�R����ݒ肵�܂��B�t���[�����[�N�̓A�v���P�[�V�����̃��C��
	// �E�B���h�E���_�C�A���O�łȂ����͎����I�ɐݒ肵�܂���B
	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R����ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R����ݒ�
	
	// TODO: ���ʂȏ��������s�����͂��̏ꏊ�ɒǉ����Ă��������B
	
	return TRUE;  // TRUE ��Ԃ��ƃR���g���[���ɐݒ肵���t�H�[�J�X�͎����܂���B
}

// �����_�C�A���O�{�b�N�X�ɍŏ����{�^����ǉ�����Ȃ�΁A�A�C�R����`�悷��
// �R�[�h���ȉ��ɋL�q����K�v������܂��BMFC �A�v���P�[�V������ document/view
// ���f�����g���Ă���̂ŁA���̏����̓t���[�����[�N�ɂ�莩���I�ɏ�������܂��B

void CSetupAutoTraderHistoryDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �`��p�̃f�o�C�X �R���e�L�X�g

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// �N���C�A���g�̋�`�̈���̒���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �A�C�R����`�悵�܂��B
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// �V�X�e���́A���[�U�[���ŏ����E�B���h�E���h���b�O���Ă���ԁA
// �J�[�\����\�����邽�߂ɂ������Ăяo���܂��B
HCURSOR CSetupAutoTraderHistoryDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSetupAutoTraderHistoryDlg::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������
	
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
			strAlphaBeta = "��";
		else
			strAlphaBeta = "��";

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
		strKey0 = "<H4 STYLE=\"color: #FFFFFF; background-color: #0000FF;\">�o�[�W��������</H4>";
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
									strTemp = "AutoTrader Ver." + ConvVer(SaVer[j]) + " ������łƂ��ă����[�X�B";
								} else if (nTemp >= 51) {
									for (j = i + 1; j < SaVer.GetSize(); j ++) {
										nTemp = atoi(SaVer[j].Mid(4));
										if (nTemp  &&  nTemp < 51)
											break;
									}
									strTemp = "AutoTrader Ver." + ConvVer(SaVer[j]) + " �����łƂ��ă����[�X�B";
								} else {
									for (j = i + 1; j < SaVer.GetSize(); j ++)
										if (atoi(SaVer[j].Mid(4)) >= 51)
											break;
									strTemp = "AutoTrader Ver." + ConvVer(SaVer[j]) + " �̃A�b�v�f�[�g���e��K�p�B";
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
		strFPath = strPersonalDPath + "\\LIB\\WEB\\����\\";

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
		strRv.Format("%d.%d.%d��", nMajor, nMinor, nRev);
	else
		strRv.Format("%d.%d.%d��", nMajor, nMinor, nRev);

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
