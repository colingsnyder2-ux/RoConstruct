// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Target {
    int invoke(int a, int b);
};

struct S {
    char padding[0x130];
    Target* target;
    int invoke(int a, int b);
};

struct Node {
    int get();
};

struct RefCount {
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Handle {
    S* pointer;
    RefCount* count;
    ~Handle();
};

Handle __cdecl acquire();

__forceinline Handle::~Handle()
{
    RefCount* p = count;
    if (p) {
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

int __cdecl lookup(int value)
{
    Handle handle = acquire();
    int node = handle.pointer->invoke(value, 1);
    return node ? ((Node*)node)->get() : 0;
}
