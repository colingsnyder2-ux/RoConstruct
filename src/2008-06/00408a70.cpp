// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_espclaude_188c2f09ea8697a7.cpp

// Candidate translation unit (score above; library headers required).
#ifndef _CPPUNWIND
#define _CPPUNWIND 1
#endif
#ifndef _AFXDLL
#define _AFXDLL
#endif
#ifndef _MBCS
#define _MBCS
#endif
#include <new>
#include <afxwin.h>
#include <atlutil.h>
#include <string>
#include <exception>
#include <intrin.h>

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0)
        {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
    long use_count_;
    long weak_count_;
};

class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};

template<class T> class shared_ptr {
public:
    T* px;
    shared_count pn;
    T* operator->() const { return px; }
};

template <class T> class CStr {
public:
    __declspec(noinline) CStr(const wchar_t* psz) { m_pszData = (T*)psz; }
    __declspec(noinline) ~CStr() throw() { m_pszData = 0; }
    __declspec(noinline) operator const T*() const throw() { return m_pszData; }
    T* m_pszData;
};
extern template class __declspec(dllimport) CStr<char>;
typedef CStr<char> CStrA;

class Logger {
public:
    void log(int level, const char* fmt, ...);
};
shared_ptr<Logger> __cdecl getLogger();
CStrA __cdecl getBaseUrl();

class Authenticator {
public:
    Authenticator(const char* host);
    ~Authenticator();
    std::string authenticate(const char* user, const char* password);
    std::string host;
};

HRESULT __cdecl ReportException(const GUID& iid, std::exception& e);
extern const GUID IID_IApp;

class CApp {
public:
    HRESULT __stdcall RobloxAuthenticate(BSTR user, BSTR password) throw();
};

HRESULT __stdcall CApp::RobloxAuthenticate(BSTR user, BSTR password) throw()
{
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    getLogger()->log(1, "CApp::RobloxAuthenticate %s %s", (const char*)CStrA(user), (const char*)CStrA(password));
    try
    {
        ATL::CUrl url;
        url.CrackUrl(getBaseUrl());
        Authenticator auth(url.GetHostName());
        auth.authenticate(CStrA(user), CStrA(password));
    }
    catch (std::exception& e)
    {
        return ReportException(IID_IApp, e);
    }
    return S_OK;
}

