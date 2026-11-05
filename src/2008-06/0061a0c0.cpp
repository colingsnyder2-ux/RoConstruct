// from server: 100% by king_originala
extern "C" void __cdecl ensure_initialized(void (__cdecl *)(), void *);

extern "C" {
    extern void (__stdcall *EnterCriticalSection)(void *);
    extern void (__stdcall *LeaveCriticalSection)(void *);
    extern int (__stdcall *TlsFree)(unsigned long);
}

extern unsigned long tls_index;
extern char critical_section;
extern char initialization_flag;

void cleanup()
{
    ensure_initialized((void (__cdecl *)())0x0061a080,
                       &initialization_flag);

    EnterCriticalSection(&critical_section);

    unsigned long index = tls_index;
    if (index != 0xffffffffUL) {
        TlsFree(index);
        tls_index = 0xffffffffUL;
    }

    LeaveCriticalSection(&critical_section);
}
