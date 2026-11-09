// from server: 83% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S {
    void __cdecl f(unsigned int count, void* dst, void* src);
};

void S::f(unsigned int count, void* dst, void* src)
{
    if (count == 0)
        return;
    void* (*allocFn)() = *(void*(**)())0x9ea380;
    do {
        if (dst != 0) {
            allocFn();
            *(void**)dst = *(void**)src;
            void* p = *(void**)((char*)src + 4);
            *(void**)((char*)dst + 4) = p;
            if (p != 0) {
                _InterlockedExchangeAdd((volatile long*)((char*)p + 8), 1);
            }
        }
        --count;
        dst = (char*)dst + 8;
    } while (count != 0);
}
