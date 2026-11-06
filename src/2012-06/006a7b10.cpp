// from server: 97% by tajop
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

namespace std {
class exception {
public:
    exception();
    exception(const exception&);
    virtual ~exception();
    virtual const char* what() const;
private:
    const char* _m_what;
    int _m_doFree;
};
}

struct lua_State;

struct sp_counted_base {
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_;
    long weak_count_;
    void add_ref_copy() {
        _InterlockedIncrement(&use_count_);
    }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};

struct Obj;
struct DerivedObj;

struct SPD {
    DerivedObj* px;
    sp_counted_base* pn;
    SPD();
    ~SPD() {
        if (pn) pn->release();
    }
};

struct SP {
    Obj* px;
    sp_counted_base* pn;
    SP(const SPD& r) : px((Obj*)r.px), pn(r.pn) {
        if (pn) pn->add_ref_copy();
    }
    ~SP() {
        if (pn) pn->release();
    }
};

struct Context {
    int identity;
    static Context& current();
};

bool isInRole(int identity, int role);
SPD getInstance();
void doCallback(lua_State* L, SP p);

struct VInstance {
    static int callback(lua_State* L);
};

int VInstance::callback(lua_State* L)
{
    if (!isInRole(Context::current().identity, 2))
        throw std::exception();
    doCallback(L, getInstance());
    return 1;
}
