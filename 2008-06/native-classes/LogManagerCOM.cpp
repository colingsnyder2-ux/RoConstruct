// native-flags: /O2 /GS- /EHsc /MD /D_AFXDLL /D_MBCS /I{headers}/mfc-import-length /I{headers}/std-noinline-string /I{headers}/../../../tools/libs/mfc-9.0-rtm/atlmfc/include
// OpenRBX COM error reporting; inactive pending provider and ABI proof.
#include <afxwin.h>
#include <afxdisp.h>
#include <atlbase.h>
#include <atlcom.h>
#include "CRobloxApp.h"
void LogManager::ReportEvent(WORD type, HRESULT hr, const char* file, int line)
{
	COleException exception;
	exception.m_sc = hr;
	char message[1024];
	exception.GetErrorMessage(message, 1024);

	CString text;
	text.Format("HRESULT = %d: %s\n%s(%d)", hr, message, file, line);
	ReportEvent(type, text);
}


// FUNCTION: ROBLOX 0x0042bf70
HRESULT LogManager::ReportCOMError(const GUID& guid, const char* message, HRESULT hr)
{
	ReportEvent(EVENTLOG_ERROR_TYPE, message);
	return AtlReportError(guid, message, GUID_NULL, hr);
}

// FUNCTION: ROBLOX 0x0042bfa0
HRESULT LogManager::ReportExceptionAsCOMError(const GUID& guid, const std::exception& e)
{
	return ReportCOMError(guid, e.what(), S_OK);
}

