#include "stdafx.h"
#include "common.h"

#include <string.h>
#include <string>
#include <time.h>
#include <stdio.h> 

using namespace std;

CString UTF8ToUnicode(char* UTF8)
{
	DWORD dwUnicodeLen;        //转换后Unicode的长度
	TCHAR *pwText;            //保存Unicode的指针
	CString strUnicode;        //返回值
	//获得转换后的长度，并分配内存

	dwUnicodeLen = MultiByteToWideChar(CP_UTF8, 0, UTF8, -1, NULL, 0);
	pwText = new TCHAR[dwUnicodeLen];
	if (!pwText)
	{
		return strUnicode;
	}
	//转为Unicode
	MultiByteToWideChar(CP_UTF8, 0, UTF8, -1, pwText, dwUnicodeLen);
	//转为CString
	strUnicode.Format(_T("%s"), pwText);
	//清除内存
	delete[]pwText;
	//返回转换好的Unicode字串
	return strUnicode;
}


time_t StampnizeTime(const CString &time_string)
{
	CString stime = time_string;
	CString cs1970 = L"1970-01-01 08:00:00";
	COleDateTime ct1970;
	ct1970.ParseDateTime(cs1970);
	COleDateTime   tempTime;
	tempTime.ParseDateTime(stime);
	COleDateTimeSpan  result = tempTime - ct1970;

	return result.GetTotalSeconds();
}

string StringnizeTimeStamp(const time_t tm_stamp)
{
	struct tm tm_time;
	localtime_s(&tm_time, &tm_stamp);
	char acTime[64] = { 0 };
	strftime(acTime, sizeof(acTime), "%Y-%m-%d %H:%M:%S", &tm_time);
	string sTime = acTime;
	return sTime;
}


time_t GetTimeFromNowBySec(time_t tt)
{
	time_t now = time(NULL);
	return now - tt;
}

time_t GetTimeFromNowByDate(int year, int month, int day, int hour, int minute, int sec)
{
	struct tm date;
	date.tm_year = year - 1900;
	date.tm_mon = month;
	date.tm_mday = day;
	date.tm_hour = hour;
	date.tm_min = minute;
	date.tm_sec = sec;

	return GetTimeFromNow(&date);
}

time_t GetTimeByDate(int year, int month, int day, int hour, int minute, int sec)
{
	struct tm date;
	date.tm_year = year - 1900;
	date.tm_mon = month - 1;
	date.tm_mday = day;
	date.tm_hour = hour;
	date.tm_min = minute;
	date.tm_sec = sec;

	return mktime(&date);
}

// 获取现在距离某个时间的秒数 (负数 < now; 正数 > 0)
time_t GetTimeFromNow(struct tm* timeptr)
{
	if (NULL == timeptr)
	{
		return 0;
	}

	time_t tt = mktime(timeptr);
	time_t now = time(NULL);

	return tt - now;
}

//获取系统当前时间戳
time_t GetCurrentTimestamp()
{
	time_t currTimestamp = time(NULL);
	return currTimestamp;
}

int splitString(string src, string sFlag, vector<string>& vecResult)
{
	int sFlagLen = sFlag.size();
	int lastPosition = 0, index = -1;
	while (-1 != (index = src.find(sFlag, lastPosition)))
	{
		vecResult.push_back(src.substr(lastPosition, index - lastPosition));
		lastPosition = index + sFlagLen;
	}

	string lastString = src.substr(lastPosition);
	if (!lastString.empty())
	{
		vecResult.push_back(lastString);
	}

	return 0;
}
