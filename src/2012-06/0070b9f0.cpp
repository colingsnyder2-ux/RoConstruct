// from server: 44% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall G1_func_00709a60(void* a1);
extern "C" void __stdcall G1_func_00832200(void* a1, void* a2, int a3);

struct RefCounted {
    void* vptr;
    long refCount;
};

struct WeakFunctionRef {
    void* vptr;
    RefCounted* strongRef;
    void* weakRef;

    void __cdecl func_0070b9f0(RefCounted* a1, void* a2, void* a3, void* a4);
};

void WeakFunctionRef::func_0070b9f0(RefCounted* a1, void* a2, void* a3, void* a4)
{
    int state = 0;
    RefCounted* strong = a1;
    void* weak = a2;

    if (weak) {
        _InterlockedExchangeAdd(&reinterpret_cast<long*>(weak)[1], 1);
    }

    G1_func_00709a60(strong);
    G1_func_00832200(this, strong, 1);

    RefCounted* obj = reinterpret_cast<RefCounted*>(a4);
    state = -1;

    if (obj) {
        long oldWeak = _InterlockedExchangeAdd(&obj->refCount, -1);
        if (oldWeak == 1) {
            void* vptr = obj->vptr;
            typedef void (__thiscall *Dtor1)(void*);
            reinterpret_cast<Dtor1>(reinterpret_cast<void**>(vptr)[1])(obj);

            long oldStrong = _InterlockedExchangeAdd(&reinterpret_cast<long*>(obj)[2], -1);
            if (oldStrong == 1) {
                void* vptr2 = obj->vptr;
                typedef void (__thiscall *Dtor2)(void*);
                reinterpret_cast<Dtor2>(reinterpret_cast<void**>(vptr2)[2])(obj);
            }
        }
    }
}
