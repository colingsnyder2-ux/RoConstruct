// from server: 50% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" unsigned char __cdecl _interlockedbittestandset(volatile long*, long);
#pragma intrinsic(_interlockedbittestandset)

extern "C" void __stdcall SetEvent(void*);

extern void G1_func_00418890();
extern void G1_func_007b7360();
extern void G1_func_004109e0();

struct CSelectionTreeCtrl {
    char pad0[0xc4];
    volatile long refcount;
    char pad1[4];
    volatile long refcount2;
    char pad2[0x100];
    char field_10c[8];
    void func_00421d30(int);
};

void CSelectionTreeCtrl::func_00421d30(int arg)
{
    char local[8];
    G1_func_00418890();
    G1_func_007b7360();
    if (_InterlockedExchangeAdd(&refcount, -1) == 1) {
        *(long*)((char*)this + 0xc8) = 0;
        long old = _InterlockedExchangeAdd(&refcount2, (long)0x80000000);
        if ((old & 0x40000000) == 0 && old > (long)0x80000000) {
            if (!_interlockedbittestandset((volatile long*)&refcount2, 0x1e)) {
                G1_func_004109e0();
                SetEvent((void*)0x98b228);
            }
        }
    }
}
