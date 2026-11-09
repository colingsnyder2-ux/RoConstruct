// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual ~Control();
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;

    void add_ref();
    void release();
};

__forceinline void Control::add_ref() {
    _InterlockedIncrement(&strong);
}

__forceinline void Control::release() {
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Shared {
    void* pointer;
    Control* control;

    Shared(const Shared& other);
    ~Shared();
};

__forceinline Shared::Shared(const Shared& other)
    : pointer(other.pointer), control(other.control) {
    if (control)
        control->add_ref();
}

__forceinline Shared::~Shared() {
    if (control)
        control->release();
}

struct Object {
    char padding[0x1c0];
    int* offsets;
};

struct S {
    typedef void (__thiscall *Setter)(void*, Shared);
    Setter setter;
    int adjustment;
    int offset;
    void f(Object* object, Shared value);
};

void S::f(Object* object, Shared value) {
    setter(reinterpret_cast<char*>(object) + 0x1c0 +
           *reinterpret_cast<int*>(reinterpret_cast<char*>(object->offsets) + offset) +
           adjustment, value);
}
