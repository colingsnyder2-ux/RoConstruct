// native-flags: /O2 /GS- /EHsc /MD /D_AFXDLL /D_ATL_APARTMENT_THREADED /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string /I{headers}/../../../tools/libs/mfc-9.0-rtm/atlmfc/include
// 2008-06 native CApp::get_ID 00406f60 (inactive). Identity: slot 16 of the CComObject<CApp> vtable 0080b50c (and of
// CComContainedObject<CApp> 0080b5a4), i.e. IApp's get_ID after IUnknown (3), IDispatch (4), CreateGame .. ClearFileCache
// (CApp2008.h order). Body: the openrbx 2007 Client/win/App.cpp CApp::get_ID (ROBLOX 0x00407fd0): GetAdaptersInfo into
// IP_ADAPTER_INFO[100] (0xfd20 bytes, _alloca_probe frame 0xfd58), MD5Hasher::create 0055c8b0 with addData(std::string)
// (slot 1) per adapter name, c_str (slot 4) through CString (#310 / #910 / #601) into the CComBSTR (operator=(LPCSTR)
// 00406930), CopyTo (SysAllocStringByteLen). Flags and includes copied from CApp2008.cpp.
#include <afx.h>
#include "CApp2008.h"
#include "CRobloxApp.h"
#include "util/ContentProvider.h"
#include <iphlpapi.h>
#include <boost/scoped_ptr.hpp>

// 00406f60
STDMETHODIMP CApp::get_ID(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	IP_ADAPTER_INFO adapterInfo[100];
	DWORD bufferLength = sizeof(adapterInfo);
	DWORD result = GetAdaptersInfo(adapterInfo, &bufferLength);
	if (result != ERROR_SUCCESS)
		return E_FAIL;

	CComBSTR id;
	if (bufferLength > 0)
	{
		boost::scoped_ptr<RBX::MD5Hasher> hasher(RBX::MD5Hasher::create());
		for (unsigned int i = 0; i < bufferLength / sizeof(IP_ADAPTER_INFO); i++)
			hasher->addData(adapterInfo[i].AdapterName);
		id = CString(hasher->c_str());
	}

	return id.CopyTo(pVal);
}
