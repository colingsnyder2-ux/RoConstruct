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

struct Member {
    virtual ~Member();
};

struct Base {
    volatile unsigned long table0;
    char pad04[0x0c];
    volatile unsigned long table10;
    volatile unsigned long table14;
    char pad18[8];
    volatile unsigned long table20;
    volatile unsigned long table24;
    char pad28[0x1c];
    volatile unsigned long table44;
    char pad48[0x1c];
    volatile unsigned long table64;
    char pad68[0x1c];
    volatile unsigned long table84;
    char pad88[0x1c];
    volatile unsigned long tableA4;
    char padA8[0x1c];
    volatile unsigned long tableC4;
    char padC8[0x68];
    ~Base();
};

struct Camera : Base {
    Member member;
    char pad134[0xa8];
    Shared shared;
    ~Camera();
};

Camera::~Camera()
{
    table0 = 0x83a654;
    table10 = 0x83a648;
    table14 = 0x83a640;
    table20 = 0x83a638;
    table24 = 0x83a628;
    table44 = 0x83a618;
    table64 = 0x83a608;
    table84 = 0x83a5f8;
    tableA4 = 0x83a5e8;
    tableC4 = 0x83a5d8;
}
