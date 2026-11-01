// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
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
    Reference() : control(0) {}
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

__forceinline Shared::Shared() : pointer(0)
{
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
    char padding[0xb0];
    Query* query;
};

struct Owner
{
    char padding[0x224];
    Link* link;
};

struct PartInstance
{
    unsigned getOwnerId();
};

struct S
{
    unsigned field0;
    unsigned field4;
    Owner* owner;
    char padding[0xc];
    unsigned field18;
    char padding2[0x18];
    unsigned field34;

    Shared f(unsigned, unsigned, unsigned);
};

Shared S::f(unsigned first, unsigned second, unsigned third)
{
    void* base = &field4;
    field18 = third;
    Query* query = owner->link->query;
    PartInstance* part = query->find(first, 0, base, &field34, &first, &second);

    Shared result;
    if (part && part->getOwnerId() != third)
        result = makeShared(GetSetImpl::get(part));
    return result;
}
