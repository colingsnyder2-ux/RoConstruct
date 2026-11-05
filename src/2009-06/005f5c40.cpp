// from server: 6% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall sub_40F8E0();
extern "C" void __stdcall sub_5F2580();

struct LocalBackpackTool {
    void destroy();
};

void LocalBackpackTool::destroy()
{
    sub_5F2580();
    int* p = *(int**)((char*)this + 0xac);
    if (p) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)p + 4), -1) == 1) {
            (*(void(__thiscall**)(int*))(*(int*)p + 4))(p);
            if (_InterlockedExchangeAdd((volatile long*)((char*)p + 8), -1) == 1) {
                (*(void(__thiscall**)(int*))(*(int*)p + 8))(p);
            }
        }
    }
    *(int*)((char*)this + 0x00) = 0x8d61c4;
    *(int*)((char*)this + 0x14) = 0x8d61b4;
    *(int*)((char*)this + 0x18) = 0x8d61ac;
    *(int*)((char*)this + 0x20) = 0x8d61a4;
    *(int*)((char*)this + 0x8c) = 0x8d619c;
    sub_40F8E0();
}
