// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" void __cdecl _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

struct Control {
    long unused;
    volatile long references;
};

struct Shared {
    void* object;
    Control* control;
    Shared(const Shared& other);
    ~Shared();
};

__forceinline Shared::Shared(const Shared& other)
{
    object = other.object;
    control = other.control;
    if (control) {
        volatile long* count = &control->references;
        _ReadWriteBarrier();
        _InterlockedExchangeAdd(count, 1);
    }
}

struct Iterator {
    void* owner;
    Shared* current;
};

struct Callback {
    void (__cdecl* function)(Shared, void*);
    void* context;
    Callback(const Callback& other);
};

__forceinline Callback::Callback(const Callback& other)
{
    function = other.function;
    context = other.context;
}

Callback __cdecl traverse(Iterator first, Iterator last, Callback callback)
{
    Shared* current = first.current;
    Shared* end = last.current;
    for (; current != end; ++current)
        callback.function(*current, callback.context);
    return callback;
}
