// from server: 49% by colin
extern "C" __declspec(dllimport) void* __stdcall GetCurrentProcess();
extern "C" __declspec(dllimport) int __stdcall IsDebuggerPresent();
extern "C" __declspec(dllimport) void* __stdcall SetUnhandledExceptionFilter(void*);
extern "C" __declspec(dllimport) int __stdcall TerminateProcess(void*, unsigned int);
extern "C" __declspec(dllimport) long __stdcall UnhandledExceptionFilter(void*);

extern "C" void __cdecl func_0063197a(int);

extern unsigned int dword_008C8370;
extern unsigned int dword_008C8374;
extern unsigned int dword_008C837C;
extern void* dword_008C83C0;
extern unsigned int dword_008C83C8;
extern unsigned int dword_008B5188;
extern unsigned int dword_008B518C;
extern void* dword_007C4E04;
extern unsigned int dword_008C8480;

void __cdecl func_006314F9()
{
    dword_008C83C8 = 0x10001;
    dword_008C837C = dword_008C8480;
    dword_008C8370 = 0xC0000409;
    dword_008C8374 = 1;
    dword_008C83C0 = GetCurrentProcess();
    func_0063197a(1);
    IsDebuggerPresent();
    SetUnhandledExceptionFilter(dword_007C4E04);
    if (dword_008C83C0 == 0)
    {
        func_0063197a(1);
    }
    TerminateProcess(dword_008C83C0, 0xC0000409);
    UnhandledExceptionFilter(0);
}
