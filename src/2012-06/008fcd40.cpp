// from server: 41% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall func_004c87b0();
extern "C" void __stdcall func_004c08f0();
extern "C" void __stdcall func_00685090();
extern "C" void __stdcall func_008fb330();
extern "C" void __stdcall func_008fb3c0();
extern "C" void __stdcall func_008fb450();

struct Sub {
    void* vt;
    char pad[0x100];
};

struct Obj {
    void* vt0;
    void* vt1;
    char pad0[0x10];
    void* vt18;
    void* vt1c;
    char pad1[0x64];
    void* ref84;
    void* ref8c;
    char pad2[0x48];
    Sub sub_d0;
    Sub sub_d8;
    Sub sub_e0;
    Sub sub_e8;
    Sub sub_f0;

    void destroy();
};

void Obj::destroy()
{
    this->vt0 = (void*)0xbf07ec;
    this->vt1 = (void*)0xbf07e4;
    this->vt18 = (void*)0xbf07d8;
    this->vt1c = (void*)0xbf07cc;

    func_004c87b0();
    func_004c08f0();

    func_004c87b0();
    func_008fb3c0();

    func_004c87b0();
    func_008fb450();

    func_004c87b0();
    func_008fb3c0();

    func_004c87b0();
    func_008fb330();

    void* p8c = this->ref8c;
    if (p8c) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)p8c + 8), -1) == 1) {
            void** vt = *(void***)p8c;
            ((void(__thiscall*)(void*))vt[2])(p8c);
        }
    }

    void* p84 = this->ref84;
    if (p84) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)p84 + 4), -1) == 1) {
            void** vt = *(void***)p84;
            ((void(__thiscall*)(void*))vt[1])(p84);
            if (_InterlockedExchangeAdd((volatile long*)((char*)p84 + 8), -1) == 1) {
                void** vt2 = *(void***)p84;
                ((void(__thiscall*)(void*))vt2[2])(p84);
            }
        }
    }

    func_00685090();
}
