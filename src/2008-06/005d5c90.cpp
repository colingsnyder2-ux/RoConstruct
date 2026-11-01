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
};

struct Base {
    volatile unsigned long words[76];
    ~Base();
};

struct Shared {
    void* object;
    Control* volatile control;
    ~Shared();
};

struct S : Base {
    Shared shared;
    ~S();
};

inline Shared::~Shared()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0) {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

S::~S()
{
    words[0] = 0x0083ce54;
    words[4] = 0x0083ce48;
    words[5] = 0x0083ce40;
    words[8] = 0x0083ce38;
    words[9] = 0x0083ce28;
    words[17] = 0x0083ce18;
    words[25] = 0x0083ce08;
    words[33] = 0x0083cdf8;
    words[41] = 0x0083cde8;
    words[49] = 0x0083cdd8;
}
