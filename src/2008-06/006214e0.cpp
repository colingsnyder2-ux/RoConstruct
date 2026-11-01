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

struct Ref {
    void* pointer;
    Control* control;
    unsigned char value[16];

    Ref(void*, double);
    ~Ref();
    Ref& operator=(const Ref&);
};

struct S {
    unsigned long first;
    Ref reference;

    void f(void*, double);
};

inline Ref::~Ref()
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

void S::f(void* p, double value)
{
    unsigned char* base = p ? static_cast<unsigned char*>(p) - 12 : 0;
    base[8] = 1;
    reference = Ref(p, value);
}
