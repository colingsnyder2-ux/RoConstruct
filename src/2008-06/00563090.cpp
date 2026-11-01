// from server: 100% by king_originala
extern "C" {
    extern void (__stdcall *EnterCriticalSection)(void *);
    extern void (__stdcall *LeaveCriticalSection)(void *);
    extern unsigned long (__stdcall *WaitForSingleObject)(void *, unsigned long);
    extern int (__stdcall *ReleaseMutex)(void *);
}

struct S {
    void *handle;
    bool criticalSection;
    unsigned int count;
    void lock();
};

void S::lock()
{
    if (criticalSection)
        EnterCriticalSection(handle);
    else
        WaitForSingleObject(handle, 0xFFFFFFFFUL);

    ++count;
    if (count > 1) {
        if (criticalSection)
            LeaveCriticalSection(handle);
        else
            ReleaseMutex(handle);
    }
}
