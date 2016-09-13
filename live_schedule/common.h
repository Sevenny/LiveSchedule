#ifndef _COMMON_H_
#define _COMMON_H_
#include <vector>
#include <ATLComTime.h>
using namespace std;

#define LIVE_DOMAIN				"data.v.qq.com"
#define VIDEO_DOMAIN			"tv.video.qq.com"
#define VIDEO_DOMAIN_TEST		"test.tv.video.qq.com"
#define URL_ARGS				"/i-tvbin/qtv_video/live_details/get_live_schedule?start_time=%s&category_selector=%s&end_time=%s&site_selector=%s&live_status_filter=%s&cid_filter=%s&pay_selector=%s&pictures=1920x1080&format=json&nouse=%d"
#define URL_QUA					"&Q-UA=QV%3D1%26PR%3DVIDEO%26PT%3DCHIQ%26CHID%3D10019%26RL%3D1920*1080%26VN%3D3.0.0%26VN_CODE%3D120%26SV%3D4.4.2%26DV%3DMiBOX2%26VN_BUILD%3D0"
#define URL_PID					"/live/v2/api/live/info?reqsrc=tv&pid="
#define URL_LIVESERVER			"/live/v2/api/live/%s?reqsrc=tv&scope=tv_box&appclient=tv&nouse=%d"
#define ARGS_V_1_1				"&page_type=%s&page_size=%s&page_start=%s"


struct LiveResponse
{
	int finish;
	int next_start;
	int req_num;
	int rsp_num;
	void clear()
	{
		finish = 0;
		next_start = 0;
		req_num = 0;
		rsp_num = 0;
	}
};

struct LiveInfo
{
	CString csPid;
	CString csSite;
	CString csType;
	CString csStart;
	CString csEnd;
	CString csTitle;
	
	void clear()
	{
		csPid = L"";
		csSite = L"";
		csType = L"";
		csStart = L"";
		csEnd = L"";
		csTitle = L"";
	}
};

struct LiveRequest
{
	CString csTimeStart;
	CString csTimeEnd;
	CString csCid;
	CString csPageType;
	CString csPageStart;
	CString csPageSize;
	CString csPay;
	CString csSite;
	CString csCate;
	CString csStatus;
	void clear()
	{
		csTimeStart = L"";
		csTimeEnd = L"";
		csCid = L"";
		csPageType = L"";
		csPageStart = L"";
		csPageSize = L"";
		csPay = L"";
		csSite = L"";
		csCate = L"";
		csStatus = L"";
	}
};


CString UTF8ToUnicode(char* UTF8);
string StringnizeTimeStamp(const time_t tm_stamp);
time_t StampnizeTime(const CString &time_string);

int splitString(string src, string sFlag, vector<string>& vecResult);
int SplitCString(CString strSource, vector<CString> &vecString);
#endif