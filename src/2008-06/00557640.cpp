// from server: 100% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct S;

struct Shared {
    S* object;
    Control* control;
    ~Shared();
};

struct S {
    char padding[0x104];
    S* parent;

    bool ancestor(S* object);
    bool f(Shared object);
};

__forceinline Shared::~Shared()
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

bool S::f(Shared object)
{
    bool result;
    if (!object.object) {
        result = false;
    } else {
        S* p = object.object->parent;
        if (p == this)
            result = true;
        else
            result = ancestor(p);
    }
    return result;
}

Control::~Control()
{
}
