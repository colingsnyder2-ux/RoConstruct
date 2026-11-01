// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

namespace RBX {
struct Instance;
struct ServiceProvider;
}

RBX::ServiceProvider* __cdecl func_00421cb0(RBX::Instance*);

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Reference {
    Control* control;
    Reference& operator=(const Reference&);
    ~Reference();
};

__forceinline Reference::~Reference()
{
    Control* p = control;
    if (p) {
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct Product {
    void* object;
    Reference reference;
};

Product __cdecl func_00618a40(RBX::ServiceProvider*);

struct S {
    RBX::Instance* instance;
    Product cached;
    void* f(int);
};

void* S::f(int)
{
    if (!cached.object)
        cached = func_00618a40(func_00421cb0(instance));
    return cached.object;
}
