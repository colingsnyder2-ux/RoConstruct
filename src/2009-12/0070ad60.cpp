// from server: 18% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __cdecl sub_7F4AAA(int, int, int, int, int);
extern "C" int __cdecl sub_682520();
extern "C" int __cdecl sub_704C00();
extern "C" int __cdecl sub_7EA500();

struct S {
    void __cdecl f(int a, int b, int c);
};

void S::f(int a, int b, int c)
{
    int v = sub_7F4AAA(a, 0, 0xaffe40, 0xb040d8, 0);
    if (v != 0 && *(int*)(v + 0xd0) == 0) {
        int sp;
        sub_682520();
        int esi = sp;
        if (esi != 0) {
            if (_InterlockedExchangeAdd((volatile long*)(esi + 4), -1) == 1) {
                (*(void(**)(int))esi)(esi);
                if (_InterlockedExchangeAdd((volatile long*)(esi + 8), -1) == 1) {
                    (*(void(**)(int))(*(int*)esi + 8))(esi);
                }
            }
        }
        sub_7EA500();
    }
    int local[3];
    local[0] = 0x70ad60;
    local[1] = b;
    local[2] = c;
    sub_704C00();
    int esi2 = local[0];
    if (esi2 != 0) {
        if (_InterlockedExchangeAdd((volatile long*)(esi2 + 4), -1) == 1) {
            (*(void(**)(int))esi2)(esi2);
            if (_InterlockedExchangeAdd((volatile long*)(esi2 + 8), -1) == 1) {
                (*(void(**)(int))(*(int*)esi2 + 8))(esi2);
            }
        }
    }
}
