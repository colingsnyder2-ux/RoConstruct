// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct ControlBlock {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();

    volatile long strongCount;
    volatile long weakCount;
};

struct SharedResult {
    void* object;
    ControlBlock* control;
};

struct WeakReference {
    SharedResult* lock(SharedResult* result);
};

struct RotatePJoint {
    char padding[0x148];
    WeakReference reference;

    void* get();
};

void* RotatePJoint::get() {
    SharedResult result;
    SharedResult* locked = reference.lock(&result);
    ControlBlock* control = result.control;
    void* object = locked->object;

    if (control) {
        if (_InterlockedDecrement(&control->strongCount) == 0) {
            control->dispose();
            if (_InterlockedDecrement(&control->weakCount) == 0)
                control->destroy();
        }
    }

    return object;
}
