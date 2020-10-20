#include <iostream>
#include <windows.h>
#include <WinUser.h>
#include <WinBase.h>
#include <tchar.h>
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
#pragma comment(lib,"wininet.lib")
#pragma comment(lib, "Advapi32.lib")
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <WinInet.h>
#include <iomanip>
#include <cstdio>
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>

#pragma once

using namespace System;
using namespace std;
using namespace msclr::interop;
#define HOST_VK ("vk.com")

namespace OnlineLib {
	public ref class Class
	{
	public:
		string GetUrlData(String^ url)
		{
			LPCSTR host = HOST_VK;
			string request_data = "";

			HINTERNET hIntSession = InternetOpenA("", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);

			if (!hIntSession)
				return request_data;

			HINTERNET hHttpSession = InternetConnectA(hIntSession, host, 80, 0, 0, INTERNET_SERVICE_HTTP, 0, NULL);

			if (!hHttpSession)
				return request_data;

			HINTERNET hHttpRequest = HttpOpenRequestA(hHttpSession, "GET", marshal_as<std::string>(url).c_str()
				, 0, 0, 0, INTERNET_FLAG_RELOAD, 0);

			if (!hHttpSession)
				return request_data;

			const char* szHeaders = ("Content-Type: text/html\r\nUser-Agent: License");
			char szRequest[1024] = { 0 };

			if (!HttpSendRequestA(hHttpRequest, szHeaders, strlen(szHeaders), szRequest, strlen(szRequest)))
				return request_data;
			CHAR szBuffer[1024] = { 0 };
			DWORD dwRead = 0;

			while (InternetReadFile(hHttpRequest, szBuffer, sizeof(szBuffer) - 1, &dwRead) && dwRead)
				request_data.append(szBuffer, dwRead);

			InternetCloseHandle(hHttpRequest);
			InternetCloseHandle(hHttpSession);
			InternetCloseHandle(hIntSession);

			return request_data;
		}

		bool GetOnlineAdmin(String^ name)
		{
			return GetUrlData("/" + name).find("<span class=\"pp_last_activity_text\">Online</span>") != string::npos;
		}
	};
}
