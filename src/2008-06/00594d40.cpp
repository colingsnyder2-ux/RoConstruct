// from server: 100% by king_originala
extern "C" {
    extern void (__stdcall *LeaveCriticalSection)(void *);
    extern int (__stdcall *ReleaseMutex)(void *);
}

struct S {
    void *handle;
    unsigned char criticalSection;
    void unlock(void *&);
};

void S::unlock(void *&)
{
    if (criticalSection)
        LeaveCriticalSection(handle);
    else
        ReleaseMutex(handle);
}
