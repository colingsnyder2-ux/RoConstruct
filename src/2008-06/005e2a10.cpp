// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();

    volatile long strongCount;
    volatile long weakCount;
};

struct Shared {
    void* ptr;
    Control* control;

    ~Shared() {
        Control* p = control;
        if (p) {
            if (_InterlockedDecrement(&p->strongCount) == 0) {
                p->dispose();
                if (_InterlockedDecrement(&p->weakCount) == 0)
                    p->destroy();
            }
        }
    }
};

struct Factory {
    Shared get();
};

struct RotatePJoint {
    char padding[0x140];
    Factory factory;

    void* get();
};

void* RotatePJoint::get() {
    return factory.get().ptr;
}
