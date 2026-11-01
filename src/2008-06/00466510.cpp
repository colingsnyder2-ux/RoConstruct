// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* object;
    Control* control;
    Shared(const Shared&);
    ~Shared();
};

__forceinline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control)
        _InterlockedIncrement(&control->strong);
}

__forceinline Shared::~Shared()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0) {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

struct Primary {
    virtual ~Primary();
    unsigned char padding[0x50];
};

struct Secondary {
    virtual ~Secondary();
    unsigned char padding[0x138];
};

struct Base : Primary, Secondary {
    virtual ~Base();
};

struct First {
    virtual ~First();
};

struct Storage {
    virtual ~Storage();
    void* allocation;
    unsigned int reserved[2];
    void* begin;
    void* end;
    void* capacity;
    unsigned int reserved2;
    void* object;
};

struct Registry {
    void remove(Storage*);
};

struct Object {
    unsigned char padding[0x130];
    Registry registry;
};

struct Guard {
    unsigned long data[3];
    Guard(Shared);
    ~Guard();
};

struct S : Base, First, Storage {
    Shared shared;
    Shared owner;
    virtual ~S();
};

S::~S()
{
    Guard guard(shared);
    if (owner.object)
        static_cast<Object*>(owner.object)->registry.remove(
            static_cast<Storage*>(this));
}
