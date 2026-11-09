// from server: 100% by tajop
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

struct Counted {
    long use;
    long weak;
    virtual ~Counted();
    virtual void dispose();
    virtual void destroy();
    void weak_release() {
        if (_InterlockedDecrement(&weak) == 0) destroy();
    }
    void release() {
        if (_InterlockedDecrement(&use) == 0) {
            dispose();
            weak_release();
        }
    }
};

struct SP {
    void* px;
    Counted* pn;
    SP(const SP& o) : px(o.px), pn(o.pn) {
        if (pn) _InterlockedIncrement(&pn->use);
    }
    ~SP() {
        if (pn) pn->release();
    }
};

struct B1 { int a; };
struct B2 { int b; };
struct T : B1, B2 { void m(int); };

struct Arg1 {};
extern Arg1 g_1;

struct BindT {
    void (T::*f)(int);
    SP a;
};

BindT bind(void (T::*f)(int), SP p, Arg1 a);

struct Buf { int d[6]; };

struct VT {
    typedef void (*Mgr)(Buf&, Buf&, int);
    Mgr manager;
    void clear(Buf& b) {
        Mgr m = manager;
        if (m) m(b, b, 2);
    }
};

struct Func {
    VT* vtable;
    int pad;
    Buf functor;
    Func(BindT f, int = 0);
    ~Func() {
        if (vtable) {
            vtable->clear(functor);
            vtable = 0;
        }
    }
};

struct Conn {
    int x;
    Conn(const Conn&);
    ~Conn();
};

struct S {
    Conn g(int a, const Func& f);
    Conn f(int a, SP b);
};

Conn S::f(int a, SP b)
{
    Func fn(bind(&T::m, b, g_1));
    return g(a, fn);
}
