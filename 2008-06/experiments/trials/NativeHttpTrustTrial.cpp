#define _SCL_SECURE_NO_DEPRECATE
#include "util/Http.h"
#include <boost/thread/once.hpp>
#include <windows.h>
#include <atlutil.h>

namespace RBX {
static bool skipTrustCheck;
	static boost::once_flag trustCheckOnce = BOOST_ONCE_INIT;
	static void initializeTrustCheck()
	{
		DWORD data = 0;
		ATL::CRegKey key;
		if (key.Open(HKEY_CURRENT_USER, "Software\\ROBLOX Corporation\\Roblox", KEY_READ) == ERROR_SUCCESS)
			key.QueryDWORDValue("SkipTrustCheck", data);
		if (key.Open(HKEY_LOCAL_MACHINE, "Software\\Roblox", KEY_READ) == ERROR_SUCCESS)
			key.QueryDWORDValue("SkipTrustCheck", data);
		skipTrustCheck = data == TRUE;
	}

	bool Http::trustCheck(const char* url)
	{
		boost::call_once(&initializeTrustCheck, trustCheckOnce);
		if (skipTrustCheck)
			return true;

		if (ATL::CString("about:blank") == url)
			return true;

		if (isRobloxSite(url))
			return true;

		if (isScript(url))
			return true;

		ATL::CUrl crack;
		crack.CrackUrl(url);
		switch (crack.GetScheme())
		{
		case ATL_URL_SCHEME_FTP:
		case ATL_URL_SCHEME_HTTP:
		case ATL_URL_SCHEME_HTTPS:
			return false;
		default:
		{
			ATL::CString sUrl = url;
			sUrl.Replace("%20", " ");
			if (sUrl.Find("res://") == 0)
			{
				if (sUrl.Find("res://mshtml.dll") == 0) return true;
				if (sUrl.Find("res://ieframe.dll") == 0) return true;
				if (sUrl.Find("res://shdoclc.dll") == 0) return true;
				TCHAR module[_MAX_PATH];
				if (GetModuleFileName(NULL, module, _MAX_PATH))
				{
					ATL::CString strResourceURL;
					strResourceURL.Format(_T("res://%s"), module);
					if (sUrl.Find(strResourceURL) == 0) return true;
				}
			}
			return false;
		}
		}
	}

}
