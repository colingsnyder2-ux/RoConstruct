// from server: 48% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RBX_Reflection_ClassDescriptor_0040de50 {
    short __cdecl get_refcount(char* p);
};

short RBX_Reflection_ClassDescriptor_0040de50::get_refcount(char* p) {
    if (p != 0) {
        p -= 5;
    } else {
        p = 0;
    }
    short* ref = (short*)(p - 4);
    short old = (short)_InterlockedExchangeAdd((volatile long*)ref, 1);
    return *ref;
}
