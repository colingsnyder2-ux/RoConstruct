// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_espclaude_ef514ace34b2232d.cpp

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
#include <vector>
#include <memory>
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
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};

template<class T> class shared_ptr {
public:
    T* px;
    shared_count pn;
    T* get() const { return px; }
    T* operator->() const { return px; }
};

class tss {
public:
    void* get() const;
    void set(void* p);
    void cleanup(void* p);
};

template<class T> class thread_specific_ptr {
public:
    T* get() const { return static_cast<T*>(m_tss.get()); }
    void reset(T* p = 0)
    {
        T* cur = get();
        if (cur == p)
            return;
        m_tss.set(p);
        if (cur)
            m_tss.cleanup(cur);
    }
    tss m_tss;
};

struct Identity;
class Impersonator {
public:
    Impersonator(int identity);
    ~Impersonator() { current().reset(previous); }
    static thread_specific_ptr<Identity>& current();
    Identity* previous;
};

struct Value { void* type; void* data; };

class LuaArgs {
public:
    ~LuaArgs();
    void push(ATL::CComVariant value);
    std::vector<Value> values;
};

void __cdecl toVariant(const Value& value, VARIANT* result);

struct FunctionRef { int data[9]; };

class ScriptContext {
public:
    std::auto_ptr<LuaArgs> callFunction(const FunctionRef& function, LuaArgs& args);
};

class DataModel {
public:
    ScriptContext* createScriptContext();
};

inline ScriptContext* getScriptContext(DataModel* dm) { return dm ? dm->createScriptContext() : 0; }

struct Lock { Lock(shared_ptr<DataModel> dm); ~Lock(); int a, b, c; };

class Logger {
public:
    void log(int level, const char* fmt, ...);
};
shared_ptr<Logger> __cdecl getLogger();

HRESULT __cdecl ReportException(const GUID& iid, std::exception& e);
extern const GUID IID_ILuaFunction;

class CLuaFunction {
public:
    void* vtbl;
    int ref;
    shared_ptr<DataModel> dm;
    FunctionRef function;
    int identity;
    HRESULT __stdcall Call(VARIANT arg1, VARIANT arg2, VARIANT arg3, VARIANT arg4, VARIANT* result) throw();
};

HRESULT __stdcall CLuaFunction::Call(VARIANT arg1, VARIANT arg2, VARIANT arg3, VARIANT arg4, VARIANT* result) throw()
{
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    try
    {
        LuaArgs args;
        args.push(arg1);
        args.push(arg2);
        args.push(arg3);
        args.push(arg4);
        std::auto_ptr<LuaArgs> ret;
        {
            Lock lock(dm);
            ScriptContext* context = getScriptContext(dm.get());
            Impersonator impersonate(identity);
            ret = context->callFunction(function, args);
        }
        if (!ret->values.empty())
            toVariant(ret->values.front(), result);
    }
    catch (std::exception& e)
    {
        getLogger()->log(2, "CLuaFunction::Call failed, %s", e.what());
        return ReportException(IID_ILuaFunction, e);
    }
    return S_OK;
}
