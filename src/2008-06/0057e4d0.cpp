// from server: 100% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)


struct Control {
    long reserved;
    volatile long references;
};

struct Shared {
    void* object;
    Control* control;
    Shared(const Shared&);
    ~Shared();
};

__forceinline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control)
        _InterlockedIncrement(&control->references);
}

struct Iterator {
    void* owner;
    Shared* position;
};

struct Function {
    void (__cdecl *callback)(Shared);
    unsigned long state;
    Function(const Function&);
};

__forceinline Function::Function(const Function& other)
    : callback(other.callback), state(other.state)
{
}

Function __cdecl apply(Iterator first, Iterator last, Function function)
{
    Shared* current = first.position;
    Shared* end = last.position;
    for (; current != end; ++current)
        function.callback(*current);
    return function;
}
