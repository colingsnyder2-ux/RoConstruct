// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_espclaude_720efa37bcc08351.cpp

// Candidate translation unit (score above; library headers required).
#ifndef _CPPUNWIND
#define _CPPUNWIND 1
#endif
#ifndef _AFXDLL
#define _AFXDLL
#endif
#include <new>
#include <afxwin.h>
#include <fstream>
#include <memory>
#include <intrin.h>

struct sp_counted_base { void* vtbl; long use_count_; long weak_count_; };
template<class T> struct shared_ptr {
    T* px; sp_counted_base* pn;
    shared_ptr(const shared_ptr& r) : px(r.px), pn(r.pn) { if (pn) _InterlockedIncrement(&pn->use_count_); }
    ~shared_ptr();
};
struct DataModel;
struct PathString {
    char* m_pszData;
    __declspec(dllimport) PathString(const wchar_t* psz);
    __declspec(dllimport) operator const char*() const throw();
    __declspec(dllimport) ~PathString() throw();
};
struct Lock { Lock(shared_ptr<DataModel> dm); ~Lock(); int a, b, c; };
struct Writer { ~Writer(); int x; };

class VCWorkspace {
public:
    char pad[0x24];
    shared_ptr<DataModel> dm;
    std::auto_ptr<Writer> createWriter();
    void write(Writer* w, std::ostream& s);
    HRESULT __stdcall Save(BSTR path) throw();
};

HRESULT __stdcall VCWorkspace::Save(BSTR path) throw()
{
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    std::ofstream stream;
    stream.open(PathString(path), std::ios::out | std::ios::binary);
    Lock lock(dm);
    write(createWriter().get(), stream);
    return S_OK;
}
