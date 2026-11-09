// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* object;
    Control* control;
    ~Shared();
};

__forceinline Shared::~Shared()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0) {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

template<int Size, int Id> struct Part {
    virtual void slot();
    char padding[Size - 4];
};

template<int Id> struct Part<4, Id> {
    virtual void slot();
};

struct Base :
    Part<16, 0>,
    Part<4, 1>,
    Part<12, 2>,
    Part<4, 3>,
    Part<32, 4>,
    Part<32, 5>,
    Part<32, 6>,
    Part<32, 7>,
    Part<32, 8>,
    Part<108, 9>,
    Part<56, 10>,
    Part<4, 11>,
    Part<4, 12>,
    Part<4, 13>,
    Part<4, 14>,
    Part<4, 15>,
    Part<4, 16>
{
    ~Base();
};

struct LocalBackpack : Base {
    Shared first;
    Shared second;
    Shared third;
    Shared fourth;
    Shared fifth;

    virtual void slot();
    void cleanup();
    ~LocalBackpack();
};

LocalBackpack::~LocalBackpack()
{
    cleanup();
}
