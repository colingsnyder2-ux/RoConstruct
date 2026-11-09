// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct PartInstance;

struct GetSetImpl
{
    static PartInstance* get(PartInstance*);
};

struct Control
{
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;

    void release();
    void weakRelease();
};

__forceinline void Control::weakRelease()
{
    if (_InterlockedDecrement(&weak) == 0)
        destroy();
}

__forceinline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0)
    {
        dispose();
        weakRelease();
    }
}

struct Reference
{
    Control* control;
    Reference& operator=(const Reference&);
    ~Reference();
};

__forceinline Reference::~Reference()
{
    if (control)
        control->release();
}

struct Shared
{
    PartInstance* pointer;
    Reference reference;

    Shared();
    ~Shared();
    Shared& operator=(const Shared&);
};

__forceinline Shared::Shared()
{
    pointer = 0;
    reference.control = 0;
}

__forceinline Shared::~Shared()
{
}

__forceinline Shared& Shared::operator=(const Shared& other)
{
    pointer = other.pointer;
    reference = other.reference;
    return *this;
}

Shared __cdecl makeShared(PartInstance*);

struct Query
{
    PartInstance* find(unsigned, int, void*, void*, unsigned*, unsigned*);
};

struct Link
{
    char padding[0x84];
    Query* query;
};

struct Owner
{
    char padding[0x21c];
    Link* link;
};

struct S
{
    unsigned field0;
    unsigned field4;
    Owner* owner;
    char padding[0x20];
    unsigned field2c;

    Shared f(unsigned, unsigned);
};

Shared S::f(unsigned first, unsigned second)
{
    void* base = this ? &field4 : 0;
    Query* query = owner->link->query;
    PartInstance* part = query->find(
        first, 0, base, &field2c, &first, &second);

    Shared result;
    if (part)
        result = makeShared(GetSetImpl::get(part));
    return result;
}
