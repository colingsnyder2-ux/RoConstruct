// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

void __cdecl operator delete(void*);

struct Control {
    virtual void dispose();
    virtual void release();
    virtual void destroy();
    volatile long strongCount;
    volatile long weakCount;
};

struct Weak {
    ~Weak();
};

struct Thing {
    ~Thing();
};

struct Primary {
    virtual ~Primary();
};

struct Secondary {
    virtual ~Secondary();
};

struct Base : Primary, Secondary {
    char data[20];
    virtual ~Base();
};

struct ThingOwner {
    Thing* pointer;
    ~ThingOwner();
};

struct WeakOwner {
    Weak* pointer;
    ~WeakOwner();
};

struct Shared {
    void* pointer;
    Control* control;
    ~Shared();
};

struct S : Base {
    ThingOwner thing;
    WeakOwner weak;
    Shared shared;
    virtual ~S();
};

inline ThingOwner::~ThingOwner()
{
    Thing* p = pointer;
    if (p) {
        p->~Thing();
        operator delete(p);
    }
}

inline WeakOwner::~WeakOwner()
{
    Weak* p = pointer;
    if (p) {
        p->~Weak();
        operator delete(p);
    }
}

inline Shared::~Shared()
{
    Control* p = control;
    if (p) {
        if (_InterlockedDecrement(&p->strongCount) == 0) {
            p->release();
            if (_InterlockedDecrement(&p->weakCount) == 0)
                p->destroy();
        }
    }
}

S::~S()
{
}
