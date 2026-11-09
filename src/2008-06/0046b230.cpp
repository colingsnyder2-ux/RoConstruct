// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_espclaude_8a1f827b418cba68.cpp

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
#include <string>
#include <memory>
#include <exception>
#include <intrin.h>

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    __forceinline void add_ref_copy() { _InterlockedIncrement(&use_count_); }
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
    __forceinline shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};

template<class T> class shared_ptr {
public:
    T* px;
    shared_count pn;
    T* operator->() const { return px; }
};

struct DataModel;
struct Lock { Lock(shared_ptr<DataModel> dm); ~Lock(); int a, b, c; };

class LuaArgs {
public:
    LuaArgs();
    ~LuaArgs();
    void push(ATL::CComVariant value);
    int data[6];
};

class ScriptRunner {
public:
    std::auto_ptr<LuaArgs> execute(int identity, const char* script, const char* name, LuaArgs& args);
};

class ScriptContext {
public:
    ScriptRunner* getRunner();
};

template<class E> struct ImpStr : std::basic_string<E> { __declspec(noinline) const E* c_str() const { return std::basic_string<E>::c_str(); } };
extern template struct __declspec(dllimport) ImpStr<char>;
static inline const char* cstr(const std::string& x) { return static_cast<const ImpStr<char>&>(x).c_str(); }
std::string __cdecl format(const char* fmt, ...);
HRESULT __cdecl ReportError(const GUID& iid, const char* msg, HRESULT hr);
IDispatch* __cdecl ToDispatch(LuaArgs* args);
extern const GUID IID_IWorkspace;

struct WorkspaceHead { void* a; void* b; };
struct SiteCheck { HRESULT CheckSite(); };

class VCWorkspace : public WorkspaceHead, public SiteCheck {
public:
    char pad[0x24 - 8];
    shared_ptr<DataModel> dm;
    shared_ptr<ScriptContext> getScriptContext();
    HRESULT execScript(const char* script, VARIANT arg1, VARIANT arg2, VARIANT arg3, VARIANT arg4, IDispatch** result);
};


HRESULT VCWorkspace::execScript(const char* script, VARIANT arg1, VARIANT arg2, VARIANT arg3, VARIANT arg4, IDispatch** result)
{
    HRESULT hr = CheckSite();
    if (hr)
        return hr;
    try
    {
        Lock lock(dm);
        LuaArgs args;
        args.push(arg1);
        args.push(arg2);
        args.push(arg3);
        args.push(arg4);
        std::auto_ptr<LuaArgs> ret = getScriptContext()->getRunner()->execute(4, script, 0, args);
        if (result)
            *result = ToDispatch(ret.get());
        return S_OK;
    }
    catch (std::exception& e)
    {
        std::string s(script);
        std::string msg = format("DoExecScript failed because %s.  %s", e.what(), cstr(s.substr(0, 64)));
        hr = ReportError(IID_IWorkspace, static_cast<const ImpStr<char>&>(msg).c_str(), 0);
    }
    return hr;
}

