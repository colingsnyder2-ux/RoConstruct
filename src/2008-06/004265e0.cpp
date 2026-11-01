// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" void __cdecl _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

extern unsigned char table_810060[];
extern unsigned char table_810054[];
extern unsigned char table_810048[];

struct RefCount {
    unsigned long reserved;
    volatile long strong;

    __forceinline void addRef();
};

__forceinline void RefCount::addRef()
{
    volatile long* p = &strong;
    _ReadWriteBarrier();
    _InterlockedExchangeAdd(p, 1);
}

struct Handle {
    void* pointer;
    RefCount* count;

    __forceinline Handle(const Handle& other);
    ~Handle();
};

__forceinline Handle::Handle(const Handle& other)
    : pointer(other.pointer), count(other.count)
{
    if (count)
        count->addRef();
}

struct S {
    void* table0;
    void* table1;
    void* table2;
    unsigned char padding[0x48];
    unsigned char flags;

    void initialize(int mode, Handle handle, int value);
    S* construct(const Handle& handle, int value);
};

S* S::construct(const Handle& handle, int value)
{
    initialize(0, handle, value);
    flags |= 2;
    table0 = table_810060;
    table1 = table_810054;
    table2 = table_810048;
    return this;
}
