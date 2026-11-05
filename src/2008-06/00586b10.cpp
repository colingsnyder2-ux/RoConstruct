// from server: 100% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)


struct RefCount {
    long reserved;
    volatile long count;
};

struct Pair {
    void* object;
    RefCount* control;

    Pair();
    Pair(const Pair&);
};

inline Pair::Pair() : object(0), control(0) {}

inline Pair::Pair(const Pair& other)
    : object(other.object), control(other.control)
{
    if (control)
        _InterlockedIncrement(&control->count);
}

struct Key {
    char data[20];
};

namespace RBX {
    class Instance {
    public:
        virtual ~Instance();
        char pad[0x100];
        Instance* next;
    };

    class ServiceProvider : public Instance {
    public:
        Pair get(const Key&);
    };
}

RBX::ServiceProvider* __cdecl func_00465210(RBX::Instance*);

struct Script : RBX::Instance {
    char padding[0x28];
    Pair cached;
    Key key;
    long state;

    Pair get();
};

Pair Script::get()
{
    volatile long temporary;

    if (state == 0) {
        temporary = 0;
        return cached;
    }

    temporary = 0;
    RBX::ServiceProvider* provider = func_00465210(this);
    if (provider)
        return provider->get(key);

    return Pair();
}
