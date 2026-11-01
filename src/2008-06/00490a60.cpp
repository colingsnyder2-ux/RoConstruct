// from server: 100% by colin
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCount {
    long unused;
    volatile long count;
};

struct Argument {
    unsigned long value1;
    RefCount* ref1;
    unsigned long value2;
    RefCount* ref2;
    unsigned long unused;

    void destroy();
};

extern bool __cdecl func_0060a2f0(void*);

inline void* __cdecl operator new(unsigned int, void* p) {
    return p;
}

struct Payload {
    unsigned long first;
    unsigned long value1;
    RefCount* ref1;
    unsigned long value2;
    RefCount* ref2;

    __forceinline Payload(unsigned long, const Argument&);
};

__forceinline Payload::Payload(unsigned long value, const Argument& arg) {
    first = value;
    value1 = arg.value1;
    ref1 = arg.ref1;
    if (ref1)
        _InterlockedIncrement(&ref1->count);
    value2 = arg.value2;
    ref2 = arg.ref2;
    if (ref2)
        _InterlockedIncrement(&ref2->count);
}

struct S {
    unsigned long tag;
    unsigned long unused;
    Payload payload;

    S* f(unsigned long, Argument);
};

S* S::f(unsigned long first, Argument arg) {
    tag = 0;
    if (!func_0060a2f0(&first)) {
        new (&payload) Payload(first, arg);
        tag = 0x00821ca0;
        arg.destroy();
        return this;
    }
    tag = 0;
    arg.destroy();
    return this;
}
