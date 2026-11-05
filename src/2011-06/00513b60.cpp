// from server: 45% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __cdecl sub_410880(int);

extern "C" int (__stdcall *off_a403a8)(int, int);

struct PhysicsPacketCache {
    volatile long refcount;
    char pad[8];
    void* ptr;
    bool release(int);
};

bool PhysicsPacketCache::release(int a) {
    long esi = refcount;
    for (;;) {
        long eax;
        if (esi & 0x80400000) {
            eax = (esi & 0xfffff800) + 0x800;
            eax ^= esi;
            eax &= 0x3ff800;
        } else {
            eax = esi + 1;
            eax ^= esi;
            eax &= 0x7ff;
        }
        eax ^= esi;
        long prev = _InterlockedExchangeAdd(&refcount, eax - esi);
        if (prev == esi) break;
        esi = prev;
    }
    long eax = esi;
    eax >>= 9;
    eax |= esi;
    if (eax & 0x400000) {
        int r = sub_410880(a);
        int* p = *(int**)((char*)this + 0xc);
        int r2 = off_a403a8(*p, r);
        if (r2 != 0x102) {
            return true;
        }
        long esi2 = refcount;
        for (;;) {
            long eax2;
            if (esi2 & 0x80400000) {
                long ecx = esi2 >> 11;
                if ((ecx & 0x7ff) == 0) {
                    eax2 = 0;
                } else {
                    eax2 = (ecx - 1) << 11;
                    eax2 ^= esi2;
                    eax2 &= 0x3ff800;
                }
            } else {
                eax2 = esi2 + 1;
                eax2 ^= esi2;
                eax2 &= 0x7ff;
            }
            eax2 ^= esi2;
            long prev2 = _InterlockedExchangeAdd(&refcount, eax2 - esi2);
            if (prev2 == esi2) break;
            esi2 = prev2;
        }
        unsigned char al = (unsigned char)((unsigned long)esi2 >> 31);
        al |= (unsigned char)((unsigned long)esi2 >> 22);
        al = ~al;
        al &= 1;
        return al != 0;
    }
    return true;
}
