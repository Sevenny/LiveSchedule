#pragma once
#include "afxwin.h"


// CLiveAbout �Ի���

class CLiveAbout : public CDialogEx
{
	DECLARE_DYNAMIC(CLiveAbout)

public:
	CLiveAbout(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLiveAbout();

// �Ի�������
	enum { IDD = IDD_DIALOG_ABOUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_eAbout;
};
