// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct ControlBlock {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
    void release();
};

struct Service {
    void apply(int value);
};

struct ServicePtr {
    Service* pointer;
    ControlBlock* control;
    ~ServicePtr();
    Service* operator->() const;
};

struct S {
    ServicePtr getService();
    void finish();
    void f(int value);
};

__forceinline void ControlBlock::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

__forceinline Service* ServicePtr::operator->() const
{
    return pointer;
}

__forceinline ServicePtr::~ServicePtr()
{
    if (control)
        control->release();
}

void S::f(int value)
{
    getService()->apply(value);
    finish();
}
