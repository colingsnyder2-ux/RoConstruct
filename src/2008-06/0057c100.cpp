// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" void __cdecl _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

struct Control {
    long reserved;
    volatile long references;

    void retain();
};

__forceinline void Control::retain()
{
    volatile long* count = &references;
    _ReadWriteBarrier();
    _InterlockedExchangeAdd(count, 1);
}

struct Object {
    char reserved[0x259];
    bool flag;

    void update(void*);
};

struct Shared {
    Object* object;
    Control* control;

    Shared(const Shared&);
    ~Shared();
};

__forceinline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control)
        control->retain();
}

struct Guard {
    Object* object;
    Control* control;
    long reserved;

    Guard(Shared);
    ~Guard();
};

Shared acquire();

Shared function(void* argument)
{
    Shared result = acquire();
    Guard guard(result);
    result.object->update(argument);
    result.object->flag = true;
    return result;
}
