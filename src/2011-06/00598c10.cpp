// from server: 26% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl func_7062b0(int, int, int);
extern "C" void __cdecl func_596c30(int);
extern "C" void __cdecl func_598730(int, int, int);

struct S {
    void f(int, int, int, int);
};

void S::f(int a, int b, int c, int d)
{
    int local14 = 0;
    int local1c = 0;
    char pad[0x28 - 8];
    int local34 = 0;
    int local38 = 0;
    int local3c = 0;
    int local40 = 0;
    int local44 = 0;
    int local48 = 0;
    int local4c = 0;

    unsigned char g1 = *(unsigned char*)0xcbbe8e;
    unsigned char g2 = *(unsigned char*)0xcbbf62;

    int tmp[2];
    tmp[0] = c;
    tmp[1] = d;

    local40 = 1;

    int* p = (int*)0x595ad0;

    if (a != 0) {
        int* r = (int*)(a + 4);
        _InterlockedExchangeAdd((volatile long*)r, 1);
    }

    func_7062b0((int)tmp, (int)p, 0);

    func_596c30((int)&local14);

    local3c = 2;

    func_598730((int)this, b, (int)&local14);

    int* q = (int*)local14;
    local38 = 1;
    local3c = 1;
    if (q != 0) {
        int* vt = (int*)*q;
        if (vt != 0) {
            typedef void (__stdcall *Fn)(int, int, int);
            Fn fn = (Fn)vt;
            fn((int)&local1c, (int)&local1c, 2);
        }
        local14 = 0;
    }

    int* s = (int*)local48;
    local3c = 0;
    if (s != 0) {
        if (_InterlockedExchangeAdd((volatile long*)(s + 1), -1) == 1) {
            int* vt = (int*)*s;
            typedef void (__stdcall *Fn)(int);
            Fn fn = (Fn)vt[1];
            fn((int)s);
            if (_InterlockedExchangeAdd((volatile long*)((char*)s + 8), -1) == 1) {
                int* vt2 = (int*)*s;
                typedef void (__stdcall *Fn2)(int);
                Fn2 fn2 = (Fn2)vt2[2];
                fn2((int)s);
            }
        }
    }
}
