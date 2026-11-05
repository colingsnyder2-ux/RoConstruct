// from server: 26% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl sub_718A38(unsigned int);
extern "C" void __cdecl sub_4F3880(void*, void*, void*);
extern "C" void __cdecl sub_4F3FE0(void*);

struct S_func_0062abb0 {
    void f(void*, void*, void*, void*);
};

struct Helper {
    void* m0;
    char pad1[8];
    void* m12;
    void* m16;
    void* m20;
};

void S_func_0062abb0::f(void* a1, void* a2, void* a3, void* a4)
{
    Helper h;
    h.m0 = 0;
    h.m12 = 0;
    h.m16 = 0;
    h.m20 = 0;

    void* p = sub_718A38(4);
    if (p != 0) {
        *(void**)p = &h;
    } else {
        p = 0;
    }
    h.m0 = p;

    void* local[2];
    local[0] = a1;
    local[1] = a2;

    if (a3 != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)a3 + 4), 1);
    }

    sub_4F3880(local, (void*)0x4F3170, 0);
    sub_4F3FE0(&h);

    void* v = h.m0;
    if (v != 0) {
        void* vt = *(void**)v;
        if (vt != 0) {
            void* tmp = &h;
            ((void (__stdcall*)(void*, void*, int))vt)(tmp, tmp, 2);
        }
        h.m0 = 0;
    }

    if (a4 != 0) {
        void* esi = a4;
        if (_InterlockedExchangeAdd((volatile long*)((char*)esi + 4), -1) == 1) {
            void* vt = *(void**)esi;
            ((void (__stdcall*)(void*))*(void**)((char*)vt + 4))(esi);
            if (_InterlockedExchangeAdd((volatile long*)((char*)esi + 8), -1) == 1) {
                void* vt2 = *(void**)esi;
                ((void (__stdcall*)(void*))*(void**)((char*)vt2 + 8))(esi);
            }
        }
    }
}
