// from server: 31% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct SignalSlot {
    void* vptr;
    long refCount;
    long weakCount;
};

struct VInstance {
    void connect(SignalSlot* slot, float f, int a, int b);
};

extern "C" void __cdecl sub_634380(void*);

void VInstance::connect(SignalSlot* slot, float f, int a, int b)
{
    SignalSlot* local = slot;
    if (local != 0) {
        _InterlockedExchangeAdd(&local->refCount, 1);
    }
    sub_634380((char*)this + 8);
    if (local != 0) {
        if (_InterlockedExchangeAdd(&local->refCount, -1) == 1) {
            void** vt = *(void***)local;
            void (*fn)(void*) = (void (*)(void*))vt[1];
            fn(local);
            if (_InterlockedExchangeAdd(&local->weakCount, -1) == 1) {
                void** vt2 = *(void***)local;
                void (*fn2)(void*) = (void (*)(void*))vt2[2];
                fn2(local);
            }
        }
    }
}
