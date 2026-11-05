// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

bool func_0060a2f0();

inline void* operator new(unsigned int, void* p)
{
    return p;
}

struct RefCount
{
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct MemberPointer
{
    unsigned long a;
    unsigned long b;
    unsigned long c;
    unsigned long d;
};

struct Shared
{
    unsigned long object;
    RefCount* ref;

    Shared(const Shared& other);
};

inline Shared::Shared(const Shared& other)
    : object(other.object), ref(other.ref)
{
    if (ref)
        _InterlockedIncrement(&ref->strong);
}

struct Payload
{
    MemberPointer member;
    Shared shared;
};

struct S
{
    unsigned long manager;
    unsigned long reserved;
    char storage[sizeof(Payload)];

    S* f(Payload value, unsigned long);
};

S* S::f(Payload value, unsigned long)
{
    manager = 0;
    if (!reinterpret_cast<bool (__cdecl *)(const Payload*)>(
            func_0060a2f0)(&value))
    {
        new (storage) Payload(value);
        manager = 0x843f50;
    }
    else
    {
        manager = 0;
    }

    if (value.shared.ref)
    {
        RefCount* r = value.shared.ref;
        if (_InterlockedDecrement(&r->strong) == 0)
        {
            r->dispose();
            if (_InterlockedDecrement(&r->weak) == 0)
                r->destroy();
        }
    }
    return this;
}
