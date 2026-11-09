// from server: 45% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl sub_410330(void*, void*);

struct S {
    void* vptr;
    void* f(void* out);
};

void* S::f(void* out) {
    void* local = 0;
    void* v = this->vptr;
    void* (__thiscall *fn)(void*) = *(void* (__thiscall **)(void*))((char*)v + 0x84);
    void* r = fn(this);
    sub_410330(&local, r);
    void** src = (void**)&local;
    void** dst = (void**)out;
    dst[0] = src[0];
    dst[1] = src[1];
    if (dst[1]) {
        _InterlockedExchangeAdd((volatile long*)((char*)dst[1] + 4), 1);
    }
    void* esi = local;
    if (esi) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)esi + 4), -1) == 1) {
            void** vt = *(void***)esi;
            void (__thiscall *d)(void*) = (void (__thiscall *)(void*))vt[1];
            d(esi);
            if (_InterlockedExchangeAdd((volatile long*)((char*)esi + 8), -1) == 1) {
                void** vt2 = *(void***)esi;
                void (__thiscall *d2)(void*) = (void (__thiscall *)(void*))vt2[2];
                d2(esi);
            }
        }
    }
    return out;
}
