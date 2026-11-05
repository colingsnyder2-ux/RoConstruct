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

struct Value {
    void* object;
    Control* control;
    Value(const Value& other);
    ~Value();
};

__forceinline Value::Value(const Value& other)
    : object(other.object), control(other.control)
{
    if (control)
        _InterlockedIncrement(&control->references);
}

int __cdecl count_if(Value* first, Value* last,
                     bool (__cdecl *predicate)(Value))
{
    int count = 0;
    for (; first != last; ++first) {
        if (predicate(*first))
            ++count;
    }
    return count;
}
