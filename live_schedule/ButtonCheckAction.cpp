// 按钮点击事件响应文件
//

#include "stdafx.h"
#include "live_schedule.h"
#include "live_scheduleDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



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
	m_reShow.SetWindowTextW(L"");
}


void Clive_scheduleDlg::OnBnClickedBtnNext()
{
	if (m_stRsp.finish == 1 && m_stReq.csPageType == "forward")
	{
		m_reShow.ReplaceSel(L"已到尽头，请换一个方向\r\n");
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
		m_reShow.ReplaceSel(L"已到尽头，请换一个方向\r\n");
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
	if (MessageBox(L"确认退出？\r\n欢迎下次光临^_^", L"直播节目单", MB_OKCANCEL) == 1)
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


int Clive_scheduleDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	SetTimer(TIMER_TIME, 1000, 0);
	SetTimer(TIMER2, 1000 * 60, 0);
	return 0;
}


bool Clive_scheduleDlg::IsAllCheck()
{
	if (m_cbSports.GetCheck() == BST_UNCHECKED)
		return FALSE;
	if (m_cbConcert.GetCheck() == BST_UNCHECKED)
		return FALSE;
	if (m_cbVariety.GetCheck() == BST_UNCHECKED)
		return FALSE;
	if (m_cbNews.GetCheck() == BST_UNCHECKED)
		return FALSE;
	if (m_cbGame.GetCheck() == BST_UNCHECKED)
		return FALSE;
	if (m_cbEnt.GetCheck() == BST_UNCHECKED)
		return FALSE;
	if (m_cbTv.GetCheck() == BST_UNCHECKED)
		return FALSE;
	if (m_cbTech.GetCheck() == BST_UNCHECKED)
		return FALSE;
	if (m_cbFinance.GetCheck() == BST_UNCHECKED)
		return FALSE;
	if (m_cbAuto.GetCheck() == BST_UNCHECKED)
		return FALSE;
	if (m_cbLocal.GetCheck() == BST_UNCHECKED)
		return FALSE;
	if (m_cbEdu.GetCheck() == BST_UNCHECKED)
		return FALSE;

	return TRUE;
}

void Clive_scheduleDlg::OnBnClickedCheckSports()
{
	if (m_cbSports.GetCheck() == BST_CHECKED && IsAllCheck() && m_cbAll.GetCheck() == BST_UNCHECKED)
		m_cbAll.SetCheck(1);
	else
		m_cbAll.SetCheck(0);
}


void Clive_scheduleDlg::OnBnClickedCheckConcert()
{
	if (m_cbConcert.GetCheck() == BST_CHECKED && IsAllCheck() && m_cbAll.GetCheck() == BST_UNCHECKED)
		m_cbAll.SetCheck(1);
	else
		m_cbAll.SetCheck(0);
}


void Clive_scheduleDlg::OnBnClickedCheckVariety()
{
	if (m_cbVariety.GetCheck() == BST_CHECKED && IsAllCheck() && m_cbAll.GetCheck() == BST_UNCHECKED)
		m_cbAll.SetCheck(1);
	else
		m_cbAll.SetCheck(0);
}


void Clive_scheduleDlg::OnBnClickedCheckNews()
{
	if (m_cbNews.GetCheck() == BST_CHECKED && IsAllCheck() && m_cbAll.GetCheck() == BST_UNCHECKED)
		m_cbAll.SetCheck(1);
	else
		m_cbAll.SetCheck(0);
}


void Clive_scheduleDlg::OnBnClickedCheckGame()
{
	if (m_cbGame.GetCheck() == BST_CHECKED && IsAllCheck() && m_cbAll.GetCheck() == BST_UNCHECKED)
		m_cbAll.SetCheck(1);
	else
		m_cbAll.SetCheck(0);
}


void Clive_scheduleDlg::OnBnClickedCheckEnt()
{
	if (m_cbEnt.GetCheck() == BST_CHECKED && IsAllCheck() && m_cbAll.GetCheck() == BST_UNCHECKED)
		m_cbAll.SetCheck(1);
	else
		m_cbAll.SetCheck(0);
}


void Clive_scheduleDlg::OnBnClickedCheckTv()
{
	if (m_cbTv.GetCheck() == BST_CHECKED && IsAllCheck() && m_cbAll.GetCheck() == BST_UNCHECKED)
		m_cbAll.SetCheck(1);
	else
		m_cbAll.SetCheck(0);
}


void Clive_scheduleDlg::OnBnClickedCheckTech()
{
	if (m_cbTech.GetCheck() == BST_CHECKED && IsAllCheck() && m_cbAll.GetCheck() == BST_UNCHECKED)
		m_cbAll.SetCheck(1);
	else
		m_cbAll.SetCheck(0);
}


void Clive_scheduleDlg::OnBnClickedCheckFinance()
{
	if (m_cbFinance.GetCheck() == BST_CHECKED && IsAllCheck() && m_cbAll.GetCheck() == BST_UNCHECKED)
		m_cbAll.SetCheck(1);
	else
		m_cbAll.SetCheck(0);
}


void Clive_scheduleDlg::OnBnClickedCheckAuto()
{
	if (m_cbAuto.GetCheck() == BST_CHECKED && IsAllCheck() && m_cbAll.GetCheck() == BST_UNCHECKED)
		m_cbAll.SetCheck(1);
	else
		m_cbAll.SetCheck(0);
}


void Clive_scheduleDlg::OnBnClickedCheckLocal()
{
	if (m_cbLocal.GetCheck() == BST_CHECKED && IsAllCheck() && m_cbAll.GetCheck() == BST_UNCHECKED)
		m_cbAll.SetCheck(1);
	else
		m_cbAll.SetCheck(0);
}


void Clive_scheduleDlg::OnBnClickedCheckEdu()
{
	if (m_cbEdu.GetCheck() == BST_CHECKED && IsAllCheck() && m_cbAll.GetCheck() == BST_UNCHECKED)
		m_cbAll.SetCheck(1);
	else
		m_cbAll.SetCheck(0);
}


void Clive_scheduleDlg::OnBnClickedCheckDomain()
{
	if (m_cbDomain.GetCheck() == BST_CHECKED)
	{
		m_eDomain.GetWindowTextW(m_csDomain);
		if (m_csDomain == L"")
		{
			m_cbDomain.SetCheck(0);
			return;
		}
		m_cbTest.SetCheck(0);
		m_cbTest.EnableWindow(FALSE);
	}
	else
		m_cbTest.EnableWindow(TRUE);
}


void Clive_scheduleDlg::OnBnClickedCheckHistory()
{
	if (m_cbHistory.GetCheck() == BST_CHECKED)
		m_cbSchedule.SetCheck(0);

	if (m_cbHistory.GetCheck() == BST_UNCHECKED && m_cbSchedule.GetCheck() == BST_UNCHECKED)
		m_cbShowTV.SetCheck(0);
}


void Clive_scheduleDlg::OnBnClickedCheckSchedule()
{
	if (m_cbSchedule.GetCheck() == BST_CHECKED)
		m_cbHistory.SetCheck(0);

	if (m_cbHistory.GetCheck() == BST_UNCHECKED && m_cbSchedule.GetCheck() == BST_UNCHECKED)
		m_cbShowTV.SetCheck(0);
}

void Clive_scheduleDlg::OnBnClickedCheckLiveinfo()
{
	m_ePid.SetFocus();
	m_ePid.SetWindowTextW(L"12276");
	m_ePid.SetSel(0, -1);
}

void Clive_scheduleDlg::OnDtnDatetimechangeDatetimeEnd(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	*pResult = 0;
}