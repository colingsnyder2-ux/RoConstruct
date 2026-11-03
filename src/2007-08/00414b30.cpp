// from server: 100% by EspClaude
// roc 2007-08 00414b30  ctor of an object holding an RBX::Lua::FunctionRef at +0x14
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
namespace boost {
struct sp_counted_base { void* vptr; volatile long use_count; long weak_count;
    void add_ref_copy() { _InterlockedIncrement(&use_count); } };
template<class T> class shared_ptr {
    T* px; sp_counted_base* pn;
public:
    shared_ptr(const shared_ptr& r) : px(r.px), pn(r.pn) { if (pn) pn->add_ref_copy(); }
};
}

struct lua_State;
namespace boost { class mutex; }

namespace RBX { namespace Lua {
class ThreadRef {
    const boost::shared_ptr<boost::mutex> sync;
    void* node;
    ThreadRef* previous;
    ThreadRef* next;
    lua_State* L;
    int threadId;
    static boost::shared_ptr<boost::mutex> syncSingleton;
protected:
    virtual void removeRef();
public:
    ThreadRef() : sync(syncSingleton), node(0), previous(0), next(0), L(0), threadId(0) {}
};
class FunctionRef : public ThreadRef {
public:
    int functionId;
    FunctionRef() : functionId(0) {}
protected:
    virtual void removeRef();
};
}}

struct DHTMLWindowItem {
    int a;
    int b;
    int c;
    int d;
    int e;
    RBX::Lua::FunctionRef function;
    DHTMLWindowItem();
};

DHTMLWindowItem::DHTMLWindowItem() : c(0), d(0), e(0) {}
