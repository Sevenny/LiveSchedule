
// live_scheduleDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "live_schedule.h"
#include "LiveAbout.h"


// Clive_scheduleDlg �Ի���
class Clive_scheduleDlg : public CDialogEx
{
// ����
public:
	Clive_scheduleDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LIVE_SCHEDULE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedCheckAll();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBtnClean();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedBtnNext();
	afx_msg void OnBnClickedBtnLast();
	afx_msg void OnBnClickedBtnAbout();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedCheckOntop();
	afx_msg void OnBnClickedBtnMin();
	DECLARE_MESSAGE_MAP()

public:
	int GetLiveSchedule(const LiveRequest req);
	void GetItemValue(LiveRequest &req);

	CString m_csDomain;
	CString m_csArgs;
	LiveRequest m_stReq;
	LiveResponse m_stRsp;

public:
	CEdit m_eShow;
	CEdit m_eResult;
	CEdit m_eTimeStart;
	CEdit m_eTimeEnd;
	CListBox m_lSite;
	CListBox m_lCate;
	CButton m_rCidYes;
	CButton m_rCidNo;
	CButton m_rForward;
	CButton m_rBackward;
	CButton m_rSiteAll;
	CButton m_rSports;
	CButton m_rConcert;
	CButton m_rVariety;
	CButton m_rNews;
	CButton m_rGames;
	CButton m_rTv;
	CButton m_rEnt;
	CButton m_rFinance;
	CButton m_rTech;
	CButton m_rLocal;
	CButton m_rEdu;
	CButton m_rAuto;
	CEdit m_eCate;
	CButton m_cbAll;
	CButton m_cbSports;
	CButton m_cbConcert;
	CButton m_cbVariety;
	CButton m_cbNews;
	CButton m_cbGame;
	CButton m_cbEnt;
	CButton m_cbTv;
	CButton m_cbTech;
	CButton m_cbFinance;
	CButton m_cbAuto;
	CButton m_cbLocal;
	CButton m_cbEdu;
	CButton m_cbStatus1;
	CButton m_cbStatus2;
	CButton m_cbStatus3;
	CEdit m_ePageSize;
	CEdit m_ePageStart;
	CButton m_cbFree;
	CButton m_cbVip;
	CButton m_cbTest;
	CButton m_cbVer1_1;
	CButton m_cbOnTop;
	
};