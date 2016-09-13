
// live_scheduleDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "live_schedule.h"
#include "live_scheduleDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clive_scheduleDlg 对话框



Clive_scheduleDlg::Clive_scheduleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Clive_scheduleDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON_LIVE);
}

void Clive_scheduleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ERROR,		m_eResult);
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
	DDX_Control(pDX, IDC_EDIT_TIME,			m_eTime);
	DDX_Control(pDX, IDC_CHECK_DEBUG,		m_cbDebug);
	DDX_Control(pDX, IDC_CHECK_CID,			m_cbCid);
	DDX_Control(pDX, IDC_EDIT_DOMAIN,		m_eDomain);
	DDX_Control(pDX, IDC_EDIT_PAGESIZE2,	m_ePid);
	DDX_Control(pDX, IDC_CHECK_HISTORY,		m_cbHistory);
	DDX_Control(pDX, IDC_CHECK_SCHEDULE,	m_cbSchedule);
	DDX_Control(pDX, IDC_CHECK_DOMAIN,		m_cbDomain);
	DDX_Control(pDX, IDC_CHECK_ONLYTV,		m_cbShowTV);
	DDX_Control(pDX, IDC_CHECK_LIVEINFO,	m_cbPid);
	DDX_Control(pDX, IDC_RADIO_BACKWARD,	m_rBackward);
	DDX_Control(pDX, IDC_BTN_NEXT,			m_btNext);
	DDX_Control(pDX, IDC_BTN_LAST,			m_btLast);
	DDX_Control(pDX, IDC_RESHOW,			m_reShow);
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
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_CHECK_SPORTS,		&Clive_scheduleDlg::OnBnClickedCheckSports)
	ON_BN_CLICKED(IDC_CHECK_CONCERT,	&Clive_scheduleDlg::OnBnClickedCheckConcert)
	ON_BN_CLICKED(IDC_CHECK_VARIETY,	&Clive_scheduleDlg::OnBnClickedCheckVariety)
	ON_BN_CLICKED(IDC_CHECK_NEWS,		&Clive_scheduleDlg::OnBnClickedCheckNews)
	ON_BN_CLICKED(IDC_CHECK_GAME,		&Clive_scheduleDlg::OnBnClickedCheckGame)
	ON_BN_CLICKED(IDC_CHECK_ENT,		&Clive_scheduleDlg::OnBnClickedCheckEnt)
	ON_BN_CLICKED(IDC_CHECK_TV,			&Clive_scheduleDlg::OnBnClickedCheckTv)
	ON_BN_CLICKED(IDC_CHECK_TECH,		&Clive_scheduleDlg::OnBnClickedCheckTech)
	ON_BN_CLICKED(IDC_CHECK_FINANCE,	&Clive_scheduleDlg::OnBnClickedCheckFinance)
	ON_BN_CLICKED(IDC_CHECK_AUTO,		&Clive_scheduleDlg::OnBnClickedCheckAuto)
	ON_BN_CLICKED(IDC_CHECK_LOCAL,		&Clive_scheduleDlg::OnBnClickedCheckLocal)
	ON_BN_CLICKED(IDC_CHECK_EDU,		&Clive_scheduleDlg::OnBnClickedCheckEdu)
	ON_BN_CLICKED(IDC_CHECK_DOMAIN,		&Clive_scheduleDlg::OnBnClickedCheckDomain)
	ON_BN_CLICKED(IDC_CHECK_HISTORY,	&Clive_scheduleDlg::OnBnClickedCheckHistory)
	ON_BN_CLICKED(IDC_CHECK_SCHEDULE,	&Clive_scheduleDlg::OnBnClickedCheckSchedule)
	ON_BN_CLICKED(IDC_CHECK_LIVEINFO,	&Clive_scheduleDlg::OnBnClickedCheckLiveinfo)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIME_END, &Clive_scheduleDlg::OnDtnDatetimechangeDatetimeEnd)
	ON_BN_CLICKED(IDC_CHECK_VER_1_1,	&Clive_scheduleDlg::OnBnClickedCheckVer11)
END_MESSAGE_MAP()


BOOL Clive_scheduleDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_MOUSEMOVE)
		m_Mytip.RelayEvent(pMsg);
	return CDialog::PreTranslateMessage(pMsg);
}

// Clive_scheduleDlg 消息处理程序

BOOL Clive_scheduleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	ShowWindow(SW_SHOW);

	// TODO:  在此添加额外的初始化代码
	m_rForward.SetCheck(1);
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

	m_reShow.SetSel(-1, -1);
	m_csDomain = _T(VIDEO_DOMAIN);
	m_reShow.SetReadOnly();

	m_tStartDate.SetFormat(L"yyyy-MM-dd HH:mm:ss");
	m_tEndDate.SetFormat(L"yyyy-MM-dd HH:mm:ss");
	COleDateTime oleDate;
	m_tStartDate.GetTime(oleDate);
	oleDate.SetDateTime(oleDate.GetYear(), oleDate.GetMonth(), oleDate.GetDay(), 0, 0, 0);
	m_tStartDate.SetTime(oleDate);

	oleDate.SetDateTime(oleDate.GetYear(), oleDate.GetMonth(), oleDate.GetDay(), 23, 59, 59);
	m_tEndDate.SetTime(oleDate);

	//按钮提示
	m_Mytip.Create(this);
	m_Mytip.AddTool(GetDlgItem(IDC_CHECK_START), L"默认不设置开始时间，如需要请勾选"); 
	m_Mytip.AddTool(GetDlgItem(IDC_CHECK_END),	 L"默认不设置结束时间，如需要请勾选");
	m_Mytip.AddTool(GetDlgItem(IDC_EDIT_CATE),	 L"小类别的填写请查看帮助？");
	m_Mytip.AddTool(GetDlgItem(IDC_CHECK_ONTOP), L"总是在最前");
	m_Mytip.SetDelayTime(200);					//设置延迟
	m_Mytip.SetTipTextColor(RGB(0, 0, 255));	//设置提示文本的颜色
	m_Mytip.SetTipBkColor(RGB(255, 255, 255));	//设置提示框的背景颜色
	m_Mytip.Activate(TRUE);						//设置是否启用提示

	m_clRed = RGB(255, 0, 0);
	m_brRed.CreateSolidBrush(m_clRed);

	m_font.CreateFontW(13, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, 0, 1,
		OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS,
		_T("宋体"));
	m_reShow.SetFont(&m_font);
	//AllocConsole();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Clive_scheduleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Clive_scheduleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//读取各种值。传给
void Clive_scheduleDlg::GetItemValue(LiveRequest &req)
{
	req.clear();
	m_vecSite.clear();
	//开始时间
	if (m_cbStart.GetCheck() == BST_CHECKED)
	{
		CString csTimeStart = L"";
		m_tStartDate.GetTime(m_ctTimeStart);
		csTimeStart.Format(L"%d-%d-%d %02d:%02d:%02d", m_ctTimeStart.GetYear(), m_ctTimeStart.GetMonth(), m_ctTimeStart.GetDay(),
			m_ctTimeStart.GetHour(), m_ctTimeStart.GetMinute(), m_ctTimeStart.GetSecond());

		time_t iTimeStart = StampnizeTime(csTimeStart);
		csTimeStart = L"";
		csTimeStart.Format(L"%ld", iTimeStart);
		req.csTimeStart = csTimeStart;
	}
	else
		req.csTimeStart = L"0";

	//结束时间
	if (m_cbEnd.GetCheck() == BST_CHECKED)
	{
		CString csTimeEnd = L"";
		m_tEndDate.GetTime(m_ctTimeEnd);
		csTimeEnd.Format(L"%d-%d-%d %02d:%02d:%02d", m_ctTimeEnd.GetYear(), m_ctTimeEnd.GetMonth(), m_ctTimeEnd.GetDay(),
			m_ctTimeEnd.GetHour(), m_ctTimeEnd.GetMinute(), m_ctTimeEnd.GetSecond());

		time_t iTimeEnd = StampnizeTime(csTimeEnd);
		csTimeEnd = L"";
		csTimeEnd.Format(L"%ld", iTimeEnd);
		req.csTimeEnd = csTimeEnd;
	}
	else
		req.csTimeEnd = L"0";

	m_ePageSize.GetWindowTextW(req.csPageSize);

	m_ePageStart.GetWindowTextW(req.csPageStart);

	m_eCate.GetWindowTextW(req.csCate);

	if (m_cbCid.GetCheck() == BST_CHECKED)
		req.csCid = L"yes";
	else
		req.csCid = L"no";

	if (m_rForward.GetCheck() == BST_CHECKED)
		req.csPageType = L"forward";
	else
		req.csPageType = L"backward";

	if (m_cbAll.GetCheck() == BST_CHECKED)
		req.csSite = L"all";
	else
	{
		req.csSite = L"";
		if (m_cbSports.GetCheck() == BST_CHECKED)
		{
			req.csSite.Append(L"sports,");
			m_vecSite.push_back(L"sports");
		}
		if (m_cbConcert.GetCheck() == BST_CHECKED)
		{
			req.csSite.Append(L"concert,");
			m_vecSite.push_back(L"concert");
		}
		if (m_cbVariety.GetCheck() == BST_CHECKED)
		{
			req.csSite.Append(L"variety,");
			m_vecSite.push_back(L"variety");
		}
		if (m_cbGame.GetCheck() == BST_CHECKED)
		{
			req.csSite.Append(L"game,");
			m_vecSite.push_back(L"game");
		}
		if (m_cbNews.GetCheck() == BST_CHECKED)
		{
			req.csSite.Append(L"news,");
			m_vecSite.push_back(L"news");
		}
		if (m_cbTv.GetCheck() == BST_CHECKED)
		{
			req.csSite.Append(L"tv,");
			m_vecSite.push_back(L"tv");
		}
		if (m_cbLocal.GetCheck() == BST_CHECKED)
		{
			req.csSite.Append(L"local,");
			m_vecSite.push_back(L"local");
		}
		if (m_cbEnt.GetCheck() == BST_CHECKED)
		{
			req.csSite.Append(L"ent,");
			m_vecSite.push_back(L"ent");
		}
		if (m_cbEdu.GetCheck() == BST_CHECKED)
		{
			req.csSite.Append(L"edu,");
			m_vecSite.push_back(L"edu");
		}
		if (m_cbAuto.GetCheck() == BST_CHECKED)
		{
			req.csSite.Append(L"auto,");
			m_vecSite.push_back(L"auto");
		}
		if (m_cbFinance.GetCheck() == BST_CHECKED)
		{
			req.csSite.Append(L"finance,");
			m_vecSite.push_back(L"finance");
		}
		if (m_cbTech.GetCheck() == BST_CHECKED)
		{
			req.csSite.Append(L"tech,");
			m_vecSite.push_back(L"tech");
		}
	}
	if (req.csSite == "")
		req.csSite = L"all";

	req.csStatus = L"";
	if (m_cbStatus1.GetCheck() == BST_CHECKED)
		req.csStatus.Append(L"1,");
	if (m_cbStatus2.GetCheck() == BST_CHECKED)
		req.csStatus.Append(L"2,");
	if (m_cbStatus3.GetCheck() == BST_CHECKED)
		req.csStatus.Append(L"3,");

	req.csPay = L"";
	if (m_cbFree.GetCheck() == BST_CHECKED)
		req.csPay.Append(L"0,");
	if (m_cbVip.GetCheck() == BST_CHECKED)
		req.csPay.Append(L"1,");

	if (m_cbTest.GetCheck() == BST_CHECKED)
		m_csDomain = _T(VIDEO_DOMAIN_TEST);

	m_csArgs = URL_ARGS;
	if (m_cbVer1_1.GetCheck() == BST_CHECKED)
		m_csArgs.Append(L"&version=1.1");
}
void Clive_scheduleDlg::OnBnClickedOk()
{
	int iRet = 0;
	//查询pid详细信息
	if (m_cbPid.GetCheck() == BST_CHECKED)
	{
		CString csPid;
		if (m_cbDomain.GetCheck() == BST_UNCHECKED)
			m_csDomain = _T(LIVE_DOMAIN);
		m_ePid.GetWindowTextW(csPid);
		iRet = GetLiveInfo(csPid);
	}
	else if (m_cbHistory.GetCheck() == BST_CHECKED)
	{
		if (m_cbDomain.GetCheck() == BST_UNCHECKED)
			m_csDomain = _T(LIVE_DOMAIN);
		iRet = GetLiveFromServer(L"history");
	}
	else if (m_cbSchedule.GetCheck() == BST_CHECKED)
	{
		if (m_cbDomain.GetCheck() == BST_UNCHECKED)
			m_csDomain = _T(LIVE_DOMAIN);
		iRet = GetLiveFromServer(L"schedule");
	}
	else
	{
		if (m_cbDomain.GetCheck() == BST_UNCHECKED)
			m_csDomain = _T(VIDEO_DOMAIN);
		GetItemValue(m_stReq);
		iRet = GetLiveSchedule(m_stReq);
		CButton *btn = (CButton*)GetDlgItem(IDC_BTN_NEXT);
		btn->EnableWindow();
		btn = (CButton*)GetDlgItem(IDC_BTN_LAST);
		btn->EnableWindow();
	}
	CButton *btn = (CButton*)GetDlgItem(IDC_BTN_CLEAN);
	btn->EnableWindow();
}
static int iNouse = 0;
//获取节目列表并且解析输出
int Clive_scheduleDlg::GetLiveSchedule(const LiveRequest req)
{
	m_reShow.SetWindowTextW(L"");
	CString csUrl, csVer_1_1;
	csUrl.Format(m_csArgs, req.csTimeStart, req.csCate, req.csTimeEnd, req.csSite, req.csStatus, req.csCid, req.csPay, ++iNouse);
	if (m_cbVer1_1.GetCheck() == BST_CHECKED)
	{
		csVer_1_1.Format(_T(ARGS_V_1_1), req.csPageType, req.csPageSize, req.csPageStart);
		csUrl.Append(csVer_1_1);
	}
	
	csUrl.Append(_T(URL_QUA));
	CInternetSession mysession;
	CHttpConnection *myconn = mysession.GetHttpConnection(m_csDomain);
	CHttpFile *myfile = myconn->OpenRequest(L"GET", csUrl);
	myfile->SendRequest();

	if (m_cbDebug.GetCheck() == BST_CHECKED)
	{
		string strTimeStart = StringnizeTimeStamp((int)_ttoi(req.csTimeStart));
		string strTimeEnd = StringnizeTimeStamp((int)_ttoi(req.csTimeEnd));
		CString csTimeStart, csTimeEnd;
		csTimeStart = strTimeStart.c_str();
		csTimeEnd = strTimeEnd.c_str();
		m_reShow.ReplaceSel(L"开始时间 : " + csTimeStart + L"\r\n");
		m_reShow.ReplaceSel(L"结束时间 : " + csTimeEnd + L"\r\n");
		m_reShow.ReplaceSel(L"每页数量 : " + req.csPageSize + L"\r\n");
		m_reShow.ReplaceSel(L"翻页起点 : " + req.csPageStart + L"\r\n");
		m_reShow.ReplaceSel(L"翻页类型 : " + req.csPageType + L"\r\n");
		m_reShow.ReplaceSel(L"大 类 别 : " + req.csSite + L"\r\n");
		m_reShow.ReplaceSel(L"小 类 别 : " + req.csCate + L"\r\n");
		m_reShow.ReplaceSel(L"直播状态 : " + req.csStatus + L"\r\n");
		m_reShow.ReplaceSel(L"付费状态 : " + req.csPay + L"\r\n");
		m_reShow.ReplaceSel(L"过滤Cid  : " + m_stReq.csCid + L"\r\n");
		m_reShow.ReplaceSel(L"URL:" + m_csDomain + csUrl + L"\r\n");
	}

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

	//HANDLE hdlWrite = GetStdHandle(STD_OUTPUT_HANDLE); //这里也可以使用STD_ERROR_HANDLE

	CString strTemp = strUtf8;
	std::string value;
	Json::Reader reader;
	Json::Value root;
	if (!reader.parse((char*)strUtf8.GetBuffer(0), root))  // reader将Json字符串解析到root，root将包含Json里所有子元素  
	{
		std::string errMsg = reader.getFormatedErrorMessages();
		strTemp = errMsg.c_str();
		m_eResult.SetWindowTextW(strTemp);
		m_reShow.ReplaceSel(strUnicode);
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
	csErrMsg.Format(L"Ret:%d | Next:%d | Cost:%dms | Msg:", code, m_stRsp.next_start, root["result"]["cost_time"].asInt() / 1000);
	csErrMsg.Append(strTemp);
	m_eResult.SetWindowTextW(csErrMsg);
	Json::Value stLives = root["data"]["lives"];
	

	int iSize = stLives.size();
	CString csLiveShow = L"", csLiveTemp = L"";
	LiveInfo stInfo;
	m_reShow.ReplaceSel(L"===================================================================================================================\r\n");
	for (int i = 0; i < iSize; i++)
	{
		stInfo.clear();
		csLiveTemp = L"";
		CString csErrMsg;
		Json::Value Live = stLives[i];
		std::string strPid, strType, strTitle, strStart, strEnd;

		if (!Live["pid"].empty() && Live["pid"].isString())
		{
			strPid = Live["pid"].asString();
			stInfo.csPid = strPid.c_str();
		}
		else
		{
			csErrMsg = L"pid error";
			m_eResult.SetWindowTextW(csErrMsg);
		}
		if (!Live["site"].empty() && Live["site"].isString())
		{
			strType = Live["site"].asString();
			stInfo.csSite = strType.c_str();
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
		stInfo.csStart = strStart.c_str();
		strEnd = jStream["end_time"].asString();
		stInfo.csEnd = strEnd.c_str();

		if (!Live["title"].empty() && Live["title"].isString())
		{
			strTitle = Live["title"].asString();
			char *pszTitle = (char *)strTitle.data();
			CString csTitleUnicode;
			stInfo.csTitle = UTF8ToUnicode(pszTitle);
		}
		else
		{
			csErrMsg = L"title error";
			m_eResult.SetWindowTextW(csErrMsg);
		}
		csLiveTemp.Format(L"| %02d | %5s | %7s | %s | %s | %s\r\n", i+1, stInfo.csPid, stInfo.csSite,
			stInfo.csStart, stInfo.csEnd, stInfo.csTitle);
		csLiveShow.Append(csLiveTemp);
		UpdateData(FALSE);
	}
	m_reShow.ReplaceSel(csLiveShow);
	m_reShow.ReplaceSel(L"===================================================================================================================\r\n");

	myfile->Close();
	myconn->Close();
	mysession.Close();
	delete myfile;
	delete myconn;
	myfile = 0;
	myconn = 0;
	strUtf8.ReleaseBuffer();
	strUnicode.ReleaseBuffer();
	m_reShow.SetFocus();

	return 0;
}



//获取某个节目详细信息
int Clive_scheduleDlg::GetLiveInfo(CString csPid)
{
	int iRet = 0;

	m_reShow.SetWindowTextW(L"");

	CString csDomain = _T(LIVE_DOMAIN);
	CString csUrl = _T(URL_PID);
	csUrl.Append(csPid);
	CInternetSession mysession;
	CHttpConnection *myconn = mysession.GetHttpConnection(csDomain);
	CHttpFile *myfile = myconn->OpenRequest(L"GET", csUrl);
	myfile->SendRequest();

	if (m_cbDebug.GetCheck() == BST_CHECKED)
	{
		m_reShow.ReplaceSel(L"URL:" + csDomain + csUrl + L"\r\n");
	}

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

	CString strTemp = strUtf8;
	std::string value;
	Json::Reader reader;
	Json::Value root;
	if (!reader.parse((char*)strUtf8.GetBuffer(0), root))  // reader将Json字符串解析到root，root将包含Json里所有子元素  
	{
		std::string errMsg = reader.getFormatedErrorMessages();
		strTemp = errMsg.c_str();
		m_eResult.SetWindowTextW(strTemp);
		m_reShow.SetWindowTextW(strUtf8);
		return -1;
	}
	CString csErrMsg;
	string strErrMsg = root["response"]["message"].asString();
	strTemp = strErrMsg.c_str();
	csErrMsg.Format(L"Ret:%d | Msg:",root["response"]["code"].asInt());
	csErrMsg.Append(strTemp);
	m_eResult.SetWindowTextW(csErrMsg);

	CString csLiveInfo = L"";
	Json::Value live = root["data"]["live"];

	string strItem = live["pid"].asString();
	CString csItem;
	csItem = strItem.c_str();
	csLiveInfo.Append(L"p  i  d:\t" + csItem + L"\r\n");

	strItem = live["title"].asString();
	char *pszTitle = (char *)strItem.data();
	csItem = UTF8ToUnicode(pszTitle);
	csLiveInfo.Append(L"标   题:\t" + csItem + L"\r\n");

	strItem = live["sub_title"].asString();
	pszTitle = (char *)strItem.data();
	csItem = UTF8ToUnicode(pszTitle);
	csLiveInfo.Append(L"副 标 题:\t" + csItem + L"\r\n");

	int iCatalogID = live["catalog_id"].asInt();
	char szCatalogID[10] = {0};
	sprintf_s(szCatalogID, sizeof(szCatalogID), "%d", iCatalogID);
	strItem = szCatalogID;
	pszTitle = (char *)strItem.data();
	csItem = UTF8ToUnicode(pszTitle);
	csLiveInfo.Append(L"catalogid:\t" + csItem + L"\r\n");

	strItem = live["site"].asString();
	pszTitle = (char *)strItem.data();
	csItem = UTF8ToUnicode(pszTitle);
	csLiveInfo.Append(L"节目类型:\t" + csItem + L"\r\n");

	strItem = live["live_type"].asString();
	pszTitle = (char *)strItem.data();
	csItem = UTF8ToUnicode(pszTitle);
	csLiveInfo.Append(L"子 类 型:\t" + csItem + L"\r\n");

	strItem = live["start_time"].asString();
	csItem = strItem.c_str();
	csLiveInfo.Append(L"开始时间:\t" + csItem + L"\r\n");

	strItem = live["end_time"].asString();
	csItem = strItem.c_str();
	csLiveInfo.Append(L"结束时间:\t" + csItem + L"\r\n");

	Json::Value Streams = live["streams"];
	CString csType = L"";
	for (unsigned int i = 0; i < Streams.size(); i++)
	{
		Json::Value jStream = Streams[i];
		strItem = jStream["type"].asString();
		csItem = strItem.c_str();
		csType.Append(csItem + "\t");
	}
	csLiveInfo.Append(L"终   端:\t" + csType + "\r\n");

	iCatalogID = live["flags"]["search_flag"].asInt();
	sprintf_s(szCatalogID, sizeof(szCatalogID), "%d", iCatalogID);
	strItem = szCatalogID;
	csItem = strItem.c_str();
	csLiveInfo.Append(L"search_flag:\t" + csItem + "\r\n");

	iCatalogID = live["flags"]["pay_flag"].asInt();
	sprintf_s(szCatalogID, sizeof(szCatalogID), "%d", iCatalogID);
	strItem = szCatalogID;
	csItem = strItem.c_str();
	csLiveInfo.Append(L"pay_flag:\t" + csItem + "\r\n");

	iCatalogID = live["flags"]["recommend_flag"].asInt();
	sprintf_s(szCatalogID, sizeof(szCatalogID), "%d", iCatalogID);
	strItem = szCatalogID;
	csItem = strItem.c_str();
	csLiveInfo.Append(L"recommend_flag:\t" + csItem + "\r\n");

	m_reShow.ReplaceSel(csLiveInfo);

	return 0;
}

//从直播平台拉取节目单列表
int Clive_scheduleDlg::GetLiveFromServer(CString csType)
{
	m_reShow.SetSel(0, -1);
	m_reShow.Clear();
	CString csUrl;
	csUrl.Format(_T(URL_LIVESERVER), csType, ++iNouse);
	CInternetSession mysession;
	CHttpConnection *myconn = mysession.GetHttpConnection(m_csDomain);
	CHttpFile *myfile = myconn->OpenRequest(L"GET", csUrl);
	myfile->SendRequest();

	if (m_cbDebug.GetCheck() == BST_CHECKED)
		m_reShow.ReplaceSel(csUrl + L"\r\n");

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

	//HANDLE hdlWrite = GetStdHandle(STD_OUTPUT_HANDLE); //这里也可以使用STD_ERROR_HANDLE

	CString strTemp = strUtf8;
	std::string value;
	Json::Reader reader;
	Json::Value root;
	if (!reader.parse((char*)strUtf8.GetBuffer(0), root))  // reader将Json字符串解析到root，root将包含Json里所有子元素  
	{
		std::string errMsg = reader.getFormatedErrorMessages();
		strTemp = errMsg.c_str();
		m_eResult.SetWindowTextW(strTemp);
		m_reShow.ReplaceSel(strUnicode);
		return -1;
	}

	Json::Value stLives = root["data"]["lives"];

	LiveRequest stReq;
	stReq.clear();
	GetItemValue(stReq);
	int iSize = stLives.size();
	bool bIsTV = FALSE;
	CString csLiveShow = L"";
	CString csLiveTemp = L"";
	m_reShow.ReplaceSel(L"===================================================================================================================\r\n");
	int iIndex = 0;
	LiveInfo stInfo;
	for (int i = 0; i < iSize; i++)
	{
		stInfo.clear();
		bIsTV = FALSE;
		csLiveTemp = L"";
		CString csErrMsg;
		Json::Value Live = stLives[i];
		std::string strPid, strType, strTitle, strStart, strEnd;
		CString csPid, csType, csTitle, csStart, csEnd, csIndex;
		
		if (!Live["pid"].empty() && Live["pid"].isString())
		{
			strPid = Live["pid"].asString();
			stInfo.csPid = strPid.c_str();
		}
		else
		{
			csErrMsg = L"pid error";
			m_eResult.SetWindowTextW(csErrMsg);
		}
		if (!Live["site"].empty() && Live["site"].isString())
		{
			strType = Live["site"].asString();
			stInfo.csSite = strType.c_str();
			if (m_vecSite.size() > 0)
			{
				bool bTrue = FALSE;//符合筛选条件
				for (unsigned int i = 0; i < m_vecSite.size(); i++)
				{
					CString csSite = m_vecSite.at(i);
					if (stInfo.csSite == csSite)
					{
						bTrue = TRUE;
						break;
					}
				}
				if (!bTrue)
					continue;
			}
		}
		else
		{
			csErrMsg = L"live_type error";
			m_eResult.SetWindowTextW(csErrMsg);
		}
		Json::Value jStreams = Live["streams"];
		CString csLiveType = L"", csStream = L"";
		for (unsigned int j = 0; j < jStreams.size(); j++)
		{
			Json::Value jStream = jStreams[j];
			strType = jStream["type"].asString();
			stInfo.csType = strType.c_str();
			if (stInfo.csType == L"tv")
				bIsTV = TRUE;
		}

		if (!Live["start_time"].empty() && Live["start_time"].isString())
		{
			strStart = Live["start_time"].asString();
			stInfo.csStart = strStart.c_str();
		}

		if (!Live["end_time"].empty() && Live["end_time"].isString())
		{
			strEnd = Live["end_time"].asString();
			stInfo.csEnd = strEnd.c_str();
		}

		if (!Live["title"].empty() && Live["title"].isString())
		{
			strTitle = Live["title"].asString();
			char *pszTitle = (char *)strTitle.data();
			stInfo.csTitle = UTF8ToUnicode(pszTitle);
		}
		else
		{
			csErrMsg = L"title error";
			m_eResult.SetWindowTextW(csErrMsg);
		}
		csLiveTemp = L"";
		//过滤非tv端
		if (m_cbShowTV.GetCheck() == BST_CHECKED)
		{
			if (bIsTV)
			{
				csLiveTemp.Format(L"%03d | %5s | %7s | %6s | %s | %s | %s", ++iIndex, stInfo.csPid, stInfo.csSite, stInfo.csType,
					stInfo.csStart, stInfo.csEnd, stInfo.csTitle);
				csLiveShow.Append(csLiveTemp + L"\r\n");
			}
		}
		else
		{
			csLiveTemp.Format(L"%03d | %5s | %7s | %6s | %s | %s | %s", ++iIndex, stInfo.csPid, stInfo.csSite, stInfo.csType,
				stInfo.csStart, stInfo.csEnd, stInfo.csTitle);
			csLiveShow.Append(csLiveTemp + L"\r\n");
		}

		UpdateData(FALSE);
	}
	m_reShow.ReplaceSel(csLiveShow);
	m_reShow.ReplaceSel(L"===================================================================================================================\r\n");

	myfile->Close();
	myconn->Close();
	mysession.Close();
	delete myfile;
	delete myconn;
	myfile = 0;
	myconn = 0;

	m_reShow.SetFocus();

	return 0;
}



void Clive_scheduleDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	switch (nIDEvent)
	{
		case TIMER_TIME	:
		{
			SetNowTime();
			break;
		}
		case TIMER2:
		{
			break;
		}
		default:
			break;
	}

	CDialogEx::OnTimer(nIDEvent);
}

void Clive_scheduleDlg::SetNowTime()
{
	COleDateTime date = COleDateTime::GetCurrentTime();
	CString csTime;
	csTime.Format(L"%d-%02d-%02d %02d:%02d:%02d", date.GetYear(), date.GetMonth(), date.GetDay(), date.GetHour(), date.GetMinute(), date.GetSecond());
	m_eTime.SetWindowTextW(csTime);
}



void Clive_scheduleDlg::OnBnClickedCheckVer11()
{
	if (m_cbVer1_1.GetCheck() == BST_CHECKED)
	{
		m_ePageSize.EnableWindow(1);
		m_rBackward.EnableWindow(1);
		m_rForward.EnableWindow(1);
		m_ePageStart.EnableWindow(1);
		m_btNext.EnableWindow(1);
		m_btLast.EnableWindow(1);
	}
	else if (m_cbVer1_1.GetCheck() == BST_UNCHECKED)
	{
		m_ePageSize.EnableWindow(0);
		m_rBackward.EnableWindow(0);
		m_rForward.EnableWindow(0);
		m_ePageStart.EnableWindow(0);
		m_btNext.EnableWindow(0);
		m_btLast.EnableWindow(0);
	}
}
