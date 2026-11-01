// from server: 100% by king_originala
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
    void release();
};

inline void Control::release() {
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct SharedCount {
    Control* control;
    SharedCount& operator=(const SharedCount& other);
    ~SharedCount();
};

inline SharedCount::~SharedCount() {
    if (control)
        control->release();
}

struct SharedValue {
    void* pointer;
    SharedCount count;
    SharedValue& operator=(const SharedValue& other);
};

inline SharedValue& SharedValue::operator=(const SharedValue& other) {
    pointer = other.pointer;
    count = other.count;
    return *this;
}

SharedValue __cdecl makeValue(void* argument);

struct S {
    char padding[0x148];
    SharedValue value;
    void f(void* argument);
};

void S::f(void* argument) {
    value = makeValue(argument);
}
