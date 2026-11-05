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

struct Accoutrement;

struct Shared {
    Accoutrement* pointer;
    Control* control;
    ~Shared();
};

extern Accoutrement* __cdecl helper(Accoutrement*);

struct Accoutrement {
    char padding[0x134];
    Accoutrement* attached;
    void update();
    void change(int, Accoutrement*);
    void f(Shared value);
};

inline Shared::~Shared() {
    Control* p = control;
    if (p) {
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

void Accoutrement::f(Shared value) {
    if (value.pointer != this) {
        if (value.pointer == attached)
            change(0, helper(this));
        update();
    }
}
