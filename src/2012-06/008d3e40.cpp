// from server: 52% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" unsigned char __cdecl _interlockedbittestandset(volatile long*, long);
#pragma intrinsic(_interlockedbittestandset)

extern "C" void __stdcall SetEvent(void*);

extern void __cdecl func_008d3070();
extern void __cdecl func_00413890();
extern void __cdecl func_008c05f0();
extern void* __cdecl func_0040b9c0();

struct S {
    char pad0[0x10];
    void* field10;
    void method();
};

void S::method()
{
    if (field10 != 0) {
        func_008d3070();
        void* p = field10;
        func_00413890();
        void* q = field10;
        field10 = 0;
        if (q != 0) {
            func_008c05f0();
        }
        if (p != 0) {
            long old = _InterlockedExchangeAdd((volatile long*)p, (long)0x80000000);
            if ((old & 0x40000000) == 0 && old > (long)0x80000000) {
                if (!_interlockedbittestandset((volatile long*)p, 0x1e)) {
                    SetEvent(func_0040b9c0());
                }
            }
        }
    }
}
