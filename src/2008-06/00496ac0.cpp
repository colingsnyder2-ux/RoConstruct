// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)








struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* pointer;
    Control* control;
    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : pointer(other.pointer), control(other.control) {
    if (control)
        _InterlockedIncrement(&control->strong);
}

inline Shared::~Shared() {
    if (control) {
        Control* p = control;
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct Error {
    unsigned char storage[40];
    Error();
    ~Error();
};

__declspec(noreturn) void __cdecl raiseError(const Error&);

typedef void (__cdecl *Invoke)(void*, std::string, Shared);

struct Table {
    void* unused;
    Invoke invoke;
};

struct S {
    Table* table;
    unsigned long reserved;
    unsigned char callable[1];
    void f(std::string, Shared);
};

void S::f(std::string text, Shared value) {
    if (!table)
        raiseError(Error());
    table->invoke(callable, text, value);
}
