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
    void weakRelease();
};

inline void Control::weakRelease()
{
    if (_InterlockedDecrement(&weak) == 0)
        destroy();
}

struct Temporary {
    void* pointer;
    Control* control;
    ~Temporary();
};

struct Result {
    void* pointer;
    Control* control;
    Result(const Temporary&);
    ~Result();
};

inline Temporary::~Temporary()
{
    Control* p = control;
    if (p) {
        volatile long* count = &p->strong;
        if (_InterlockedDecrement(count) == 0) {
            p->dispose();
            p->weakRelease();
        }
    }
}

inline Result::Result(const Temporary& value)
    : pointer(value.pointer), control(value.control)
{
    if (control) {
        volatile long* count = &control->strong;
        _InterlockedExchangeAdd(count, 1);
    }
}

inline Result::~Result()
{
    Control* p = control;
    if (p) {
        volatile long* count = &p->strong;
        if (_InterlockedDecrement(count) == 0) {
            p->dispose();
            p->weakRelease();
        }
    }
}

struct S;

struct VTable {
    void* preceding[17];
    void* (__thiscall *get)(S*);
};

struct S {
    VTable* table;
    Result f();
};

extern Temporary __cdecl makeTemporary(void*);

Result S::f()
{
    return Result(makeTemporary(table->get(this)));
}
