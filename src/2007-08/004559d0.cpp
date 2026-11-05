// from server: 49% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct CRobloxReportPaneView {
    void func(int, int, int, int);
};

extern "C" void __stdcall sub_004555b0(int);

void CRobloxReportPaneView::func(int a, int b, int c, int d)
{
    int* p = (int*)b;
    if (p) {
        _InterlockedExchangeAdd((volatile long*)((char*)p + 4), 1);
    }
    sub_004555b0((int)((char*)this - 0x318));
    if (p) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)p + 4), -1) == 1) {
            (*(void(__thiscall**)(int*))(*(int*)p + 4))((int*)p);
            if (_InterlockedExchangeAdd((volatile long*)((char*)p + 8), -1) == 1) {
                (*(void(__thiscall**)(int*))(*(int*)p + 8))((int*)p);
            }
        }
    }
    int* q = (int*)d;
    if (q) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)q + 4), -1) == 1) {
            (*(void(__thiscall**)(int*))(*(int*)q + 4))((int*)q);
            if (_InterlockedExchangeAdd((volatile long*)((char*)q + 8), -1) == 1) {
                (*(void(__thiscall**)(int*))(*(int*)q + 8))((int*)q);
            }
        }
    }
}
