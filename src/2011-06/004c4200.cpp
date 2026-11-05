// from server: 25% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall sub_697580(int, int, int);
extern "C" void __cdecl sub_4bbc20(int);
extern "C" void __stdcall sub_5986f0(int, int, int);

struct VPlayer {
    void func(int, int, int, int);
};

void VPlayer::func(int a, int b, int c, int d)
{
    int local14 = 0;
    int local1c = 0;
    int local28 = 0;
    int local34 = 0;
    int local3c = 0;
    int local44 = 0;
    int local48 = 0;
    int local4c = 0;
    int local50 = 0;
    int local5c = 0;
    int local24 = 0;
    int local30 = 0;

    unsigned char flag = *(unsigned char*)0xcb5a01;

    sub_697580(flag, (int)&local1c, 0);
    sub_4bbc20((int)&local28);

    local3c = 2;
    sub_5986f0(a, b, (int)&local14);

    local5c = 1;
    local3c = 1;

    if (local14) {
        int* p = (int*)local14;
        int vt = *p;
        if (vt) {
            ((void (__stdcall*)(int, int))vt)((int)&local1c, 2);
        }
        local14 = 0;
    }

    local3c = 0;

    if (local50) {
        int* obj = (int*)local50;
        if (_InterlockedExchangeAdd((volatile long*)((char*)obj + 4), -1) == 1) {
            int vt = *obj;
            ((void (__stdcall*)(int))*(int*)(vt + 4))(local50);
            if (_InterlockedExchangeAdd((volatile long*)((char*)obj + 8), -1) == 1) {
                int vt2 = *obj;
                ((void (__stdcall*)(int))*(int*)(vt2 + 8))(local50);
            }
        }
    }
}
