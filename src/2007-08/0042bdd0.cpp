// from server: 90% by EspClaude
// from server: 48% by colin
// roc 2007-08 0042bdd0  unit: VCLuaFunction::?$CComObjectNoLock  size: 442 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042bdd0
#include <string>
#include <stdexcept>

extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

typedef long HRESULT;

struct IUnknown {
    virtual HRESULT __stdcall QueryInterface(const void* riid, void** ppv) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};
struct IDispatch : IUnknown {};

template<class T> struct CComPtr {
    T* p;
    T* operator=(T* lp)
    {
        if (p != lp) {
            if (lp != 0)
                lp->AddRef();
            if (p)
                p->Release();
            p = lp;
        }
        return lp;
    }
};

struct sp_counted_base {
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long use_count_;
    volatile long weak_count_;
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
};

struct shared_count {
    sp_counted_base* pi_;
    ~shared_count()
    {
        if (pi_ != 0)
            pi_->release();
    }
    shared_count& operator=(const shared_count& r);   // 0x402a60
};

template<class T> struct shared_ptr {
    T* px;
    shared_count pn;
    shared_ptr& operator=(const shared_ptr& r)
    {
        px = r.px;
        pn = r.pn;
        return *this;
    }
    T* operator->() const { return px; }
    T* get() const { return px; }
};

struct Context;

struct ScriptHost {               // base at +0xa4 of Instance
    int dummy;
};

struct Instance {
    char pad0[0xa4];
    ScriptHost host;              // +0xa4
    char pad1[0xbc - 0xa8];
    struct Parent* parent;        // +0xbc
};

struct Parent {
    Instance* getInstance();      // 0x42a4e0
};

shared_ptr<Context> __cdecl getContext(ScriptHost* host);   // 0x42b620

struct LuaRoot {
    virtual void root0();
};

struct LuaFunction : LuaRoot, IDispatch {
    char pad[4];
    shared_ptr<Context> context;  // +0xc
};

HRESULT __cdecl createLuaFunction(LuaFunction** pp, int flags);   // 0x42bc60

struct CLuaHtmlView {
    char pad0[0xf4];
    CComPtr<IDispatch> dispatch;  // +0xf4
    LuaFunction* function;        // +0xf8
    shared_ptr<Context> context;  // +0xfc
    shared_ptr<Instance> script;  // +0x104
    void setScript(shared_ptr<Instance> s);
};

void CLuaHtmlView::setScript(shared_ptr<Instance> s)
{
    Instance* inst = s.get();
    script = s;
    Instance* root = inst->parent ? inst->parent->getInstance() : inst;
    context = getContext(root ? &root->host : 0);
    if (createLuaFunction(&function, 0) != 0)
        throw std::runtime_error("CLuaHtmlView failed to create CLuaFunction");
    function->context = context;
    dispatch = function;
}
