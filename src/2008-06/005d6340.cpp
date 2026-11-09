// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);
extern char instanceType;
extern char teamType;

struct Control {
    virtual void reserved() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* object;
    Control* control;
    ~Shared();
};

inline Shared::~Shared()
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

Shared __cdecl makeShared(void*);

struct Slot {
    void fire(const Shared&);
};

struct Holder {
    Slot* slot;
};

struct Signal {
    Holder* get();
};

struct Teams {
    char padding[0x130];
    Signal signal;
    void notify(void*);
};

void Teams::notify(void* object)
{
    if (__RTDynamicCast(object, 0, &instanceType, &teamType, 0)) {
        Holder* holder = signal.get();
        holder->slot->fire(makeShared(object));
    }
}
