// from server: 34% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __cdecl sub_7f4aaa(int, int, int, int, int);
extern "C" void __cdecl sub_6cba70();
extern "C" void __cdecl sub_464170();

struct S_func_00697f30 {
    void f(int a);
};

void S_func_00697f30::f(int a)
{
    int* p = (int*)sub_7f4aaa(a, 0, 0xaffe40, 0xb03a58, 0);
    if (p) {
        ((void (__thiscall*)(int*))0x6cba70)(p);
    } else {
        ((void (__thiscall*)(void*, int))0x464170)(this, 0x697db0);
    }
    int* q = (int*)a;
    if (q) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)q + 4), -1) == 1) {
            ((void (__thiscall*)(int*))*(int*)(*(int*)q + 4))(q);
            if (_InterlockedExchangeAdd((volatile long*)((char*)q + 8), -1) == 1) {
                ((void (__thiscall*)(int*))*(int*)(*(int*)q + 8))(q);
            }
        }
    }
}
