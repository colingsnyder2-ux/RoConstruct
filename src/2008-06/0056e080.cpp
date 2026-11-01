// from server: 100% by colin
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Control {
    long unused;
    volatile long references;
};

struct Holder {
    char* pointer;
    Control* control;
};

Holder* __cdecl convert(Holder* result, const Holder& source)
{
    volatile int state = 0;
    char* p = source.pointer;
    result->pointer = p ? p + 20 : 0;
    result->control = source.control;
    if (result->control)
        _InterlockedIncrement(&result->control->references);
    return result;
}
