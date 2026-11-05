// from server: 67% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S {
    char pad[0x10];
    long *ref;
    void assign(long **out);
};

void S::assign(long **out) {
    long *p = this->ref;
    *out = p;
    if (p != 0) {
        _InterlockedExchangeAdd(p, 1);
    }
}
