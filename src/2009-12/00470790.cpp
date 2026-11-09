// from server: 44% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __stdcall sub_7F4AAA(int, int, int, int, int);

struct CSettingsExplorer {
    void sub_41BF00(int, int);
    void sub_470790(int, int);
};

void CSettingsExplorer::sub_470790(int a, int b)
{
    int local = 0;
    int* p = (int*)sub_7F4AAA(a, 0, 0xaffe40, 0xb00098, 0);
    if (p != 0) {
        int v1 = a;
        int v2 = b;
        int* q = &v1;
        int* r = (int*)&v2;
        int* s = (int*)&v1;
        (void)r;
        (void)s;
        if (b != 0) {
            _InterlockedExchangeAdd((volatile long*)(b + 4), 1);
        }
        sub_41BF00(v1, v2);
    }
    if (b != 0) {
        if (_InterlockedExchangeAdd((volatile long*)(b + 4), -1) == 1) {
            (*(void (__thiscall**)(int))(*(int*)b + 4))(b);
            if (_InterlockedExchangeAdd((volatile long*)(b + 8), -1) == 1) {
                (*(void (__thiscall**)(int))(*(int*)b + 8))(b);
            }
        }
    }
}
