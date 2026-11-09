// from server: 59% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct ControlBlock {
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Registry {
    void insert(void*);
};

extern Registry registry;

struct S {
    void* object;
    ControlBlock* control;
    void f(const S& source, void* entry, ControlBlock* temporary);
};

void S::f(const S& source, void* entry, ControlBlock* temporary)
{
    object = source.object;
    control = source.control;
    if (control)
        _InterlockedExchangeAdd(&control->strong, 1);

    registry.insert(entry);

    if (temporary) {
        if (_InterlockedExchangeAdd(&temporary->strong, -1) == 1) {
            temporary->dispose();
            if (_InterlockedExchangeAdd(&temporary->weak, -1) == 1)
                temporary->destroy();
        }
    }
}
