// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)








struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Count {
    Control* control;
    Count& operator=(const Count&);
    __forceinline ~Count();
};

__forceinline Count::~Count()
{
    if (control) {
        Control* p = control;
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct Shared {
    void* pointer;
    Count count;
    __forceinline ~Shared();
};

__forceinline Shared::~Shared()
{
}

Shared __cdecl makeShared(void*);

struct Parent {
    char* find(const std::string&);
};

struct S {
    char padding0[0x104];
    Parent* parent;
    char padding1[0xf4];
    Shared cached;
    void* f();
};

void* S::f()
{
    if (!cached.pointer && parent) {
        std::string name("Left Leg");
        char* object = parent->find(name);
        cached = makeShared(object ? object + 0xe4 : 0);
    }
    return cached.pointer;
}
