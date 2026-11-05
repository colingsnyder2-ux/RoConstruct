// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern "C" double __cdecl clockValue();

struct Control {
    virtual void reserved() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long references;
    volatile long weakReferences;

    void release();
};

inline void Control::release()
{
    if (_InterlockedDecrement(&references) == 0) {
        dispose();
        if (_InterlockedDecrement(&weakReferences) == 0)
            destroy();
    }
}

struct Object {
    void update(float);
};

struct Shared {
    Object* object;
    Control* control;

    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control) {
        volatile long* count = &control->references;
        _InterlockedExchangeAdd(count, 1);
    }
}

inline Shared::~Shared()
{
    if (control)
        control->release();
}

struct Guard {
    unsigned char storage[12];

    Guard(Shared);
    ~Guard();
};

struct RunService {
    unsigned char padding[0x1c0];
    float step;
    unsigned char padding2[4];
    double elapsed;

    void f(Shared);
};

void RunService::f(Shared value)
{
    double start = clockValue();
    {
        Guard guard(value);
        value.object->update(step);
        elapsed = clockValue() - start;
    }
}
