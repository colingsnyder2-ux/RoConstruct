// from server: 60% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S {
};

void __cdecl f(void** first, void** last, void** dest) {
    if (first != last) {
        do {
            if (dest != 0) {
                void* p = *first;
                *dest = p;
                if (p != 0) {
                    volatile long* ref = (volatile long*)((char*)p + 0x10);
                    _InterlockedExchangeAdd(ref, 1);
                }
            }
            first++;
            dest++;
        } while (first != last);
    }
}
