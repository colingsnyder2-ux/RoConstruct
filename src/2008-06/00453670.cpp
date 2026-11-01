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

    void addRef();
    void release();
};

__forceinline void Control::addRef() {
    volatile long* count =
        reinterpret_cast<volatile long*>(reinterpret_cast<char*>(this) + 4);
    _InterlockedExchangeAdd(count, 1);
}

__forceinline void Control::release() {
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Result {
    void invoke();
};

struct Object {
    Result* getResult();
};

struct Shared {
    Object* pointer;
    Control* control;

    Shared(const Shared& other);
    ~Shared();
};

__forceinline Shared::Shared(const Shared& other)
    : pointer(other.pointer), control(other.control) {
    if (control)
        control->addRef();
}

__forceinline Shared::~Shared() {
    if (control)
        control->release();
}

struct Source {
    Shared get();
};

struct Guard {
    unsigned char storage[12];
    Guard(Shared value);
    ~Guard();
};

struct CRobloxDoc {
    unsigned char padding[0x94];
    Source* source;
    void f();
};

void CRobloxDoc::f() {
    Shared value = source->get();
    Guard guard(value);
    value.pointer->getResult()->invoke();
}
