// LiveAbout.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "live_schedule.h"
#include "LiveAbout.h"
#include "afxdialogex.h"


// CLiveAbout �Ի���

IMPLEMENT_DYNAMIC(CLiveAbout, CDialogEx)

CLiveAbout::CLiveAbout(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLiveAbout::IDD, pParent)
{

}

CLiveAbout::~CLiveAbout()
{
}

void CLiveAbout::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ABOUT, m_eAbout);
}


BEGIN_MESSAGE_MAP(CLiveAbout, CDialogEx)
END_MESSAGE_MAP()


// CLiveAbout ��Ϣ�������
