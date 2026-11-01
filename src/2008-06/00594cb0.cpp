// from server: 100% by king_originala
extern "C" void (__stdcall *DeleteCriticalSection)(void *);
extern "C" int (__stdcall *CloseHandle)(void *);
extern "C" void __cdecl releaseMemory(void *);

struct S {
    void *object;
    bool criticalSection;
    void f();
};

void S::f()
{
    if (criticalSection) {
        void *p = object;
        DeleteCriticalSection(p);
        releaseMemory(p);
    } else {
        CloseHandle(object);
    }
}
