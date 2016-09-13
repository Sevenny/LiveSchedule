
// live_scheduleDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "live_schedule.h"
#include "LiveAbout.h"
#include "afxdtctl.h"
#include "afxcmn.h"
#include <wchar.h>

// Clive_scheduleDlg 对话框
class Clive_scheduleDlg : public CDialogEx
{
// 构造
public:
	Clive_scheduleDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_LIVE_SCHEDULE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL	OnInitDialog();
	BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void	OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void	OnBnClickedCheckAll();
	afx_msg void	OnBnClickedOk();
	afx_msg void	OnBnClickedBtnClean();
	afx_msg void	OnBnClickedButton2();
	afx_msg void	OnBnClickedBtnNext();
	afx_msg void	OnBnClickedBtnLast();
	afx_msg void	OnBnClickedBtnAbout();
	afx_msg void	OnBnClickedCancel();
	afx_msg void	OnBnClickedCheckOntop();
	afx_msg void	OnBnClickedBtnMin();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedCheckSports();
	afx_msg void OnBnClickedCheckConcert();
	afx_msg void OnBnClickedCheckVariety();
	afx_msg void OnBnClickedCheckNews();
	afx_msg void OnBnClickedCheckGame();
	afx_msg void OnBnClickedCheckEnt();
	afx_msg void OnBnClickedCheckTv();
	afx_msg void OnBnClickedCheckTech();
	afx_msg void OnBnClickedCheckFinance();
	afx_msg void OnBnClickedCheckAuto();
	afx_msg void OnBnClickedCheckLocal();
	afx_msg void OnBnClickedCheckEdu();
	afx_msg void OnBnClickedCheckHistory();
	afx_msg void OnBnClickedCheckSchedule();
	afx_msg void OnBnClickedCheckDomain2();
	afx_msg void OnBnClickedCheckLiveinfo();
	afx_msg void OnDtnDatetimechangeDatetimeEnd(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedCheckVer11();
	afx_msg void OnBnClickedCheckDomain();
	DECLARE_MESSAGE_MAP()

public:
	int GetLiveSchedule(const LiveRequest req);//从客厅读服务拉取节目单
	void GetItemValue(LiveRequest &req);
	void SetNowTime();
	bool IsAllCheck();
	int GetLiveFromServer(CString csType);//从直播平台拉取
	int GetLiveInfo(CString csPid);

	CString			m_csDomain;
	CString			m_csArgs;
	CTime			m_ctTimeStart;
	CTime			m_ctTimeEnd;
	LiveRequest		m_stReq;
	LiveResponse	m_stRsp;
	CToolTipCtrl    m_Mytip;
	CBrush			m_brRed;
	COLORREF		m_clRed;
	CFont			m_font;
	vector<CString> m_vecSite;

public:
	CEdit			m_eResult;
	CButton			m_rForward;
	CButton			m_rBackward;
	CEdit			m_eCate;
	CButton			m_cbAll;
	CButton			m_cbSports;
	CButton			m_cbConcert;
	CButton			m_cbVariety;
	CButton			m_cbNews;
	CButton			m_cbGame;
	CButton			m_cbEnt;
	CButton			m_cbTv;
	CButton			m_cbTech;
	CButton			m_cbFinance;
	CButton			m_cbAuto;
	CButton			m_cbLocal;
	CButton			m_cbEdu;
	CButton			m_cbStatus1;
	CButton			m_cbStatus2;
	CButton			m_cbStatus3;
	CEdit			m_ePageSize;
	CEdit			m_ePageStart;
	CButton			m_cbFree;
	CButton			m_cbVip;
	CButton			m_cbTest;
	CButton			m_cbVer1_1;
	CButton			m_cbOnTop;
	CDateTimeCtrl	m_tStartDate;
	CDateTimeCtrl	m_tEndDate;
	CButton			m_cbStart;
	CButton			m_cbEnd;
	CEdit			m_eTime;
	CButton			m_cbDebug;
	CButton			m_cbCid;
	CEdit			m_eDomain;
	CEdit			m_ePid;
	CButton			m_cbHistory;
	CButton			m_cbSchedule;
	CButton			m_cbDomain;
	CButton			m_cbShowTV;
	CButton			m_cbPid;
	CButton			m_btNext;
	CButton			m_btLast;
	CRichEditCtrl	m_reShow;
};
