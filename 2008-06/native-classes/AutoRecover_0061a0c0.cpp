// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" {
    // INFERRED: boost::call_once(void (*)(), once_flag&) ; mangled ?call_once@boost@@YAXP6AXXZAAJ@Z
    void __cdecl fn_00557330(void (__cdecl *fn)(), long *flag);
    __declspec(dllimport) void __stdcall EnterCriticalSection(void *);
    __declspec(dllimport) void __stdcall LeaveCriticalSection(void *);
    __declspec(dllimport) int __stdcall TlsFree(unsigned long);
}

extern long g_0097bf54;               // once flag
extern char g_0097bf3c;               // CRITICAL_SECTION
extern unsigned long g_0095af6c;      // TLS index

extern "C" void fn_0061a0c0()
{
    fn_00557330((void (__cdecl *)())0x0061a080, &g_0097bf54);

    EnterCriticalSection(&g_0097bf3c);

    unsigned long index = g_0095af6c;
    if (index != 0xffffffffUL) {
        TlsFree(index);
        g_0095af6c = 0xffffffffUL;
    }

    LeaveCriticalSection(&g_0097bf3c);
}
