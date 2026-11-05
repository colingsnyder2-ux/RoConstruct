// from server: 46% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall sub_a404d0();
extern "C" void __stdcall sub_ccfe70();

struct S_func_00687e60 {
    char pad[4];
    bool f(int, int, int, int, int, int, int);
};

struct Str {
    char pad[0x1c];
};

struct Ref {
    char pad[4];
    volatile long m_ref;
    volatile long m_ref2;
};

extern "C" void* __cdecl sub_006812f0(void*);
extern "C" void* __cdecl sub_00593980(void*, void*);
extern "C" void* __cdecl sub_005e1c20(void*, void*);
extern "C" void* __cdecl sub_00597910(void*, void*);

bool S_func_00687e60::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    void* p;
    void* q;
    void* r;
    void* s;
    Str str;
    Ref* ref;

    p = sub_006812f0(this);
    if (p != 0) {
        if (sub_00593980(p, &str) != 0) {
            sub_a404d0();
            return false;
        }
    }
    sub_a404d0();

    sub_005e1c20(&q, 0);
    (*(void (__thiscall**)(void*, Str*))(*(char**)q + 8))(q, &str);

    r = q;
    if (r != 0) {
        r = (char*)r + 0x1c;
    } else {
        r = 0;
    }

    s = sub_006812f0(this);
    sub_00597910(s, r);

    ref = (Ref*)q;
    if (ref != 0) {
        if (_InterlockedExchangeAdd(&ref->m_ref, -1) == 1) {
            (*(void (__thiscall**)(Ref*))(*(char**)ref + 4))(ref);
            if (_InterlockedExchangeAdd(&ref->m_ref2, -1) == 1) {
                (*(void (__thiscall**)(Ref*))(*(char**)ref + 8))(ref);
            }
        }
    }

    sub_a404d0();
    return true;
}
