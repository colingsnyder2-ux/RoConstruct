// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
extern "C" __declspec(dllimport) void* __stdcall SetWindowsHookExA(int, void*, void*, unsigned long);
extern "C" __declspec(dllimport) int __stdcall UnhookWindowsHookEx(void*);

// INFERRED: globals at 0x97e8f8 / 0x97e8fc, names from address
extern "C" void* g_0097e8f8;
extern "C" void* g_0097e8fc;

extern "C" void* fn_006f9900;

extern "C" void __cdecl fn_006fa0d0(void* target)
{
    if (target != 0)
    {
        if (g_0097e8f8 == 0)
        {
            unsigned long tid = GetCurrentThreadId();
            g_0097e8f8 = SetWindowsHookExA(7, (void*)&fn_006f9900, 0, tid);
            g_0097e8fc = target;
            return;
        }
    }
    else
    {
        if (g_0097e8f8 != 0)
        {
            UnhookWindowsHookEx(g_0097e8f8);
            g_0097e8f8 = 0;
        }
    }
    g_0097e8fc = target;
}
