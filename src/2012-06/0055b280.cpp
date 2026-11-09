// from server: 44% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long ref1;
    long ref2;
};

struct Slot {
    void* vptr;
    char pad[8];
    RefCounted* ref;
};

struct Vtbl {
    void* f0;
    void (*f1)(void*);
    void (*f2)(void*);
};

void SlotAssign(Slot* dst, Slot* src, int mode) {
    if (mode == 0 || mode == 1) {
        if (dst) {
            dst->vptr = src->vptr;
            *(int*)((char*)dst + 4) = *(int*)((char*)src + 4);
            *(int*)((char*)dst + 8) = *(int*)((char*)src + 8);
            RefCounted* r = *(RefCounted**)((char*)src + 12);
            *(RefCounted**)((char*)dst + 12) = r;
            if (r) {
                _InterlockedExchangeAdd(&r->ref1, 1);
            }
        }
        if (mode == 1) {
            RefCounted* r = *(RefCounted**)((char*)src + 12);
            if (r) {
                if (_InterlockedExchangeAdd(&r->ref1, -1) == 1) {
                    ((Vtbl*)r->vptr)->f1(r);
                    if (_InterlockedExchangeAdd(&r->ref2, -1) == 1) {
                        ((Vtbl*)r->vptr)->f2(r);
                    }
                }
            }
        }
        return;
    }
    if (mode == 2) {
        RefCounted* r = *(RefCounted**)((char*)src + 12);
        if (r) {
            if (_InterlockedExchangeAdd(&r->ref1, -1) == 1) {
                ((Vtbl*)r->vptr)->f1(r);
                if (_InterlockedExchangeAdd(&r->ref2, -1) == 1) {
                    ((Vtbl*)r->vptr)->f2(r);
                }
            }
        }
        return;
    }
    if (mode == 3) {
        *(void**)dst = (void*)0xd87b80;
        *((char*)dst + 4) = 0;
        *((char*)dst + 5) = 0;
        return;
    }
    *(void**)dst = (void*)0xd87b80;
    *((char*)dst + 4) = 0;
    *((char*)dst + 5) = 0;
}
