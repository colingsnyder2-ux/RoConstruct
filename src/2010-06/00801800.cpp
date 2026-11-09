// from server: 100% by tester
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
extern "C" __declspec(dllimport) void* __stdcall SetWindowsHookExA(int, void*, void*, unsigned long);
extern "C" __declspec(dllimport) int __stdcall UnhookWindowsHookEx(void*);

void* g_hook = 0;
void* g_target = 0;

void __cdecl SetHook(void* target)
{
    if (target != 0)
    {
        if (g_hook == 0)
        {
            unsigned long tid = GetCurrentThreadId();
            g_hook = SetWindowsHookExA(7, (void*)0x681f70, 0, tid);
            g_target = target;
            return;
        }
    }
    else
    {
        if (g_hook != 0)
        {
            UnhookWindowsHookEx(g_hook);
            g_hook = 0;
        }
    }
    g_target = target;
}
