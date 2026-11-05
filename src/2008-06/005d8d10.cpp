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
    virtual void reserved() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Handle {
    Control* control;
    Handle& operator=(const Handle&);
    ~Handle();
};

__forceinline Handle::~Handle() {
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
    void* object;
    Handle handle;
    ~Shared();
};

__forceinline Shared::~Shared() {
}

struct Instance {
    void* find(const std::string&);
};

extern Shared __cdecl acquire(void*);

struct S {
    char padding0[0x104];
    Instance* parent;
    char padding1[0xfc];
    void* cached;
    Handle owner;
    void assign(const Shared&);
    void* f();
};

__forceinline void S::assign(const Shared& value) {
    cached = value.object;
    owner = value.handle;
}

void* S::f() {
    if (!cached && parent) {
        std::string name("Right Leg");
        void* found = parent->find(name);
        assign(acquire(found ? static_cast<char*>(found) + 0xe4 : 0));
    }
    return cached;
}
