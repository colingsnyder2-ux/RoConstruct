// from server: 100% by colin
// from server: 0% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_espeon_contentdistinctstringtemps61ed3b750b05af46.cpp

// Candidate translation unit (score above; library headers required).
#ifndef _CPPUNWIND
#define _CPPUNWIND 1
#endif
#ifndef _AFXDLL
#define _AFXDLL
#endif
#include <new>
#include <afxwin.h>
#include <atlbase.h>
#include <atlcom.h>
#include <sstream>
#include <string>

extern const GUID IID_IContent;
extern const GUID CLSID_Content;
extern const GUID LIBID_RobloxLib;

struct __declspec(uuid("00000000-0000-0000-0000-000000000001")) IContent : public IDispatch
{
    virtual HRESULT STDMETHODCALLTYPE Load(BSTR url) = 0;
};

class ATL_NO_VTABLE CContent :
    public ATL::CComObjectRootEx<ATL::CComSingleThreadModel>,
    public ATL::CComCoClass<CContent, &CLSID_Content>,
    public ATL::ISupportErrorInfoImpl<&IID_IContent>,
    public ATL::IDispatchImpl<IContent, &IID_IContent, &LIBID_RobloxLib, 1, 0>
{
public:
    std::stringstream stream;

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CContent)
    COM_INTERFACE_ENTRY(IContent)
    COM_INTERFACE_ENTRY(IDispatch)
    COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

    virtual HRESULT STDMETHODCALLTYPE Load(BSTR url);
};


struct CStr {
    char* m_pszData;
    __declspec(dllimport) CStr() throw();
    __declspec(dllimport) CStr(const wchar_t* psz);
    __declspec(dllimport) ~CStr() throw();
    __declspec(dllimport) operator const char*() const throw();
    __declspec(dllimport) void __cdecl Format(const char* fmt, ...);
};

struct TemporaryCStr {
    char* m_pszData;
    __declspec(dllimport) TemporaryCStr() throw();
    __declspec(dllimport) TemporaryCStr(const wchar_t* psz);
    __declspec(dllimport) ~TemporaryCStr() throw();
    __declspec(dllimport) operator const char*() const throw();
    __declspec(dllimport) void __cdecl Format(const char* fmt, ...);
};

HRESULT __cdecl CheckUrl(BSTR url);
HRESULT __cdecl ReportError(const GUID& iid, const char* msg, HRESULT hr);
HRESULT __cdecl ReportError(const GUID& iid, const std::exception& e);

class UrlContent {
public:
    UrlContent(const char* url);
    ~UrlContent();
    void load(std::iostream& stream, bool binary, std::string& error);
private:
    char data[0x38];
};

HRESULT STDMETHODCALLTYPE CContent::Load(BSTR url)
{
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    if (HRESULT hr = CheckUrl(url))
    {
        CStr msg;
        msg.Format("Untrusted Url: %s", TemporaryCStr(url));
        return ReportError(IID_IContent, msg, hr);
    }
    try
    {
        std::string error;
        UrlContent(TemporaryCStr(url)).load(stream, true, error);
    }
    catch (std::exception& e)
    {
        return ReportError(IID_IContent, e);
    }
    return S_OK;
}
