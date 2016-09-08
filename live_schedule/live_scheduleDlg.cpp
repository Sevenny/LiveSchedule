
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

// Clive_scheduleDlg 消息处理程序

BOOL Clive_scheduleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//ShowWindow(SW_MINIMIZE);

	// TODO:  在此添加额外的初始化代码
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
	m_Mytip.AddTool(GetDlgItem(IDC_CHECK_START), L"默认不设置开始时间，如需要请勾选"); 
	m_Mytip.AddTool(GetDlgItem(IDC_CHECK_END),	 L"默认不设置结束时间，如需要请勾选");
	m_Mytip.AddTool(GetDlgItem(IDC_EDIT_CATE),	 L"小类别的填写请查看帮助？");
	m_Mytip.SetDelayTime(200);					//设置延迟
	m_Mytip.SetTipTextColor(RGB(0, 0, 255));	//设置提示文本的颜色
	m_Mytip.SetTipBkColor(RGB(255, 255, 255));	//设置提示框的背景颜色
	m_Mytip.Activate(TRUE);						//设置是否启用提示

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
	m_stReq.clear();
	m_csDomain = _T(VIDEO_DOMAIN);

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
		m_stReq.csTimeStart = csTimeStart;
	}
	else
		m_stReq.csTimeStart = L"0";

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

//获取节目列表并且解析输出
int Clive_scheduleDlg::GetLiveSchedule(const LiveRequest req)
{
	m_eShow.SetWindowTextW(L"");
	CString csUrl;
	string strTimeStart = StringnizeTimeStamp((int)_ttoi(req.csTimeStart));
	CString csTimeStart;
	csTimeStart = strTimeStart.c_str();
	m_eShow.ReplaceSel(L"开始时间 : "	+ csTimeStart		+ L"\r\n");
	m_eShow.ReplaceSel(L"结束时间 : "	+ req.csTimeEnd		+ L"\r\n");
	m_eShow.ReplaceSel(L"每页数量 : "	+ req.csPageSize	+ L"\r\n");
	m_eShow.ReplaceSel(L"翻页起点 : "	+ req.csPageStart	+ L"\r\n");
	m_eShow.ReplaceSel(L"翻页类型 : "	+ req.csPageType	+ L"\r\n");
	m_eShow.ReplaceSel(L"大  类 别 : "	+ req.csSite		+ L"\r\n");
	m_eShow.ReplaceSel(L"小  类 别 : "	+ req.csCate		+ L"\r\n");
	m_eShow.ReplaceSel(L"直播状态 : "	+ req.csStatus		+ L"\r\n");
	m_eShow.ReplaceSel(L"付费状态 : "	+ req.csPay			+ L"\r\n");
	m_eShow.ReplaceSel(L"过滤Cid   : "	+ m_stReq.csCid		+ L"\r\n");
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
		m_eShow.ReplaceSel(L"已到尽头，请换一个方向\r\n");
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
		m_eShow.ReplaceSel(L"已到尽头，请换一个方向\r\n");
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
	pDlg->m_eAbout.ReplaceSel(L"\t\t\t      关于\r\n");
	pDlg->m_eAbout.ReplaceSel(L"※作者：v_shkhuang\r\n");
	pDlg->m_eAbout.ReplaceSel(L"※参数说明：\r\n");
	pDlg->m_eAbout.ReplaceSel(L"※小类别：对大类别进行细分，目前只针对体育分类。当前值包括：\r\n\
  100、NBA\r\n\
  101、中超\r\n\
  102、英超\r\n\
  104、意甲\r\n\
  105、欧冠\r\n\
  109、世界杯\r\n\
  110、CBA\r\n其他值请联系作者获取。可以组合使用：100,101");
	pDlg->m_eAbout.SetReadOnly();
	pDlg->ShowWindow(SW_SHOW);
}


void Clive_scheduleDlg::OnBnClickedCancel()
{
	if (MessageBox(L"确认退出？\r\n欢迎下次光临^_^",L"直播节目单", MB_OKCANCEL) == 1)
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
	ShowWindow(SW_MINIMIZE); //隐藏主窗口 
}
