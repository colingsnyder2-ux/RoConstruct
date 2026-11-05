// from server: 26% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl sub_401000(long);
extern "C" void* __cdecl sub_403800(void*, void*);
extern "C" void __cdecl sub_40D550(void*);
extern "C" void* __cdecl sub_412090(void*);
extern "C" void __cdecl sub_42DB50(void*, void*);
extern "C" void __cdecl sub_42E120(void*);
extern "C" void __cdecl sub_42E5D0(void*);
extern "C" void* __cdecl sub_53CED0(void*, void*, void*, void*, void*, void*);
extern "C" void __cdecl sub_5595A0(void*);
extern "C" void __cdecl sub_62FC62(void*);

extern "C" int (__stdcall *g_pfn77EA04)(void*, void*);

struct S_00467680 {
    void __stdcall f(void* a1, void* a2, void* a3, void* a4, void* a5, void* a6, void* a7, void* a8, void* a9, void* a10, void* a11, void* a12, void* a13, void* a14, void* a15, void* a16, void* a17);
};

void __stdcall S_00467680::f(void* a1, void* a2, void* a3, void* a4, void* a5, void* a6, void* a7, void* a8, void* a9, void* a10, void* a11, void* a12, void* a13, void* a14, void* a15, void* a16, void* a17)
{
    char* self = (char*)this;
    void* saved = a1;
    void* out = a17;

    void* p34 = *(void**)(self + 0x34);
    void* p38 = *(void**)(self + 0x38);

    if (p38 != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)p38 + 4), 1);
    }

    char buf84[0x20];
    sub_40D550(buf84);

    char buf60[0x10];
    *(void**)(buf60 + 0) = 0;
    *(void**)(buf60 + 4) = 0;
    *(void**)(buf60 + 8) = 0;

    {
        unsigned short tmp = 0;
        int hr = g_pfn77EA04(&tmp, a2);
        if (hr < 0) {
            tmp = 0xa;
            *(int*)((char*)&tmp + 8) = hr;
            sub_401000(hr);
        }
    }

    sub_42E120(buf84);

    {
        unsigned short tmp = 0;
        int hr = g_pfn77EA04(&tmp, a3);
        if (hr < 0) {
            tmp = 0xa;
            *(int*)((char*)&tmp + 8) = hr;
            sub_401000(hr);
        }
    }

    sub_42E120(buf84);

    {
        unsigned short tmp = 0;
        int hr = g_pfn77EA04(&tmp, a4);
        if (hr < 0) {
            tmp = 0xa;
            *(int*)((char*)&tmp + 8) = hr;
            sub_401000(hr);
        }
    }

    sub_42E120(buf84);

    {
        unsigned short tmp = 0;
        int hr = g_pfn77EA04(&tmp, a5);
        if (hr < 0) {
            tmp = 0xa;
            *(int*)((char*)&tmp + 8) = hr;
            sub_401000(hr);
        }
    }

    sub_42E120(buf84);

    void* r = sub_403800(self, (char*)&a1 - 0x74);
    void* v = *(void**)r;
    sub_42E5D0(v);

    void* res = sub_53CED0(r, buf60, (void*)4, saved, 0, buf84);
    void* esi = *(void**)res;
    *(void**)res = 0;

    void* p50 = *(void**)buf60;
    if (p50 != 0) {
        void* p4 = *(void**)((char*)p50 + 4);
        if (p4 != 0) {
            void* p8 = *(void**)((char*)p50 + 8);
            sub_42DB50(p4, p8);
            sub_62FC62(*(void**)((char*)p50 + 4));
        }
        *(void**)((char*)p50 + 4) = 0;
        *(void**)((char*)p50 + 8) = 0;
        *(void**)((char*)p50 + 12) = 0;
        sub_62FC62(p50);
    }

    void* p70 = *(void**)((char*)&a1 - 0x70);
    if (p70 != 0) {
        long old = _InterlockedExchangeAdd((volatile long*)((char*)p70 + 4), -1);
        if (old == 1) {
            void* vt = *(void**)p70;
            void (*fn)(void*) = *(void (**)(void*))((char*)vt + 4);
            fn(p70);
            long old2 = _InterlockedExchangeAdd((volatile long*)((char*)p70 + 8), -1);
            if (old2 == 1) {
                void* vt2 = *(void**)p70;
                void (*fn2)(void*) = *(void (**)(void*))((char*)vt2 + 8);
                fn2(p70);
            }
        }
    }

    if (out != 0) {
        void* r2 = sub_412090(esi);
        *(void**)out = r2;
    }

    if (esi != 0) {
        void* p4 = *(void**)((char*)esi + 4);
        if (p4 != 0) {
            void* p8 = *(void**)((char*)esi + 8);
            sub_42DB50(p4, p8);
            sub_62FC62(*(void**)((char*)esi + 4));
        }
        *(void**)((char*)esi + 4) = 0;
        *(void**)((char*)esi + 8) = 0;
        *(void**)((char*)esi + 12) = 0;
        sub_62FC62(esi);
    }

    void* pA0 = *(void**)((char*)&a1 - 0x60);
    if (pA0 != 0) {
        void* pA4 = *(void**)((char*)&a1 - 0x5c);
        sub_42DB50(pA0, pA4);
        sub_62FC62(pA0);
    }

    *(void**)((char*)&a1 - 0x60) = 0;
    *(void**)((char*)&a1 - 0x5c) = 0;
    *(void**)((char*)&a1 - 0x58) = 0;

    sub_5595A0(buf84);
}
