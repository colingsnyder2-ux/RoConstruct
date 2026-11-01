// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;

    __forceinline void add_ref();
    __forceinline void release();
};

__forceinline void Control::add_ref()
{
    _InterlockedIncrement(&strong);
}

__forceinline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Value {
    void* pointer;
    Control* control;
    double first;
    double second;

    __forceinline Value& operator=(const Value& source);
};

__forceinline Value& Value::operator=(const Value& source)
{
    pointer = source.pointer;
    Control* incoming = source.control;
    if (incoming != control) {
        if (incoming)
            incoming->add_ref();
        Control* outgoing = control;
        if (outgoing)
            outgoing->release();
        control = incoming;
    }
    first = source.first;
    second = source.second;
    return *this;
}

Value* __cdecl copy_values(Value* first, Value* last, Value* destination)
{
    for (; first != last; ++first, ++destination)
        *destination = *first;
    return destination;
}
