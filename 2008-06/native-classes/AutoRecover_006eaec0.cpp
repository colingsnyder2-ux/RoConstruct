// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
extern "C" __declspec(dllimport) void* __stdcall SetWindowsHookExA(int, void*, void*, unsigned long);

// INFERRED: layout from disassembly offsets 0x0, 0xc, 0x18; padding fills untouched slots
struct Local_006eaec0 {
    void* m_pHook1;
    int m_pad1;
    int m_pad2;
    void* m_pHook2;
    int m_pad3;
    int m_pad4;
    void* m_pHook3;
};

extern "C" void __fastcall fn_006eaec0(Local_006eaec0* self, int unusedEdx)
{
    unsigned long (__stdcall *pGetCurrentThreadId)() = GetCurrentThreadId;
    void* (__stdcall *pSetWindowsHookExA)(int, void*, void*, unsigned long) = SetWindowsHookExA;

    unsigned long tid = pGetCurrentThreadId();
    self->m_pHook1 = pSetWindowsHookExA(7, (void*)0x6ea350, 0, tid);

    tid = pGetCurrentThreadId();
    self->m_pHook2 = pSetWindowsHookExA(2, (void*)0x6ea3b0, 0, tid);

    tid = pGetCurrentThreadId();
    self->m_pHook3 = pSetWindowsHookExA(4, (void*)0x6ea410, 0, tid);
}
