
// live_schedule.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include <afxinet.h>
#include "json/json.h"
#include "common.h"
#include "live_scheduleDlg.h"

#pragma comment(lib, "lib_json_r.lib")

class Clive_scheduleApp : public CWinApp
{
public:
	Clive_scheduleApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()

};

extern Clive_scheduleApp theApp;