// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* object;
    Control* volatile control;
    ~Shared();
};

__forceinline Shared::~Shared()
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

struct Base {
    volatile unsigned long words[0x2d68 / 4];
    ~Base();
};

struct S : Base {
    Shared shared;
    ~S();
};

S::~S()
{
    words[0x0000 / 4] = 0x823474;
    words[0x0010 / 4] = 0x823464;
    words[0x0014 / 4] = 0x82345c;
    words[0x0020 / 4] = 0x823454;
    words[0x0024 / 4] = 0x823444;
    words[0x0044 / 4] = 0x823434;
    words[0x0064 / 4] = 0x823424;
    words[0x0084 / 4] = 0x823414;
    words[0x00a4 / 4] = 0x823404;
    words[0x00c4 / 4] = 0x8233f4;
    words[0x2b74 / 4] = 0x8233c4;
}
