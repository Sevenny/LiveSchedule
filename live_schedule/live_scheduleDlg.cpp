
// live_scheduleDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "live_schedule.h"
#include "live_scheduleDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clive_scheduleDlg �Ի���



Clive_scheduleDlg::Clive_scheduleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Clive_scheduleDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Clive_scheduleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1,				m_eShow);
	DDX_Control(pDX, IDC_EDIT_ERROR,		m_eResult);
	DDX_Control(pDX, IDC_RADIO_CIDYES,		m_rCidYes);
	DDX_Control(pDX, IDC_RADIO_CIDNO,		m_rCidNo);
	DDX_Control(pDX, IDC_RADIO_FORWARD,		m_rForward);
	DDX_Control(pDX, IDC_EDIT_CATE,			m_eCate);
	DDX_Control(pDX, IDC_CHECK_ALL,			m_cbAll);
	DDX_Control(pDX, IDC_CHECK_SPORTS,		m_cbSports);
	DDX_Control(pDX, IDC_CHECK_CONCERT,		m_cbConcert);
	DDX_Control(pDX, IDC_CHECK_VARIETY,		m_cbVariety);
	DDX_Control(pDX, IDC_CHECK_NEWS,		m_cbNews);
	DDX_Control(pDX, IDC_CHECK_GAME,		m_cbGame);
	DDX_Control(pDX, IDC_CHECK_ENT,			m_cbEnt);
	DDX_Control(pDX, IDC_CHECK_TV,			m_cbTv);
	DDX_Control(pDX, IDC_CHECK_TECH,		m_cbTech);
	DDX_Control(pDX, IDC_CHECK_FINANCE,		m_cbFinance);
	DDX_Control(pDX, IDC_CHECK_AUTO,		m_cbAuto);
	DDX_Control(pDX, IDC_CHECK_LOCAL,		m_cbLocal);
	DDX_Control(pDX, IDC_CHECK_EDU,			m_cbEdu);
	DDX_Control(pDX, IDC_CHECK_STATUS_1,	m_cbStatus1);
	DDX_Control(pDX, IDC_CHECK_STATUS_2,	m_cbStatus2);
	DDX_Control(pDX, IDC_CHECK_STATUS_3,	m_cbStatus3);
	DDX_Control(pDX, IDC_EDIT_PAGESIZE,		m_ePageSize);
	DDX_Control(pDX, IDC_EDIT_PAGESTART,	m_ePageStart);
	DDX_Control(pDX, IDC_CHECK_VIP,			m_cbVip);
	DDX_Control(pDX, IDC_CHECK_FREE,		m_cbFree);
	DDX_Control(pDX, IDC_CHECK_TEST,		m_cbTest);
	DDX_Control(pDX, IDC_CHECK_VER_1_1,		m_cbVer1_1);
	DDX_Control(pDX, IDC_CHECK_ONTOP,		m_cbOnTop);
	DDX_Control(pDX, IDC_DATETIMEPICKER2,	m_tStartDate);
	DDX_Control(pDX, IDC_DATETIMEPICKER3,	m_tEndDate);
	DDX_Control(pDX, IDC_CHECK_START,		m_cbStart);
	DDX_Control(pDX, IDC_CHECK_END,			m_cbEnd);
}

BEGIN_MESSAGE_MAP(Clive_scheduleDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK,				&Clive_scheduleDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK_ALL,	&Clive_scheduleDlg::OnBnClickedCheckAll)
	ON_BN_CLICKED(IDC_BTN_CLEAN,	&Clive_scheduleDlg::OnBnClickedBtnClean)
	ON_BN_CLICKED(IDC_BTN_NEXT,		&Clive_scheduleDlg::OnBnClickedBtnNext)
	ON_BN_CLICKED(IDC_BTN_LAST,		&Clive_scheduleDlg::OnBnClickedBtnLast)
	ON_BN_CLICKED(IDC_BTN_ABOUT,	&Clive_scheduleDlg::OnBnClickedBtnAbout)
	ON_BN_CLICKED(IDCANCEL,			&Clive_scheduleDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_CHECK_ONTOP,	&Clive_scheduleDlg::OnBnClickedCheckOntop)
	ON_BN_CLICKED(IDC_BTN_MIN,		&Clive_scheduleDlg::OnBnClickedBtnMin)
END_MESSAGE_MAP()


BOOL Clive_scheduleDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_MOUSEMOVE)
		m_Mytip.RelayEvent(pMsg);
	return CDialog::PreTranslateMessage(pMsg);
}

// Clive_scheduleDlg ��Ϣ�������

BOOL Clive_scheduleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	//ShowWindow(SW_MINIMIZE);

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	m_rForward.SetCheck(1);
	m_rCidNo.SetCheck(1);
	m_cbFree.SetCheck(1);
	m_cbVip.SetCheck(1);
	m_cbStatus1.SetCheck(1);
	m_cbStatus2.SetCheck(1);
	m_cbStatus3.SetCheck(1);
	m_cbAll.SetCheck(1);
	m_cbOnTop.SetCheck(1);

	m_ePageSize.SetWindowTextW(L"20");
	m_ePageStart.SetWindowTextW(L"0");
	m_eCate.SetWindowTextW(L"all");

	m_eShow.SetSel(-1);
	m_csDomain = _T(VIDEO_DOMAIN);
	m_eShow.SetReadOnly();

	m_tStartDate.SetFormat(L"yyyy-MM-dd HH:mm:ss");
	m_tEndDate.SetFormat(L"yyyy-MM-dd HH:mm:ss");
	COleDateTime oleDate;
	m_tStartDate.GetTime(oleDate);
	oleDate.SetDateTime(oleDate.GetYear(), oleDate.GetMonth(), oleDate.GetDay(), 0, 0, 0);
	m_tStartDate.SetTime(oleDate);

	oleDate.SetDateTime(oleDate.GetYear(), oleDate.GetMonth(), oleDate.GetDay(), 23, 59, 59);
	m_tEndDate.SetTime(oleDate);


	m_Mytip.Create(this);
	m_Mytip.AddTool(GetDlgItem(IDC_CHECK_START), L"Ĭ�ϲ����ÿ�ʼʱ�䣬����Ҫ�빴ѡ"); 
	m_Mytip.AddTool(GetDlgItem(IDC_CHECK_END),	 L"Ĭ�ϲ����ý���ʱ�䣬����Ҫ�빴ѡ");
	m_Mytip.AddTool(GetDlgItem(IDC_EDIT_CATE),	 L"С������д��鿴������");
	m_Mytip.SetDelayTime(200);					//�����ӳ�
	m_Mytip.SetTipTextColor(RGB(0, 0, 255));	//������ʾ�ı�����ɫ
	m_Mytip.SetTipBkColor(RGB(255, 255, 255));	//������ʾ��ı�����ɫ
	m_Mytip.Activate(TRUE);						//�����Ƿ�������ʾ

	//AllocConsole();
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Clive_scheduleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Clive_scheduleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//��ȡ����ֵ������
void Clive_scheduleDlg::GetItemValue(LiveRequest &req)
{
	m_stReq.clear();
	m_csDomain = _T(VIDEO_DOMAIN);

	//��ʼʱ��
	if (m_cbStart.GetCheck() == BST_CHECKED)
	{
		CString csTimeStart = L"";
		m_tStartDate.GetTime(m_ctTimeStart);
		csTimeStart.Format(L"%d-%d-%d %02d:%02d:%02d", m_ctTimeStart.GetYear(), m_ctTimeStart.GetMonth(), m_ctTimeStart.GetDay(),
			m_ctTimeStart.GetHour(), m_ctTimeStart.GetMinute(), m_ctTimeStart.GetSecond());

		time_t iTimeStart = StampnizeTime(csTimeStart);
		csTimeStart = L"";
		csTimeStart.Format(L"%ld", iTimeStart);
		m_stReq.csTimeStart = csTimeStart;
	}
	else
		m_stReq.csTimeStart = L"0";

	//����ʱ��
	if (m_cbEnd.GetCheck() == BST_CHECKED)
	{
		CString csTimeEnd = L"";
		m_tEndDate.GetTime(m_ctTimeEnd);
		csTimeEnd.Format(L"%d-%d-%d %02d:%02d:%02d", m_ctTimeEnd.GetYear(), m_ctTimeEnd.GetMonth(), m_ctTimeEnd.GetDay(),
			m_ctTimeEnd.GetHour(), m_ctTimeEnd.GetMinute(), m_ctTimeEnd.GetSecond());

		time_t iTimeEnd = StampnizeTime(csTimeEnd);
		csTimeEnd = L"";
		csTimeEnd.Format(L"%ld", iTimeEnd);
		m_stReq.csTimeEnd = csTimeEnd;
	}
	else
		m_stReq.csTimeEnd = L"0";

	m_ePageSize.GetWindowTextW(m_stReq.csPageSize);

	m_ePageStart.GetWindowTextW(m_stReq.csPageStart);

	m_eCate.GetWindowTextW(m_stReq.csCate);

	if (m_rCidNo.GetCheck() == BST_CHECKED)
		m_stReq.csCid = L"no";
	else
		m_stReq.csCid = L"yes";

	if (m_rForward.GetCheck() == BST_CHECKED)
		m_stReq.csPageType = L"forward";
	else
		m_stReq.csPageType = L"backward";

	if (m_cbAll.GetCheck() == BST_CHECKED)
		m_stReq.csSite = L"all";
	else
	{
		m_stReq.csSite = L"";
		if (m_cbSports.GetCheck() == BST_CHECKED)
			m_stReq.csSite.Append(L"sports,");
		if (m_cbConcert.GetCheck() == BST_CHECKED)
			m_stReq.csSite.Append(L"concert,");
		if (m_cbVariety.GetCheck() == BST_CHECKED)
			m_stReq.csSite.Append(L"variety,");
		if (m_cbGame.GetCheck() == BST_CHECKED)
			m_stReq.csSite.Append(L"game,");
		if (m_cbNews.GetCheck() == BST_CHECKED)
			m_stReq.csSite.Append(L"news,");
		if (m_cbTv.GetCheck() == BST_CHECKED)
			m_stReq.csSite.Append(L"tv,");
		if (m_cbLocal.GetCheck() == BST_CHECKED)
			m_stReq.csSite.Append(L"local,");
		if (m_cbEnt.GetCheck() == BST_CHECKED)
			m_stReq.csSite.Append(L"ent,");
		if (m_cbEdu.GetCheck() == BST_CHECKED)
			m_stReq.csSite.Append(L"edu,");
		if (m_cbAuto.GetCheck() == BST_CHECKED)
			m_stReq.csSite.Append(L"auto,");
		if (m_cbFinance.GetCheck() == BST_CHECKED)
			m_stReq.csSite.Append(L"finance,");
		if (m_cbTech.GetCheck() == BST_CHECKED)
			m_stReq.csSite.Append(L"tech,");
	}
	if (m_stReq.csSite == "")
		m_stReq.csSite = L"all";

	m_stReq.csStatus = L"";
	if (m_cbStatus1.GetCheck() == BST_CHECKED)
		m_stReq.csStatus.Append(L"1,");
	if (m_cbStatus2.GetCheck() == BST_CHECKED)
		m_stReq.csStatus.Append(L"2,");
	if (m_cbStatus3.GetCheck() == BST_CHECKED)
		m_stReq.csStatus.Append(L"3,");

	m_stReq.csPay = L"";
	if (m_cbFree.GetCheck() == BST_CHECKED)
		m_stReq.csPay.Append(L"0,");
	if (m_cbVip.GetCheck() == BST_CHECKED)
		m_stReq.csPay.Append(L"1,");

	if (m_cbTest.GetCheck() == BST_CHECKED)
		m_csDomain = _T(VIDEO_DOMAIN_TEST);

	m_csArgs = URL_ARGS;
	if (m_cbVer1_1.GetCheck() == BST_CHECKED)
		m_csArgs.Append(L"&version=1.1");
}
void Clive_scheduleDlg::OnBnClickedOk()
{
	int iRet = 0;
	GetItemValue(m_stReq);

	iRet = GetLiveSchedule(m_stReq);
	CButton *btn = (CButton*)GetDlgItem(IDC_BTN_NEXT);
	btn->EnableWindow();
	btn = (CButton*)GetDlgItem(IDC_BTN_LAST);
	btn->EnableWindow();
	btn = (CButton*)GetDlgItem(IDC_BTN_CLEAN);
	btn->EnableWindow();
}

//��ȡ��Ŀ�б��ҽ������
int Clive_scheduleDlg::GetLiveSchedule(const LiveRequest req)
{
	m_eShow.SetWindowTextW(L"");
	CString csUrl;
	string strTimeStart = StringnizeTimeStamp((int)_ttoi(req.csTimeStart));
	CString csTimeStart;
	csTimeStart = strTimeStart.c_str();
	m_eShow.ReplaceSel(L"��ʼʱ�� : "	+ csTimeStart		+ L"\r\n");
	m_eShow.ReplaceSel(L"����ʱ�� : "	+ req.csTimeEnd		+ L"\r\n");
	m_eShow.ReplaceSel(L"ÿҳ���� : "	+ req.csPageSize	+ L"\r\n");
	m_eShow.ReplaceSel(L"��ҳ��� : "	+ req.csPageStart	+ L"\r\n");
	m_eShow.ReplaceSel(L"��ҳ���� : "	+ req.csPageType	+ L"\r\n");
	m_eShow.ReplaceSel(L"��  �� �� : "	+ req.csSite		+ L"\r\n");
	m_eShow.ReplaceSel(L"С  �� �� : "	+ req.csCate		+ L"\r\n");
	m_eShow.ReplaceSel(L"ֱ��״̬ : "	+ req.csStatus		+ L"\r\n");
	m_eShow.ReplaceSel(L"����״̬ : "	+ req.csPay			+ L"\r\n");
	m_eShow.ReplaceSel(L"����Cid   : "	+ m_stReq.csCid		+ L"\r\n");
	csUrl.Format(m_csArgs, req.csTimeStart, req.csCate, req.csTimeEnd, req.csSite, req.csPageType, req.csPageSize, req.csPageStart, req.csStatus, req.csCid, req.csPay);
	csUrl.Append(_T(URL_QUA));
	CInternetSession mysession;
	CHttpConnection *myconn = mysession.GetHttpConnection(m_csDomain);
	CHttpFile *myfile = myconn->OpenRequest(L"GET", csUrl);
	m_eShow.ReplaceSel(L"URL:" + m_csDomain + csUrl + L"\r\n");
	myfile->SendRequest();

	CString tmp;
	CString strUtf8;
	CString strUnicode;
	while (myfile->ReadString(tmp))
	{
		strUtf8 += tmp;
	}
	char *pValue = (char *)strUtf8.GetBuffer(0);
	strUnicode = UTF8ToUnicode(pValue);
	char *pSzValue = (char *)strUnicode.GetBuffer(0);

	//HANDLE hdlWrite = GetStdHandle(STD_OUTPUT_HANDLE); //����Ҳ����ʹ��STD_ERROR_HANDLE

	CString strTemp = strUtf8;
	std::string value;
	Json::Reader reader;
	Json::Value root;
	if (!reader.parse((char*)strUtf8.GetBuffer(0), root))  // reader��Json�ַ���������root��root������Json��������Ԫ��  
	{
		std::string errMsg = reader.getFormatedErrorMessages();
		strTemp = errMsg.c_str();
		m_eResult.SetWindowTextW(strTemp);
		m_eShow.SetWindowTextW(strUtf8);
		return -1;
	}
	m_stRsp.clear();
	m_stRsp.finish		= root["finish"].asInt();
	m_stRsp.next_start	= root["next_page_start"].asInt();
	m_stRsp.req_num		= root["req_num"].asInt();
	m_stRsp.rsp_num		= root["rsp_num"].asInt();

	std::string strMsg	= root["result"]["msg"].asString();
	int code			= root["result"]["ret"].asInt();
	strTemp				= strMsg.c_str();
	CString csErrMsg;
	csErrMsg.Format(L"Ret:%d | Next:%d | Cost:%dms | Msg:", code, m_stRsp.next_start, root["result"]["cost_time"].asInt());
	csErrMsg.Append(strTemp);
	m_eResult.SetWindowTextW(csErrMsg);
	Json::Value stLives = root["data"]["lives"];
	

	int iSize = stLives.size();
	CString csLiveShow = L"";
	m_eShow.ReplaceSel(L"========================================================================================\r\n");
	for (int i = 0; i < iSize; i++)
	{
		CString csErrMsg;
		Json::Value Live = stLives[i];
		std::string strPid, strType, strTitle, strStart, strEnd;
		CString csPid, csType, csTitle, csStart, csEnd, csIndex;
		csIndex.Format(L"%d", i+1);

		csLiveShow.Append(L"| " + csIndex + L"\t| ");
		if (!Live["pid"].empty() && Live["pid"].isString())
		{
			strPid = Live["pid"].asString();
			csPid = strPid.c_str();
			csLiveShow.Append(csPid + L"\t| ");
		}
		else
		{
			csErrMsg = L"pid error";
			m_eResult.SetWindowTextW(csErrMsg);
		}
		if (!Live["site"].empty() && Live["site"].isString())
		{
			strType = Live["site"].asString();
			csType = strType.c_str();
			csLiveShow.Append(csType + L"\t|  ");
		}
		else
		{
			csErrMsg = L"live_type error";
			m_eResult.SetWindowTextW(csErrMsg);
		}
		Json::Value jStreams = Live["streams"];
		int j = 0;
		Json::Value jStream = jStreams[j];
		strStart = jStream["start_time"].asString();
		csStart = strStart.c_str();
		csLiveShow.Append(csStart + " |  ");
		strEnd = jStream["end_time"].asString();
		csEnd = strEnd.c_str();
		csLiveShow.Append(csEnd + "  | ");
		if (!Live["title"].empty() && Live["title"].isString())
		{
			strTitle = Live["title"].asString();
			char *pszTitle = (char *)strTitle.data();
			CString csTitleUnicode;
			csTitleUnicode = UTF8ToUnicode(pszTitle);
			csLiveShow.Append(csTitleUnicode);
		}
		else
		{
			csErrMsg = L"title error";
			m_eResult.SetWindowTextW(csErrMsg);
		}
		csLiveShow.Append(L"\r\n");
		UpdateData(FALSE);
	}
	m_eShow.ReplaceSel(csLiveShow);
	m_eShow.ReplaceSel(L"========================================================================================\r\n");

	myfile->Close();
	myconn->Close();
	mysession.Close();
	delete myfile;
	delete myconn;
	myfile = 0;
	myconn = 0;

	m_eShow.SetFocus();

	return 0;
}


void Clive_scheduleDlg::OnBnClickedCheckAll()
{
	if (m_cbAll.GetCheck() == BST_CHECKED)
	{
		m_cbSports.SetCheck(1);
		m_cbConcert.SetCheck(1);
		m_cbNews.SetCheck(1);
		m_cbAuto.SetCheck(1);
		m_cbEdu.SetCheck(1);
		m_cbEnt.SetCheck(1);
		m_cbFinance.SetCheck(1);
		m_cbGame.SetCheck(1);
		m_cbLocal.SetCheck(1);
		m_cbTech.SetCheck(1);
		m_cbTv.SetCheck(1);
		m_cbVariety.SetCheck(1);
	}
	else
	{
		m_cbSports.SetCheck(0);
		m_cbConcert.SetCheck(0);
		m_cbNews.SetCheck(0);
		m_cbAuto.SetCheck(0);
		m_cbEdu.SetCheck(0);
		m_cbEnt.SetCheck(0);
		m_cbFinance.SetCheck(0);
		m_cbGame.SetCheck(0);
		m_cbLocal.SetCheck(0);
		m_cbTech.SetCheck(0);
		m_cbTv.SetCheck(0);
		m_cbVariety.SetCheck(0);
	}
}


void Clive_scheduleDlg::OnBnClickedBtnClean()
{
	m_eShow.SetWindowTextW(L"");
}


void Clive_scheduleDlg::OnBnClickedBtnNext()
{
	if (m_stRsp.finish == 1 && m_stReq.csPageType == "forward")
	{
		m_eShow.ReplaceSel(L"�ѵ���ͷ���뻻һ������\r\n");
		return;
	}
	
	m_stReq.csPageType = L"forward";
	m_stReq.csPageStart = L"";
	m_stReq.csPageStart.Format(L"%d", m_stRsp.next_start);

	GetLiveSchedule(m_stReq);
}


void Clive_scheduleDlg::OnBnClickedBtnLast()
{
	if (m_stRsp.finish == 1 && m_stReq.csPageType == "backward")
	{
		m_eShow.ReplaceSel(L"�ѵ���ͷ���뻻һ������\r\n");
		return;
	}

	m_stReq.csPageType = L"backward";
	m_stReq.csPageStart = L"";
	m_stReq.csPageStart.Format(L"%d", m_stRsp.next_start);

	GetLiveSchedule(m_stReq);
}


void Clive_scheduleDlg::OnBnClickedBtnAbout()
{
	CLiveAbout *pDlg = new CLiveAbout;
	pDlg->Create(IDD_DIALOG_ABOUT, this);
	pDlg->m_eAbout.SetSel(-1);
	pDlg->m_eAbout.ReplaceSel(L"\t\t\t      ����\r\n");
	pDlg->m_eAbout.ReplaceSel(L"�����ߣ�v_shkhuang\r\n");
	pDlg->m_eAbout.ReplaceSel(L"������˵����\r\n");
	pDlg->m_eAbout.ReplaceSel(L"��С��𣺶Դ�������ϸ�֣�Ŀǰֻ����������ࡣ��ǰֵ������\r\n\
  100��NBA\r\n\
  101���г�\r\n\
  102��Ӣ��\r\n\
  104�����\r\n\
  105��ŷ��\r\n\
  109�����籭\r\n\
  110��CBA\r\n����ֵ����ϵ���߻�ȡ���������ʹ�ã�100,101");
	pDlg->m_eAbout.SetReadOnly();
	pDlg->ShowWindow(SW_SHOW);
}


void Clive_scheduleDlg::OnBnClickedCancel()
{
	if (MessageBox(L"ȷ���˳���\r\n��ӭ�´ι���^_^",L"ֱ����Ŀ��", MB_OKCANCEL) == 1)
		CDialogEx::OnCancel();
}


void Clive_scheduleDlg::OnBnClickedCheckOntop()
{
	if (m_cbOnTop.GetCheck() == BST_CHECKED)
		SetWindowPos(&wndTopMost, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	else if (m_cbOnTop.GetCheck() == BST_UNCHECKED)
		SetWindowPos(&wndNoTopMost, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
}


void Clive_scheduleDlg::OnBnClickedBtnMin()
{
	ShowWindow(SW_MINIMIZE); //���������� 
}
