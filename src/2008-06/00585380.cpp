// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
    void release();
};

inline void Control::release() {
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Shared {
    void* pointer;
    Control* control;
    ~Shared();
};

inline Shared::~Shared() {
    if (control)
        control->release();
}

struct Holder {
    Shared get();
};

struct Property {
    virtual void reserved0();
    virtual void reserved1();
    virtual void reserved2();
    virtual void set(void*, void**);
};

struct S {
    void* vtable;
    Property* property;
    void f(void*, void*);
};

void S::f(void* object, void* value) {
    Shared temporary = static_cast<Holder*>(value)->get();
    value = temporary.pointer;
    property->set(object, &value);
}
