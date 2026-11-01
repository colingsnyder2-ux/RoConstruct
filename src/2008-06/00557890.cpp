// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct RefCount {
    virtual ~RefCount();
    virtual void dispose() = 0;
    virtual void destroy();

    volatile long strong;
    volatile long weak;

    void release();
};

struct S;

struct Pointer {
    S* object;
    RefCount* count;

    ~Pointer();
};

struct S {
    char padding[0x104];
    S* parent;

    bool f(S* node);
    bool g(Pointer node);
};

__forceinline void RefCount::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

__forceinline Pointer::~Pointer()
{
    if (count)
        count->release();
}

bool S::g(Pointer node)
{
    bool result;
    if (node.object == parent)
        result = true;
    else if (parent)
        result = parent->f(node.object);
    else
        result = false;
    return result;
}
