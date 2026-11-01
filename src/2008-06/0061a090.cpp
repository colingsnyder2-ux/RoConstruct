// from server: 100% by king_originala
extern char criticalSection;
extern char initializationFlag;

extern void __cdecl initialize();
extern void __cdecl initializeOnce(void (__cdecl *)(), void *);

extern "C" {
    extern void (__stdcall *EnterCriticalSection)(void *);
    extern void (__stdcall *LeaveCriticalSection)(void *);
}

void func_0061a090()
{
    initializeOnce(initialize, &initializationFlag);
    EnterCriticalSection(&criticalSection);
    LeaveCriticalSection(&criticalSection);
}
