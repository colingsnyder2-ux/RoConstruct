// from server: 100% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)


void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

extern "C" long (__stdcall *SendMessageA)(void*, unsigned int, unsigned int, long);

struct RefCount {
    unsigned long reserved;
    volatile long strong;
};

struct Shared {
    void* object;
    RefCount* count;

    Shared(const Shared&);
    ~Shared();
};

struct S;

struct Tool {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void activate();

    unsigned char padding[0x7c];
    long item;
    unsigned char tail[8];

    Tool(const Shared&, S*);
    void setup();
};

struct S {
    unsigned char padding0[0x20];
    void* window;
    unsigned char padding1[0x70];
    Tool* tool;
    unsigned char padding2[0x8c];
    Shared selection;

    void prepare();
    void f();
};

__forceinline Shared::Shared(const Shared& other)
{
    object = other.object;
    count = other.count;
    if (count)
        _InterlockedIncrement(&count->strong);
}

void S::f()
{
    prepare();
    if (selection.object && window) {
        tool = new Tool(Shared(selection), this);
        tool->activate();
        tool->setup();
        SendMessageA(window, 0x1102, 2, tool->item);
    }
}
