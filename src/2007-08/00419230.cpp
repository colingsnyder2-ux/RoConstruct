// from server: 36% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct VDHTMLWindow_SignalDesc {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    void construct(int, int, int, int, int, int, int, int);
};

void VDHTMLWindow_SignalDesc::construct(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    int local[6];
    int* p;
    int* q;

    f0 = 0;
    f4 = 0;
    f8 = 0;

    local[0] = a1;
    local[1] = a2;
    local[2] = a3;
    local[3] = a4;
    local[4] = a5;
    local[5] = a6;

    if (a4 != 0) {
        _InterlockedExchangeAdd((volatile long*)(a4 + 4), 1);
    }

    local[4] = a7;
    local[5] = a8;

    ((void (__thiscall*)(VDHTMLWindow_SignalDesc*, int*))0x418980)(this, local);

    if (a4 != 0) {
        if (_InterlockedExchangeAdd((volatile long*)(a4 + 4), -1) == 1) {
            (*(void (__thiscall**)(int))(*(int*)a4 + 4))(a4);
            if (_InterlockedExchangeAdd((volatile long*)(a4 + 8), -1) == 1) {
                (*(void (__thiscall**)(int))(*(int*)a4 + 8))(a4);
            }
        }
    }
}
