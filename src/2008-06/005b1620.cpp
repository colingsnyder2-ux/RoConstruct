// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Ref {
    virtual ~Ref();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct S;

struct Shared {
    S* ptr;
    Ref* ref;

    ~Shared()
    {
        Ref* r = ref;
        if (r && _InterlockedDecrement(&r->strong) == 0) {
            r->dispose();
            if (_InterlockedDecrement(&r->weak) == 0)
                r->destroy();
        }
    }
};

struct Controller {
    void* check();
};

extern Controller* __cdecl resolve(S*);

struct S {
    char padding0[0x104];
    S* parent;
    char padding1[0x4C];
    int state;

    int has();
    void setParent(S*);
    void f(Shared);
};

void S::f(Shared value)
{
    if (state == 2) {
        S* parentObject = value.ptr->parent;
        Controller* controller = resolve(parentObject);
        if (controller && controller->check() && !parentObject->has())
            setParent(parentObject);
    }
}
