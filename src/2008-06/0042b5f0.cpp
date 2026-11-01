// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" void __cdecl _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

struct Control {
    unsigned int reserved;
    volatile long references;
};

struct Shared {
    void* pointer;
    Control* control;

    __forceinline Shared(const Shared& other);
    ~Shared();
};

__forceinline Shared::Shared(const Shared& other)
    : pointer(other.pointer), control(other.control)
{
    if (control) {
        volatile long* references = &control->references;
        _ReadWriteBarrier();
        _InterlockedExchangeAdd(references, 1);
    }
}

struct Guard {
    void* pointer;
    Control* control;
    unsigned char padding[4];

    Guard(Shared value);
    ~Guard();
};

struct Container {
    void clear();
};

struct EventHandler {
    unsigned char padding[0x100];
    Shared shared;
    unsigned char gap[8];
    Container container;

    void f();
};

void EventHandler::f()
{
    Guard guard(shared);
    container.clear();
}
