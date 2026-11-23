// native-flags: /O2 /Oy /Ob2 /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <windows.h>
#include <new>

// INFERRED: no class header is available, so the object is accessed through raw offsets.

extern "C" int  __fastcall fn_005ceaa0(void* self, int unusedEdx);                 // UserInputBase::UserInputBase
extern "C" int  __fastcall fn_004328c0(void* self, int unusedEdx);                 // ATL::CCriticalSection::CCriticalSection
extern "C" void* __fastcall fn_006a14a8(void* wnd, int unusedEdx);                 // CWnd::GetTopLevelFrame
extern "C" void* __fastcall fn_006a0974(void* wnd, int unusedEdx);                 // CWnd::GetParentFrame
extern "C" void fn_00618a40(void* out, void* p);                                   // shared_from<...>
extern "C" void* __fastcall fn_004530f0(void* sp, int unusedEdx);                  // ServiceProvider::create<RunService>
extern "C" int  fn_0069fbd0(int a1, int a2, int a3, int a4, int a5, int a6);       // INFERRED: really takes 6 stack args
extern "C" void __stdcall fn_00401000(long hr);                                    // ATL::AtlThrowImpl
extern "C" int  __fastcall fn_00467550(void* self, int unusedEdx);
extern "C" int  __fastcall fn_004675e0(void* self, int unusedEdx);
extern "C" void __fastcall fn_004218a0(void* notifier, int unusedEdx, void* listener); // Notifier::addListener

#pragma pack(push, 1)
struct Accel6 { char c[6]; };
#pragma pack(pop)

typedef HACCEL (__thiscall *GetAccelFn)(void* thisFrame);

extern "C" void* __fastcall fn_004690f0(void* selfv, int unusedEdx, void* wnd, void* serviceProvider)
{
    char* self = (char*)selfv;

    fn_005ceaa0(self, 0);
    *(void**)(self + 0x00) = (void*)0x0081c404;
    *(void**)(self + 0x28) = (void*)0x0081c3f8;
    *(void**)(self + 0x2c) = (void*)0x0081c3ec;
    fn_004328c0(self + 0x34, 0);

    *(DWORD*)(self + 0x50) = 0;
    *(DWORD*)(self + 0x54) = 0;
    *(BYTE*)(self + 0x58) = 0;
    *(BYTE*)(self + 0x59) = 0;
    *(DWORD*)(self + 0x5c) = 0;
    *(float*)(self + 0x60) = 0.0f;
    *(float*)(self + 0x64) = 0.0f;
    *(DWORD*)(self + 0x168) = 0;
    *(void**)(self + 0x16c) = wnd;

    char* top = (char*)fn_006a14a8(wnd, 0);
    *(DWORD*)(self + 0x170) = top ? *(DWORD*)(top + 0x20) : 0;
    *(DWORD*)(self + 0x174) = 0;
    *(DWORD*)(self + 0x178) = 0;
    *(DWORD*)(self + 0x17c) = 0;

    fn_00618a40(self + 0x180, serviceProvider);
    void* runService = serviceProvider ? fn_004530f0(serviceProvider, 0) : 0;
    fn_00618a40(self + 0x188, runService);

    *(BYTE*)(self + 0x190) = 0;
    *(BYTE*)(self + 0x191) = 0;
    *(BYTE*)(self + 0x192) = 0;
    *(BYTE*)(self + 0x193) = 0;

    void* frame = fn_006a0974(*(void**)(self + 0x16c), 0);
    *(void**)(self + 0x4c) = frame;
    while (frame)
    {
        GetAccelFn getAccel = (GetAccelFn)(*(void***)frame)[0x188 / 4];
        int count = CopyAcceleratorTableA(getAccel(frame), 0, 0);
        *(int*)(self + 0x54) = count;
        if (count != 0)
        {
            Accel6* buf = new Accel6[(unsigned)count];
            void* f = *(void**)(self + 0x4c);
            *(Accel6**)(self + 0x50) = buf;
            GetAccelFn g = (GetAccelFn)(*(void***)f)[0x188 / 4];
            CopyAcceleratorTableA(g(f), (LPACCEL)buf, *(int*)(self + 0x54));
            break;
        }
        frame = fn_006a0974(*(void**)(self + 0x4c), 0);
        *(void**)(self + 0x4c) = frame;
    }

    memset(self + 0x68, 0, 0x100);

    int hr = fn_0069fbd0((int)GetModuleHandleA(0), 0, 0x800, 0x0081f028, (int)(self + 0x174), 0);
    if (hr < 0)
        fn_00401000(hr);

    fn_00467550(self, 0);
    fn_004675e0(self, 0);

    char* rs = *(char**)(self + 0x188);
    if (rs)
        fn_004218a0(rs + 0x130, 0, self + 0x2c);
    rs = *(char**)(self + 0x188);
    if (rs)
        fn_004218a0(rs + 0x170, 0, self + 0x28);

    return self;
}
