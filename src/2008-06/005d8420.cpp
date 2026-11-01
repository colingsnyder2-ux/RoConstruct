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

struct Object {
    void setValue(float);
};

struct Count {
    Control* control;

    Count(const Count&);
    ~Count();
};

inline Count::Count(const Count& other)
    : control(other.control)
{
    if (control) {
        volatile long* count = &control->strong;
        _InterlockedExchangeAdd(count, 1);
    }
}

inline Count::~Count()
{
    if (control) {
        Control* p = control;
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct Shared {
    Object* object;
    Count count;

    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : object(other.object), count(other.count)
{
}

inline Shared::~Shared()
{
}

extern Shared __cdecl createRotate();
extern Shared __cdecl createLighting();
extern const float initialValue;

Shared __cdecl makeState(bool rotate)
{
    if (rotate) {
        Shared result = createRotate();
        result.object->setValue(initialValue);
        return result;
    } else {
        Shared result = createLighting();
        return result;
    }
}
