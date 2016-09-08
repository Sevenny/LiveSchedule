#include "stdafx.h"
#include "common.h"

#include <string.h>
#include <string>
#include <time.h>
#include <stdio.h> 

using namespace std;

CString UTF8ToUnicode(char* UTF8)
{
	DWORD dwUnicodeLen;        //ת����Unicode�ĳ���
	TCHAR *pwText;            //����Unicode��ָ��
	CString strUnicode;        //����ֵ
	//���ת����ĳ��ȣ��������ڴ�

	dwUnicodeLen = MultiByteToWideChar(CP_UTF8, 0, UTF8, -1, NULL, 0);
	pwText = new TCHAR[dwUnicodeLen];
	if (!pwText)
	{
		return strUnicode;
	}
	//תΪUnicode
	MultiByteToWideChar(CP_UTF8, 0, UTF8, -1, pwText, dwUnicodeLen);
	//תΪCString
	strUnicode.Format(_T("%s"), pwText);
	//����ڴ�
	delete[]pwText;
	//����ת���õ�Unicode�ִ�
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
