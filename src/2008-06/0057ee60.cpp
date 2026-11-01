// from server: 100% by colin
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Control {
    void* reserved;
    volatile long references;
};

struct Pointer {
    void* object;
    Control* control;

    Pointer(const Pointer&);
    ~Pointer();
};

__forceinline Pointer::Pointer(const Pointer& other)
    : object(other.object), control(other.control)
{
    if (control)
        _InterlockedIncrement(&control->references);
}

struct Predicate {
    bool (__cdecl *function)(void*, Pointer);
    void* context;
};

Pointer* __cdecl findPointer(Pointer* first, Pointer* last,
                            Predicate predicate)
{
    while (first != last) {
        if (predicate.function(predicate.context, *first))
            break;
        ++first;
    }
    return first;
}
