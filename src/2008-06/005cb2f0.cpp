// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

namespace RBX {
    class Instance;
    class ServiceProvider;
}

RBX::ServiceProvider* __cdecl func_00492e00(RBX::Instance*);

struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct __declspec(novtable) Listener {
    virtual void notify() = 0;
};

struct Event {
    void connect(Listener*);
};

struct Product {
    char padding[0x130];
    Event event;
};

struct Shared {
    Product* pointer;
    Control* control;
    ~Shared();
};

Shared __cdecl func_00618a40(RBX::Instance*);

struct Weak {
    Product* pointer;
    Control* control;
    Weak(const Shared&);
    ~Weak();
};

struct Base {
    virtual ~Base();
    volatile unsigned first;
    volatile unsigned second;
    Base();
};

struct S : Base, Listener {
    Shared product;
    Weak instance;
    S(RBX::Instance*);
    virtual ~S();
    virtual void notify();
};

inline Base::Base() : first(0), second(0) {}

inline Shared::~Shared()
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

inline Weak::Weak(const Shared& p)
    : pointer(p.pointer), control(p.control)
{
    if (control) {
        volatile long* count = &control->weak;
        _InterlockedExchangeAdd(count, 1);
    }
}

S::S(RBX::Instance* p)
    : product(func_00618a40(
          reinterpret_cast<RBX::Instance*>(func_00492e00(p)))),
      instance(func_00618a40(p))
{
    if (product.pointer)
        product.pointer->event.connect(static_cast<Listener*>(this));
}
