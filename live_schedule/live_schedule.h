
// live_schedule.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号
#include <afxinet.h>
#include "json/json.h"
#include "common.h"
#include "live_scheduleDlg.h"

#pragma comment(lib, "lib_json_r.lib")

class Clive_scheduleApp : public CWinApp
{
public:
	Clive_scheduleApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()

};

extern Clive_scheduleApp theApp;