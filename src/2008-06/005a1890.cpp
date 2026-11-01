// from server: 100% by colin
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Value {
    void* pointer;
    volatile long* control;
    Value(const Value&);
    ~Value();
};

inline Value::Value(const Value& other)
    : pointer(other.pointer), control(other.control)
{
    if (control)
        _InterlockedIncrement(control + 1);
}

struct Iterator {
    void* unused;
    Value* pointer;
};

struct Function {
    void (__cdecl *callback)(Value, int, int, int);
    int a;
    int b;
    int c;
};

Function __cdecl func_005a1890(Iterator first, Iterator last, Function function)
{
    Value* current = first.pointer;
    Value* end = last.pointer;
    for (; current != end; ++current)
        function.callback(*current, function.a, function.b, function.c);
    return function;
}
