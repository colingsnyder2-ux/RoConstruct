// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused();
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

inline Shared::~Shared()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0) {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

Shared __cdecl makeShared(void*);

struct Weak {
    void* object;
    Control* control;

    Weak(const Shared&);
    ~Weak();
};

inline Weak::Weak(const Shared& source)
    : object(source.object), control(source.control)
{
    if (control) {
        volatile long* count = &control->weak;
        _InterlockedExchangeAdd(count, 1);
    }
}

inline Weak::~Weak()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->weak) == 0)
        p->destroy();
}

struct Subobject {
    char storage[24];
    Subobject(void*);
};

struct Inner {
    char padding[0x84];
    void* value;
};

struct Object {
    char padding[0x2e4];
    Inner* inner;
};

struct S : Weak {
    Subobject subobject;
    bool enabled;
    Object* object;
    void* value;

    S(void*, void*, Object*);
};

S::S(void* first, void* second, Object* third)
    : Weak(makeShared(first)), subobject(second)
{
    object = third;
    enabled = true;
    value = third->inner->value;
}
