#pragma once
#include "afxwin.h"


// CLiveAbout 对话框

class CLiveAbout : public CDialogEx
{
	DECLARE_DYNAMIC(CLiveAbout)

public:
	CLiveAbout(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLiveAbout();

// 对话框数据
	enum { IDD = IDD_DIALOG_ABOUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_eAbout;
};
