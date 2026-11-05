// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Resource {
    ~Resource();
};

struct Holder {
    long count;
    unsigned char flags;
    unsigned char padding[3];
    Resource resource;
};

struct Control {
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared {
    Holder* pointer;
    Control* control;
    ~Shared();
};

struct S {
    Shared value;
    ~S();
};

inline Shared::~Shared()
{
    Control* p = control;
    if (p) {
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

S::~S()
{
    --value.pointer->count;
    if (value.pointer->count == 0 && (value.pointer->flags & 1)) {
        value.pointer->resource.~Resource();
        value.pointer->flags &= 0xfe;
    }
}
